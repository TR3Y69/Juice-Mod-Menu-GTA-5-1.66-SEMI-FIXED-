#include "Juice.h"
#include "Natives.hpp"
#include "Types.hpp"
#include "ScriptCallback.hpp"
#include "Hooking.hpp"
#include <xstring>

using namespace Big;

void Juice::Loop()
{
	Juice::JuMode();
	Juice::Speedometer();
	Juice::nearkill();
	Juice::fixloopin();
	Juice::Neverwandet();
	Juice::brund();
	Juice::glow();
	Juice::NameTagESP();
	Juice::eesp();
	Juice::freecam();
	Juice::RainbowWeapons();
	Juice::MatrixPlate();
	Juice::HasPaintLoop();
	Juice::forcefeldd();
	Juice::Superjump();
	Juice::fireworkk();
	Juice::Aimbot();
	Juice::Sp();
	Juice::mobiletunes();
	Juice::Fast();
	Juice::Hornboostt();
	Juice::watergunn();
	Juice::Ji();
	Juice::JIBBI();
	Juice::pi();
	Juice::Forcefield();
	Juice::deletenearbyvehicles();
	Juice::rainbow();
	Juice::slideRun();
	Juice::ParticlEE1();
	Juice::Extremejump();
	Juice::Superman();
	Juice::firebreath();
	Juice::Sel();
	Juice::deletenearbypeds();
	Juice::AirstrikehowerToggle();
	Juice::PEDS();
	Juice::Fireammos();
	Juice::FuckTheirCam();
	Juice::semigod();
	Juice::Displays();
	Juice::dDisplayss();
	Juice::DelGun();
	Juice::featureDisplayFPS();
	Juice::explodepeds();
	Juice::killpeds();
	Juice::deletenearbyvehicles();
	Juice::Frezztime();
	Juice::P();
	Juice::Sticky();
	Juice::test();
	Juice::DriftMode();
	Juice::pi1();
	Juice::Hornboosttt();
	Juice::enginealwayson();
	Juice::repairnearbyvehicles();
	Juice::loggi();
	Juice::invisibility();
	Juice::trapcagee();
	Juice::zoomCam();
	Juice::ShakeLobby();
	Juice::clearArea();
	Juice::autoclean();
	Juice::RandomOutfit();
	Juice::alarm();
	Juice::FlyingCarLoop();
	Juice::KickFromVehiclee();
	Juice::Gayforce();
	Juice::Freeze();
	Juice::firebreath();
	Juice::FireLoop();
	Juice::WaterLoop();
	Juice::Fre();
	for (int ix = 0; ix < 32; ix++)
	{
		if (SpectateList[ix])
		{
			Spectate(ix);
		}
	}
}
Vector3 add3(Vector3* vectorA, Vector3* vectorB)
{
	Vector3 result;
	result.x = vectorA->x;
	result.y = vectorA->y;
	result.z = vectorA->z;

	result.x += vectorB->x;
	result.y += vectorB->y;
	result.z += vectorB->z;

	return result;
}
Vector3 multiply3(Vector3* vector, float x)
{
	Vector3 result;
	result.x = vector->x;
	result.y = vector->y;
	result.z = vector->z;

	result.x *= x;
	result.y *= x;
	result.z *= x;

	return result;
}
bool penisdunigger = false;
Vector3 rotDirection(Vector3* rot)
{
	float radianz = rot->z * 0.0174532924f;
	float radianx = rot->x * 0.0174532924f;
	float num = std::abs((float)std::cos((double)radianx));

	Vector3 dir;

	dir.x = (float)((double)((float)(-(float)std::sin((double)radianz))) * (double)num);
	dir.y = (float)((double)((float)std::cos((double)radianz)) * (double)num);
	dir.z = (float)std::sin((double)radianx);

	return dir;
}
auto iIsPedShooting(std::int32_t p)
{
	return PED::GET_PED_CONFIG_FLAG(p, 58, TRUE);
}
Vector3 add(Vector3* vectorA, Vector3* vectorB) {
	Vector3 result;
	result.x = vectorA->x;
	result.y = vectorA->y;
	result.z = vectorA->z;
	result.x += vectorB->x;
	result.y += vectorB->y;
	result.z += vectorB->z;
	return result;
}
Vector3 rot_to_direction(Vector3* rot) {
	float radiansZ = rot->z * 0.0174532924f;
	float radiansX = rot->x * 0.0174532924f;
	float num = abs((float)cos((double)radiansX));
	Vector3 dir;
	dir.x = (float)((double)((float)(-(float)sin((double)radiansZ))) * (double)num);
	dir.y = (float)((double)((float)cos((double)radiansZ)) * (double)num);
	dir.z = (float)sin((double)radiansX);
	return dir;
}
float get_distance(Vector3* pointA, Vector3* pointB) {
	float a_x = pointA->x;
	float a_y = pointA->y;
	float a_z = pointA->z;
	float b_x = pointB->x;
	float b_y = pointB->y;
	float b_z = pointB->z;
	double x_ba = ((double)b_x - a_x);
	double y_ba = ((double)b_y - a_y);
	double z_ba = ((double)b_z - a_z);
	double y_2 = y_ba * y_ba;
	double x_2 = x_ba * x_ba;
	double sum_2 = y_2 + x_2;
	return(float)sqrt(sum_2 + z_ba);
}
void RequestControlOfid(Entity netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}
void RequestControlOfEnt(Entity entity)
{
	int tick = 0;
	while (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(entity) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(entity);
		tick++;
	}
	if (NETWORK::NETWORK_IS_SESSION_STARTED())
	{
		int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(entity);
		RequestControlOfid(netID);
		NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
	}
}
void ApplyForceToEntity(Entity e, float x, float y, float z)
{
	if (e != PLAYER::PLAYER_PED_ID() && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(e) == FALSE)
	{
		RequestControlOfEnt(e);
	}

	ENTITY::APPLY_FORCE_TO_ENTITY(e, 1, x, y, z, 0, 0, 0, 0, 1, 1, 1, 0, 1);

}
Hash bagHash = 0x9CA6F755;
//Player
bool Juice::Testboollll = false;
void Juice::Test(){
	if (Testboollll) {

	}
}
bool Juice::Fr = false;
void Juice::Fre() {
	if (Fr) {
		Player player = PLAYER::PLAYER_ID();
		TASK::CLEAR_PED_TASKS_IMMEDIATELY(player);
		TASK::CLEAR_PED_TASKS(player);
		TASK::CLEAR_PED_SECONDARY_TASK(player);
	}
}
bool Juice::Freezee = false;
void Juice::Freeze() {
	if (Freezee) {
		Ped Player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
		TASK::CLEAR_PED_TASKS_IMMEDIATELY(Player);
		TASK::CLEAR_PED_TASKS(Player);
		TASK::CLEAR_PED_SECONDARY_TASK(Player);
	}
}
bool Juice::SpectateList[32];
void Juice::Spectate(int target)
{
	if (Juice::SpectateList[target] == true) {
		Ped SelectedCoords = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
		NativeVector3 SelectCoords = ENTITY::GET_ENTITY_COORDS(SelectedCoords, true);
		GRAPHICS::DRAW_MARKER(3, SelectCoords.x, SelectCoords.y, SelectCoords.z + 1.25, 0, 0, 0, 0, 180, 0, 0.25, 0.25, 0.25, 200, 94, 100, 255, 1, 1, 1, 0, 0, 0, 0);
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(Juice::SpectateList[target], PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target));
	}

	else if (Juice::SpectateList[target] == false) {
		Ped SelectedCoords = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
		NativeVector3 SelectCoords = ENTITY::GET_ENTITY_COORDS(SelectedCoords, true);
		GRAPHICS::DRAW_MARKER(3, SelectCoords.x, SelectCoords.y, SelectCoords.z + 1.25, 0, 0, 0, 0, 180, 0, 0.25, 0.25, 0.25, 200, 94, 100, 255, 1, 1, 1, 0, 0, 0, 0);
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(true, PLAYER::PLAYER_PED_ID());
	}
}
bool Juice::FIREBREATH = false;
void Juice::firebreath() {
	if (FIREBREATH) {
		float XPos = 0.02, YPos = 0.2, ZPos = 0.0, XOff = 90.0, YOff = -100.0, ZOff = 90.0;
		STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
		GRAPHICS::USE_PARTICLE_FX_ASSET("core"); {
			int ptfx = GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("ent_sht_flame", PLAYER::PLAYER_PED_ID(), XPos, YPos, ZPos,
				XOff, YOff, ZOff, 0x796e, 1, 1, 1, 1);	}
		STREAMING::REMOVE_PTFX_ASSET();
	}
}
bool Juice::Fire = false;
void Juice::FireLoop()
{
	if (Fire) {
		Player selectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
		NativeVector3 pos = ENTITY::GET_ENTITY_COORDS(selectedPlayer, true);
		FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 12, 5.f, true, false, 0.f, false);
	}
}
bool Juice::Water = false;
void Juice::WaterLoop()
{
	if (Water) {
		int handel = PLAYER::GET_PLAYER_PED(g_SelectedPlayer);
		NativeVector3 SelectCoords = ENTITY::GET_ENTITY_COORDS(handel, false);
		FIRE::ADD_EXPLOSION(SelectCoords.x, SelectCoords.y, SelectCoords.z, 13, 100000, 1, 0, 1, 0);
	}
}
int m_ForwardBoost;
int m_BackwardBoost;
int Juice::boostlevel = 0;
void Juice::carboost()
{
	int player = PLAYER::PLAYER_PED_ID();

	if (PED::IS_PED_IN_ANY_VEHICLE(player, 0))
	{
		if (IsKeyPressed(m_ForwardBoost))
		{
			Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
			{
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, boostlevel);
			}
		}
		if (IsKeyPressed(m_BackwardBoost))
		{
			Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
			{
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, 0);
			}
		}
	}
}
bool Juice::Gayforcebool = false;
void Juice::Gayforce() {
	if (Gayforcebool) {
		g_Logger->Infos("Juice.Vip");
		g_Logger->notify("Juice.Vip"); 
		g_Logger->Error("Juice.Vip");
		g_Logger->Info("Juice.Vip");
		g_Logger->Hooking("Juice.Vip");
	}
}
void notifyMap(char* fmt, ...)
{
	char buf[2048] = { 0 };
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	char buff2[2048] = { 0 };
	sprintf_s(buff2, "%s", buf);

	HUD::SET_TEXT_OUTLINE();
	HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(buff2);
	HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(FALSE, FALSE);
}	void notifyMap(std::string str) { notifyMap(&str[0]); }
bool Juice::KickFromVehicleebool = false;
void Juice::KickFromVehiclee()
{
	if (KickFromVehicleebool) {
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), FALSE))
		{
			Ped SelectedCoords(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer));
			TASK::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer));
			TASK::CLEAR_PED_TASKS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer));
			TASK::CLEAR_PED_SECONDARY_TASK(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer));
		}
		else
		{  //ok thanks
			NULL;
		}
	}
}
bool Juice::ALARM = false;
void Juice::alarm()
{
	VEHICLE::START_VEHICLE_ALARM;
}
bool Juice::fcbool = false;
void Juice::FlyingCarLoop()
{
	if (fcbool){
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			int Vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			ENTITY::APPLY_FORCE_TO_ENTITY(Vehid, 1, 0, 0, 20, 0, 0, 0, 1, false, true, true, true, true);
			if (PAD::IS_CONTROL_PRESSED(2, 67) == true) //Forward
			{
				float Speed = ENTITY::GET_ENTITY_SPEED(Vehid) + 0.5;
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(Vehid, 25);

			}

			if ((PAD::IS_CONTROL_PRESSED(2, 196) == true) && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Vehid))) //Left
			{
				NativeVector3 Rot = ENTITY::GET_ENTITY_ROTATION(Vehid, 2);
				Rot.z = Rot.z + 1.0;
				ENTITY::SET_ENTITY_ROTATION(Vehid, Rot.x, Rot.y, Rot.z, 2, 1);
			}

			if ((PAD::IS_CONTROL_PRESSED(2, 197) == true) && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Vehid))) //Right
			{
				NativeVector3 Rot = ENTITY::GET_ENTITY_ROTATION(Vehid, 2);
				Rot.z = Rot.z - 1.0;
				ENTITY::SET_ENTITY_ROTATION(Vehid, Rot.x, Rot.y, Rot.z, 2, 1);
			}
		}
	}
}
bool Juice::trapcageeeee1 = false;
void Juice::trapcageeeee()
{
	if (trapcageeeee1) {
		Ped Player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
		TASK::CLEAR_PED_TASKS_IMMEDIATELY(Player);
		TASK::CLEAR_PED_TASKS(Player);
		TASK::CLEAR_PED_SECONDARY_TASK(Player);
	}
}
bool Juice::RandomOutfitt = false;
void Juice::RandomOutfit()
{
	if (RandomOutfitt) {
		PED::SET_PED_RANDOM_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), true);
	}
}
bool Juice::autocleanbool = false;
void Juice::autoclean()
{
	int Ped = PLAYER::PLAYER_PED_ID();
	PED::CLEAR_PED_BLOOD_DAMAGE(Ped);
	PED::RESET_PED_VISIBLE_DAMAGE(Ped);
}
bool is_ped_shooting(Ped ped) {
	NativeVector3 coords = ENTITY::GET_ENTITY_COORDS(ped, 1);
	return PED::IS_PED_SHOOTING_IN_AREA(ped, coords.x, coords.y, coords.z, coords.x, coords.y, coords.z, true, true);
}
bool Juice::invisibilitybool = false;
void Juice::invisibility()
{
	if (!invisibilitybool)
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, 0);
	else
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false, 0);
}
bool Juice::clearareabool = false;
void Juice::clearArea() {
	if (clearareabool)
	{
		NativeVector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		MISC::CLEAR_AREA(Pos.x, Pos.y, Pos.z, 250, true, true, true, true);
		MISC::CLEAR_AREA_OF_COPS(Pos.x, Pos.y, Pos.z, 250, 0);
		MISC::CLEAR_AREA_OF_OBJECTS(Pos.x, Pos.y, Pos.z, 250, 0);
		MISC::CLEAR_AREA_OF_VEHICLES(Pos.x, Pos.y, Pos.z, 250, 1, 1, 0, 0, 1, 1);
		MISC::CLEAR_AREA_OF_PEDS(Pos.x, Pos.y, Pos.z, 250, 0);
		MISC::CLEAR_AREA_OF_PROJECTILES(Pos.x, Pos.y, Pos.z, 250, 0);
	}
}
float gameCamZoomInt = 1.0f;
bool Juice::gameCamZoom = false;
void Juice::zoomCam() {
	if (gameCamZoom) {
		CAM::_ANIMATE_GAMEPLAY_CAM_ZOOM(gameCamZoomInt, gameCamZoomInt);
	}
}
bool Juice::ShakeLobbyy = false;
void Juice::ShakeLobby() {
	if (ShakeLobbyy){
	Ped playerPedID = PLAYER::PLAYER_PED_ID();
	NativeVector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPedID, 0);
	for (int i = 0; i <= 32; i++)
	{
		if (i == g_SelectedPlayer)continue;
		int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		NativeVector3 pos = ENTITY::GET_ENTITY_COORDS(Handle, 1);
		if (!ENTITY::DOES_ENTITY_EXIST(Handle)) continue;
		FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z + 15, 29, 999999.5f,false, false, false, false);
		{
			if (i == 32)

			{
				break;
			}
		}
		}
	}
}
void ForceKick() {
	for (int i = 0; i <= 32; i++)
	{
		int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		const int FRIEND_HANDLE_SIZE = 13;
		int NETWORK_HANDLE[FRIEND_HANDLE_SIZE];
		NETWORK::NETWORK_HANDLE_FROM_PLAYER(i, NETWORK_HANDLE, FRIEND_HANDLE_SIZE);
		if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) != PLAYER::PLAYER_PED_ID() && !NETWORK::NETWORK_IS_FRIEND(NETWORK_HANDLE))
		{
		}
	}
}
int ficksize = 10;
int Explosionfick = 38;
bool Juice::trapcageeb = false;
void Juice::trapcagee(){
	if (trapcageeb) {
		NativeVector3 remotePos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), 0);
		Object obj = OBJECT::CREATE_OBJECT(MISC::GET_HASH_KEY("prop_gold_cont_01"), remotePos.x, remotePos.y, remotePos.z - 1.f, true, false, false);
	}
}
bool RequestNetworkControl(int vehID)
{
	int Tries = 0;
	bool
		hasControl = false,
		giveUp = false;
	do
	{
		hasControl = NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(vehID);
		Tries++;
		if (Tries > 300)
			giveUp = true;
	} while (!hasControl && !giveUp);

	if (giveUp)
		return false;
	else return true;
}
void Juice::doAnimation(char* anim, char* animid)
{
	int pPlayer = PLAYER::PLAYER_PED_ID();
	RequestNetworkControl(pPlayer);
	STREAMING::REQUEST_ANIM_DICT(anim);
	if (STREAMING::HAS_ANIM_DICT_LOADED((anim)))
	{
		TASK::TASK_PLAY_ANIM(pPlayer, anim, animid, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
	}
}
bool Juice::Gravity = false;
void Juice::GravityGun()
{
	if (Gravity) {
		Entity del_entity;
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &del_entity))

			if (ENTITY::DOES_ENTITY_EXIST(del_entity) && NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(del_entity))
			{
				NativeVector3 tmp = ENTITY::GET_ENTITY_COORDS(del_entity, 1);
				ENTITY::DETACH_ENTITY(del_entity, 1, 1);
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(del_entity, 0, 0, 0, 0, 0, 0);
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(del_entity, 0, 1);
				ENTITY::DELETE_ENTITY(&del_entity);
			}
	}
}
void Juice::animation(char* anim, char* dict)
{
	Ped targ_ped = PLAYER::PLAYER_PED_ID();//seleted player
	STREAMING::REQUEST_ANIM_DICT(dict);
	if (STREAMING::HAS_ANIM_DICT_LOADED(dict))
	{
		NativeVector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(targ_ped, 0.0, 0.0, 0.0);//since get_coord is patched i found this native
		int sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(coords.x, coords.y, coords.z, 0, 0, 0, 2, 0, 1, 1.0f , false, false);
		NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(targ_ped, sceneID, dict, anim, 8.0f, -8.0f, 120, 0, 100, 0);/*i changed any to char* i provide the native below(modificated)*/
		NETWORK::NETWORK_START_SYNCHRONISED_SCENE(sceneID);

	}
}
bool Juice::hornnearbyvehiclesbool = false;
void Juice::hornnearbyvehicles()
{
	if (hornnearbyvehiclesbool) {
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Vehicle* vehs = new Vehicle[ArrSize];
		vehs[0] = ElementAmount;
		int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

		for (int i = 0; i < VehFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
			{
				RequestControlOfEnt(vehs[OffsetID]);
				VEHICLE::START_VEHICLE_HORN(vehs[OffsetID], 5000, AUDIO::GET_VEHICLE_DEFAULT_HORN_IGNORE_MODS(vehs[OffsetID]), true);
			}
		}
	}
}
bool Juice::repairnearbyvehicless = false;
void Juice::repairnearbyvehicles()
{
	if (repairnearbyvehicless) {
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Vehicle* vehs = new Vehicle[ArrSize];
		vehs[0] = ElementAmount;
		int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

		for (int i = 0; i < VehFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
			{
				RequestControlOfEnt(vehs[OffsetID]);
				for (int i = 0; i < 50; i++)
				{
					VEHICLE::SET_VEHICLE_FIXED(vehs[OffsetID]);
					VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehs[OffsetID]);
					VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehs[OffsetID], 0);
				}
			}
		}
	}
}
bool Juice::enginealwaysonbool = false;
void Juice::enginealwayson() {
	if (enginealwaysonbool) {
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, Juice::enginealwaysonbool, Juice::enginealwaysonbool, Juice::enginealwaysonbool);
		VEHICLE::SET_VEHICLE_LIGHTS(veh, 0);
		VEHICLE::_SET_VEHICLE_LIGHTS_MODE(veh, 2);
	}
}
bool Juice::hornboosttt = false;
void Juice::Hornboosttt()
{
	if (hornboostt)
	{
		if (PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::PLAYER_ID()))
		{
			Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
			{
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, 90);
			}
		}
	}
}
bool Juice::Drift = false;
void Juice::DriftMode() {
	if (Drift) {
			VEHICLE::SET_VEHICLE_REDUCE_GRIP(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 1); }
	else { VEHICLE::SET_VEHICLE_REDUCE_GRIP(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 0); }
}
bool Juice::testbool = true;
void Juice::test()
{
	if (Juice::testbool) {
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, false);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, (char*)"Juice");
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(vehicle, 5);
	}
}
bool Juice::StickyBool = false;
void Juice::Sticky(){
	if (StickyBool) {
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))	{
			int myJuice = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(myJuice, true);
		}
	}
}
void Juice::KickPlayer()
{
}


