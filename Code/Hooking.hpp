#pragma once
#include "VMTHook.hpp"
namespace Big
{
	struct Hooks
	{
		static int GetNumOfEvents(int eventgroup);
		static int JoinPlayer(__int64 a1, int a2, __int64* a3, int a4);
		static bool IsDlcPresent(std::uint32_t hash);
		//static int TriggerScriptEvent(bool unk0, uint64_t* args, int argCount, int bitFlags);
		static const char* GetLabelText(void* unk, const char* label);
		static bool GetEventData(std::int32_t eventGroup, std::int32_t eventIndex, std::int64_t* args, std::uint32_t argCount);
		static LRESULT WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		static constexpr auto PresentIndex = 8;
		static HRESULT Present(IDXGISwapChain* dis, UINT syncInterval, UINT flags);
		static bool TestHook(__int64 a, __int64 b, int c, char d);
		static constexpr auto ResizeBuffersIndex = 13;
		static HRESULT ResizeBuffers(IDXGISwapChain* dis, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags);
		static bool NetworkCanBail();
	};

	struct scrThread
	{
		void* vTable;
		void* m_pStack;
		void* pad;
		void* pad2;
		const char* m_pszExitMessage;
	};

	struct ScriptThread : scrThread
	{
		const char Name[64];
		void* m_pScriptHandler;
		const char gta_pad2[40];
		const char flag1;
		const char m_networkFlag;
		bool bool1;
		bool bool2;
		bool bool3;
		bool bool4;
		bool bool5;
		bool bool6;
		bool bool7;
		bool bool8;
		bool bool9;
		bool bool10;
		bool bool11;
		bool bool12;
		const char gta_pad3[10];
	};
	
	class CPatternResult
	{
	private:
		static BOOL InitializeHooks();
		static void FindPatterns();
		static void FailPatterns(const char* name);
	public:
		CPatternResult(void* pVoid);
		CPatternResult(void* pVoid, void* pBegin, void* pEnd);
		~CPatternResult();

		template <typename rT>
		rT* get(int offset = 0)
		{
			rT* ret = nullptr;
			if (m_pVoid != nullptr)
				ret = reinterpret_cast<rT*>(reinterpret_cast<char*>(m_pVoid) + offset);
			return ret;
		}

		template <typename rT>
		rT* get_rel(int offset = 0)
		{
			rT* result = nullptr;
			int32_t	rel;
			char* ptr = get<char>(offset);

			if (ptr == nullptr)
				goto LABEL_RETURN;

			rel = *(int32_t*)ptr;
			result = reinterpret_cast<rT*>(ptr + rel + sizeof(rel));

		LABEL_RETURN:
			return result;
		}

		template <typename rT>
		rT* section_begin()
		{
			return reinterpret_cast<rT*>(m_pBegin);
		}

		template <typename rT>
		rT* section_end()
		{
			return reinterpret_cast<rT*>(m_pEnd);
		}

	protected:
		void* m_pVoid = nullptr;
		void* m_pBegin = nullptr;
		void* m_pEnd = nullptr;
	};
	class Hooking
	{
	public:
		explicit Hooking();
		~Hooking() noexcept;
		Hooking(Hooking const&) = delete;
		Hooking(Hooking&&) = delete;
		Hooking& operator=(Hooking const&) = delete;
		Hooking& operator=(Hooking&&) = delete;
		void Hook();
		void Unhook();
		bool Swapping(bool toggle);

		friend struct Hooks;
	private:
		void* m_OriginalIsDlcPresent{};
		void* m_OriginalScriptVM{};
		void* m_OriginalGetNumOfEvents{};
		void* m_OriginalDisableErrorScreen{};
		void* m_OriginalChatMesage{};
		void* m_OriginalIsEntityUpsideDown{};
		void* m_OriginalReceiveEvent{};
		//void* m_OriginalTriggerScriptEvent{};
		void* m_OriginalEventManager{};
		void* m_OriginalResourceError{};
		void* m_OriginalEventQue{};
		void* m_OriginalResourceCall{};
		void* m_OriginalReportMyselfEvent{};
		void* m_OriginalInfoEvent{};
		void* m_OriginalNetworkManager{};
		void* m_OriginalSensorChat{};
		void* m_OriginalEventPat{};
		void* m_OriginalpMetricHook{};
		void* m_OriginalTestHook{};
		void* m_OriginalpNetworkCanBail{};
		void* m_OriginalGetEventData{};
		void* m_OriginalJoinPlayer{};
		void* m_OriginalPattern{};
		void* m_Originalsub_7FF6A853F9EC{};
		void* m_Originalsub_7FF6A8902B0C{};
		void* m_Originalsub_7FF6A89027C4{};
		
		//CNetGamePlayers* m_OriginalGetPlayerByIndexNet{};

		void* m_OriginalGetLabelText{};
		void* m_OriginalWndProc{};
		void* m_OriginalDenyDrops{};
		VMTHook m_D3DHook;
		char* m_ObjectBypass;
		char m_OriginalObjectBypass[2];
		char* m_ObjectCheck;
		char m_OriginalObjectCheck[24];
		char* m_ModelSpawn;
		char m_OriginalModelSpawn[2];
	};
	class CMetaData
	{
	public:
		static uint64_t	begin();
		static uint64_t	end();
		static DWORD	size();
		static void		init();
	private:
		static uint64_t	m_begin;
		static uint64_t	m_end;
		static DWORD	m_size;
	};

	inline std::unique_ptr<Hooking> g_Hooking;
}
