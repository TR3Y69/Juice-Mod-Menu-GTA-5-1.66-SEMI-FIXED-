#include "Hooking.hpp"
#include "Game.hpp"
#include "ScriptManager.hpp"
#include "CustomText.hpp"
#include "Util.hpp"
#include "D3DRenderer.hpp"
#include "UI/UIManager.hpp"
#include <MinHook/MinHook.h>
#ifdef BIGBASE_DEBUG
#  pragma comment(lib, "MinHook-Debug.lib")
#else
#  pragma comment(lib, "MinHook-Release.lib")
#endif

namespace Big
{


	namespace
	{
		std::uint32_t g_HookFrameCount{};
	}

	bool Hooks::IsDlcPresent(std::uint32_t hash)
	{
		if (g_Running && g_HookFrameCount != *g_GameVariables->m_FrameCount)
		{
			g_HookFrameCount = *g_GameVariables->m_FrameCount;
			g_ScriptManager->OnGameTick();
		}

		return static_cast<decltype(&IsDlcPresent)>(g_Hooking->m_OriginalIsDlcPresent)(hash);
	}

	const char* Hooks::GetLabelText(void* unk, const char* label)
	{
		if (g_Running)
			if (auto text = g_CustomText->GetText(Joaat(label)))
				return text;

		return static_cast<decltype(&GetLabelText)>(g_Hooking->m_OriginalGetLabelText)(unk, label);
	}
	
	bool Hooks::GetEventData(std::int32_t eventGroup, std::int32_t eventIndex, std::int64_t* args, std::uint32_t argCount)
	{
		auto result = static_cast<decltype(&GetEventData)>(g_Hooking->m_OriginalGetEventData)(eventGroup, eventIndex, args, argCount);

		if (result && g_LogScriptEvents)
		{
			g_Logger->Infos("Log Script event group: %i", eventGroup);
			for (std::uint32_t i = 0; i < argCount; ++i)
				g_Logger->Infos("Log Script event args[%u] : %" PRIi64, i, args[i]);
		}

		return result;
	}
	bool Hooks::NetworkCanBail()
	{
		return false;
	}

	LRESULT Hooks::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		g_D3DRenderer->WndProc(hWnd, msg, wParam, lParam);
		return static_cast<decltype(&WndProc)>(g_Hooking->m_OriginalWndProc)(hWnd, msg, wParam, lParam);
	}

	HRESULT Hooks::Present(IDXGISwapChain* dis, UINT syncInterval, UINT flags)
	{
		if (g_Running)
		{
			g_D3DRenderer->BeginFrame();
			g_ScriptManager->OnD3DTick();
			g_D3DRenderer->EndFrame();
		}

		return g_Hooking->m_D3DHook.GetOriginal<decltype(&Present)>(PresentIndex)(dis, syncInterval, flags);
	}
	void WAIT(DWORD ms)
	{
		SwitchToFiber;
	}
	HRESULT Hooks::ResizeBuffers(IDXGISwapChain* dis, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags)
	{
		if (g_Running)
		{
			g_D3DRenderer->PreResize();
			auto hr = g_Hooking->m_D3DHook.GetOriginal<decltype(&ResizeBuffers)>(ResizeBuffersIndex)(dis, bufferCount, width, height, newFormat, swapChainFlags);
			if (SUCCEEDED(hr))
			{
				g_D3DRenderer->PostResize();
			}

			return hr;
		}

		return g_Hooking->m_D3DHook.GetOriginal<decltype(&ResizeBuffers)>(ResizeBuffersIndex)(dis, bufferCount, width, height, newFormat, swapChainFlags);
	}
#ifndef __INPUT_HOOK_H__
#define __INPUT_HOOK_H__

#pragma once

	class InputHook
	{
	public:
		bool Initialize();
		void Remove();
		typedef void(*TKeyboardFn)(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow);
		void keyboardHandlerRegister(TKeyboardFn function);
		void keyboardHandlerUnregister(TKeyboardFn function);
		HWND getWindow() { return hWindow; }
	protected:
		HWND hWindow;
	}; extern InputHook iHook;

	static LRESULT APIENTRY WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif 

	struct RttiCompleteObjectLocator
	{
		std::uint32_t m_Signature;
		std::uint32_t m_OffsetFromBase;
		std::uint32_t m_ConstructorDisplacement;
		std::uint32_t m_TypeDescRva;
		std::uint32_t m_HierarchyDescRva;
		std::uint32_t m_BaseClassRva;
	};
	int Hooks::JoinPlayer(__int64 a1, int a2, __int64* a3, int a4) {
		if (JoinPlayer)
		{
			if (a3 == 0)
			{
				return static_cast<decltype(&JoinPlayer)>(g_Hooking->m_OriginalJoinPlayer)(a1, a2, a3, a4);
			}
			*a3;
		}
		return static_cast<decltype(&JoinPlayer)>(g_Hooking->m_OriginalJoinPlayer)(a1, a2, a3, a4);
	}
	Hooking::Hooking() :
		m_D3DHook(g_GameVariables->m_Swapchain, 18)
	{
		MH_Initialize();
		MH_CreateHook(g_GameFunctions->m_IsDlcPresent, &Hooks::IsDlcPresent, &m_OriginalIsDlcPresent);	
		MH_CreateHook(g_GameFunctions->m_GetLabelText, &Hooks::GetLabelText, &m_OriginalGetLabelText);		
		MH_CreateHook(g_GameFunctions->m_GetEventData, &Hooks::GetEventData, &m_OriginalGetEventData);	
		MH_CreateHook(g_GameFunctions->m_WndProc, &Hooks::WndProc, &m_OriginalWndProc);		
		m_D3DHook.Hook(&Hooks::Present, Hooks::PresentIndex);
		m_D3DHook.Hook(&Hooks::ResizeBuffers, Hooks::ResizeBuffersIndex);
	}
	/*bool LogEvent = false;
	int Hooks::TriggerScriptEvent(bool unk0, uint64_t* args, int argCount, int bitFlags)
	{
		if (LogEvent)
		{
			g_Logger->Info("TSE");
			for (int i = 0; i < argCount; i++)
				g_Logger->Info("args[%i]: 0x%016llx => %d", i, args[i], args[i]);
		}
		return static_cast<decltype(&TriggerScriptEvent)>(g_Hooking->m_OriginalTriggerScriptEvent)(unk0, args, argCount, bitFlags);
	}*/
	Hooking::~Hooking() noexcept
	{
		MH_RemoveHook(g_GameFunctions->m_WndProc);
		MH_RemoveHook(g_GameFunctions->m_GetEventData);
		MH_RemoveHook(g_GameFunctions->m_GetLabelText);
		MH_RemoveHook(g_GameFunctions->m_IsDlcPresent);
		MH_Uninitialize();
		MH_RemoveHook(g_GameFunctions->m_GetEventData);
		MH_RemoveHook(g_GameFunctions->m_IsDlcPresent);
	}
	struct objectHash
	{
		DWORD* ptr;
		DWORD	hash;
	};
	void Hooking::Hook()
	{
		m_D3DHook.Enable();
		MH_EnableHook(MH_ALL_HOOKS);
	}

	void Hooking::Unhook()
	{
		m_D3DHook.Disable();
		MH_DisableHook(MH_ALL_HOOKS);
	}
}