bool Juice::delgun = false;
void Juice::DelGun() {
	if (delgun) {
		Entity del_entity;
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &del_entity))

			if (ENTITY::DOES_ENTITY_EXIST(del_entity) && NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(del_entity))
			{
				NativeVector3 tmp = ENTITY::GET_ENTITY_COORDS(del_entity, 1);
				ENTITY::DETACH_ENTITY(del_entity, 1, 1);
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(del_entity, 0, 0, 0, 0, 0, 0);
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(del_entity, 0, 1);
				ENTITY::DELETE_ENTITY(&del_entity);
			}
	}
}

void Juice::PES() {
	if (PES) {
		int pedclone = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
		PED::CLONE_PED(pedclone, 1, 1, 1);
	}
}
void Juice::DeleteCar()
{
	Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
	if (PED::IS_PED_IN_ANY_VEHICLE(selectedplayer, false))
	{
		int Vehicle = PED::GET_VEHICLE_PED_IS_USING(selectedplayer);
		if (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Vehicle))
			while (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Vehicle));

		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(Vehicle, 1, 1);
		VEHICLE::DELETE_VEHICLE(&Vehicle);
	}
}

bool Juice::fireammo = false;
void Juice::Fireammos() {
	if (fireammo) {
		{
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), 0)) {
				{
					float xD[6];
					WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, (NativeVector3*)xD);
					if (xD[0] != 0 || xD[2] != 0 || xD[4] != 0)
					{
						ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, xD[0], xD[2], xD[4], 0, true, false);
					}
				}
			}
		}
	}
}
bool Juice::PEDSs = false;
void Juice::PEDS() {
	if (PEDSs) {
		int pedclone = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 2);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 2, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		
	}
}
bool Juice::PE = false;
void Juice::P() {
	if (PE) {
		int pedclone = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 2);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
		PED::CLONE_PED(pedclone, 1, 1, 1);
	}
}


