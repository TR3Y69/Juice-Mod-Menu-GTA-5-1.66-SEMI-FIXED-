#include "Game.hpp"
#include "LogScript.hpp"
#include "UI/UIManager.hpp"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_impl_win32.h"

namespace Big
{
	bool LogScript::IsInitialized()
	{
		return m_Initialized;
	}

	ScriptType LogScript::GetType()
	{
		return ScriptType::D3D;
	}

	void LogScript::Initialize()
	{
		m_Initialized = true;
	}

	void LogScript::Destroy()
	{
	}

	namespace
	{
		std::size_t s_LastLogCount = 0;
	}

	void LogScript::Tick()
	{
		
		
	}
}
