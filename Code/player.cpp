#include "player.h"
#include "Natives.hpp"
#include "Types.hpp"
#include "ScriptCallback.hpp"
#include "Juice.h"

using namespace Big;
void Features::loop()
{
	Features::RainbowNeon();
	Features::shakecam();
}
//bool Features::deleteboolcartos[32] = { 0 };
//void Features::deleteboolcartol(Player target)
//{
//	PLAYER::_EXPAND_WORLD_LIMITS(FLT_MAX, FLT_MAX, FLT_MAX);
//	const int ElementAmount = 10;
//	const int ArrSize = ElementAmount * 2 + 2;
//	Vehicle* vehs = new Vehicle[ArrSize];
//	vehs[0] = ElementAmount;
//	int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);
//	for (int i = 0; i < VehFound; i++)
//	{
//		int OffsetID = i * 2 + 2;
//		if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
//		{
//			(vehs[OffsetID]);
//			NativeVector3 Playertarget = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
//			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(vehs[OffsetID], Playertarget.x, Playertarget.y, Playertarget.z, false, false, false);
//		}
//	}
//	delete[] vehs;
//}
bool Features::camshaker = false;
void Features::shakecam(){
	if (camshaker) {
		NativeVector3 targetCords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), false);
		FIRE::ADD_EXPLOSION(targetCords.x, targetCords.y, targetCords.z, 4, 0.f, false, true, 1000.f, false);
	}
}
int stealthDelay4088 = 100;
bool Features::Rneon = false;
void Features::RainbowNeon()
{
	if (Rneon) {
		if (stealthDelay4088) {
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			if (RainbowNeon) {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
				DWORD model = ENTITY::GET_ENTITY_MODEL(veh);
				if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0)){
					if (VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 0) && VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 1) && VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 2) && VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 3)){
						VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, false, false, false);
					}
					else
					{
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, false, false, false);
					}
				}
			}
		}
	}
}
void Features::CrashPlayerv(int player)
{
	for (int i = 0; i <= 500; i++)
	{
		Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
		Player ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
		{
			PED::CLONE_PED(playerPed, 1, 1, 1);
			PED::CLONE_PED(playerPed, 1, 1, 1);
			PED::CLONE_PED(playerPed, 1, 1, 1);
			PED::CLONE_PED(playerPed, 1, 1, 1);
			PED::CLONE_PED(playerPed, 1, 1, 1);
			PED::CLONE_PED(playerPed, 1, 1, 1);
			PED::CLONE_PED(playerPed, 1, 1, 1);
			PED::CLONE_PED(playerPed, 1, 1, 1);
			PED::CLONE_PED(playerPed, 1, 1, 1);
			PED::CLONE_PED(playerPed, 1, 1, 1);
			PED::CLONE_PED(playerPed, 1, 1, 1);
			PED::CLONE_PED(playerPed, 1, 1, 1);
			PED::CLONE_PED(playerPed, 1, 1, 1);
			PED::CLONE_PED(playerPed, 1, 1, 1);
			PED::CLONE_PED(playerPed, 1, 1, 1);
			NativeVector3 targetCords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(ped), false);
			FIRE::ADD_EXPLOSION(targetCords.x, targetCords.y, targetCords.z, 9999.0f, true, false, 0.0f, true, false);
			Player selectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
			NativeVector3 pos = ENTITY::GET_ENTITY_COORDS(selectedPlayer, true);
			FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 12, 5.f, true, false, 0.f, false);
			Vehicle selectedlPlayerveh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(ped), FALSE);
			bool isveh = PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(ped), FALSE);
			if (isveh)
			{
				(selectedlPlayerveh);
				VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(selectedlPlayerveh, TRUE);
				for (int i = 5; i--;)
					VEHICLE::SET_VEHICLE_TYRE_BURST(selectedlPlayerveh, i, TRUE, 1000.f);
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
				if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
				NativeVector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
				FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 29, 0.5f, true, false, 5.0f, 10);
			}
		}
	}
}
void Features::ExplodeVehicle(int players)
{
	Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(players);
	if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
	NativeVector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
	FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 29, 0.5f, true, false, 5.0f, 10);
}
void Features::PopTires(int target)
{
	Vehicle selectedlPlayerveh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), FALSE);
	bool isveh = PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), FALSE);
	if (isveh)
	{
		(selectedlPlayerveh);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(selectedlPlayerveh, TRUE);
		for (int i = 5; i--;)
			VEHICLE::SET_VEHICLE_TYRE_BURST(selectedlPlayerveh, i, TRUE, 1000.f);
	}
}
void Features::KickFromVehicle(int player)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), FALSE))
	{
		Ped SelectedCoords (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player));
		TASK::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player));
		TASK::CLEAR_PED_TASKS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player));
		TASK::CLEAR_PED_SECONDARY_TASK(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player));
	}
	else
	{
		NULL;
	}
}
bool Features::smokedown[32] = { false };
void Features::smokedownloop(int player)
{
	NativeVector3 targetCords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), false);
	FIRE::ADD_EXPLOSION(targetCords.x, targetCords.y, targetCords.z, 11, 11.1f, true, false, 11.1f, true);
}
void Features::ExplodeLoopPlayer(int player)
{
	NativeVector3 targetCords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), false);
	FIRE::ADD_EXPLOSION(targetCords.x, targetCords.y, targetCords.z, 9999.0f, true, false, 0.0f, true, false);
}
void Features::TeleportToPlayer(int player) {
	{
		Entity handle;
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
		NativeVector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), false);
		PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : handle = PLAYER::PLAYER_PED_ID();
		ENTITY::SET_ENTITY_COORDS(handle, coords.x, coords.y, coords.z, false, false, false, false);
	}
}
void Features::AirStrikeKill()
{
	Entity playerOnline = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
	int weaponHash = MISC::GET_HASH_KEY("VEHICLE_WEAPON_SPACE_ROCKET");
	if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponHash))
	{
		WEAPON::REQUEST_WEAPON_ASSET(weaponHash, 31, 0);
	}
	NativeVector3 getcoords1 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerOnline, 0.0f, 0.0f, 26.6f);
	NativeVector3 getcoords2 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerOnline, 0.0f, 0.0f, 1.5f);
	MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(getcoords1.x, getcoords1.y, getcoords1.z, getcoords2.x, getcoords2.y, getcoords2.z, 250, 1, weaponHash, NULL, 1, 0, -1.0);
}
void Features::tpcar(int player)
{

	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(player), true))
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED(player)), VEHICLE::IS_VEHICLE_SEAT_FREE(PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED(player)), -1, false));
	}
}
void Features::ValkyrieCannonAllPlayer()
{
	for (int i = 0; i < 32; i++)
	{
		int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
		{

			Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			NativeVector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			FIRE::ADD_EXPLOSION(playerPosition.x, playerPosition.y, playerPosition.z - 1, 38, 0.5f, 0.0f, true, true, true);
		}

	}
}