bool Juice::Sell = false;
void Juice::Sel()
{
	if (Sell)
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_VEHICLE_SELL_TIME"), 0, 1);
	}
}
bool Juice::superman = false;
void Juice::Superman()
{
	if (superman) {
		if (GetAsyncKeyState(VK_SPACE))
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), 1, 0, 0, 10, 0, 0, 0, 1, true, true, true, true, true);
		}
		Hash hash = MISC::GET_HASH_KEY("GADGET_PARACHUTE");
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), hash, 1, 1);
		if (ENTITY::IS_ENTITY_IN_AIR(PLAYER::PLAYER_PED_ID()) && !PED::IS_PED_RAGDOLL(PLAYER::PLAYER_PED_ID()))
		{
			if (GetAsyncKeyState(0x57)) // W
			{
				ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 3, 0, 0);
			}

			if (GetAsyncKeyState(0x53)) // S
			{
				ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 3, 6, 0);
			}
			if (GetAsyncKeyState(VK_SHIFT))
			{
				ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 6, 0, 0);
			}
		}
	}
}
void Juice::SpawnVehicle(std::string hash) {
	STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
	GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
	GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.6, false, false, false);
	Hash vehiclehash = MISC::GET_HASH_KEY(hash.c_str());
	if (STREAMING::IS_MODEL_IN_CDIMAGE(vehiclehash) && STREAMING::IS_MODEL_A_VEHICLE(vehiclehash)) {
		g_CallbackScript->AddCallback<ModelCallback>(vehiclehash, [=] {
			NativeVector3 Coordinates = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
			Ped PedDirection = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
			*(unsigned short*)g_GameVariables->ModelBypass = 0x9090; //Just dont touch these :3
			Vehicle lastVehicle = VEHICLE::CREATE_VEHICLE(vehiclehash, Coordinates.x + 5.500, Coordinates.y, Coordinates.z, PedDirection, 1, 1, 0); //Thats just for calling the Vehicle.
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(lastVehicle, 1);
			*(unsigned short*)g_GameVariables->ModelBypass = 0x0574;
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), lastVehicle, -1);
			ENTITY::SET_ENTITY_HEADING(lastVehicle, PedDirection);
			*ScriptGlobal(4269479).As<int*>() = 1;  //I will give you the Singleplayer Bypass as a gift because iam sure you will often need bigger help. WTF why is this native not working for you idk 
 	});
	}
}
void Juice::playerspawnplayercar(std::string hash){
	NativeVector3 Coordinates = ENTITY::GET_ENTITY_COORDS(g_SelectedPlayer, true);
	Hash vehiclehash = MISC::GET_HASH_KEY(hash.c_str());
	if (STREAMING::IS_MODEL_IN_CDIMAGE(vehiclehash) && STREAMING::IS_MODEL_A_VEHICLE(vehiclehash)) {
		g_CallbackScript->AddCallback<ModelCallback>(vehiclehash, [=] {
			Ped PedDirection = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
			*(unsigned short*)g_GameVariables->ModelBypass = 0x9090; 
			Vehicle lastVehicle = VEHICLE::CREATE_VEHICLE(vehiclehash, Coordinates.x + 5.500, Coordinates.y, Coordinates.z, PedDirection, 1, 1, 0); //Thats just for calling the Vehicle.
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(lastVehicle, 1);
			*(unsigned short*)g_GameVariables->ModelBypass = 0x0574;
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), lastVehicle, -1);
			ENTITY::SET_ENTITY_HEADING(lastVehicle, PedDirection);
			*ScriptGlobal(4269479).As<int*>() = 1;  
			});
	}
}
int ped;
bool Juice::FuckCamBool = false;
void Juice::FuckTheirCam(){
	if (FuckCamBool) {
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), false);
		RequestControlOfEnt(veh);
		VEHICLE::SET_VEHICLE_STEER_BIAS(veh, 1.0f);
	}
}
bool Juice::Forcefieldd;
void Juice::Forcefield()
{
	if (Forcefieldd)
	{
		Player playerPed = PLAYER::PLAYER_PED_ID();
		NativeVector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
		FIRE::ADD_EXPLOSION(pCoords.x + 2, pCoords.y + 2, pCoords.z, 7, 9.0f, false, true, 0.0f, 1);
		FIRE::ADD_EXPLOSION(pCoords.x + 3, pCoords.y + 3, pCoords.z, 7, 9.0f, false, true, 0.0f, 1);
		FIRE::ADD_EXPLOSION(pCoords.x + 4, pCoords.y + 4, pCoords.z, 7, 9.0f, false, true, 0.0f, 1);
		FIRE::ADD_EXPLOSION(pCoords.x + 5, pCoords.y + 5, pCoords.z, 7, 9.0f, false, true, 0.0f, 1);
		FIRE::ADD_EXPLOSION(pCoords.x + 6, pCoords.y + 6, pCoords.z, 7, 9.0f, false, true, 0.0f, 1);
		FIRE::ADD_EXPLOSION(pCoords.x + 7, pCoords.y + 7, pCoords.z, 7, 9.0f, false, true, 0.0f, 1);

	}
}
bool Juice::AirstrikeShower = false;
void Juice::AirstrikehowerToggle() {
	NativeVector3 kek = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true); {
		if (AirstrikeShower)

		{
			float ang = MISC::GET_RANDOM_FLOAT_IN_RANGE(0.0f, 10.0f) * 3.14159265359f;
			float rad = MISC::GET_RANDOM_FLOAT_IN_RANGE(0.0f, 10.0f) * 15.0f;
			float x = kek.x + rad * cos(ang);
			float y = kek.y + rad * sin(ang);
			Hash airStrike = MISC::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET");
			WEAPON::REQUEST_WEAPON_ASSET(airStrike, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(airStrike))

				MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(x, y, 200.0f, x, y, 0, 250, 1, airStrike, PLAYER::PLAYER_PED_ID(), 1, 0, -1.0);
		}
	}
}
bool Juice::particlee1 = false;
void Juice::ParticlEE1()
{
	if (particlee1)
	{
		Vector3 coords;
		Entity e = PLAYER::PLAYER_PED_ID();
		if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
			e = PED::GET_VEHICLE_PED_IS_USING(e);

		int WaypointHandle = HUD::GET_FIRST_BLIP_INFO_ID(8);
		if (HUD::DOES_BLIP_EXIST(WaypointHandle))
		{
			NativeVector3 WaypointPos = HUD::GET_BLIP_COORDS(WaypointHandle);
			WaypointPos.z += 25.0f;
			int Handle = PLAYER::PLAYER_PED_ID();
			if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
				Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			ENTITY::SET_ENTITY_COORDS(Handle, WaypointPos.x, WaypointPos.y, WaypointPos.z, 0, 0, 0, 1);

		}
	}
}
bool Juice::extremejump = false;
void Juice::Extremejump() {
	if (extremejump)
	{
		int Me = PLAYER::PLAYER_PED_ID();
		if (GetAsyncKeyState(VK_SPACE))
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(Me, 1, 0, 0, +3, 0, 0, 0, 1, 1, 1, 1, 0, 1);
		}
	}
}
bool Juice::isSlideRun = false;
void Juice::slideRun()
{
	if (isSlideRun) {
		Ped ped = PLAYER::PLAYER_PED_ID();

		if (TASK::IS_PED_RUNNING(ped) || TASK::IS_PED_SPRINTING(ped))
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(ped, 1, 0.f, 1.5f, 0.f, 0.f, 0.f, 0.f, 1, true, true, true, false, true);
		}
	}
}
typedef struct { int R, G, B, A; } RGBA;
RGBA aprimary{ 255, 0, 0 };
RGBA asecondary{ 255, 0, 0 };
bool Juice::semigodbool = false;
void Juice::semigod()
{
	if (semigodbool) {
		Hash oball = MISC::GET_HASH_KEY("prop_juicestand");
		STREAMING::REQUEST_MODEL(oball);
		while (!STREAMING::HAS_MODEL_LOADED(oball))
			SYSTEM::WAIT(0);
		int orangeball = OBJECT::CREATE_OBJECT(oball, 0, 0, 0, true, 1, 0);
		RequestControlOfEnt(orangeball);
		ENTITY::SET_ENTITY_VISIBLE(orangeball, 0, true);
		ENTITY::ATTACH_ENTITY_TO_ENTITY(orangeball, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
	}
}
bool Juice::rainbowbool = false;
void Juice::rainbow()
{
	if (rainbowbool) {
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
		{
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			if (aprimary.R > 0 && aprimary.B == 0)
			{
				aprimary.R--;
				aprimary.G++;
			}
			if (aprimary.G > 0 && aprimary.R == 0)
			{
				aprimary.G--;
				aprimary.B++;
			}
			if (aprimary.B > 0 && aprimary.G == 0)
			{
				aprimary.R++;
				aprimary.B--;
			}

			if (asecondary.R > 0 && asecondary.B == 0)
			{
				asecondary.R--;
				asecondary.G++;
			}
			if (asecondary.G > 0 && asecondary.R == 0)
			{
				asecondary.G--;
				asecondary.B++;
			}
			if (asecondary.B > 0 && asecondary.G == 0)
			{
				asecondary.R++;
				asecondary.B--;
			}
			VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(vehicle, aprimary.R, aprimary.G, aprimary.B);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, aprimary.R, aprimary.G, aprimary.B);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, asecondary.R, asecondary.G, asecondary.B);
			VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 0, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 1, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 2, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 3, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 4, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 5, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 6, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 7, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(vehicle, aprimary.R, aprimary.G, aprimary.B);

		}
	}
}
bool Juice::WaterGunn = false;
void Juice::watergunn()
{
	if (WaterGunn) {
		for (int i = 0; i < 32; i++)
		{
			int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
			{
				if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID()) continue;
				{
					NativeVector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
					FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 1000.f, true, false, 100.f, false); //patched
				}
			}
		}
	}
}
bool Juice::hornboostt = false;
void Juice::Hornboostt()
{
	if (hornboostt)
	{
		if (PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::PLAYER_ID()))
		{
			Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
			{
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, 90);
			}
		}
	}
}
bool Juice::AimbotBool = false;
void Juice::Aimbot()
{
	if (AimbotBool)
	{
		int player = PLAYER::PLAYER_ID();
		int playerPed = PLAYER::PLAYER_PED_ID();

		for (int i = 0; i < 32; i++)
		{
			if (i != player)
			{
				if (GetAsyncKeyState(VK_RBUTTON))
				{
					Ped targetPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
					NativeVector3 targetPos = ENTITY::GET_ENTITY_COORDS(targetPed, 1);
					BOOL exists = ENTITY::DOES_ENTITY_EXIST(targetPed);
					BOOL dead = PLAYER::IS_PLAYER_DEAD(targetPed);

					if (exists && !dead)
					{
						float screenX, screenY;
						BOOL onScreen = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(targetPos.x, targetPos.y, targetPos.z, &screenX, &screenY);
						if (ENTITY::IS_ENTITY_VISIBLE(targetPed) && onScreen)
						{
							if (ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(playerPed, targetPed, 17))
							{
								NativeVector3 targetCoords = PED::GET_PED_BONE_COORDS(targetPed, 31086, 0, 0, 0);
								PED::SET_PED_SHOOTS_AT_COORD(playerPed, targetCoords.x, targetCoords.y, targetCoords.z, 1);

							}
						}
					}
				}
			}
		}
	}
}
bool Juice::Superrun = false;
void Juice::Sp()
{
	if (Superrun)
	{
		PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(PLAYER::PLAYER_ID(), 1.40);
	}
	else if (!Superrun)
	{
		PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(PLAYER::PLAYER_ID(), 1.0);
	}
}
bool Juice::Fastrrun = false;
void Juice::Fast()
{
	if (Fastrrun)
	{
		PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(PLAYER::PLAYER_ID(), 1.70);
	}
	else if (!Fast)
	{
		PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(PLAYER::PLAYER_ID(), 1.0);
	}
}
class WeaponModelCallback;
bool Juice::nearbykill;
void Juice::nearkill()
{
	if (nearbykill)
	{
		const int numElements1 = 10;
		const int arrSize = numElements1 * 2 + 2;
		Ped ped[arrSize];
		ped[0] = numElements1;
		int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
		if (ped != NULL)
		{
			for (int i = 1; i <= count; i++)
			{
				int offsettedID = i;
				NativeVector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
				NativeVector3 Pos2 = ENTITY::GET_ENTITY_COORDS(ped[offsettedID], true);
				GRAPHICS::DRAW_LINE(Pos.x, Pos.y, Pos.z, Pos2.x, Pos2.y, Pos2.z, 133, 8, 255, 255);
				FIRE::ADD_EXPLOSION(Pos2.x, Pos2.y, Pos2.z, 2, 5, 1, 0, 0, 0);
			}
		}
	}
}
bool Juice::RainbowPaintLoop = false;
void Juice::HasPaintLoop()
{
	if (RainbowPaintLoop) {
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(VehID, MISC::GET_RANDOM_INT_IN_RANGE(0, 255), MISC::GET_RANDOM_INT_IN_RANGE(0, 255), MISC::GET_RANDOM_INT_IN_RANGE(0, 255));
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(VehID, MISC::GET_RANDOM_INT_IN_RANGE(0, 255), MISC::GET_RANDOM_INT_IN_RANGE(0, 255), MISC::GET_RANDOM_INT_IN_RANGE(0, 255));
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, MISC::GET_RANDOM_INT_IN_RANGE(0, 255), MISC::GET_RANDOM_INT_IN_RANGE(0, 255), MISC::GET_RANDOM_INT_IN_RANGE(0, 255));
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 0, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 1, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 2, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 3, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 4, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 5, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 6, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 7, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, MISC::GET_RANDOM_INT_IN_RANGE(0, 255), MISC::GET_RANDOM_INT_IN_RANGE(0, 255), MISC::GET_RANDOM_INT_IN_RANGE(0, 255));
	}
}
bool Juice::SelfGodmode = false;
void Juice::JuMode()
{
	static int armour_player = 0;
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (armour_player == 0)
	{
		armour_player = PED::GET_PED_ARMOUR(playerPed);
	}

	if (SelfGodmode)
	{
		PLAYER::SET_PLAYER_INVINCIBLE(player, true);
		ENTITY::SET_ENTITY_PROOFS(playerPed, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE);
		PED::ADD_ARMOUR_TO_PED(playerPed, PLAYER::GET_PLAYER_MAX_ARMOUR(player) - PED::GET_PED_ARMOUR(playerPed));
	}
	else
	{
		PLAYER::SET_PLAYER_INVINCIBLE(player, false);
		ENTITY::SET_ENTITY_PROOFS(playerPed, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE);
		if (armour_player != 0)
		{
			PED::SET_PED_ARMOUR(playerPed, armour_player);
			armour_player = 0;
		}
	}
}
bool Juice::fixlooping = false;
void Juice::fixloopin() {
	if (Juice::fixlooping) {
		int Vehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
		VEHICLE::SET_VEHICLE_FIXED(Vehicle);
		VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(Vehicle);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(Vehicle, 0);
	}
}
bool Juice::neverwandet = false;
void Juice::Neverwandet()
{
	if (neverwandet) {
		Entity player = PLAYER::PLAYER_PED_ID();
		if (Juice::neverwandet) {
			PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
			PLAYER::SET_MAX_WANTED_LEVEL(0);
			PLAYER::SET_POLICE_IGNORE_PLAYER(player, true);
			PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(player, false);
			PLAYER::SET_EVERYONE_IGNORE_PLAYER(player, true);
			PLAYER::SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(player, true);}
		else {
			PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
			PLAYER::SET_MAX_WANTED_LEVEL(5);
			PLAYER::SET_POLICE_IGNORE_PLAYER(player, false);
			PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(player, false);
			PLAYER::SET_EVERYONE_IGNORE_PLAYER(player, false);
			PLAYER::SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(player, false);
		}
	}
}
bool Juice::Forcefeldd = false;
void Juice::forcefeldd()
{
	if (Juice::Forcefeldd)
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 0.5, false, false, false);
		const int numElements = 10;
		const int arrSize = numElements * 2 + 2;
		Vehicle veh[arrSize];
		veh[0] = numElements;

		int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
		if (veh != NULL)
		{
			for (int i = 1; i <= count; i++)
			{
				int offsettedID = i;
				if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, 5, 0, 0, 0, 1, false, true, true, true, true);

				}
			}
		}
	}
}
bool Juice::superjump = false;
void Juice::Superjump()
{
	if (superjump)
	{
		MISC::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_PED_ID());
		MISC::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
	}
	else
	{
		NULL;
	}



}
bool Juice::brundd;
void Juice::brund()
{
	if (brundd)
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_agencyheist");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_agencyheist");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_fbi_dd_breach_smoke", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 0, 0.5f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_agencyheist");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_agencyheist");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_fbi_dd_breach_smoke", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 28422, 0.1f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_agencyheist");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_agencyheist");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_fbi_dd_breach_smoke", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 60309, 0.1f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_agencyheist");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_agencyheist");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_fbi_dd_breach_smoke", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 31086, 0.2f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_agencyheist");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_agencyheist");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_fbi_dd_breach_smoke", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 52301, 0.1f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_agencyheist");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_agencyheist");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_fbi_dd_breach_smoke", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 14201, 0.1f, 0, 0, 0);
	}
}
bool Juice::firework;
void Juice::fireworkk()
{
	if (Juice::firework)
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET("proj_xmas_firework");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("proj_xmas_firework");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("proj_xmas_firework", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 0, 0.5f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("proj_xmas_firework");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("proj_xmas_firework");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("proj_xmas_firework", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 28422, 0.5f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("proj_xmas_firework");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("proj_xmas_firework");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("proj_xmas_firework", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 60309, 0.5f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("proj_xmas_firework");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("proj_xmas_firework");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("proj_xmas_firework", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 31086, 0.6f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("proj_xmas_firework");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("proj_xmas_firework");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("proj_xmas_firework", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 52301, 0.5f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("proj_xmas_firework");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("proj_xmas_firework");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("proj_xmas_firework", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 14201, 0.6f, 0, 0, 0);
	}
}
bool Juice::gglow = false;
void Juice::glow()
	{
		if (gglow)
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry1");// FX Attachment
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry1");
			GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_alien_teleport", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 28422, 0.1f, 0, 0, 0);
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry1");// FX Attachment
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry1");
			GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_alien_teleport", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 60309, 0.1f, 0, 0, 0);
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry1");// FX Attachment
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry1");
			GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_alien_teleport", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 31086, 0.2f, 0, 0, 0);
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry1");// FX Attachment
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry1");
			GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_alien_teleport", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 52301, 0.1f, 0, 0, 0);
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry1");// FX Attachment
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry1");
		}
	}
bool Juice::JibBool = false;
void Juice::JIBBI()
{
	if (JibBool)
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 28422, 0.2f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 60309, 0.2f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 31086, 0.3f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 52301, 0.2f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
	}
}
bool Juice::JiBool = false;
void Juice::Ji()
{
	if (JiBool)
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("muz_clown", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 28422, 0.3f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("muz_clown", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 60309, 0.3f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("muz_clown", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 31086, 0.4f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("muz_clown", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 52301, 0.3f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("muz_clown");
	}
}
bool Juice::pip = false;
void Juice::pi()
{
	if (pip)
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 28422, 99.1f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 60309, 99.1f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 31086, 100.2f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 52301, 99.1f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
	}
}
bool Juice::pip1 = false;
void Juice::pi1()
{
	if (pip)
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET("proj_xmas_firework");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_firework_xmas_burst_rgw");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_firework_xmas_burst_rgw", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 28422, 99.1f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("proj_xmas_firework");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_firework_xmas_burst_rgw");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_firework_xmas_burst_rgw", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 60309, 99.1f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("proj_xmas_firework");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_firework_xmas_burst_rgw");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 31086, 100.2f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("proj_xmas_firework");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_firework_xmas_burst_rgw");
		GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 52301, 99.1f, 0, 0, 0);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("proj_xmas_firework");// FX Attachment
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_firework_xmas_burst_rgw");
	}
}
char* model;
int clone[1000];
int gcount = 1;
bool Juice::RainbowWeaponsBool = false;
void Juice::RainbowWeapons() {
		if (Juice::RainbowWeaponsBool) {
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			static LPCSTR weaponNames[] = {
				"WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT", "WEAPON_GOLFCLUB", "WEAPON_CROWBAR",
				"WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_MICROSMG", "WEAPON_SMG",
				"WEAPON_ASSAULTSMG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_MG",
				"WEAPON_COMBATMG", "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN",
				"WEAPON_STUNGUN", "WEAPON_SNIPERRIFLE", "WEAPON_HEAVYSNIPER", "WEAPON_GRENADELAUNCHER", "WEAPON_GRENADELAUNCHER_SMOKE",
				"WEAPON_RPG", "WEAPON_MINIGUN", "WEAPON_GRENADE", "WEAPON_STICKYBOMB", "WEAPON_SMOKEGRENADE", "WEAPON_BZGAS",
				"WEAPON_MOLOTOV", "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN",
				"WEAPON_SNSPISTOL", "WEAPON_SPECIALCARBINE", "WEAPON_HEAVYPISTOL", "WEAPON_BULLPUPRIFLE", "WEAPON_HOMINGLAUNCHER",
				"WEAPON_PROXMINE", "WEAPON_SNOWBALL", "WEAPON_VINTAGEPISTOL", "WEAPON_DAGGER", "WEAPON_FIREWORK", "WEAPON_MUSKET",
				"WEAPON_MARKSMANRIFLE", "WEAPON_HEAVYSHOTGUN", "WEAPON_GUSENBERG", "WEAPON_HATCHET", "WEAPON_RAILGUN", "WEAPON_FLAREGUN",
				"WEAPON_KNUCKLE", "GADGET_NIGHTVISION", "GADGET_PARACHUTE", "WEAPON_MARKSMANPISTOL", "", ""
			};
			for (int i = 0; i < sizeof(weaponNames) / sizeof(weaponNames[0]); i++)
			{
				if (WEAPON::HAS_PED_GOT_WEAPON(playerPed, MISC::GET_HASH_KEY((char*)weaponNames[i]), 0))
				{
					WEAPON::SET_PED_WEAPON_TINT_INDEX(playerPed, MISC::GET_HASH_KEY((char*)weaponNames[i]), rand() % 8);
				}
			}
		}
	}
std::string plateSymbols[35] = {
	"a", "b", "c", "d", "e", "f",
	"g", "h", "i", "j", "k", "l",
	"m", "n", "o", "p", "q",
	"r", "s", "t", "u", "v",
	"w", "x", "y", "z", "1",
	"2", "3", "4", "5", "6", "7",
	"8", "9",
	};
bool Juice::MatrixPlates = false;	
void Juice::MatrixPlate()
	{
		if (Juice::MatrixPlates)
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			std::string textInput = plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35];
			char* plateText = (strcpy((char*)malloc(textInput.length() + 1), textInput.c_str()));
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), plateText);
		}
	}
