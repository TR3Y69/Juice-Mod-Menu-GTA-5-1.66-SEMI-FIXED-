#include "Game.hpp"
#include "Hooking.hpp"
#include "ScriptManager.hpp"
#include "LogScript.hpp"
#include "MainScript.hpp"
#include "ScriptCallback.hpp"
#include "Invoker.hpp"
#include "CustomText.hpp"
#include "D3DRenderer.hpp"
#include "UI/UIManager.hpp"
#include "Translation.hpp"


/**
 * \brief The entry point of the library
 * \param hInstance The base address of the DLL
 * \param reason The reason for this function being called
 */
HANDLE neger;
BOOL DllMain(HINSTANCE hInstance, DWORD reason, LPVOID)
{
	using namespace Big;

	if (reason == DLL_PROCESS_ATTACH)
	{
		g_Module = hInstance;
		neger = CreateThread(nullptr, 0, [](LPVOID) -> DWORD
		{
			g_Logger = std::make_unique<Logger>();
			g_Logger->Error(R"(Running Start-Up Juice
    ___  ___  ___  ___  ________  _______      
   |\  \|\  \|\  \|\  \|\   ____\|\  ___ \     
   \ \  \ \  \\\  \ \  \ \  \___|\ \   __/|    
 __ \ \  \ \  \\\  \ \  \ \  \    \ \  \_|/__  
|\  \\_\  \ \  \\\  \ \  \ \  \____\ \  \_|\ \ 
\ \________\ \_______\ \__\ \_______\ \_______\
 \|________|\|_______|\|__|\|_______|\|_______|)");
g_Logger->Hooks("Start The Inject.");
g_Logger->Error("Loading English Translations.");

			g_GameFunctions = std::make_unique<GameFunctions>();
			g_GameVariables = std::make_unique<GameVariables>();

			// Wait for the game to load
			while (*g_GameVariables->m_GameState != 0)
			{
				std::this_thread::sleep_for(9s);
				std::this_thread::yield();
			}

			g_GameVariables->PostInit();

			g_Invoker = std::make_unique<Invoker>();
			g_CustomText = std::make_unique<CustomText>();
			g_D3DRenderer = std::make_unique<D3DRenderer>();
			g_UiManager = std::make_unique<UserInterface::UIManager>();

			g_ScriptManager = std::make_unique<ScriptManager>();
			g_MainScript = std::make_shared<MainScript>();
			g_LogScript = std::make_shared<LogScript>();
			g_CallbackScript = std::make_shared<CallbackScript>();
			g_ScriptManager->AddScript(g_MainScript);
			g_ScriptManager->AddScript(g_LogScript);
			g_ScriptManager->AddScript(g_CallbackScript);

			g_Hooking = std::make_unique<Hooking>();
			g_Hooking->Hook();
			
			g_Logger->Hooks("Juice Is Successfully Injected");
			g_Logger->Hooks("Press F7 To Open");

			while (g_Running)
			{
				if (IsKeyPressed(VK_F1))
					g_Running = false;

				std::this_thread::sleep_for(3ms);
				std::this_thread::yield();
			}

			std::this_thread::sleep_for(500ms);
			g_Hooking->Unhook();

			g_ScriptManager.reset();
			g_LogScript.reset();
			g_MainScript.reset();
			g_CallbackScript.reset();

			g_UiManager.reset();
			g_D3DRenderer.reset();
			g_CustomText.reset();
			g_Invoker.reset();

			std::this_thread::sleep_for(500ms);

			g_Hooking.reset();

			g_TranslationManager.reset();

			g_GameVariables.reset();
			g_GameFunctions.reset();
			
			g_Logger->Info("Close");
			g_Logger.reset();
			CloseHandle(neger);
			FreeLibraryAndExitThread(g_Module, 0);
		}, nullptr, 0, nullptr);
	}

	return true;
}
