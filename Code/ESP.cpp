#include "ESP.h"

namespace ESP
{
	void Tick()
	{
		//Aimbot FOV
		if (Config::Aimbot::enabled && Config::Aimbot::draw_fov)
		{
			float ScreenCX = ImGui::GetIO().DisplaySize.x / 2;
			float ScreenCY = ImGui::GetIO().DisplaySize.y / 2;
			Config::draw_list->AddCircle(ImVec2(ScreenCX, ScreenCY), Config::Aimbot::fov, ImColor(255, 255, 0, 70), 24, 1.5f);
		}

		//Players
		if (Config::ESP::enabled)
		{
			for (int i = 0; i < 1024; i++)
			{
				if (Pools::players[i].ped == SDK::LocalPlayer)
					continue;

				Vector3 pedPos = Vector3(Pools::players[i].position.x, Pools::players[i].position.y, Pools::players[i].position.z);
				if (pedPos.x == 0.0f || pedPos.y == 0.0f || pedPos.z == 0.0f)
					continue;

				float health = Pools::players[i].health;
				if (health > 200.0f)    health = 200.0f;
				else if (health < 0.0f) health = 0.0f;

				float armor = Pools::players[i].armor;
				if (armor > 100.0f)    armor = 100.0f;
				else if (armor < 0.0f) armor = 0.0f;

				Vector3 originPos = Vector3(pedPos.x, pedPos.y, pedPos.z - 1.0f);
				Vector3 headPos = Vector3(pedPos.x, pedPos.y, pedPos.z + 0.9f);
				ImVec2 screenPos = SDK::WorldToScreen(originPos);
				ImVec2 screenPosHead = SDK::WorldToScreen(headPos);

				//Если игрок на экране
				if (screenPos.x > 0 && screenPosHead.x > 0)
				{
					float h = screenPosHead.y - screenPos.y;
					float w = (screenPos.y - screenPosHead.y) / 3.5f;
					
					//Box
					if (Config::ESP::boxes)
					{
						Config::draw_list->AddLine(ImVec2(screenPos.x - w, screenPosHead.y), ImVec2(screenPos.x + w, screenPosHead.y), ImColor(255, 200, 0, 180), 1.50f);
						Config::draw_list->AddLine(ImVec2(screenPos.x - w, screenPos.y), ImVec2(screenPos.x - w, screenPosHead.y), ImColor(255, 200, 0, 180), 1.50f);
						Config::draw_list->AddLine(ImVec2(screenPos.x + w, screenPos.y), ImVec2(screenPos.x + w, screenPosHead.y), ImColor(255, 200, 0, 180), 1.50f);
						Config::draw_list->AddLine(ImVec2(screenPos.x - w, screenPos.y), ImVec2(screenPos.x + w, screenPos.y), ImColor(255, 200, 0, 180), 1.50f);
					}

					//Health
					if (Config::ESP::health)
					{
						float oneHealth = h / 100;
						Config::draw_list->AddLine(ImVec2(screenPos.x - w - 6.0f, screenPos.y), ImVec2(screenPos.x - w - 6.0f, screenPosHead.y), ImColor(0, 0, 0, 255), 2.0f);
						Config::draw_list->AddLine(ImVec2(screenPos.x - w - 6.0f, screenPos.y), ImVec2(screenPos.x - w - 6.0f, screenPosHead.y - h + oneHealth * health), ImColor(0, 255, 0, 255), 2.0f);

						if (armor > 0)
						{
							Config::draw_list->AddLine(ImVec2(screenPos.x - w - 9.0f, screenPos.y), ImVec2(screenPos.x - w - 9.0f, screenPosHead.y), ImColor(0, 0, 0, 255), 2.0f);
							Config::draw_list->AddLine(ImVec2(screenPos.x - w - 9.0f, screenPos.y), ImVec2(screenPos.x - w - 9.0f, screenPosHead.y - h + oneHealth * armor), ImColor(0, 0, 255, 255), 2.0f);
						}
					}
				}
			}
		}
	}
}