bool Juice::eespbool = false;
void Juice::eesp()
	{
		if (Juice::eespbool) 
			{
				Player playerPed = PLAYER::PLAYER_PED_ID();
				for (int i = 0; i < 32; i++)
				{
					Player playerHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
					NativeVector3 handleCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerHandle, 0, 0, 0);

					if (ENTITY::DOES_ENTITY_EXIST(playerHandle))
					{
						GRAPHICS::DRAW_LINE(handleCoords.x + 0.5, handleCoords.y + 0.5, handleCoords.z + 0.75, handleCoords.x + 0.5, handleCoords.y - 0.5, handleCoords.z + 0.75, 200, 94, 100, 255); // top Box
						GRAPHICS::DRAW_LINE(handleCoords.x + 0.5, handleCoords.y - 0.5, handleCoords.z + 0.75, handleCoords.x - 0.5, handleCoords.y - 0.5, handleCoords.z + 0.75, 200, 94, 100, 255);
						GRAPHICS::DRAW_LINE(handleCoords.x - 0.5, handleCoords.y - 0.5, handleCoords.z + 0.75, handleCoords.x - 0.5, handleCoords.y + 0.5, handleCoords.z + 0.75, 200, 94, 100, 255);
						GRAPHICS::DRAW_LINE(handleCoords.x - 0.5, handleCoords.y + 0.5, handleCoords.z + 0.75, handleCoords.x + 0.5, handleCoords.y + 0.5, handleCoords.z + 0.75, 200, 94, 100, 255);

						GRAPHICS::DRAW_LINE(handleCoords.x + 0.5, handleCoords.y + 0.5, handleCoords.z - 0.75, handleCoords.x + 0.5, handleCoords.y - 0.5, handleCoords.z - 0.75, 200, 94, 100, 255); // bottom Box
						GRAPHICS::DRAW_LINE(handleCoords.x + 0.5, handleCoords.y - 0.5, handleCoords.z - 0.75, handleCoords.x - 0.5, handleCoords.y - 0.5, handleCoords.z - 0.75, 200, 94, 100, 255);
						GRAPHICS::DRAW_LINE(handleCoords.x - 0.5, handleCoords.y - 0.5, handleCoords.z - 0.75, handleCoords.x - 0.5, handleCoords.y + 0.5, handleCoords.z - 0.75, 200, 94, 100, 255);
						GRAPHICS::DRAW_LINE(handleCoords.x - 0.5, handleCoords.y + 0.5, handleCoords.z - 0.75, handleCoords.x + 0.5, handleCoords.y + 0.5, handleCoords.z - 0.75, 200, 94, 100, 255);

						GRAPHICS::DRAW_LINE(handleCoords.x + 0.5, handleCoords.y + 0.5, handleCoords.z - 0.75, handleCoords.x + 0.5, handleCoords.y + 0.5, handleCoords.z + 0.75, 200, 94, 100, 255); // bottom Box
						GRAPHICS::DRAW_LINE(handleCoords.x + 0.5, handleCoords.y - 0.5, handleCoords.z - 0.75, handleCoords.x + 0.5, handleCoords.y - 0.5, handleCoords.z + 0.75, 200, 94, 100, 255);
						GRAPHICS::DRAW_LINE(handleCoords.x - 0.5, handleCoords.y - 0.5, handleCoords.z - 0.75, handleCoords.x - 0.5, handleCoords.y - 0.5, handleCoords.z + 0.75, 200, 94, 100, 255);
						GRAPHICS::DRAW_LINE(handleCoords.x - 0.5, handleCoords.y + 0.5, handleCoords.z - 0.75, handleCoords.x - 0.5, handleCoords.y + 0.5, handleCoords.z + 0.75, 200, 94, 100, 255);
						NativeVector3 locationOne = ENTITY::GET_ENTITY_COORDS(playerHandle, false);
						NativeVector3 locationTwo = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
						GRAPHICS::DRAW_LINE(locationOne.x, locationOne.y, locationOne.z, locationTwo.x, locationTwo.y, locationTwo.z, 255, 0, 0, 255);

					}
				}
			}
		}
bool Juice::Nametag = false;
void Juice::NameTagESP()
	{
		if (Juice::Nametag) {
			Player playerPed = PLAYER::PLAYER_PED_ID();
			for (int i = 0; i < 32; i++)
			{
				Player playerHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
				NativeVector3 handleCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerHandle, 0, 0, 0);
				NativeVector3 playerCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);

				if (ENTITY::DOES_ENTITY_EXIST(playerHandle))
				{
					float x1;
					float y1;

					BOOL screenCoords = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(handleCoords.x, handleCoords.y, handleCoords.z, &x1, &y1);

					std::string playerName = PLAYER::GET_PLAYER_NAME(PLAYER::INT_TO_PLAYERINDEX(i));

					std::string nameSetupPurple = "~HUD_COLOUR_PURPLE~" + playerName;
					std::string nameSetupGreen = "~HUD_COLOUR_BLUE~" + playerName;

					char* playerInfoRed = new char[nameSetupPurple.length() + 1];
					char* playerInfoGreen = new char[nameSetupGreen.length() + 1];

					std::strcpy(playerInfoRed, nameSetupPurple.c_str());
					std::strcpy(playerInfoGreen, nameSetupGreen.c_str());

					HUD::SET_TEXT_FONT(7);
					HUD::SET_TEXT_SCALE(0.0, 0.40);
					HUD::SET_TEXT_COLOUR(0, 255, 0, 255);
					HUD::SET_TEXT_CENTRE(0);
					HUD::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
					HUD::SET_TEXT_EDGE(0, 0, 0, 0, 0);
					HUD::BEGIN_TEXT_COMMAND_DISPLAY_TEXT((char*)"STRING");
					if (ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(playerPed, playerHandle, 17))
					{
						HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(playerInfoGreen);
					}
					else
					{
						HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(playerInfoRed);
					}
					HUD::END_TEXT_COMMAND_DISPLAY_TEXT(x1, y1, 0);
					HUD::SET_TEXT_OUTLINE();
					HUD::SET_TEXT_DROPSHADOW(5, 0, 78, 255, 255);
				}
			}
		}
	}
bool Juice::freecambool;
void Juice::freecam() {
	{
		{
			if (freecambool)
			{
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				NativeVector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, false);
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
				if (GetAsyncKeyState(0x53) || PAD::IS_DISABLED_CONTROL_JUST_PRESSED(2, 268)) {
					float fivef = .5f;
					float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
					float xVec = fivef * sin((heading)) * -1.0f;
					float yVec = fivef * cos((heading));
					ENTITY::SET_ENTITY_HEADING(playerPed, heading);

					pos.x -= xVec, pos.y -= yVec;
					ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
				}
				if (GetAsyncKeyState(0x57) || PAD::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269)) {
					float fivef = .5f;
					float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
					float xVec = fivef * sin((heading)) * -1.0f;
					float yVec = fivef * cos((heading));
					ENTITY::SET_ENTITY_HEADING(playerPed, heading);

					pos.x += xVec, pos.y += yVec;
					ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
				}
				if (GetAsyncKeyState(0x41) || PAD::IS_DISABLED_CONTROL_JUST_PRESSED(2, 266)) {
					float fivef = .5f;
					float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
					ENTITY::SET_ENTITY_HEADING(playerPed, heading + 0.5f);
				}
				if (GetAsyncKeyState(0x44) || PAD::IS_DISABLED_CONTROL_JUST_PRESSED(2, 271)) {
					float fivef = .5f;
					float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
					ENTITY::SET_ENTITY_HEADING(playerPed, heading - 0.5f);
				}
				if (GetAsyncKeyState(VK_SHIFT)) {
					float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
					ENTITY::SET_ENTITY_HEADING(playerPed, heading);

					pos.z -= 0.5;
					ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
				}
				if (GetAsyncKeyState(VK_SPACE)) {
					float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
					ENTITY::SET_ENTITY_HEADING(playerPed, heading);

					pos.z += 0.5;
					ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
				}
			}
		}
	}
}
float degToRad(float degs)
	{
		return degs * 3.141592653589793f / 180.f;
	}
void RequestingControl(Entity e)
{
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(e);
	if (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(e))
		SYSTEM::WAIT(0);
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(e);
}
void Juice::CrashPlayer(int Player)
{
	const int maxPeds = 225;
	Ped ClonedPed[maxPeds];
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	NativeVector3 selectedPedPosition = ENTITY::GET_ENTITY_COORDS(Player, false);
	NativeVector3 playerPosition = ENTITY::GET_ENTITY_COORDS(playerPed, FALSE);

	if (MISC::GET_DISTANCE_BETWEEN_COORDS(playerPosition.x, playerPosition.y, playerPosition.z, selectedPedPosition.x, selectedPedPosition.y, selectedPedPosition.z, false) > 350.0f)
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PED::GET_VEHICLE_PED_IS_IN(Player, 1), FALSE))
		{
			TASK::CLEAR_PED_TASKS_IMMEDIATELY(Player);
			TASK::CLEAR_PED_SECONDARY_TASK(Player);
		}
		for (int i = 0; i < maxPeds; i++)
		{

			ClonedPed[i] = PED::CLONE_PED(Player, ENTITY::GET_ENTITY_HEADING(playerPed), 1, 1);
			RequestingControl(ClonedPed[i]);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(ClonedPed[i], Player, PED::GET_PED_BONE_INDEX(Player, false), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false, false, false, false, 2, true);
			TASK::CLEAR_PED_TASKS_IMMEDIATELY(Player);
		}
		for (int i = 0; i < maxPeds; i++)
		{
			RequestingControl(ClonedPed[i]);
			ENTITY::SET_PED_AS_NO_LONGER_NEEDED(&ClonedPed[i]);
			PED::DELETE_PED(&ClonedPed[i]);
		}
	}
	else
	{

	}
}
bool Juice::explodepedsbool = false;
void Juice::explodepeds()
{
	if (explodepedsbool) {
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Ped* peds = new Ped[ArrSize];
		peds[0] = ElementAmount;

		int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			RequestControlOfEnt(peds[OffsetID]);
			if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
			{
				NativeVector3 pos = ENTITY::GET_ENTITY_COORDS(peds[OffsetID], false);
				FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 0, 1000.f, true, false, 0.f, 1);
			}
		}
	}
}
bool Juice::killpedsbool = false;
void Juice::killpeds()
{
	if (killpedsbool) {
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Ped* peds = new Ped[ArrSize];
		peds[0] = ElementAmount;

		int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			RequestControlOfEnt(peds[OffsetID]);
			if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
			{
				PED::APPLY_DAMAGE_TO_PED(peds[OffsetID], 1000, false, 0);
			}
		}
	}
}
bool Juice::deletenearbyvehiclesbool = false;
void Juice::deletenearbyvehicles()
{
	if (deletenearbyvehiclesbool) {
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Vehicle* vehs = new Vehicle[ArrSize];
		vehs[0] = ElementAmount;
		int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

		for (int i = 0; i < VehFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
			{
				RequestControlOfEnt(vehs[OffsetID]);
				ENTITY::SET_ENTITY_COORDS(vehs[OffsetID], 6400.f, 6400.f, 0.f, false, false, false, false);
			}
		}
		delete vehs;

	}
}
bool Juice::Frezztimebool = true;
void Juice::Frezztime() {
	if (Frezztimebool) {
		CLOCK::PAUSE_CLOCK(0);
	}
}
bool Juice::deletenearbypedsbool = false;
void Juice::deletenearbypeds()
{
	if (deletenearbypedsbool) {
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Ped* Peds = new Ped[ArrSize];
		Peds[0] = ElementAmount;
		int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), Peds, true);

		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (Peds[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
			{
				RequestControlOfEnt(Peds[OffsetID]);
				ENTITY::SET_ENTITY_COORDS(Peds[OffsetID], 6400.f, 6400.f, 0.f, false, false, false, false);
			}
		}
		delete Peds;

	}
}
void setupdraw()
{
	HUD::SET_TEXT_FONT(1);
	HUD::SET_TEXT_SCALE(0.4f, 0.4f);
	HUD::SET_TEXT_COLOUR(255, 255, 255, 255);
	HUD::SET_TEXT_WRAP(0.0f, 1.0f);
	HUD::SET_TEXT_CENTRE(0);
	HUD::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	HUD::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	{
		HUD::SET_TEXT_OUTLINE();
	}
}
void drawstring(char* text, float X, float Y)
{
	HUD::BEGIN_TEXT_COMMAND_DISPLAY_TEXT((char*)"STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	HUD::END_TEXT_COMMAND_DISPLAY_TEXT(X, Y, 0);
}
void drawinteger(int text, float X, float Y)
{
	HUD::BEGIN_TEXT_COMMAND_DISPLAY_TEXT((char*)"NUMBER");
	HUD::ADD_TEXT_COMPONENT_INTEGER(text);
	HUD::END_TEXT_COMMAND_DISPLAY_TEXT(X, Y, 0);
}
bool HeaderImage = 1;
bool Juice::DisplayFPS = true;
void Juice::featureDisplayFPS()
{
	if (DisplayFPS) {
		float LastFrameTime = MISC::GET_FRAME_TIME();
		int getFPS = (1.0f / LastFrameTime);
		char FPStext[60];
		snprintf(FPStext, sizeof(FPStext), "FPS: %d ", getFPS);
		setupdraw();
		HUD::SET_TEXT_FONT(6);
		HUD::SET_TEXT_SCALE(0.5f, 0.5f);
		HUD::SET_TEXT_COLOUR(255, 255, 255, 255);
		HUD::SET_TEXT_CENTRE(0);
		drawstring(FPStext, 0.020f, 0.010f);
	}
}
bool Juice::Display = false;
void Juice::Displays()
{
	if (Display) {
		float LastFrameTime = MISC::GET_FRAME_TIME();
		int getFPS = (1.0f / LastFrameTime);
		char FPStext[60];
		snprintf(FPStext, sizeof(FPStext), "~p~Juice.Vip", getFPS);
		setupdraw();
		HUD::SET_TEXT_FONT(6);
		HUD::SET_TEXT_SCALE(0.5f, 0.5f);
		HUD::SET_TEXT_COLOUR(255, 255, 255, 255);
		HUD::SET_TEXT_CENTRE(0);
		drawstring(FPStext, 0.500f, 0.005f);
	}
}
bool Juice::dDisplays = false;
void Juice::dDisplayss()
{
	if (dDisplays) {
		float LastFrameTime = MISC::GET_FRAME_TIME();
		int getFPS = (1.0f / LastFrameTime);
		char FPStext[60];
		snprintf(FPStext, sizeof(FPStext), "Status:~g~Undetected", getFPS);
		setupdraw();
		HUD::SET_TEXT_FONT(6);
		HUD::SET_TEXT_SCALE(0.5f, 0.5f);
		HUD::SET_TEXT_COLOUR(255, 255, 255, 255);
		HUD::SET_TEXT_CENTRE(0);
		drawstring(FPStext, 0.910f, 0.005f);
	}
}	
bool Juice::SpeedoBool = false;
bool Juice::MPH = true;
bool Juice::PlateMPH = false;
void Juice::Speedometer()
{
	Ped ped = PLAYER::PLAYER_PED_ID();
	RequestControlOfEnt(ped);
	bool inVehicle = PED::IS_PED_IN_ANY_VEHICLE(ped, 0);
	std::ostringstream VehicleModel; VehicleModel;
	if (inVehicle) {
		Ped ped = PLAYER::PLAYER_PED_ID();
		RequestControlOfEnt(ped);
		float speed = ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID())) * 2.6f;

		if (MPH)
			speed = speed * .60f;
		char msg[0xFF];
		if (MPH)
		{
			sprintf_s(msg, " MPH ~p~%i", (int)speed);
		}
		else
		{
			sprintf_s(msg, " MPH ~p~%i", (int)speed);
		}
		drawstring(msg, .835f, .90f);
		if (PlateMPH)
		{
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), msg);
		}
	}
}
void Juice::loggi()
{
	Ped ped = PLAYER::PLAYER_PED_ID();

	if (PED::IS_PED_IN_ANY_VEHICLE(ped, 0))
	{
		Vehicle Veh = PED::GET_VEHICLE_PED_IS_USING(ped);
		Hash Model = ENTITY::GET_ENTITY_MODEL(Veh);

		Blip vBlip = HUD::ADD_BLIP_FOR_ENTITY(Veh);
		HUD::SET_BLIP_SCALE(vBlip, 1);
		if (VEHICLE::IS_THIS_MODEL_A_CAR(Model))
			HUD::SET_BLIP_SPRITE(vBlip, 225);
		else if (VEHICLE::IS_THIS_MODEL_A_HELI(Model))
			HUD::SET_BLIP_SPRITE(vBlip, 64);
		else if (VEHICLE::IS_THIS_MODEL_A_PLANE(Model))
			HUD::SET_BLIP_SPRITE(vBlip, 16);
		else if (VEHICLE::IS_THIS_MODEL_A_BIKE(Model))
			HUD::SET_BLIP_SPRITE(vBlip, 226);
		else
			HUD::SET_BLIP_SPRITE(vBlip, 225);

		HUD::SET_BLIP_NAME_FROM_TEXT_FILE(vBlip, "Pinned Vehicle");
		HUD::SET_BLIP_COLOUR(vBlip, 0);
		HUD::SET_BLIP_FLASHES(vBlip, false);
		HUD::SET_BLIP_DISPLAY(vBlip, 2);
		HUD::SET_BLIP_CATEGORY(vBlip, 1);
		HUD::BEGIN_TEXT_COMMAND_SET_BLIP_NAME("Alliance's Vehicle");
		HUD::END_TEXT_COMMAND_SET_BLIP_NAME(vBlip);
	}
	
}
void Juice::RemoteLevels(int Player)
{
	if (ENTITY::DOES_ENTITY_EXIST(g_SelectedPlayer))
	{
		const int maxPeds = 40;
		Ped ClonedPed[maxPeds];
		auto playerPed = PLAYER::PLAYER_PED_ID();
		NativeVector3 coords = ENTITY::GET_ENTITY_COORDS(g_SelectedPlayer, 0);
		for (int i = 0; i < maxPeds; i++)
		{
			ClonedPed[i] = PED::CLONE_PED(Player, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()), 1, 1);
			ENTITY::SET_ENTITY_COORDS(ClonedPed[i], coords.x, coords.y, coords.z + 25, 0, 0, 0, 1);
			PED::SET_PED_AS_COP(ClonedPed[i], true);
			NativeVector3 cloneCoord = ENTITY::GET_ENTITY_COORDS(ClonedPed[i], 0);
			ENTITY::SET_ENTITY_VISIBLE(ClonedPed[i], false, 0);
			FIRE::ADD_OWNED_EXPLOSION(Player, 9, 5.0f, 0, 1, 0.0f , false, false, false);
		}
	}
}
bool Juice::mobileRadio = false;
void Juice::mobiletunes() {
	int station = AUDIO::GET_PLAYER_RADIO_STATION_INDEX();
	if (!mobileRadio)
	{
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(false);
		AUDIO::SET_MOBILE_PHONE_RADIO_STATE(0);
	}
	else
	{
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(true);
		AUDIO::SET_MOBILE_PHONE_RADIO_STATE(1);
		AUDIO::SET_RADIO_TO_STATION_INDEX(station);
	}
}
//bool Juice::PlateMPH = false;
//void Juice::Speedometer()
//{
//	if (PlateMPH) {
//		float speed = ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID())) * 2.6f;
//
//		if (MPH)
//			speed = speed * .60f;
//		char msg[0xFF];
//		if (MPH)
//		{
//			sprintf_s(msg, "  ~p~%i", (int)speed);
//		}
//		else
//		{
//			sprintf_s(msg, "  ~p~%i", (int)speed);
//		}
//		drawstring(msg, .155f, .90f);
//		if (PlateMPH)
//		{
//			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), msg);
//		}
//	}
//}
float StringToFloat(std::string str) {
	return ::atof(str.c_str());
}
//bool Juice::cyrclenew = false;
//void Juice::CyrcleNew()
//{
//
//	Ped playerselected = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
//	{
//		STREAMING::REQUEST_MODEL(bagHash);
//		if (!STREAMING::HAS_MODEL_LOADED(bagHash)) {
//			SYSTEM::WAIT(0);
//		}
//		else {
//			NativeVector3 playerPosition = ENTITY::GET_ENTITY_COORDS(playerselected, FALSE);
//			OBJECT::CREATE_MONEY_PICKUPS(playerPosition.x, playerPosition.y, playerPosition.z, 1, bagHash, FALSE);
//			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(bagHash);
//		}
//	}
//}