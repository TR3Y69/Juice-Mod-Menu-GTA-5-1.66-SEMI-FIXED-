#include "MainScript.hpp"
#include "ScriptCallback.hpp"
#include "Lists.hpp"
#include "Natives.hpp"
#include "Timer.hpp"
#include "Translation.hpp"
#include "CustomText.hpp"
#include "UI/UIManager.hpp"
#include "UI/BoolOption.hpp"
#include "UI/ChooseOption.hpp"
#include "UI/NumberOption.hpp"
#include "UI/RegularOption.hpp"
#include "UI/SubOption.hpp"
#include "UI/RegularSubmenu.hpp"
#include "UI/PlayerSubmenu.hpp"
#include "Juice.h"
#include "player.h"
#include "Game.hpp"


namespace Big
{
	enum Submenu : std::uint32_t
	{
		SubmenuHome,
		SubmenuSettings,
		SubmenuSettingsHeader,
		SubmenuSettingsHeaderStaticBackground,
		SubmenuSettingsHeaderGradientBackground,
		SubmenuSettingsHeaderText,
		SubmenuSettingsSubmenuBar,
		SubmenuSettingsOption,
		SubmenuSettingsFooter,
		SubmenuSettingsDescription,
		SubmenuSettingsInput,
		SubmenuSettingsLanguage,
		SubmenuSelectedPlayer,
		SubmenuPlayerList,
		SubmenuTest,
		Submenunet,
		Self,
		Schutz,
		Teleport,
		Infos,
		car,
		Speedometer,
		Misc,
		SetInfos,
		Net,
		Ui,
		Wrld,
		Rank,
		Recovery,
		Movements,
		VIEW_REPORTS,
		Displays,
		tpcars,
		MODDED,
		Outfits,
		carunder,
		CONTACTS,
		Notify,
		flip,
		MOBILELSC,
		Ramp,
		Dors,
		crashkick,
		Hotkey,
		money,
		VEHICLEspawn,
		Geld,
		Unlocks,
		ESP,
		VEHICLESPAWN,
		gerneral,
		Clear,
		ScriptHookV,
		Casino,
		Tp,
		Esp,
		test,
		StealthDropd,
		Allplayers,                       
		version,//online
		map,
		Attach,
		Trolling,
		Friendly,
		Drop,
		Animation,
		tpayertpppp,
		Vehiclee,
		wrlddd,
		an,
		Animations,
		ENEMY,
		General,
		Editor,
		Chrash,
		ssss,
		IPLs,
		SELECTEDATTACH,
		ammo,
		ytd,
		CostumeOutfits,
		MODELS,
		Danger,
		UA
	};
	std::size_t WeatherTypePos = 0;
	std::vector<std::string> WeatherTypes =
	{
		"EXTRASUNNY",
		"CLEAR",
		"CLOUDS",
		"SMOG",
		"FOGGY",
		"OVERCAST",
		"RAIN",
		"THUNDER",
		"CLEARING",
		"NEUTRAL",
		"SNOW",
		"BLIZZARD",
		"SNOWLIGHT",
		"XMAS",
		"HALLOWEEN",
		"BLACK SCREEN"
	};
	bool protex1 = false;
	bool protex2 = false;
	bool protex3 = false;
	bool protex4 = false;
	bool protex5 = false;
	bool protex6 = false;
	bool protex7 = false;
	bool protex8 = false;
	bool protex9 = false;
	bool protex10 = false;
	bool protex11 = false;
	bool protex12 = false;
	bool protex17 = false;
	extern bool StealthLoop;
	int DropDelay = 500;
	Hash bagHash = 0x9CA6F755;
	int DropAmount = 2500;
	int Explosionfickk = 38;
	int ficksizee = 10;
	int maker = 43;
	int ficksize = 10;
	int DropHeight = 35;
	int DropAmount3 = 2500;
	int stealthdelay = 500;
	int delstealthdelay = 1000000000;
	int stealthDelay405 = 500;
	int stealthDelay1 = 800;
	int Horndelay = 50;
	int Bags = 1;
	int player;
	int Rundelay = 50;

	int bandelay = 300;
	int stealthDelaydel = 1000000000;
	Hash bagHash557 = 0x9CA6F755;
	bool cashdrop69Toggle[32];
	int drop_ticker = GetTickCount();
	bool MainScript::IsInitialized()

	{
		return m_Initialized;
	}

	ScriptType MainScript::GetType()
	{
		return ScriptType::Game;
	}
	void rRequestControlOfid(Entity netid)
	{
		int tick = 0;

		while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
		{
			NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
			tick++;
		}
	}
	void rRequestControlOfEnt(Entity entity)
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
			rRequestControlOfid(netID);
			NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
		}
	}
	//Cods
#pragma once
	static const char* PlateRegions[] = {
			"Blue/White", "Yellow/Black","Yellow/Blue", "Blue/White2", "Blue/White3", "Yankton"
	};
	static const char* Boats1[] = {
		"DINGHY", "DINGHY2", "DINGHY3", "DINGHY4", "JETMAX",
		"MARQUIS", "PREDATOR", "SEASHARK", "SEASHARK2", "SEASHARK3",
		"SPEEDER", "SPEEDER2", "SQUALO", "SUBMERSIBLE", "SUBMERSIBLE2",
		"SUNTRAP", "TORO", "TORO2", "TROPIC", "TROPIC2",
		"TUG"
	};
	static const char* Commercial1[] = {
		"BENSON", "BIFF", "HAULER", "MULE", "MULE2",
		"MULE3", "PACKER", "PHANTOM", "POUNDER", "STOCKADE",
		"STOCKADE3", "MULE4", "POUNDER2", "TERBYTE", "CEREBUS2", "CEREBUS3",
		"CEREBUS"
	};
	static const char* Compacts1[] = {
		"BLISTA", "BRIOSO", "DILETTANTE", "DILETTANTE2", "ISSI2",
		"PANTO", "PRAIRIE", "RHAPSODY", "ISSI3", "ISSI6", "ISSI4", "ISSI5",
		"ISSI7", "ASBO", "KANJO"
	};
	static const char* Coupes1[] = {
		"COGCABRIO", "EXEMPLAR", "F620", "FELON", "FELON2",
		"JACKAL", "ORACLE", "ORACLE2", "SENTINEL", "SENTINEL2",
		"WINDSOR", "WINDSOR2", "ZION", "ZION2"
	};
	static const char* Cycles1[] = {
		"BMX", "CRUISER", "FIXTER", "SCORCHER", "TRIBIKE",
		"TRIBIKE2", "TRIBIKE3"
	};
	static const char* Emergency1[] = {
		"AMBULANCE", "FBI", "FBI2", "FIRETRUK", "LGUARD",
		"PBUS", "PRANGER", "POLICE", "POLICE2", "POLICE3",
		"POLICE4", "POLICEB", "POLICEOLD1", "POLICEOLD2", "POLICET",
		"SHERIFF", "SHERIFF2", "RIOT", "RIOT2", "MINITANK"
	};
	static const char* Helicopters1[] = {
		"ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2",
		"CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
		"FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
		"SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
		"VALKYRIE2", "VOLATUS", "HUNTER", "HAVOK", "AKULA", "SEASPARROW",
		"BLIMP3"
	};
	static const char* Industrial1[] = {
		"BULLDOZER", "CUTTER", "DUMP", "FLATBED", "GUARDIAN",
		"HANDLER", "MIXER", "MIXER2", "RUBBLE", "TIPTRUCK",
		"TIPTRUCK2"
	};
	static const char* Military1[] = {
		"BARRACKS", "BARRACKS2", "BARRACKS3", "CRUSADER", "RHINO", "BARRAGE", "CHERNOBOG", "KHANJALI", "THRUSTER", "SCARAB", "SCARAB2", "SCARAB3"
	};
	static const char* Motorcycles1[] = {
		"AKUMA", "AVARUS", "BAGGER", "BATI", "BATI2",
		"BF400", "CARBONRS", "CHIMERA", "CLIFFHANGER", "DAEMON",
		"DAEMON2", "DEFILER", "DOUBLE", "ENDURO", "ESSKEY",
		"FAGGIO", "FAGGIO2", "FAGGIO3", "GARGOYLE", "HAKUCHOU",
		"HAKUCHOU2", "HEXER", "INNOVATION", "LECTRO", "MANCHEZ",
		"NEMESIS", "NIGHTBLADE", "PCJ", "RATBIKE", "RUFFIAN",
		"SANCHEZ", "SANCHEZ2", "SANCTUS", "SHOTARO", "SOVEREIGN",
		"THRUST", "VADER", "VINDICATOR", "VORTEX", "WOLFSBANE",
		"ZOMBIEA", "ZOMBIEB", "DIABLOUS", "DIABLOUS2", "FCR",
		"FCR2", "OPPRESSOR", "AVENGER", "OPPRESSOR2", "DEATHBIKE2",
		"DEATHBIKE3", "DEATHBIKE", "RROCKET", "STRYDER"
	};
	static const char* Muscle1[] = {
		"BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2",
		"COQUETTE3", "DOMINATOR", "DOMINATOR2", "DUKES", "DUKES2",
		"GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3",
		"HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE",
		"PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER", "RUINER2", "RUINER3",
		"SABREGT", "SABREGT2", "SLAMVAN", "SLAMVAN2", "SLAMVAN3",
		"STALION", "STALION2", "TAMPA", "VIGERO", "VIRGO",
		"VIRGO2", "VIRGO3", "VOODOO", "VOODOO2", "HERMES", "HUSTLER", "YOSEMITE", "DOMINATOR3", "ELLIE",
		"IMPALER3", "SLAMVAN6", "DOMINATOR6", "IMPALER4","SLAMVAN4","SLAMVAN5",
		"DOMINATOR4", "DOMINATOR5", "BRUISER", "BRUISER2", "BRUISER3", "RCBANDITO", "IMPALER2",
		"TULIP", "CLIQUE", "VAMOS", "IMPERATOR", "IMPERATOR2", "IMPERATOR3",
		"DEVIANT", "IMPALER", "GAUNTLET3", "GAUNTLET4", "YOSEMITE2",
	};
	static const char* OffRoad1[] = {
		"BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
		"BLAZER4", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
		"DUNE", "DUNE2", "INSURGENT", "INSURGENT2", "KALAHARI",
		"MARSHALL", "MESA3", "MONSTER", "RANCHERXL", "RANCHERXL2",
		"REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL",
		"TROPHYTRUCK", "TROPHYTRUCK2", "TECHNICAL2", "DUNE4", "DUNE5",
		"BLAZER5", "KAMACHO", "RIATA", "CARACARA", "FREECRAWLER", "MENACER",
		"MONSTER4", "MONSTER5", "BRUTUS", "BRUTUS2", "BRUTUS3", "MONSTER3",
		"CARACARA2", "HELLION", "EVERON", "NIGHTSHARK", "OUTLAW", "VAGRANT", "ZHABA"
	};
	const DWORD MK2Weapons[] = {
		0xBFE256D4, 0x78A97CD0, 0xDBBD7280, 0x394F415C, 0xFAD1F1C9, 0xA914799
	};
	const DWORD Weaponss[] =
	{
		0x1b06d571, 0x5ef9fec4, 0x22d8fe39, 0x99aeeb3b, 0xd205520e, 0xdc4db296,
		0xc1b3c3d1, 0xbfd21232, 0x83839c4, 0x3656c8c1, 0x47757124,
		0x13532244, 0x2be6766b, 0xefe7e2df, 0x9d07f764, 0x7fd62962, 0xa3d4d34,
		0x61012683, 0xdb1aa450, 0xbd248b55, 0x5307A4EC,
		0xbfefff6d, 0x83bf0278, 0xaf113f99, 0xc0a3098d, 0x7f229f94,
		0x624fe830, 0x97EA20B8, 0xCB96392F, 0x88374054, 0x969C3D67, 0x84D6FAFD, 0x555AF99A, 0x6A6C02E0,
		0x1d073a89, 0x7846a318, 0xe284c527, 0x9d61e50f,
		0x3aabbbaa, 0x12e82d3d, 0xef951fbb, 0xa89cb99e,
		0x5fc3c11, 0xc472fe2, 0xc734385a,
		0xa284510b, 0xb1ca77b1, 0x63ab0442, 0x42bf8a85,
		0x6d544c99, 0x7f7497e5, 0x781fe4a,
		0x93e220bd, 0x2c3731d9, 0xab564b93, 0xfdbc8a50, 0xa0973d5e,
		0x24b17070, 0x60ec506, 0x34a67b97, 0xba45e8b8,
		0x99b507ea, 0x678b81b1, 0x4e875f73, 0x958a4a8f, 0x440e4788, 0x84bd7bfd,
		0x94117305, 0x19044ee0, 0x8bb05fd7, 0xdfe37640, 0xcd274149, 0xf9e6aa4b,
		0x92a27487, 0xf9dcbf2d, 0xdd5df8d9, 0x787f0bb, 0xd8df3c3c,
		0xfbab5776, 0xBFE256D4, 0x78A97CD0, 0x394F415C, 0xFAD1F1C9, 0xDBBD7280, 0xA914799,
		0xAF3696A1, 0x476BF155, 0xB62D1F67
	};
	const DWORD MK1Weapons[] = {
		0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x3813FC08, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4,
		0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764,
		0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22,
		0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070,
		0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E,
		0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB,
		0x47757124, 0xD04C944D, 0x3813FC08
	};
	const DWORD forbidden_object[] =
	{
		0xdf9841d7, 0xceea3f4b, 0x2592b5cf, 0x9cf21e0f, 0xc1ce1183, 0x49863e9c, 0xcd93a7db, 0x82cac433, 0x74f24de,  0x1c725a1,  0x81fb3ff0,
		0x79b41171, 0x781e451d, 0xa5e3d471, 0x6a27feb1, 0x861d914d, 0x8c049d17, 0xffba70aa, 0xe65ec0e4, 0xc3c00861, 0x5f5dd65c,
		0xc07792d4, 0x53cfe80a, 0xd9f4474c, 0xcb2acc8,  0xc6899cde, 0xd14b5ba3, 0x32a9996c, 0x69d4f974, 0xc2e75a21, 0x1075651,
		0xe1aeb708, 0xcbbb6c39, 0x6fa03a5e, 0xcf7a9a9d, 0x34315488, 0x45ef7804, 0xac3de147, 0xcafc1ec3, 0xd971bbae, 0xe764d794,
		0xf51f7309, 0x1e78c9d,  0xa49658fc, 0x4f2526da, 0x576ab4f6, 0xd20b1778, 0x54bc1cd8, 0xce109c5c, 0xe049c0ce, 0x78de93d1,
		0xe5b89d31, 0x5850e7b3, 0x6aed0e4b, 0xc50a4285, 0xb648a502, 0x5e497511, 0x47c14801, 0xfd8bb397, 0xef541728, 0xc2cc99d8,
		0x8fb233a4, 0x24e08e1f, 0x337b2b54, 0x7367d224, 0x919d9255, 0x4484243f, 0x3c91d42d, 0x3353525a, 0xc175f658, 0x762657c6,
		0x94ac15b3, 0x28014a56, 0xe0a8bfc9, 0x3a559c31, 0x5fc8a70,  0x3b545487, 0xb9402f87
	};
	static const char* Weathers[] = {
	"Clear", "Clearing","Snowlight", "Thunder", "Blizzard", "Overcast", "Foggy", "Smog", "Clouds"
	};
	static const char* Planes1[] = {
		"BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
		"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
		"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
		"TITAN", "VELUM", "VELUM2", "VESTRA", "BOMBUSHKA",
		"ALPHAZ1", "TULA", "ROGUE", "PYRO", "MOGUL",
		"NOKOTA", "MOLOTOK", "SEABREEZE", "MICROLIGHT", "HOWARD",
		"STARLING", "AVENGER2", "VOLATOL", "STRIKEFORCE"
	};
	static const char* Sedans1[] = {
		"ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
		"COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
		"FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
		"PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
		"SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
		"STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARRENER",
		"WASHINGTON", "STAFFORD", "NEBULA"
	};
	static const char* Service1[] = {
		"AIRBUS", "BRICKADE", "BUS", "COACH", "RALLYTRUCK",
		"RENTALBUS", "TAXI", "TOURBUS", "TRASH", "TRASH2",
		"WASTELANDER", "PBUS2"
	};
	static const char* Sports1[] = {
		"ALPHA", "BANSHEE", "BESTIAGTS", "BLISTA2", "BLISTA3",
		"BUFFALO", "BUFFALO2", "BUFFALO3", "CARBONIZZARE", "COMET2",
		"COQUETTE", "ELEGY", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE",
		"FUTO", "JESTER", "JESTER2", "KHAMELION", "KURUMA",
		"KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF",
		"NINEF2", "OMNIS", "PENUMBRA", "RAPIDGT", "RAPIDGT2",
		"RAPTOR", "SCHAFTER3", "SCHAFTER4", "SCHWARZE", "SEVEN70",
		"SULTAN", "SURANO", "SPECTER", "SPECTER2", "TAMPA2", "TROPOS", "VERLIERER2",
		"RUINER2", "PHANTOM2", "RUSTON", "COMET4", "COMET5", "NEON", "PARIAH", "RAIDEN", "REVOLTER", "SENTINEL3", "STREITER", "Z190",
		"GB200", "HOTRING", "ITALIGTO", "SCHLAGEN", "ZR380", "ZR3802", "ZR3803",
		"DRAFTER", "JUGULAR", "LOCUST", "NEO", "PARAGON", "PARAGON2", "IMORGON", "KOMODA", "SUGOI", "SULTAN2", "VSTR"
	};
	static const char* SportsClassics1[] = {
		"BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2",
		"FELTZER3", "JB700", "MAMBA", "MANANA", "MONROE",
		"PEYOTE", "PIGALLE", "STINGER", "STINGERGT", "TORNADO",
		"TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5", "TORNADO6",
		"ZTYPE", "INFERNUS2", "TURISMO2", "RAPIDGT3", "RETINUE", "DELUXO", "GT500",
		"SAVESTRA", "STROMBERG", "VISERIS", "CHEBUREK", "FAGALOA", "JESTER3", "MICHELLI", "SWINGER",
		"DYNASTY", "PEYOTE2", "ZION3", "JB7002", "RETINUE2"
	};
	static const char* Super1[] = {
		"ADDER", "BANSHEE2", "BULLET", "CHEETAH", "ENTITYXF",
		"FMJ", "SHEAVA", "INFERNUS", "NERO", "NERO2","OSIRIS", "LE7B",
		"ITALIGTB", "ITALIGTB2", "PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS", "T20",
		"TEMPESTA", "TURISMOR", "TYRUS", "VACCA", "VOLTIC", "ZENTORNO", "VOLTIC2", "PENETRATOR", "GP1", "XA21", "VIGILANTE",
		"CYCLONE", "VISIONE", "AUTARCH", "SC1", "ENTITY2", "TAIPAN", "TEZERACT", "TYRANT", "SCRAMJET", "DEVESTE",
		"EMERUS", "KRIEGER", "S80", "THRAX", "ZORRUSSO", "FURIA", "FORMULA", "FORMULA2"
	};
	static const char* SUVs1[] = {
		"BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
		"BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
		"DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
		"HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
		"PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
		"XLS", "XLS2", "PATRIOT2", "TOROS", "NOVAK", "REBLA"
	};
	static const char* Trailer1[] = {
		"ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
		"DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
		"TANKER", "TANKER2", "TR2", "TR3", "TR4",
		"TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL",
		"TRFLAT", "TVTRAILER"
	};
	static const char* Trains1[] = {
		"CABLECAR", "FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
		"FREIGHTGRAIN", "METROTRAIN", "TANKERCAR"
	};
	static const char* Utility1[] = {
		"AIRTUG", "CADDY", "CADDY2", "DOCKTUG", "FORKLIFT",
		"MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP",
		"TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
		"UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3"
	};
	static const char* Vans1[] = {
		"BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
		"BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
		"BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
		"GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
		"PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
		"SPEEDO", "SPEEDO2", "SURFER", "SURFER2", "TACO",
		"YOUGA", "YOUGA2", "SPEEDO4"
	};
	static const char* objects[] = { "prop_bskball_01", "PROP_MP_RAMP_03", "PROP_MP_RAMP_02", "PROP_MP_RAMP_01", "PROP_JETSKI_RAMP_01", "PROP_WATER_RAMP_03", "PROP_VEND_SNAK_01", "PROP_TRI_START_BANNER", "PROP_TRI_FINISH_BANNER", "PROP_TEMP_BLOCK_BLOCKER", "PROP_SLUICEGATEL", "PROP_SKIP_08A", "PROP_SAM_01", "PROP_RUB_CONT_01B", "PROP_ROADCONE01A", "PROP_MP_ARROW_BARRIER_01", "PROP_HOTEL_CLOCK_01", "PROP_LIFEBLURB_02", "PROP_COFFIN_02B", "PROP_MP_NUM_1", "PROP_MP_NUM_2", "PROP_MP_NUM_3", "PROP_MP_NUM_4", "PROP_MP_NUM_5", "PROP_MP_NUM_6", "PROP_MP_NUM_7", "PROP_MP_NUM_8", "PROP_MP_NUM_9", "prop_xmas_tree_int", "prop_bumper_car_01", "prop_beer_neon_01", "prop_space_rifle", "prop_dummy_01", "prop_rub_trolley01a", "prop_wheelchair_01_s", "PROP_CS_KATANA_01", "PROP_CS_DILDO_01", "prop_armchair_01", "prop_bin_04a", "prop_chair_01a", "prop_dog_cage_01", "prop_dummy_plane", "prop_golf_bag_01", "prop_arcade_01", "hei_prop_heist_emp", "prop_alien_egg_01", "prop_air_towbar_01", "hei_prop_heist_tug", "prop_air_luggtrolley", "PROP_CUP_SAUCER_01", "prop_wheelchair_01", "prop_ld_toilet_01", "prop_acc_guitar_01", "prop_bank_vaultdoor", "p_v_43_safe_s", "p_spinning_anus_s", "prop_can_canoe", "prop_air_woodsteps", "Prop_weed_01", "prop_a_trailer_door_01", "prop_apple_box_01", "prop_air_fueltrail1", "prop_barrel_02a", "prop_barrel_float_1", "prop_barrier_wat_03b", "prop_air_fueltrail2", "prop_air_propeller01", "prop_windmill_01", "prop_Ld_ferris_wheel", "p_tram_crash_s", "p_oil_slick_01", "p_ld_stinger_s", "p_ld_soc_ball_01", "prop_juicestand", "p_oil_pjack_01_s", "prop_barbell_01", "prop_barbell_100kg", "p_parachute1_s", "p_cablecar_s", "prop_beach_fire", "prop_lev_des_barge_02", "prop_lev_des_barge_01", "prop_a_base_bars_01", "prop_beach_bars_01", "prop_air_bigradar", "prop_weed_pallet", "prop_artifact_01", "prop_attache_case_01", "prop_large_gold", "prop_roller_car_01", "prop_water_corpse_01", "prop_water_corpse_02", "prop_dummy_01", "prop_atm_01", "hei_prop_carrier_docklight_01", "hei_prop_carrier_liferafts", "hei_prop_carrier_ord_03", "hei_prop_carrier_defense_02", "hei_prop_carrier_defense_01", "hei_prop_carrier_radar_1", "hei_prop_carrier_radar_2", "hei_prop_hei_bust_01", "hei_prop_wall_alarm_on", "hei_prop_wall_light_10a_cr", "prop_afsign_amun", "prop_afsign_vbike", "prop_aircon_l_01", "prop_aircon_l_02", "prop_aircon_l_03", "prop_aircon_l_04", "prop_airhockey_01", "prop_air_bagloader", "prop_air_blastfence_01", "prop_air_blastfence_02", "prop_air_cargo_01a", "prop_air_chock_01", "prop_air_chock_03", "prop_air_gasbogey_01", "prop_air_generator_03", "prop_air_stair_02", "prop_amb_40oz_02", "prop_amb_40oz_03", "prop_amb_beer_bottle", "prop_amb_donut", "prop_amb_handbag_01", "prop_amp_01", "prop_anim_cash_pile_02", "prop_asteroid_01", "prop_arm_wrestle_01", "prop_ballistic_shield", "prop_bank_shutter", "prop_barier_conc_02b", "prop_barier_conc_05a", "prop_barrel_01a", "prop_bar_stool_01", "prop_basejump_target_01" };
	static const char* pedModels[] = {
		"A_F_M_Beach_01","A_F_M_BevHills_01","A_F_M_BevHills_02","A_F_M_BodyBuild_01","A_F_M_Business_02","A_F_M_Downtown_01","A_F_M_EastSA_01",
		"A_F_M_EastSA_02","A_F_M_FatBla_01","A_F_M_FatCult_01","A_F_M_FatWhite_01","A_F_M_KTown_01","A_F_M_KTown_02","A_F_M_ProlHost_01","A_F_M_Salton_01","A_F_M_SkidRow_01","A_F_M_SouCentMC_01","A_F_M_SouCent_01","A_F_M_SouCent_02",
		"A_F_M_Tourist_01","A_F_M_TrampBeac_01","A_F_M_Tramp_01","A_F_O_GenStreet_01","A_F_O_Indian_01","A_F_O_KTown_01","A_F_O_Salton_01","A_F_O_SouCent_01","A_F_O_SouCent_02","A_F_Y_Beach_01","A_F_Y_BevHills_01","A_F_Y_BevHills_02",
		"A_F_Y_BevHills_03","A_F_Y_BevHills_04","A_F_Y_Business_01","A_F_Y_Business_02","A_F_Y_Business_03","A_F_Y_Business_04","A_F_Y_EastSA_01","A_F_Y_EastSA_02","A_F_Y_EastSA_03","A_F_Y_Epsilon_01","A_F_Y_Fitness_01",
		"A_F_Y_Fitness_02","A_F_Y_GenHot_01","A_F_Y_Golfer_01","A_F_Y_Hiker_01","A_F_Y_Hippie_01","A_F_Y_Hipster_01","A_F_Y_Hipster_02","A_F_Y_Hipster_03","A_F_Y_Hipster_04","A_F_Y_Indian_01","A_F_Y_Juggalo_01","A_F_Y_Runner_01",
		"A_F_Y_RurMeth_01","A_F_Y_SCDressy_01","A_F_Y_Skater_01","A_F_Y_SouCent_01","A_F_Y_SouCent_02","A_F_Y_SouCent_03","A_F_Y_Tennis_01","A_F_Y_Topless_01","A_F_Y_Tourist_01","A_F_Y_Tourist_02","A_F_Y_Vinewood_01",
		"A_F_Y_Vinewood_02","A_F_Y_Vinewood_03","A_F_Y_Vinewood_04","A_F_Y_Yoga_01","A_M_M_ACult_01","A_M_M_AfriAmer_01","A_M_M_Beach_01","A_M_M_Beach_02","A_M_M_BevHills_01","A_M_M_BevHills_02","A_M_M_Business_01",
		"A_M_M_EastSA_01","A_M_M_EastSA_02","A_M_M_Farmer_01","A_M_M_FatLatin_01","A_M_M_GenFat_01","A_M_M_GenFat_02","A_M_M_Golfer_01","A_M_M_HasJew_01","A_M_M_Hillbilly_01","A_M_M_Hillbilly_02","A_M_M_Indian_01",
		"A_M_M_KTown_01","A_M_M_Malibu_01","A_M_M_MexCntry_01","A_M_M_MexLabor_01","A_M_M_OG_Boss_01","A_M_M_Paparazzi_01","A_M_M_Polynesian_01","A_M_M_ProlHost_01","A_M_M_RurMeth_01","A_M_M_Salton_01","A_M_M_Salton_02",
		"A_M_M_Salton_03","A_M_M_Salton_04","A_M_M_Skater_01","A_M_M_Skidrow_01","A_M_M_SoCenLat_01","A_M_M_SouCent_01","A_M_M_SouCent_02","A_M_M_SouCent_03","A_M_M_SouCent_04","A_M_M_StLat_02","A_M_M_Tennis_01",
		"A_M_M_Tourist_01","A_M_M_TrampBeac_01","A_M_M_Tramp_01","A_M_M_TranVest_01","A_M_M_TranVest_02","A_M_O_ACult_01","A_M_O_ACult_02","A_M_O_Beach_01","A_M_O_GenStreet_01","A_M_O_KTown_01","A_M_O_Salton_01",
		"A_M_O_SouCent_01","A_M_O_SouCent_02","A_M_O_SouCent_03","A_M_O_Tramp_01","A_M_Y_ACult_01","A_M_Y_ACult_02","A_M_Y_BeachVesp_01","A_M_Y_BeachVesp_02","A_M_Y_Beach_01","A_M_Y_Beach_02","A_M_Y_Beach_03","A_M_Y_BevHills_01",
		"A_M_Y_BevHills_02","A_M_Y_BreakDance_01","A_M_Y_BusiCas_01","A_M_Y_Business_01","A_M_Y_Business_02","A_M_Y_Business_03","A_M_Y_Cyclist_01","A_M_Y_DHill_01","A_M_Y_Downtown_01","A_M_Y_EastSA_01","A_M_Y_EastSA_02",
		"A_M_Y_Epsilon_01","A_M_Y_Epsilon_02","A_M_Y_Gay_01","A_M_Y_Gay_02","A_M_Y_GenStreet_01","A_M_Y_GenStreet_02","A_M_Y_Golfer_01","A_M_Y_HasJew_01","A_M_Y_Hiker_01","A_M_Y_Hippy_01","A_M_Y_Hipster_01","A_M_Y_Hipster_02",
		"A_M_Y_Hipster_03","A_M_Y_Indian_01","A_M_Y_Jetski_01","A_M_Y_Juggalo_01","A_M_Y_KTown_01","A_M_Y_KTown_02","A_M_Y_Latino_01","A_M_Y_MethHead_01","A_M_Y_MexThug_01","A_M_Y_MotoX_01","A_M_Y_MotoX_02","A_M_Y_MusclBeac_01",
		"A_M_Y_MusclBeac_02","A_M_Y_Polynesian_01","A_M_Y_RoadCyc_01","A_M_Y_Runner_01","A_M_Y_Runner_02","A_M_Y_Salton_01","A_M_Y_Skater_01","A_M_Y_Skater_02","A_M_Y_SouCent_01","A_M_Y_SouCent_02","A_M_Y_SouCent_03","A_M_Y_SouCent_04",
		"A_M_Y_StBla_01","A_M_Y_StBla_02","A_M_Y_StLat_01","A_M_Y_StWhi_01","A_M_Y_StWhi_02","A_M_Y_Sunbathe_01","A_M_Y_Surfer_01","A_M_Y_VinDouche_01","A_M_Y_Vinewood_01","A_M_Y_Vinewood_02","A_M_Y_Vinewood_03","A_M_Y_Vinewood_04",
		"A_M_Y_Yoga_01","CSB_Abigail","CSB_Anita","CSB_Anton","CSB_BallasOG","CSB_Bride","CSB_BurgerDrug","CSB_Car3guy1","CSB_Car3guy2","CSB_Chef","CSB_Chin_goon","CSB_Cletus","CSB_Cop","CSB_Customer","CSB_Denise_friend",
		"CSB_FOS_rep","CSB_G","CSB_Groom","CSB_Grove_str_dlr","CSB_Hao","CSB_Hugh","CSB_Imran","CSB_Janitor","CSB_Maude","CSB_MWeather","CSB_Ortega","CSB_Oscar","CSB_PornDudes","CSB_PrologueDriver","CSB_ProlSec","CSB_Ramp_gang",
		"CSB_Ramp_hic","CSB_Ramp_hipster","CSB_Ramp_marine","CSB_Ramp_mex","CSB_Reporter","CSB_RoccoPelosi","CSB_Screen_Writer","CSB_Stripper_01","CSB_Stripper_02","CSB_Tonya","CSB_TrafficWarden","CS_AmandaTownley","CS_Andreas",
		"cs_ashley","CS_Bankman","CS_Barry","CS_Beverly","CS_Brad","CS_BradCadaver","CS_Carbuyer","CS_Casey","CS_ChengSr","CS_ChrisFormage","CS_Clay","CS_Dale","CS_DaveNorton","cs_debra","cs_denise","CS_Devin","CS_Dom","CS_Dreyfuss",
		"CS_DrFriedlander","CS_Fabien","CS_FBISuit_01","CS_Floyd","CS_Guadalope","cs_gurk","CS_Hunter","CS_Janet","CS_JewelAss","CS_JimmyBoston","CS_JimmyDiSanto","CS_JoeMinuteMan","CS_JohnnyKlebitz","CS_Josef","CS_Josh","CS_LamarDavis",
		"CS_Lazlow","CS_LesterCrest","CS_LifeInvad_01","CS_Magenta","CS_Manuel","CS_Marnie","CS_MartinMadrazo","CS_MaryAnn","CS_Michelle","CS_Milton","CS_Molly","CS_MovPremF_01","CS_MovPremMale","CS_MRK","CS_MrsPhillips","CS_MRS_Thornhill",
		"CS_Natalia","CS_NervousRon","CS_Nigel","CS_Old_Man1A","CS_Old_Man2","CS_Omega","CS_Orleans","CS_Paper","CS_Patricia","CS_Priest","CS_ProlSec_02","CS_RussianDrunk","CS_SiemonYetarian","CS_Solomon","CS_SteveHains","CS_Stretch",
		"CS_Tanisha","CS_TaoCheng","CS_TaosTranslator","CS_TennisCoach","CS_Terry","CS_Tom","CS_TomEpsilon","CS_TracyDiSanto","CS_Wade","CS_Zimbor","G_F_Y_ballas_01","G_F_Y_Families_01","G_F_Y_Lost_01","G_F_Y_Vagos_01","G_M_M_ArmBoss_01",
		"G_M_M_ArmGoon_01","G_M_M_ArmLieut_01","G_M_M_ChemWork_01","G_M_M_ChiBoss_01","G_M_M_ChiCold_01","G_M_M_ChiGoon_01","G_M_M_ChiGoon_02","G_M_M_KorBoss_01","G_M_M_MexBoss_01","G_M_M_MexBoss_02","G_M_Y_ArmGoon_02","G_M_Y_Azteca_01",
		"G_M_Y_BallaEast_01","G_M_Y_BallaOrig_01","G_M_Y_BallaSout_01","G_M_Y_FamCA_01","G_M_Y_FamDNF_01","G_M_Y_FamFor_01","G_M_Y_Korean_01","G_M_Y_Korean_02","G_M_Y_KorLieut_01","G_M_Y_Lost_01","G_M_Y_Lost_02","G_M_Y_Lost_03",
		"G_M_Y_MexGang_01","G_M_Y_MexGoon_01","G_M_Y_MexGoon_02","G_M_Y_MexGoon_03","G_M_Y_PoloGoon_01","G_M_Y_PoloGoon_02","G_M_Y_SalvaBoss_01","G_M_Y_SalvaGoon_01","G_M_Y_SalvaGoon_02","G_M_Y_SalvaGoon_03","G_M_Y_StrPunk_01","G_M_Y_StrPunk_02",
		"HC_Driver","HC_Gunman","HC_Hacker","IG_Abigail","IG_AmandaTownley","IG_Andreas","IG_Ashley","IG_BallasOG","IG_Bankman","IG_Barry","IG_BestMen","IG_Beverly","IG_Brad","IG_Bride","IG_Car3guy1","IG_Car3guy2","IG_Casey",
		"IG_Chef","IG_ChengSr","IG_ChrisFormage","IG_Clay","IG_ClayPain","IG_Cletus","IG_Dale","IG_DaveNorton","IG_Denise","IG_Devin","IG_Dom","IG_Dreyfuss","IG_DrFriedlander","IG_Fabien","IG_FBISuit_01","IG_Floyd","IG_Groom",
		"IG_Hao","IG_Hunter","IG_Janet","ig_JAY_Norris","IG_JewelAss","IG_JimmyBoston","IG_JimmyDiSanto","IG_JoeMinuteMan","ig_JohnnyKlebitz","IG_Josef","IG_Josh","IG_KerryMcIntosh","IG_LamarDavis","IG_Lazlow","IG_LesterCrest",
		"IG_LifeInvad_01","IG_LifeInvad_02","IG_Magenta","IG_Manuel","IG_Marnie","IG_MaryAnn","IG_Maude","IG_Michelle","IG_Milton","IG_Molly","IG_MRK","IG_MrsPhillips","IG_MRS_Thornhill","IG_Natalia","IG_NervousRon","IG_Nigel",
		"IG_Old_Man1A","IG_Old_Man2","IG_Omega","IG_ONeil","IG_Orleans","IG_Ortega","IG_Paper","IG_Patricia","IG_Priest","IG_ProlSec_02","IG_Ramp_Gang","IG_Ramp_Hic","IG_Ramp_Hipster","IG_Ramp_Mex","IG_RoccoPelosi","IG_RussianDrunk",
		"IG_Screen_Writer","IG_SiemonYetarian","IG_Solomon","IG_SteveHains","IG_Stretch","IG_Talina","IG_Tanisha","IG_TaoCheng","IG_TaosTranslator","ig_TennisCoach","IG_Terry","IG_TomEpsilon","IG_Tonya","IG_TracyDiSanto","IG_TrafficWarden",
		"IG_TylerDix","IG_Wade","IG_Zimbor","MP_F_DeadHooker","MP_F_Freemode_01","MP_F_Misty_01","MP_F_StripperLite","MP_G_M_Pros_01","MP_HeadTargets","MP_M_Claude_01","MP_M_ExArmy_01","MP_M_FamDD_01","MP_M_FIBSec_01","MP_M_Freemode_01",
		"MP_M_Marston_01","MP_M_Niko_01","MP_M_ShopKeep_01","MP_S_M_Armoured_01","Player_One","Player_Two","Player_Zero","slod_human","slod_large_quadped","slod_small_quadped","S_F_M_Fembarber","S_F_M_Maid_01","S_F_M_Shop_HIGH",
		"S_F_M_SweatShop_01","S_F_Y_AirHostess_01","S_F_Y_Bartender_01","S_F_Y_Baywatch_01","S_F_Y_Cop_01","S_F_Y_Factory_01","S_F_Y_Hooker_01","S_F_Y_Hooker_02","S_F_Y_Hooker_03","S_F_Y_Migrant_01","S_F_Y_MovPrem_01","S_F_Y_Ranger_01",
		"S_F_Y_Scrubs_01","S_F_Y_Sheriff_01","S_F_Y_Shop_LOW","S_F_Y_Shop_MID","S_F_Y_StripperLite","S_F_Y_Stripper_01","S_F_Y_Stripper_02","S_F_Y_SweatShop_01","S_M_M_AmmuCountry","S_M_M_Armoured_01","S_M_M_Armoured_02","S_M_M_AutoShop_01",
		"S_M_M_AutoShop_02","S_M_M_Bouncer_01","S_M_M_ChemSec_01","S_M_M_CIASec_01","S_M_M_CntryBar_01","S_M_M_DockWork_01","S_M_M_Doctor_01","S_M_M_FIBOffice_01","S_M_M_FIBOffice_02","S_M_M_Gaffer_01","S_M_M_Gardener_01","S_M_M_GenTransport",
		"S_M_M_HairDress_01","S_M_M_HighSec_01","S_M_M_HighSec_02","S_M_M_Janitor","S_M_M_LatHandy_01","S_M_M_LifeInvad_01","S_M_M_Linecook","S_M_M_LSMetro_01","S_M_M_Mariachi_01","S_M_M_Marine_01","S_M_M_Marine_02","S_M_M_Migrant_01",
		"S_M_M_MovAlien_01","S_M_M_MovPrem_01","S_M_M_MovSpace_01","S_M_M_Paramedic_01","S_M_M_Pilot_01","S_M_M_Pilot_02","S_M_M_Postal_01","S_M_M_Postal_02","S_M_M_PrisGuard_01","S_M_M_Scientist_01","S_M_M_Security_01","S_M_M_SnowCop_01",
		"S_M_M_StrPerf_01","S_M_M_StrPreach_01","S_M_M_StrVend_01","S_M_M_Trucker_01","S_M_M_UPS_01","S_M_M_UPS_02","S_M_O_Busker_01","S_M_Y_AirWorker","S_M_Y_AmmuCity_01","S_M_Y_ArmyMech_01","S_M_Y_Autopsy_01","S_M_Y_Barman_01","S_M_Y_BayWatch_01",
		"S_M_Y_BlackOps_01","S_M_Y_BlackOps_02","S_M_Y_BlackOps_03","S_M_Y_BusBoy_01","S_M_Y_Chef_01","S_M_Y_Clown_01","S_M_Y_Construct_01","S_M_Y_Construct_02","S_M_Y_Cop_01","S_M_Y_Dealer_01","S_M_Y_DevinSec_01","S_M_Y_DockWork_01","S_M_Y_Doorman_01",
		"S_M_Y_DWService_01","S_M_Y_DWService_02","S_M_Y_Factory_01","S_M_Y_Fireman_01","S_M_Y_Garbage","S_M_Y_Grip_01","S_M_Y_HwayCop_01","S_M_Y_Marine_01","S_M_Y_Marine_02","S_M_Y_Marine_03","S_M_Y_Mime","S_M_Y_PestCont_01",
		"S_M_Y_Pilot_01","S_M_Y_PrisMuscl_01","S_M_Y_Prisoner_01","S_M_Y_Ranger_01","S_M_Y_Robber_01","S_M_Y_Sheriff_01","S_M_Y_Shop_MASK","S_M_Y_StrVend_01","S_M_Y_Swat_01","S_M_Y_USCG_01","S_M_Y_Valet_01","S_M_Y_Waiter_01",
		"S_M_Y_WinClean_01","S_M_Y_XMech_01","S_M_Y_XMech_02","U_F_M_Corpse_01","U_F_M_Miranda","U_F_M_ProMourn_01","U_F_O_MovieStar","U_F_O_ProlHost_01","U_F_Y_BikerChic","U_F_Y_COMJane","U_F_Y_corpse_01","U_F_Y_corpse_02",
		"U_F_Y_HotPosh_01","U_F_Y_JewelAss_01","U_F_Y_Mistress","U_F_Y_PoppyMich","U_F_Y_Princess","U_F_Y_SpyActress","U_M_M_Aldinapoli","U_M_M_BankMan","U_M_M_BikeHire_01","U_M_M_FIBArchitect","U_M_M_FilmDirector","U_M_M_GlenStank_01",
		"U_M_M_Griff_01","U_M_M_Jesus_01","U_M_M_JewelSec_01","U_M_M_JewelThief","U_M_M_MarkFost","U_M_M_PartyTarget","U_M_M_ProlSec_01","U_M_M_ProMourn_01","U_M_M_RivalPap","U_M_M_SpyActor","U_M_M_WillyFist","U_M_O_FinGuru_01",
		"U_M_O_TapHillBilly","U_M_O_Tramp_01","U_M_Y_Abner","U_M_Y_AntonB",	"U_M_Y_BabyD","U_M_Y_Baygor","U_M_Y_BurgerDrug_01","U_M_Y_Chip","U_M_Y_Cyclist_01","U_M_Y_FIBMugger_01","U_M_Y_Guido_01","U_M_Y_GunVend_01","U_M_Y_Hippie_01",
		"U_M_Y_ImpoRage","U_M_Y_Justin","U_M_Y_Mani","U_M_Y_MilitaryBum","U_M_Y_Paparazzi","U_M_Y_Party_01","U_M_Y_Pogo_01","U_M_Y_Prisoner_01","U_M_Y_ProlDriver_01","U_M_Y_RSRanger_01","U_M_Y_SBike","U_M_Y_StagGrm_01","U_M_Y_Tattoo_01",
		"U_M_Y_Zombie_01",
	};
	static const char* AFTERHOURS[] = {
		"BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
		"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
		"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
		"TITAN", "VELUM", "VELUM2", "VESTRA", "BOMBUSHKA",
		"ALPHAZ1", "TULA", "ROGUE", "PYRO", "MOGUL",
		"NOKOTA", "MOLOTOK", "SEABREEZE", "MICROLIGHT", "HOWARD",
		"STARLING", "AVENGER2", "VOLATOL", "STRIKEFORCE"
	};
	int getInputs()
	{
		MISC::DISPLAY_ONSCREEN_KEYBOARD(true, (char*)"Input", (char*)"", (char*)"", (char*)"", (char*)"", (char*)"", 20);
		while (MISC::UPDATE_ONSCREEN_KEYBOARD() == 0)
		{

		}
		if (!MISC::GET_ONSCREEN_KEYBOARD_RESULT())
			return 0;
		return stoi(MISC::GET_ONSCREEN_KEYBOARD_RESULT());
	}

	Vector3 CombineVector(float x, float y, float z)
	{
		Vector3 returnVector;
		returnVector.x = x;
		returnVector.y = y;
		returnVector.z = z;
		return returnVector;
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
	int NumberKeyboard() {
		MISC::DISPLAY_ONSCREEN_KEYBOARD(1, "", "", "", "", "", "", 10);
		while (MISC::UPDATE_ONSCREEN_KEYBOARD() == 0);
		if (!MISC::GET_ONSCREEN_KEYBOARD_RESULT()) return 0;
		return atof(MISC::GET_ONSCREEN_KEYBOARD_RESULT());
	}
	bool IsKeyboardActive;
	/// Notify
	////
	int testa = 0;
	int testb = 0;
	int testc = 0;
	int testd = 0;
	int teste = 0;
	int testf = 0;
	int testg = 0;
	int testh = 0;
	int testi = 0;
	int testj = 0;
	int testk = 0;
	int testl = 0;
	int testm = 0;
	int testn = 0;
	int testo = 0;
	bool Elite = false;
	int32_t Spoiler, FBumper, RBumper, SSkirt, Exhaust, Grille, Chasis, Hood, Fender, RFender, Roof, Engine, Brakes, Transmission, Horns, Suspension, Armor, Turbo, TSmoke, Xenon, Wheels, Windows, Plateholder, Vanity, Trims, Ornaments, Dashboard, Dial, DoorSpeaker, Seats, SteeringWheel, Shifter, Plaques, Speakers, Trunk, Hydraulics, EngineBlock, Filter, Struts, Arch, Aerials, TrimTwo, Tank, Livery = 0;
	std::string get_all_asi_files(std::string asi_path)
	{
		std::string asi_list{};
		for (auto& p : fs::recursive_directory_iterator(asi_path))
		{
			if (p.path().extension() == ".asi")
			{//
				asi_list = p.path().string();
			}
		}
		return asi_list;
	}
	enum eVehicleMod
	{
		VehicleModSpoilers = 0,
		VehicleModFrontBumper = 1,
		VehicleModRearBumper = 2,
		VehicleModSideSkirt = 3,
		VehicleModExhaust = 4,
		VehicleModFrame = 5,
		VehicleModGrille = 6,
		VehicleModHood = 7,
		VehicleModFender = 8,
		VehicleModRightFender = 9,
		VehicleModRoof = 10,
		VehicleModEngine = 11,
		VehicleModBrakes = 12,
		VehicleModTransmission = 13,
		VehicleModHorns = 14,
		VehicleModSuspension = 15,
		VehicleModArmor = 16,
		VehicleModFrontWheels = 23,
		VehicleModBackWheels = 24 // only for motocycles
	};
	enum VehicleModTypes
	{
		MOD_SPOILER = 0,
		MOD_FRONTBUMPER = 1,
		MOD_REARBUMPER = 2,
		MOD_SIDESKIRT = 3,
		MOD_EXHAUST = 4,
		MOD_CHASSIS = 5, // or roll cage
		MOD_GRILLE = 6,
		MOD_HOOD = 7,
		MOD_FENDER = 8,
		MOD_RIGHTFENDER = 9,
		MOD_ROOF = 10,
		MOD_ENGINE = 11,
		MOD_BRAKES = 12,
		MOD_TRANSMISSION = 13,
		MOD_HORNS = 14,
		MOD_SUSPENSION = 15,
		MOD_ARMOR = 16,
		MOD_UNK17 = 17, // ModToggleTurbo use 18
		MOD_TURBO = 18,
		MOD_UNK19 = 19, // ModToggleTireSmoke use 20
		MOD_TIRESMOKE = 20,
		MOD_UNK21 = 21, // ModToggleXenon use 22
		MOD_XENONLIGHTS = 22,
		MOD_FRONTWHEELS = 23,
		MOD_BACKWHEELS = 24, // Bikes only

		// Benny's
		MOD_PLATEHOLDER = 25,
		MOD_VANITY_PLATES = 26,
		MOD_TRIM = 27,
		MOD_ORNAMENTS = 28,
		MOD_DASHBOARD = 29,
		MOD_DIAL = 30,
		MOD_DOOR_SPEAKER = 31,
		MOD_SEATS = 32,
		MOD_STEERINGWHEEL = 33,
		MOD_SHIFTER_LEAVERS = 34,
		MOD_PLAQUES = 35,
		MOD_SPEAKERS = 36,
		MOD_TRUNK = 37,
		MOD_HYDRULICS = 38,
		MOD_ENGINE_BLOCK = 39,
		MOD_AIR_FILTER = 40,
		MOD_STRUTS = 41,
		MOD_ARCH_COVER = 42,
		MOD_AERIALS = 43,
		MOD_TRIM_2 = 44,
		MOD_TANK = 45,
		MOD_WINDOWS = 46,
		MOD_UNK47 = 47, // idk
		MOD_LIVERY = 48,
	};
	int attachobj22[100];
	int nuattach22 = 1;
	void attachobjects222(char* object)
	{
		for (int i = 0; i < 32; i++)
		{
			int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
			{

				Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				bool custom = false;
				int hash = 0;
				NativeVector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
				hash = MISC::GET_HASH_KEY(object);
				if (STREAMING::IS_MODEL_IN_CDIMAGE(hash))
				{
					if (STREAMING::IS_MODEL_VALID(hash))
					{
						STREAMING::REQUEST_MODEL(hash);
						if (STREAMING::HAS_MODEL_LOADED(hash))
						{
							attachobj22[nuattach22] = OBJECT::CREATE_OBJECT(hash, playerPosition.x, playerPosition.y, playerPosition.z, 1, 1, 1);
							if (ENTITY::DOES_ENTITY_EXIST(attachobj22[nuattach22]))
							{
								ENTITY::ATTACH_ENTITY_TO_ENTITY(attachobj22[nuattach22], PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 31086, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
								nuattach22++;
								if (nuattach22 >= 101) { nuattach22 = 1; }
							}
						}
					}

				}
			}
		}
	}
	bool Modders[32];
	bool IsPlayerFriend(int player)
	{
		BOOL BplayerFriend = false;
		bool bplayerFriend = false;
		int handle[76]; //var num3 = sub_34009(A_0, (A_1) + 264, (A_1) + 272);
		NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, &handle[0], 13);
		if (NETWORK::NETWORK_IS_HANDLE_VALID(&handle[0], 13))
		{
			BplayerFriend = NETWORK::NETWORK_IS_FRIEND(&handle[0]);
		}
		if (BplayerFriend == 1)
			bplayerFriend = true;
		else
			bplayerFriend = false;

		return bplayerFriend;
	}
	std::string PlayerName(int Player) {
		if (IsPlayerFriend(Player)) {
			if (Modders[Player])
			{
				return PLAYER::GET_PLAYER_NAME(Player) + (std::string)" ~b~[FRIEND] ~l~[HOST]";
			}
			return PLAYER::GET_PLAYER_NAME(Player) + (std::string)" ~b~[FRIEND]";
		}
		else {
			if (Modders[Player])
			{
				return PLAYER::GET_PLAYER_NAME(Player) + (std::string)" ~l~[HOST]";
			}
			return PLAYER::GET_PLAYER_NAME(Player);
		}
	}
	int Join = 0;
	bool Joiner;
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
	void spawn_vehicle(const char* toSpawn, Ped player) {
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.3, false, false, false);
		Hash model = MISC::GET_HASH_KEY(toSpawn);
		if (STREAMING::IS_MODEL_VALID(model)) {
			g_CallbackScript->AddCallback<ModelCallback>(model, [model, player] {
				NativeVector3 ourCoords = ENTITY::GET_ENTITY_COORDS(player, false);
				float heading = ENTITY::GET_ENTITY_HEADING(player);
				ourCoords.x + 5;
				//Vehicle veh = VEHICLE::CREATE_VEHICLE(model, heading, *g_GameVariables->is_session_started, false, false, false, false, false);
				//VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh, false);
				//DECORATOR::DECOR_SET_INT(veh, (char*)"MPBitset", 0);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
				if (player == PLAYER::PLAYER_PED_ID()) {
					//VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					for (int i = 0; i < 50; i++) {
						//VEHICLE::SET_VEHICLE_MOD(veh, i, VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) - 1, false);
					}
				}

				});
		}
		else
		{
		}
	}
	void spawn_veh(const char* vehModel, Ped player) {
		Hash model = MISC::GET_HASH_KEY(vehModel);
		if (STREAMING::IS_MODEL_VALID(model))
		{
			g_CallbackScript->AddCallback<ModelCallback>(model, [model, player] {
				PVOID object_spawn_bypass;
				NativeVector3 ourCoords = ENTITY::GET_ENTITY_COORDS(player, false);
				float heading = ENTITY::GET_ENTITY_HEADING(player);
				ourCoords.x + 5;
				//Vehicle veh = VEHICLE::CREATE_VEHICLE(model, heading, NETWORK::NETWORK_IS_SESSION_STARTED(), false, false, true, false, false);
				//VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh, false);
				//DECORATOR::DECOR_SET_INT(veh, (char*)"MPBitset", 0);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
				});
		}
	}
	Vector3 TPCoords;
	void TPto(Vector3 Coords)
		{
			int Handle = PLAYER::PLAYER_PED_ID();
			if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
			{
				ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(Handle, false), Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
			}
			else
				ENTITY::SET_ENTITY_COORDS(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
		}
	void Yankton()
		{
	
			if (STREAMING::IS_IPL_ACTIVE((char*)"prologue01"))
			{
				STREAMING::IS_IPL_ACTIVE((char*)"prologue01");
				STREAMING::IS_IPL_ACTIVE((char*)"Prologue01c");
				STREAMING::IS_IPL_ACTIVE((char*)"Prologue01d");
				STREAMING::IS_IPL_ACTIVE((char*)"Prologue01e");
				STREAMING::IS_IPL_ACTIVE((char*)"Prologue01f");
				STREAMING::IS_IPL_ACTIVE((char*)"Prologue01g");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue01h");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue01i");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue01j");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue01k");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue01z");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue02");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue03");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue03b");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue03_grv_cov");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue03_grv_dug");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue03_grv_fun");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue04");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue04b");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue04_cover");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue05");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue05b");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue06");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue06b");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue06_int");
				STREAMING::IS_IPL_ACTIVE((char*)"prologuerd");
				STREAMING::IS_IPL_ACTIVE((char*)"prologuerdb");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue_DistantLights");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue_grv_torch");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue_m2_door");
				STREAMING::IS_IPL_ACTIVE((char*)"prologue_LODLights");
				STREAMING::IS_IPL_ACTIVE((char*)"DES_ProTree_start");
				return;
			}
			STREAMING::REQUEST_IPL((char*)"prologue01");
			STREAMING::REQUEST_IPL((char*)"Prologue01c");
			STREAMING::REQUEST_IPL((char*)"Prologue01d");
			STREAMING::REQUEST_IPL((char*)"Prologue01e");
			STREAMING::REQUEST_IPL((char*)"Prologue01f");
			STREAMING::REQUEST_IPL((char*)"Prologue01g");
			STREAMING::REQUEST_IPL((char*)"prologue01h");
			STREAMING::REQUEST_IPL((char*)"prologue01i");
			STREAMING::REQUEST_IPL((char*)"prologue01j");
			STREAMING::REQUEST_IPL((char*)"prologue01k");
			STREAMING::REQUEST_IPL((char*)"prologue01z");
			STREAMING::REQUEST_IPL((char*)"prologue02");
			STREAMING::REQUEST_IPL((char*)"prologue03");
			STREAMING::REQUEST_IPL((char*)"prologue03b");
			STREAMING::REQUEST_IPL((char*)"prologue03_grv_cov");
			STREAMING::REQUEST_IPL((char*)"prologue03_grv_dug");
			STREAMING::REQUEST_IPL((char*)"prologue03_grv_fun");
			STREAMING::REQUEST_IPL((char*)"prologue04");
			STREAMING::REQUEST_IPL((char*)"prologue04b");
			STREAMING::REQUEST_IPL((char*)"prologue04_cover");
			STREAMING::REQUEST_IPL((char*)"prologue05");
			STREAMING::REQUEST_IPL((char*)"prologue05b");
			STREAMING::REQUEST_IPL((char*)"prologue06");
			STREAMING::REQUEST_IPL((char*)"prologue06b");
			STREAMING::REQUEST_IPL((char*)"prologue06_int");
			STREAMING::REQUEST_IPL((char*)"prologuerd");
			STREAMING::REQUEST_IPL((char*)"prologuerdb");
			STREAMING::REQUEST_IPL((char*)"prologue_DistantLights");
			STREAMING::REQUEST_IPL((char*)"prologue_grv_torch");
			STREAMING::REQUEST_IPL((char*)"prologue_m2_door");
			STREAMING::REQUEST_IPL((char*)"prologue_LODLights");
			STREAMING::REQUEST_IPL((char*)"DES_ProTree_start");
			Vector3 Coords;
			Coords.x = 3595.39673f; Coords.y = -4893.727f; Coords.z = 115.838394f;
			TPto(Coords);
		}
	void Yacht()
		{
			if (STREAMING::IS_IPL_ACTIVE((char*)"smboat"))
			{
				STREAMING::IS_IPL_ACTIVE((char*)"smboat");
				return;
			}
			STREAMING::REQUEST_IPL((char*)"smboat");
			Vector3 Coords;
			Coords.x = -2045.8f; Coords.y = -1031.2f; Coords.z = 11.9f;
			TPto(Coords);
		}
	void Carrier()
		{
			
			if (STREAMING::IS_IPL_ACTIVE((char*)"hei_carrier"))
			{
				STREAMING::IS_IPL_ACTIVE((char*)"hei_carrier");
				STREAMING::IS_IPL_ACTIVE((char*)"hei_carrier_DistantLights");
				STREAMING::IS_IPL_ACTIVE((char*)"hei_Carrier_int1");
				STREAMING::IS_IPL_ACTIVE((char*)"hei_Carrier_int2");
				STREAMING::IS_IPL_ACTIVE((char*)"hei_Carrier_int3");
				STREAMING::IS_IPL_ACTIVE((char*)"hei_Carrier_int4");
				STREAMING::IS_IPL_ACTIVE((char*)"hei_Carrier_int5");
				STREAMING::IS_IPL_ACTIVE((char*)"hei_Carrier_int6");
				STREAMING::IS_IPL_ACTIVE((char*)"hei_carrier_LODLights");
				return;
			}
			STREAMING::REQUEST_IPL((char*)"hei_carrier");
			STREAMING::REQUEST_IPL((char*)"hei_carrier_DistantLights");
			STREAMING::REQUEST_IPL((char*)"hei_Carrier_int1");
			STREAMING::REQUEST_IPL((char*)"hei_Carrier_int2");
			STREAMING::REQUEST_IPL((char*)"hei_Carrier_int3");
			STREAMING::REQUEST_IPL((char*)"hei_Carrier_int4");
			STREAMING::REQUEST_IPL((char*)"hei_Carrier_int5");
			STREAMING::REQUEST_IPL((char*)"hei_Carrier_int6");
			STREAMING::REQUEST_IPL((char*)"hei_carrier_LODLights");
			Vector3 Coords;
			Coords.x = 3069.330f; Coords.y = -4632.4f; Coords.z = 15.043f;
			TPto(Coords);
		}
	void SunkenShip()
		{

			if (STREAMING::IS_IPL_ACTIVE((char*)"sunkcargoship"))
			{
				STREAMING::IS_IPL_ACTIVE((char*)"sunkcargoship");
				return;
			}
			STREAMING::REQUEST_IPL((char*)"sunkcargoship");
			Vector3 Coords;
			Coords.x = -162.8918f; Coords.y = -2365.769f; Coords.z = 0.0f;
			TPto(Coords);
		}
	void Hospital()
		{
			if (STREAMING::IS_IPL_ACTIVE((char*)"RC12B_HospitalInterior"))
			{
				STREAMING::IS_IPL_ACTIVE((char*)"RC12B_HospitalInterior");
				STREAMING::IS_IPL_ACTIVE((char*)"RC12B_Destroyed");
				return;
			}
			STREAMING::REQUEST_IPL((char*)"RC12B_HospitalInterior");
			STREAMING::REQUEST_IPL((char*)"RC12B_Destroyed");
			Vector3 Coords;
			Coords.x = 356.8f; Coords.y = -590.1f; Coords.z = 43.3f;
			TPto(Coords);
		}
	void Farm()
		{
			if (STREAMING::IS_IPL_ACTIVE((char*)"farm_burnt"))
			{
				STREAMING::IS_IPL_ACTIVE((char*)"farm_burnt");
				STREAMING::IS_IPL_ACTIVE((char*)"farm_burnt_props");
				STREAMING::IS_IPL_ACTIVE((char*)"farm");
				STREAMING::IS_IPL_ACTIVE((char*)"farm_props");
				STREAMING::IS_IPL_ACTIVE((char*)"farmint");
				STREAMING::IS_IPL_ACTIVE((char*)"farmint_cap");
				
				return;
			}
			STREAMING::REQUEST_IPL((char*)"farm_burnt");
			STREAMING::REQUEST_IPL((char*)"farm_burnt_props");
			STREAMING::REQUEST_IPL((char*)"farm");
			STREAMING::REQUEST_IPL((char*)"farm_props");
			STREAMING::REQUEST_IPL((char*)"farmint");
			STREAMING::REQUEST_IPL((char*)"farmint_cap");
			Vector3 Coords;
			Coords.x = 2441.2f; Coords.y = 4968.5f; Coords.z = 51.7f;
			TPto(Coords);
		}
	void Morgue()
		{
			if (STREAMING::IS_IPL_ACTIVE((char*)"Coroner_Int_on"))
			{
				STREAMING::IS_IPL_ACTIVE((char*)"Coroner_Int_on");
				
				return;
			}
			STREAMING::REQUEST_IPL((char*)"Coroner_Int_on");
			Vector3 Coords;
			Coords.x = 244.9f; Coords.y = -1374.7f; Coords.z = 39.5f;
			TPto(Coords);
		}
	void Jewelry()
		{
			if (STREAMING::IS_IPL_ACTIVE((char*)"jewel2fake"))
			{
				STREAMING::IS_IPL_ACTIVE((char*)"jewel2fake");
				STREAMING::IS_IPL_ACTIVE((char*)"post_hiest_unload");
				STREAMING::IS_IPL_ACTIVE((char*)"bh1_16_refurb");
				return;
			}
			STREAMING::REQUEST_IPL((char*)"jewel2fake");
			STREAMING::REQUEST_IPL((char*)"post_hiest_unload");
			STREAMING::REQUEST_IPL((char*)"bh1_16_refurb");
			Vector3 Coords;
			Coords.x = -630.4f; Coords.y = -236.7f; Coords.z = 40.0f;
			TPto(Coords);
		}
	void Invader()
		{
			STREAMING::REQUEST_IPL((char*)"facelobby");
			STREAMING::REQUEST_IPL((char*)"facelobbyfake");
			Vector3 Coords;
			Coords.x = -1047.9f; Coords.y = -233.0f; Coords.z = 39.0f;
			TPto(Coords);
		}
	//NETCARS
	void maxvehiclee()
	{
		NativeVector3 targetCords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), false);
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
		for (int i = 0; i < 50; i++)
		{
			VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
		}
	}
	void highhhh()
	{
		NativeVector3 targetCords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), false);
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 99999888888.0f, 0, 0, 0, true, true, true, true, false, true);
	}
	void fixcar12()
	{
		NativeVector3 targetCords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), false);
		int Vehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
		VEHICLE::SET_VEHICLE_FIXED(Vehicle);
		VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(Vehicle);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(Vehicle, 0);
	}
	void stoppiii()
	{
		NativeVector3 targetCords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), false);
		VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 0);
	}
	void killplayer()
	{
		NativeVector3 targetCords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), false);
		ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 0, 0);
	}
	void JoinCrew(Player player)
	{
		int clanId;
		int desc;
		NETWORK::NETWORK_CLAN_PLAYER_GET_DESC(&desc, 35, &clanId);
		if (NETWORK::NETWORK_CLAN_JOIN(clanId)) {
			NETWORK::NETWORK_CLAN_JOIN(clanId);
		}
	}
	void vision1()
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("DEFAULT");
	}	
	void vision2() 
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("Drunk");
	}
	void vision3()
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("stoned");
	}
	void vision4()
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("REDMIST");
	}
	void vision5()
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("DEATH");
	}
	void vision6()
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("drug_flying_base");
	}
	void vision7()
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("DRUG_gas_huffin");
	}
	void vision8()
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("drug_wobbly");
	}
	void vision9()
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("Bloom");
	}
	void vision11()
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("PlayerSwitchPulse");
	}
	void vision12()
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("player_transition");
	}
	void vision13()
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("cinema_001");
	}
	void vision14()
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("CHOP");
	}
	void vision15()
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("Blurry");
	}
	void vision16()
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("BarryFadeOut");
	}
	///Self
	int level;
	int timeerlevelcc = 0;
	void settimechangcc()
		{
			MISC::SET_FAKE_WANTED_LEVEL(timeerlevelcc);
		}
	void goup()
	{
		NativeVector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 0.0, 100.0);
		int Handle = PLAYER::PLAYER_PED_ID();
		if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
			Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	}
	void clearplayer()
	{
		PED::CLEAR_PED_BLOOD_DAMAGE(PLAYER::PLAYER_PED_ID());
	}
	void kill()
	{
		ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 0, 0);
	}
	bool GravityBool = false;
	void Gravity()
	{
		MISC::SET_GRAVITY_LEVEL(GravityBool ? 2 : 0);
	}
	bool Tinyplayerbool = false;
	void Tinyplayer()
	{
		PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), 223, Tinyplayerbool);
	}
	bool Godmodebool = false;
	void godmode()
	{
		if (Godmodebool)
			ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), true);
		else
			ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false);
	}
	bool SlowMoBool = false;
	void SlowMo()
	{
		if (SlowMoBool)
			MISC::SET_TIME_SCALE(0.2);
		else
			MISC::SET_TIME_SCALE(1);
	}
	bool Ragdoll = false;
	void ragdoll()
	{
		if (Ragdoll)
		{
			Ped PLAYER_PED_ID = PLAYER::PLAYER_PED_ID();
			Player PLAYER_ID = PLAYER::PLAYER_ID();
			PED::SET_PED_CAN_RAGDOLL(PLAYER_PED_ID, false);
			PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER_PED_ID, false);
			PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER_PED_ID, false);
			PLAYER::GIVE_PLAYER_RAGDOLL_CONTROL(PLAYER_ID, true);
			PED::SET_PED_RAGDOLL_ON_COLLISION(PLAYER_PED_ID, false);
		}
		else
		{
			Ped PLAYER_PED_ID = PLAYER::PLAYER_PED_ID();
			Player PLAYER_ID = PLAYER::PLAYER_ID();
			PED::SET_PED_CAN_RAGDOLL(PLAYER_PED_ID, true);
			PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER_PED_ID, true);
			PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER_PED_ID, true);
			PLAYER::GIVE_PLAYER_RAGDOLL_CONTROL(PLAYER_ID, false);
			PED::SET_PED_RAGDOLL_ON_COLLISION(PLAYER_PED_ID, true);

		}
	}
	bool Forcefeldd = false;
	void forcefeldd()
	{
		if (Forcefeldd)
		{
			const int numElements = 100;
			const int arrSize = numElements * 2 + 2;
			Vehicle veh[arrSize];
			veh[0] = numElements;
			("rcmpaparazzo_4", "lift_hands_in_air_loop");
			int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
			if (veh != NULL)
			{
				for (int i = 1; i <= count; i++)
				{
					int offsettedID = i;
					if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
					{
						ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 0, 0, 0, 9999, 0, 0, 0, 0, false, false, true, true, true);

					}
				}
			}
		}
	}
	void maxalive()
	{
		ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 400, 0);
	}
	void MaxPlayer()
	{
		ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 400, 0);
		PED::ADD_ARMOUR_TO_PED(PLAYER::PLAYER_PED_ID(), 200);
	}
	void Fixplayer()
	{
		PED::CLEAR_PED_BLOOD_DAMAGE(PLAYER::PLAYER_PED_ID());
	}
	void clearwandet()
	{
		Entity player = PLAYER::PLAYER_PED_ID();
		if (clearwandet)
		{
			PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
			PLAYER::SET_MAX_WANTED_LEVEL(0);
			PLAYER::SET_POLICE_IGNORE_PLAYER(player, true);
			PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(player, false);
			PLAYER::SET_EVERYONE_IGNORE_PLAYER(player, true);
			PLAYER::SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(player, true);
		}
		else
		{
			PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
			PLAYER::SET_MAX_WANTED_LEVEL(5);
			PLAYER::SET_POLICE_IGNORE_PLAYER(player, false);
			PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(player, false);
			PLAYER::SET_EVERYONE_IGNORE_PLAYER(player, false);
			PLAYER::SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(player, false);
		}
	}
	///Network
	void juiceKick()
	{
		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer))) {
			NETWORK::NETWORK_SESSION_KICK_PLAYER(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer));
		}
	}
	int Admins[] = {
	133709045, 64234321, 131973478, 103019313, 103054099, 104041189, 110470958, 119266383, 119958356, 121397532, 121698158, 123839036, 123849404, 121943600, 129159629, 18965281, 216820, 56778561, 99453545, 99453882
	};
	bool RockstarCheck = false;
	void RockstarAdminCheck()
	{
		if (NETWORK::NETWORK_IS_SESSION_ACTIVE())
		{

			for (int i = 0; i < 32; i++)
			{
				int netHandle[13];
				NETWORK::NETWORK_HANDLE_FROM_PLAYER(i, netHandle, 13);
				uint64_t UserID = (uint64_t)NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&netHandle[0]);
				{
					{
						g_Logger->Error("Rockstar Admin Is Joining ");
						notifyMap("Rockstar Admin Is Joining ");
					}
				}
			}
		}
		else
		{
			g_Logger->Error("Pls Get out the Lobby! ");
			notifyMap("Pls Get out the Lobby! ");
		}
	}
	bool OrbitalCooldownBool = false;
	void OrbitalCooldown()
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ORBITAL_CANNON_COOLDOWN"), 0, -1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_ORBITAL_CANNON_COOLDOWN"), 0, -1);
	}

	void ceokick()
	{
	}
	void ceoban()
	{
	}
	bool DevMode = false;
	void dev()
		// (CNetGamePlayers int unk1, bool unk2) { static tSetWanted oSetWanted = ()(Memory::pattern("48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 44 88 48 20 57 41 54 41 55 41 56 41 57 48 83 EC 30 4C 8B F1 48 8B 0D ? ? ? ? 44 8B E2 B2 01 41 8A D9 45 8B E8 E8 ? ? ? ? 48 8B 0D ? ? ? ?").count(1).get(0).get<void>()); return oSetWanted(player, level, unk1, unk2); }

	{

	}
	bool badpc = false;
	void bad()
	{

	}
	///VEHICLE
	/*bool Features::free = false;
	void Features::freeCam(bool toggle)
	{
		static bool lock;
		static std::int32_t cam;
		static float dist;
		auto rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		auto coord = CAM::GET_GAMEPLAY_CAM_COORD();
		Vector3 p_coord = { 0,0,0 };
		int Handle = PLAYER::PLAYER_PED_ID();

		if (!CAM::DOES_CAM_EXIST(cam)) {
			cam = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1);
			CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 0);
			CAM::SET_CAM_COORD(cam, coord.x, coord.y, coord.z);
		}
		if (!toggle)
		{
			NativeVector3 camCoords = CAM::GET_CAM_COORD(cam);
			ENTITY::SET_ENTITY_COORDS(Handle, camCoords.x, camCoords.y, camCoords.z, 0, 0, 0, 1);
			CAM::RENDER_SCRIPT_CAMS(false, true, 700, 1, 1, 1);
			CAM::SET_CAM_ACTIVE(cam, 0);
			CAM::DESTROY_CAM(cam, true);
			PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 0);

		}

		CAM::RENDER_SCRIPT_CAMS(true, true, 700, 1, 1, 1);
		CAM::SET_CAM_ACTIVE(cam, 1);
		CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 0);

		p_coord = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);

		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(PLAYER::PLAYER_PED_ID(), p_coord.x, p_coord.y, p_coord.z, 0, 0, 0);
		PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 1);
		UI::HIDE_HUD_AND_RADAR_THIS_FRAME();

		auto speed = .5f;
		if (IsKeyPressed(VK_LSHIFT))
		{
			speed += .3f;
		}

		if (IsKeyPressed(VK_KEY_S))
		{
			speed /= -1;
			auto c = add(&CAM::GET_CAM_COORD(cam), &multiply(&rot_to_direction(&rot), speed));
			CAM::SET_CAM_COORD(cam, c.x, c.y, c.z);
		}

		if (IsKeyPressed(VK_KEY_W))
		{
			auto c = add(&CAM::GET_CAM_COORD(cam), &multiply(&rot_to_direction(&rot), speed));
			CAM::SET_CAM_COORD(cam, c.x, c.y, c.z);
		}
		
	}*/
	void crome() {
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 2.0, false, false, false);
		VEHICLE::SET_VEHICLE_COLOURS(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 120, 120);
	}
	void ChangeCoords(Vector3 Coords)
	{
		int Handle = PLAYER::PLAYER_PED_ID();
		if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
		{
			ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(Handle, false), Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
		}
		else
		{
			ENTITY::SET_ENTITY_COORDS(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
		}
	}
	void print()
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 2.0, false, false, false);
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(VehID, MISC::GET_RANDOM_INT_IN_RANGE(0, 255), MISC::GET_RANDOM_INT_IN_RANGE(0, 255), MISC::GET_RANDOM_INT_IN_RANGE(0, 255));
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(VehID, MISC::GET_RANDOM_INT_IN_RANGE(0, 255), MISC::GET_RANDOM_INT_IN_RANGE(0, 255), MISC::GET_RANDOM_INT_IN_RANGE(0, 255));
	}
	void Front()
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 13.0f, 0, -2.0f, 0, true, true, true, true, false, true);
	}
	void back()
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 13.0f, 0, 2.0f, 0, true, true, true, true, false, true);
	}
	void kickflip()
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 10.0f, 2.0f, 0, 0, true, true, true, true, false, true);
	}
	void HeelFlip()
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 10.0f, -2.0f, 0, 0, true, true, true, true, false, true);
	}
	void sky()
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 40.0f, 0, 0, 0, true, true, true, true, false, true);
	}
	void high()
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 99999888888.0f, 0, 0, 0, true, true, true, true, false, true);
	}
	void CrushVehicle()
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, -40.0f, 0, 0, 0, true, true, true, true, false, true);
	}
	void BunneyHop()
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 7.0f, 0, 0, 0, true, true, true, true, false, true);
	}
	bool cargodmodebool = false;
	void cargodmode()
	{
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		if (cargodmodebool)
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
			{
				ENTITY::SET_ENTITY_INVINCIBLE(vehicle, true);
				VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(vehicle, true);

				for (int i = 0; i < 10; i++)
				{
					try {
						VEHICLE::SET_VEHICLE_TYRE_FIXED(vehicle, i);
					}
					catch (...) {
						return;
					}
				}
			}
		}
		else
		{
			ENTITY::SET_ENTITY_INVINCIBLE(vehicle, false);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(vehicle, false);
		}
	}
	bool hornboostt = false;
	void Hornboostt()
	{
		if (hornboostt)
		{
			if (PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::PLAYER_ID()))
			{
				Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
				NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
				if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
				{
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, 50);
				}
			}
		}
	}
	bool Boost = false;
	void RocketBoost()
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		if (VEHICLE::_GET_HAS_ROCKET_BOOST(veh))
		{
			VEHICLE::_SET_VEHICLE_ROCKET_BOOST_REFILL_TIME(veh, 0);
			VEHICLE::_SET_VEHICLE_ROCKET_BOOST_PERCENTAGE(veh, 100.0f);
		}
	}
	bool InvisibleCarBool = false;
	void InvisibleCar()
	{
		Vehicle Veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
		if (InvisibleCarBool)
			ENTITY::SET_ENTITY_VISIBLE(Veh, false, 0);
		else
			ENTITY::SET_ENTITY_VISIBLE(Veh, true, 0);
	}
	bool vehiclegravitybool = false;
	void vehiclegravity()
	{
		if (vehiclegravitybool)
			MISC::SET_GRAVITY_LEVEL(3);
		else
			MISC::SET_GRAVITY_LEVEL(0);
	}
	void maxvehicle()
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 2.0, false, false, false);
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
		for (int i = 0; i < 50; i++)
		{
			VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
		}
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, false);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, (char*)"Juice");
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(vehicle, 5);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("proj_xmas_firework");
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_clown_appears");
	}
	std::string FloatToString(float flt) {
		std::ostringstream ss;
		ss << flt;
		std::string str(ss.str());
		return str;
	}
	void DeleteVeh()
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		Vehicle pedVeh = PED::GET_VEHICLE_PED_IS_IN(playerPed, FALSE);
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(pedVeh, true, true);
		VEHICLE::DELETE_VEHICLE(&pedVeh);
	}
	void OpenDoors()
	{
		VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0, true, false);
		VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 1, true, false);
		VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 2, true, false);
		VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 3, true, false);
		VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 4, true, false);
		VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 5, true, false);
		VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 6, true, false);
		VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 7, true, false);
	}
	bool mobileRadio = false;
	void mobiletunes() {
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
	bool boostlevel = false;
	void carboost()
	{
		int player = PLAYER::PLAYER_PED_ID();

		if (PED::IS_PED_IN_ANY_VEHICLE(player, 0))
		{
			if (carboost)
			{
				Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
				if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
				{
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, boostlevel);
				}
			}
			if (GetAsyncKeyState(VK_F7))
			{
				Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
				if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
				{
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, 5);
				}
			}
		}
	}
	bool FixLoop;
	void FixCar()
	{
		int Vehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
		VEHICLE::SET_VEHICLE_FIXED(Vehicle);
		VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(Vehicle);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(Vehicle, 0);
	}
	bool MentalStateBool = false;
	void MentalState()
	{
		if (MentalStateBool)
		{
			STATS::STAT_SET_FLOAT(MISC::GET_HASH_KEY("MPPLY_PLAYER_MENTAL_STATE"), 100.0f, 1);
		}
		else
		{
			STATS::STAT_SET_FLOAT(MISC::GET_HASH_KEY("MPPLY_PLAYER_MENTAL_STATE"), 0.00f, 1);

		}
	}
	void open()
	{
		VEHICLE::SET_VEHICLE_DOORS_SHUT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), true);
	}
	void fixcar1()
	{
		int Vehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
		VEHICLE::SET_VEHICLE_FIXED(Vehicle);
		VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(Vehicle);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(Vehicle, 0);
	}
	void stoppi()
	{
		VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 0);

	}
	void AddRamp()
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
		{
			NativeVector3 Him = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
			int VehicleID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true);
			STREAMING::REQUEST_MODEL(0xB157C9E4);
			if (STREAMING::HAS_MODEL_LOADED(0xB157C9E4))
			{
				Entity My_Objects = OBJECT::CREATE_OBJECT(0xB157C9E4, Him.x, Him.y, Him.z, 1, 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(My_Objects))
				{
					ENTITY::SET_ENTITY_COLLISION(My_Objects, true, true);
					ENTITY::SET_ENTITY_ALPHA(My_Objects, 120, false);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(My_Objects, VehicleID, 0, 0, 6.3, -0.3, 13.5, 0, 177.5, 0, 0, true, 0, 2, 1);
				}
			}
		}
		else { notifyMap("You are not in Vehicle"); }
	}
	void TeleportPersonalVehicletome()
	{
		NativeVector3 CoordBlip = HUD::GET_BLIP_INFO_ID_COORD(HUD::GET_FIRST_BLIP_INFO_ID(225));
		int VehicleHandle = VEHICLE::GET_CLOSEST_VEHICLE(CoordBlip.x, CoordBlip.y, CoordBlip.z, 1, 0, 71);
		if (VehicleHandle == 0) {
			NativeVector3 CoordBlipMoto = HUD::GET_BLIP_INFO_ID_COORD(HUD::GET_FIRST_BLIP_INFO_ID(226));
			int VehicleHandleMoto = VEHICLE::GET_CLOSEST_VEHICLE(CoordBlip.x, CoordBlip.y, CoordBlip.z, 1, 0, 71);
			if (VehicleHandleMoto == 0) {
				notifyMap("Could not find personal vehicle.");
			}
			else {
				NativeVector3 me = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				ENTITY::SET_ENTITY_COORDS(VehicleHandleMoto, me.x, me.y + 2, me.z, 1, 1, 1, 1);
			}
		}
		else {
			NativeVector3 me = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			ENTITY::SET_ENTITY_COORDS(VehicleHandle, me.x, me.y + 2, me.z, 1, 1, 1, 1);
		}
	}
	//ALLPLAYERS
	void deletecarplayer(){
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
	bool cstrcmp(const char* s1, const char* s2)
	{
		while (*s1 && (*s1 == *s2))
			s1++, s2++;
		if (*(const unsigned char*)s1 - *(const unsigned char*)s2 == 0)
			return true;
		else
			return false;
	}
	void GiveWepsintheLobby() 
	{
		for (int i = 0; i < 32; i++)
		{
			if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
				Player allplayers = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
				if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")))
				{
					if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) != PLAYER::PLAYER_PED_ID())
					{
						for (int i = 0; i < (sizeof(Weaponss) / 4); i++) {
							WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(allplayers), Weaponss[i], 9999, 1);
							notifyMap("~p~Gta Is Now Not Safe");
						}
					}
				}
			}
		}
	}
	void crash()
	{
		{
			for (int i = 0; i <= 500; i++)
			{
				int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
				if (Handle != PLAYER::PLAYER_PED_ID())
				{
					if (i == g_SelectedPlayer)continue;
					try {
						PED::CLONE_PED(Handle, 1, 1, 1);
						PED::CLONE_PED(Handle, 1, 1, 1);
						PED::CLONE_PED(Handle, 1, 1, 1);
						PED::CLONE_PED(Handle, 1, 1, 1);
						PED::CLONE_PED(Handle, 1, 1, 1);
					}
					catch (...) {
						return;
					}
					{
						if (i == 490)
						{
							break;
						}
					}
				}
			}
		}
	}
	void shj()
	{
		for (int i = 0; i < 32; i++)
		{
			int Me = PLAYER::PLAYER_PED_ID();
			NativeVector3 MyPosition = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Me, 0.0, 0.0, 0.0);
			(MyPosition);
		}
	}
	void allweppl()
	{
		{
			{
				for (int i = 0; i < 32; i++)
				{
					Player playerHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
					Hash crashall = MISC::GET_HASH_KEY("v_proc2_temp");
					spawn_veh,(crashall);
					while (!STREAMING::HAS_MODEL_LOADED(crashall)) SYSTEM::WAIT(0);
					if (ENTITY::DOES_ENTITY_EXIST(playerHandle))
					{
						if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID()) continue;
						{
							Vector3 Coords;
							Coords.x = 496.75f; Coords.y = 5591.17f; Coords.z = 795.03f;
							TPto(Coords);
							Object crashall = OBJECT::CREATE_OBJECT(crashall, 0, 0, 0, true, true, false);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(crashall, playerHandle, PED::GET_PED_BONE_INDEX(playerHandle, crashall), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);
						}
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(crashall);
					}
				}
			}
		}
	}
	Hash $(std::string str) {
		return MISC::GET_HASH_KEY(&str[0u]);
	}
	void CageAll()
	{
		for (int i = 1; i <= 32; i++)
		{
			if (PLAYER::PLAYER_ID() != i)
			{
				NativeVector3 remotePos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 0);
				Object obj = OBJECT::CREATE_OBJECT($("prop_gold_cont_01"), remotePos.x, remotePos.y, remotePos.z - 1.f, true, false, false);
			}
		}

	}
	void axall()
	{
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
	void cloneplayer()
	{
		for (int i = 0; i < 32; i++)
		{
			int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
			{

				PED::CLONE_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 1, 1, 1);

			}
		}
	}
	//player
     void Attachhhhhh() {
		Player player = g_SelectedPlayer;
		if (player != PLAYER::PLAYER_PED_ID())
		{
			ENTITY::ATTACH_ENTITY_TO_ENTITY(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), 0, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, true, true, false, true, 2, true);
		}
	}
	void Detach() {
		 ENTITY::DETACH_ENTITY(PLAYER::PLAYER_PED_ID(), true, true);
	 }
	void trapcagea(int player)
	{
		NativeVector3 remotePos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), 0);
		Object obj = OBJECT::CREATE_OBJECT(MISC::GET_HASH_KEY("prop_elecbox_24"), remotePos.x, remotePos.y, remotePos.z - 1.f, true, false, false);
	}
	void trapcageeeee(int player)
	{
		NativeVector3 remotePos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), 0);
		Object obj = OBJECT::CREATE_OBJECT(MISC::GET_HASH_KEY("prop_fnclink_05c"), remotePos.x, remotePos.y, remotePos.z - 1.f, true, false, false);
	}
	void trapcageeee(int player)
	{
		NativeVector3 remotePos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), 0);
		Object obj = OBJECT::CREATE_OBJECT(MISC::GET_HASH_KEY("prop_asteroid_01"), remotePos.x, remotePos.y, remotePos.z - 1.f, true, false, false);
	}
	void trapcageee(int player)
	{
		NativeVector3 remotePos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), 0);
		Object obj = OBJECT::CREATE_OBJECT(MISC::GET_HASH_KEY("prop_gold_cont_01"), remotePos.x, remotePos.y, remotePos.z - 1.f, true, false, false);
	}
	void AirStrikeKill(int player)
	{
		Entity playerOnline = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
		int weaponHash = MISC::GET_HASH_KEY("VEHICLE_WEAPON_SPACE_ROCKET");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponHash)) //wronghas//
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponHash, 31, 0);
		}
		NativeVector3 getcoords1 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerOnline, 0.0f, 0.0f, 26.6f);
		NativeVector3 getcoords2 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerOnline, 0.0f, 0.0f, 1.5f);
		MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(getcoords1.x, getcoords1.y, getcoords1.z, getcoords2.x, getcoords2.y, getcoords2.z, 250, 1, weaponHash, NULL, 1, 0, -1.0);
	}
	int eclone2[1000];
	int egcount2 = 1;
	void CrashPlayer22(Player selectedPed)
	{
		for (int i = 0; i <= 500; i++)
		{
			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPed);
			Player player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPed);
			eclone2[egcount2] = PED::CLONE_PED(playerPed, 1, 1, 1);
			ENTITY::SET_ENTITY_VISIBLE(eclone2[egcount2], false, 0);
			try {
				ENTITY::SET_ENTITY_VISIBLE(eclone2[egcount2], false, 0);
				ENTITY::SET_ENTITY_VISIBLE(eclone2[egcount2], false, 0);
				ENTITY::SET_ENTITY_VISIBLE(eclone2[egcount2], false, 0);
				ENTITY::SET_ENTITY_VISIBLE(eclone2[egcount2], false, 0);
				ENTITY::SET_ENTITY_VISIBLE(eclone2[egcount2], false, 0);
			}
			catch (...) {
				return;
			}
			{
				if (i == 490)
				{
					break;
				}
				HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
				HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~r~Stay away from this players");
				HUD::END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT_WITH_CREW_TAG_AND_ADDITIONAL_ICON("CHAR_STRIPPER_CHEETAH", "CHAR_STRIPPER_CHEETAH", 1, 8, "~w~Juice Menu\n", "~w~Clone Crash Player\r\n", 1, "~w~Juice Menu\n ~w~Clone Crash Player\r\n", 9, 1);
				HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER_WITH_TOKENS(FALSE, FALSE);
			}
		}
	}
	void byyyy(int player)
	{

		int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
		if (Handle != PLAYER::PLAYER_PED_ID())
		{
			Player playerHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
			Hash crashp = MISC::GET_HASH_KEY("a_c_dolphin");
			while (!STREAMING::HAS_MODEL_LOADED(crashp))
				if (ENTITY::DOES_ENTITY_EXIST(playerHandle))
				{
					Object crash = OBJECT::CREATE_OBJECT(crashp, 0, 0, 0, true, true, false); 
						Ped crashh = PED::CREATE_PED(crashp, 0, 0, 0, 1, 0, 1, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(crashh, playerHandle, PED::GET_PED_BONE_INDEX(playerHandle, true), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(crashh);
				}
		}
	}
	void noweapon(){
	for (int i = 0; i <= 32; i++)
	{
		int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		WEAPON::REMOVE_ALL_PED_WEAPONS(Handle, 1);
		{
			if (i == 32)
			{
				break;
			}
			notifyMap("~p~Los Santos is now safe..");

		}
	}
			}
	void KickallfromVehicle(){
		for (int i = 0; i <= 32; i++)
		{
			if (i == g_SelectedPlayer)continue;
			int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			TASK::CLEAR_PED_TASKS_IMMEDIATELY(Handle);
			{
				if (i == 32)
				{
					break;
				}
				notifyMap("~p~lmfao");
			}
		}
	}
    ///Weapon
	void Weaponsmk2()
	{
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED;
		std::vector<Hash> pistolMk2{
		1329061674, 2396306288, 1140676955, 1709866683, 568543123, 2467084625
		};
		std::vector<Hash> smgMk2{
			190476639, 2076495324, 2681951826, 3842157419, 1038927834, 1303784126, 2774849419, 966612367
		};
		std::vector<Hash> assltRifleMk2{
			1675665560, 2640679034, 2076495324, 1108334355, 77277509, 3328927042, 2805810788, 1303784126, 1447477866, 3115408816
		};
		std::vector<Hash> carbineRifleMk2{
			1141059345, 2640679034, 2076495324, 1108334355, 77277509, 3328927042, 2205435306, 1303784126, 2335983627, 3663056191
		};
		std::vector<Hash> combatMgMk2{
			1475288264, 2640679034, 1108334355, 1060929921, 3328927042, 1303784126, 3051509595, 3607349581
		};
		std::vector<Hash> heavySniperMk2{
			2313935527, 2193687427, 3159677559, 3061846192, 776198721, 2890063729, 1764221345, 277524638, 1815270123
		};
		std::vector<Hash> WeaponHash{
			0xBFE256D4, 0x78A97CD0, 0xDBBD7280, 0x394F415C, 0xFAD1F1C9, 0xA914799
		};

		for (Hash hash : pistolMk2)
			WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_PISTOL_MK2"), hash);

		for (Hash hash : smgMk2)
			WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_SMG_MK2"), hash);

		for (Hash hash : assltRifleMk2)
			WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), hash);

		for (Hash hash : carbineRifleMk2)
			WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), hash);

		for (Hash hash : combatMgMk2)
			WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), hash);

		for (Hash hash : heavySniperMk2)
			WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), hash);

		for (Hash hash : WeaponHash)
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), hash, 9999, 0);
	}
	void GiveAllWeps()
	{
		
		for (int ix = 0; ix < 32; ix++)
		{
			for (int i = 0; i < (sizeof(Weaponss) / 4); i++) {
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(ix), Weaponss[i], 9999, 1);
			}
		}
	}
    void byeweapon()
	{
		WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::PLAYER_PED_ID(), true);
	}
	bool Unlimitedammo = false;
	void unlimitedammo()
	{
		if (Unlimitedammo)
		{
			WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), true);
		}
		else
		{
			WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), false);
		}



	}
	bool Freezeammobool = false;
	void Freezeammo()
	{
		if (Freezeammo)
		{
			WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), true);
		}
		else
		{
			WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), false);
		}



	}
	bool RainbowGunn = false;
	void rainbowgunn()
	{
		if (RainbowGunn)
		{
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
				"WEAPON_PROXMINE", "WEAPON_SNOWBALL"," WEAPON_BALL", "WEAPON_VINTAGEPISTOL", "WEAPON_DAGGER", "WEAPON_FIREWORK", "WEAPON_MUSKET",
				"WEAPON_MARKSMANRIFLE", "WEAPON_HEAVYSHOTGUN", "WEAPON_GUSENBERG", "WEAPON_HATCHET", "WEAPON_RAILGUN", "WEAPON_FLAREGUN",
				"WEAPON_KNUCKLE", "GADGET_NIGHTVISION", "GADGET_PARACHUTE", "WEAPON_MARKSMANPISTOL", "WEAPON_ANIMAL", "WEAPON_STICKYBOMB"
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
	void maxamo()
	{
		PED::ADD_ARMOUR_TO_PED(PLAYER::PLAYER_PED_ID(), 200);
	}
	bool ClownGuun = false;
	void clownguun()
	{
		if (ClownGuun)
		{
			if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA)
			{
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				while (!STREAMING::HAS_NAMED_PTFX_ASSET_LOADED("scr_rcbarry2"));

				auto w = WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID(), 0);
				NativeVector3 v0, v1;
				MISC::GET_MODEL_DIMENSIONS(WEAPON::GET_SELECTED_PED_WEAPON(PLAYER::PLAYER_PED_ID()), &v0, &v1);
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_ENTITY("muz_clown", w, (v0.x - v1.x) / 2.0f + 0.7f, 0.f, 0.f, 0.f, 180.f, 0.f, 1.f, 1, 1, 1);
			}
		}
	}
	bool Explosivammo = false;
	void explosivammo()
	{
		if (Explosivammo)
		{
			if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA)
			{
				NativeVector3 iCoord;
				if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &iCoord))
				{
					FIRE::ADD_EXPLOSION(iCoord.x, iCoord.y, iCoord.z, 29, 100, true, false, 0,false);
				}
			}
			else
			{
				NULL;
			}
		}
	}
	void rail()
	{
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
		NativeVector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		Hash stripper = MISC::GET_HASH_KEY("u_m_y_justin");
		Hash railgun = MISC::GET_HASH_KEY("WEAPON_RAILGUN");
		STREAMING::REQUEST_MODEL(stripper);
		while (!STREAMING::HAS_MODEL_LOADED(stripper));
	}
     //Recovery
	void OfficeMoney()
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_LIFETIME_CONTRA_EARNINGS"), 25000000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_LIFETIME_CONTRA_EARNINGS"), 25000000, true);
		g_Logger->Info("Clear Reports...");
	}
	int Levels[8000] = { 0, 800, 2100, 3800, 6100, 9500, 12500, 16000, 19800, 24000, 28500, 33400, 38700, 44200, 50200, 56400, 63000, 69900, 77100, 84700, 92500, 100700, 109200, 118000, 127100, 136500, 146200,
	156200, 166500, 177100, 188000, 199200, 210700, 222400, 234500, 246800, 259400, 272300, 285500, 299000, 312700, 326800, 341000, 355600, 370500, 385600, 401000, 416600, 432600, 448800, 465200, 482000, 499000,
	516300, 533800, 551600, 569600, 588000, 606500, 625400, 644500, 663800, 683400, 703300, 723400, 743800, 764500, 785400, 806500, 827900, 849600, 871500, 893600, 916000, 938700, 961600, 984700, 1008100, 1031800,
	1055700, 1079800, 1104200, 1128800, 1153700, 1178800, 1204200, 1229800, 1255600, 1281700, 1308100, 1334600, 1361400, 1388500, 1415800, 1443300, 1471100, 1499100, 1527300, 1555800, 1584350, 1612950, 1641600,
	1670300, 1699050, 1727850, 1756700, 1785600, 1814550, 1843550, 1872600, 1901700, 1930850, 1960050, 1989300, 2018600, 2047950, 2077350, 2106800, 2136300, 2165850, 2195450, 2225100, 2254800, 2284550, 2314350,
	2344200, 2374100, 2404050, 2434050, 2464100, 2494200, 2524350, 2554550, 2584800, 2615100, 2645450, 2675850, 2706300, 2736800, 2767350, 2797950, 2828600, 2859300, 2890050, 2920850, 2951700, 2982600, 3013550,
	3044550, 3075600, 3106700, 3137850, 3169050, 3200300, 3231600, 3262950, 3294350, 3325800, 3357300, 3388850, 3420450, 3452100, 3483800, 3515550, 3547350, 3579200, 3611100, 3643050, 3675050, 3707100, 3739200,
	3771350, 3803550, 3835800, 3868100, 3900450, 3932850, 3965300, 3997800, 4030350, 4062950, 4095600, 4128300, 4161050, 4193850, 4226700, 4259600, 4292550, 4325550, 4358600, 4391700, 4424850, 4458050, 4491300,
	4524600, 4557950, 4591350, 4624800, 4658300, 4691850, 4725450, 4759100, 4792800, 4826550, 4860350, 4894200, 4928100, 4962050, 4996050, 5030100, 5064200, 5098350, 5132550, 5166800, 5201100, 5235450, 5269850,
	5304300, 5338800, 5373350, 5407950, 5442600, 5477300, 5512050, 5546850, 5581700, 5616600, 5651550, 5686550, 5721600, 5756700, 5791850, 5827050, 5862300, 5897600, 5932950, 5968350, 6003800, 6039300, 6074850,
	6110450, 6146100, 6181800, 6217550, 6253350, 6289200, 6325100, 6361050, 6397050, 6433100, 6469200, 6505350, 6541550, 6577800, 6614100, 6650450, 6686850, 6723300, 6759800, 6796350, 6832950, 6869600, 6906300,
	6943050, 6979850, 7016700, 7053600, 7090550, 7127550, 7164600, 7201700, 7238850, 7276050, 7313300, 7350600, 7387950, 7425350, 7462800, 7500300, 7537850, 7575450, 7613100, 7650800, 7688550, 7726350, 7764200,
	7802100, 7840050, 7878050, 7916100, 7954200, 7992350, 8030550, 8068800, 8107100, 8145450, 8183850, 8222300, 8260800, 8299350, 8337950, 8376600, 8415300, 8454050, 8492850, 8531700, 8570600, 8609550, 8648550,
	8687600, 8726700, 8765850, 8805050, 8844300, 8883600, 8922950, 8962350, 9001800, 9041300, 9080850, 9120450, 9160100, 9199800, 9239550, 9279350, 9319200, 9359100, 9399050, 9439050, 9479100, 9519200, 9559350,
	9599550, 9639800, 9680100, 9720450, 9760850, 9801300, 9841800, 9882350, 9922950, 9963600, 10004300, 10045050, 10085850, 10126700, 10167600, 10208550, 10249550, 10290600, 10331700, 10372850, 10414050, 10455300,
	10496600, 10537950, 10579350, 10620800, 10662300, 10703850, 10745450, 10787100, 10828800, 10870550, 10912350, 10954200, 10996100, 11038050, 11080050, 11122100, 11164200, 11206350, 11248550, 11290800, 11333100,
	11375450, 11417850, 11460300, 11502800, 11545350, 11587950, 11630600, 11673300, 11716050, 11758850, 11801700, 11844600, 11887550, 11930550, 11973600, 12016700, 12059850, 12103050, 12146300, 12189600, 12232950,
	12276350, 12319800, 12363300, 12406850, 12450450, 12494100, 12537800, 12581550, 12625350, 12669200, 12713100, 12757050, 12801050, 12845100, 12889200, 12933350, 12977550, 13021800, 13066100, 13110450, 13154850,
	13199300, 13243800, 13288350, 13332950, 13377600, 13422300, 13467050, 13511850, 13556700, 13601600, 13646550, 13691550, 13736600, 13781700, 13826850, 13872050, 13917300, 13962600, 14007950, 14053350, 14098800,
	14144300, 14189850, 14235450, 14281100, 14326800, 14372550, 14418350, 14464200, 14510100, 14556050, 14602050, 14648100, 14694200, 14740350, 14786550, 14832800, 14879100, 14925450, 14971850, 15018300, 15064800,
	15111350, 15157950, 15204600, 15251300, 15298050, 15344850, 15391700, 15438600, 15485550, 15532550, 15579600, 15626700, 15673850, 15721050, 15768300, 15815600, 15862950, 15910350, 15957800, 16005300, 16052850,
	16100450, 16148100, 16195800, 16243550, 16291350, 16339200, 16387100, 16435050, 16483050, 16531100, 16579200, 16627350, 16675550, 16723800, 16772100, 16820450, 16868850, 16917300, 16965800, 17014350, 17062950,
	17111600, 17160300, 17209050, 17257850, 17306700, 17355600, 17404550, 17453550, 17502600, 17551700, 17600850, 17650050, 17699300, 17748600, 17797950, 17847350, 17896800, 17946300, 17995850, 18045450, 18095100,
	18144800, 18194550, 18244350, 18294200, 18344100, 18394050, 18444050, 18494100, 18544200, 18594350, 18644550, 18694800, 18745100, 18795450, 18845850, 18896300, 18946800, 18997350, 19047950, 19098600, 19149300,
	19200050, 19250850, 19301700, 19352600, 19403550, 19454550, 19505600, 19556700, 19607850, 19659050, 19710300, 19761600, 19812950, 19864350, 19915800, 19967300, 20018850, 20070450, 20122100, 20173800, 20225550,
	20277350, 20329200, 20381100, 20433050, 20485050, 20537100, 20589200, 20641350, 20693550, 20745800, 20798100, 20850450, 20902850, 20955300, 21007800, 21060350, 21112950, 21165600, 21218300, 21271050, 21323850,
	21376700, 21429600, 21482550, 21535550, 21588600, 21641700, 21694850, 21748050, 21801300, 21854600, 21907950, 21961350, 22014800, 22068300, 22121850, 22175450, 22229100, 22282800, 22336550, 22390350, 22444200,
	22498100, 22552050, 22606050, 22660100, 22714200, 22768350, 22822550, 22876800, 22931100, 22985450, 23039850, 23094300, 23148800, 23203350, 23257950, 23312600, 23367300, 23422050, 23476850, 23531700, 23586600,
	23641550, 23696550, 23751600, 23806700, 23861850, 23917050, 23972300, 24027600, 24082950, 24138350, 24193800, 24249300, 24304850, 24360450, 24416100, 24471800, 24527550, 24583350, 24639200, 24695100, 24751050,
	24807050, 24863100, 24919200, 24975350, 25031550, 25087800, 25144100, 25200450, 25256850, 25313300, 25369800, 25426350, 25482950, 25539600, 25596300, 25653050, 25709850, 25766700, 25823600, 25880550, 25937550,
	25994600, 26051700, 26108850, 26166050, 26223300, 26280600, 26337950, 26395350, 26452800, 26510300, 26567850, 26625450, 26683100, 26740800, 26798550, 26856350, 26914200, 26972100, 27030050, 27088050, 27146100,
	27204200, 27262350, 27320550, 27378800, 27437100, 27495450, 27553850, 27612300, 27670800, 27729350, 27787950, 27846600, 27905300, 27964050, 28022850, 28081700, 28140600, 28199550, 28258550, 28317600, 28376700,
	28435850, 28495050, 28554300, 28613600, 28672950, 28732350, 28791800, 28851300, 28910850, 28970450, 29030100, 29089800, 29149550, 29209350, 29269200, 29329100, 29389050, 29449050, 29509100, 29569200, 29629350,
	29689550, 29749800, 29810100, 29870450, 29930850, 29991300, 30051800, 30112350, 30172950, 30233600, 30294300, 30355050, 30415850, 30476700, 30537600, 30598550, 30659550, 30720600, 30781700, 30842850, 30904050,
	30965300, 31026600, 31087950, 31149350, 31210800, 31272300, 31333850, 31395450, 31457100, 31518800, 31580550, 31642350, 31704200, 31766100, 31828050, 31890050, 31952100, 32014200, 32076350, 32138550, 32200800,
	32263100, 32325450, 32387850, 32450300, 32512800, 32575350, 32637950, 32700600, 32763300, 32826050, 32888850, 32951700, 33014600, 33077550, 33140550, 33203600, 33266700, 33329850, 33393050, 33456300, 33519600,
	33582950, 33646350, 33709800, 33773300, 33836850, 33900450, 33964100, 34027800, 34091550, 34155350, 34219200, 34283100, 34347050, 34411050, 34475100, 34539200, 34603350, 34667550, 34731800, 34796100, 34860450,
	34924850, 34989300, 35053800, 35118350, 35182950, 35247600, 35312300, 35377050, 35441850, 35506700, 35571600, 35636550, 35701550, 35766600, 35831700, 35896850, 35962050, 36027300, 36092600, 36157950, 36223350,
	36288800, 36354300, 36419850, 36485450, 36551100, 36616800, 36682550, 36748350, 36814200, 36880100, 36946050, 37012050, 37078100, 37144200, 37210350, 37276550, 37342800, 37409100, 37475450, 37541850, 37608300,
	37674800, 37741350, 37807950, 37874600, 37941300, 38008050, 38074850, 38141700, 38208600, 38275550, 38342550, 38409600, 38476700, 38543850, 38611050, 38678300, 38745600, 38812950, 38880350, 38947800, 39015300,
	39082850, 39150450, 39218100, 39285800, 39353550, 39421350, 39489200, 39557100, 39625050, 39693050, 39761100, 39829200, 39897350, 39965550, 40033800, 40102100, 40170450, 40238850, 40307300, 40375800, 40444350,
	40512950, 40581600, 40650300, 40719050, 40787850, 40856700, 40925600, 40994550, 41063550, 41132600, 41201700, 41270850, 41340050, 41409300, 41478600, 41547950, 41617350, 41686800, 41756300, 41825850, 41895450,
	41965100, 42034800, 42104550, 42174350, 42244200, 42314100, 42384050, 42454050, 42524100, 42594200, 42664350, 42734550, 42804800, 42875100, 42945450, 43015850, 43086300, 43156800, 43227350, 43297950, 43368600,
	43439300, 43510050, 43580850, 43651700, 43722600, 43793550, 43864550, 43935600, 44006700, 44077850, 44149050, 44220300, 44291600, 44362950, 44434350, 44505800, 44577300, 44648850, 44720450, 44792100, 44863800,
	44935550, 45007350, 45079200, 45151100, 45223050, 45295050, 45367100, 45439200, 45511350, 45583550, 45655800, 45728100, 45800450, 45872850, 45945300, 46017800, 46090350, 46162950, 46235600, 46308300, 46381050,
	46453850, 46526700, 46599600, 46672550, 46745550, 46818600, 46891700, 46964850, 47038050, 47111300, 47184600, 47257950, 47331350, 47404800, 47478300, 47551850, 47625450, 47699100, 47772800, 47846550, 47920350,
	47994200, 48068100, 48142050, 48216050, 48290100, 48364200, 48438350, 48512550, 48586800, 48661100, 48735450, 48809850, 48884300, 48958800, 49033350, 49107950, 49182600, 49257300, 49332050, 49406850, 49481700,
	49556600, 49631550, 49706550, 49781600, 49856700, 49931850, 50007050, 50082300, 50157600, 50232950, 50308350, 50383800, 50459300, 50534850, 50610450, 50686100, 50761800, 50837550, 50913350, 50989200, 51065100,
	51141050, 51217050, 51293100, 51369200, 51445350, 51521550, 51597800, 51674100, 51750450, 51826850, 51903300, 51979800, 52056350, 52132950, 52209600, 52286300, 52363050, 52439850, 52516700, 52593600, 52670550,
	52747550, 52824600, 52901700, 52978850, 53056050, 53133300, 53210600, 53287950, 53365350, 53442800, 53520300, 53597850, 53675450, 53753100, 53830800, 53908550, 53986350, 54064200, 54142100, 54220050, 54298050,
	54376100, 54454200, 54532350, 54610550, 54688800, 54767100, 54845450, 54923850, 55002300, 55080800, 55159350, 55237950, 55316600, 55395300, 55474050, 55552850, 55631700, 55710600, 55789550, 55868550, 55947600,
	56026700, 56105850, 56185050, 56264300, 56343600, 56422950, 56502350, 56581800, 56661300, 56740850, 56820450, 56900100, 56979800, 57059550, 57139350, 57219200, 57299100, 57379050, 57459050, 57539100, 57619200,
	57699350, 57779550, 57859800, 57940100, 58020450, 58100850, 58181300, 58261800, 58342350, 58422950, 58503600, 58584300, 58665050, 58745850, 58826700, 58907600, 58988550, 59069550, 59150600, 59231700, 59312850,
	59394050, 59475300, 59556600, 59637950, 59719350, 59800800, 59882300, 59963850, 60045450, 60127100, 60208800, 60290550, 60372350, 60454200, 60536100, 60618050, 60700050, 60782100, 60864200, 60946350, 61028550,
	61110800, 61193100, 61275450, 61357850, 61440300, 61522800, 61605350, 61687950, 61770600, 61853300, 61936050, 62018850, 62101700, 62184600, 62267550, 62350550, 62433600, 62516700, 62599850, 62683050, 62766300,
	62849600, 62932950, 63016350, 63099800, 63183300, 63266850, 63350450, 63434100, 63517800, 63601550, 63685350, 63769200, 63853100, 63937050, 64021050, 64105100, 64189200, 64273350, 64357550, 64441800, 64526100,
	64610450, 64694850, 64779300, 64863800, 64948350, 65032950, 65117600, 65202300, 65287050, 65371850, 65456700, 65541600, 65626550, 65711550, 65796600, 65881700, 65966850, 66052050, 66137300, 66222600, 66307950,
	66393350, 66478800, 66564300, 66649850, 66735450, 66821100, 66906800, 66992550, 67078350, 67164200, 67250100, 67336050, 67422050, 67508100, 67594200, 67680350, 67766550, 67852800, 67939100, 68025450, 68111850,
	68198300, 68284800, 68371350, 68457950, 68544600, 68631300, 68718050, 68804850, 68891700, 68978600, 69065550, 69152550, 69239600, 69326700, 69413850, 69501050, 69588300, 69675600, 69762950, 69850350, 69937800,
	70025300, 70112850, 70200450, 70288100, 70375800, 70463550, 70551350, 70639200, 70727100, 70815050, 70903050, 70991100, 71079200, 71167350, 71255550, 71343800, 71432100, 71520450, 71608850, 71697300, 71785800,
	71874350, 71962950, 72051600, 72140300, 72229050, 72317850, 72406700, 72495600, 72584550, 72673550, 72762600, 72851700, 72940850, 73030050, 73119300, 73208600, 73297950, 73387350, 73476800, 73566300, 73655850,
	73745450, 73835100, 73924800, 74014550, 74104350, 74194200, 74284100, 74374050, 74464050, 74554100, 74644200, 74734350, 74824550, 74914800, 75005100, 75095450, 75185850, 75276300, 75366800, 75457350, 75547950,
	75638600, 75729300, 75820050, 75910850, 76001700, 76092600, 76183550, 76274550, 76365600, 76456700, 76547850, 76639050, 76730300, 76821600, 76912950, 77004350, 77095800, 77187300, 77278850, 77370450, 77462100,
	77553800, 77645550, 77737350, 77829200, 77921100, 78013050, 78105050, 78197100, 78289200, 78381350, 78473550, 78565800, 78658100, 78750450, 78842850, 78935300, 79027800, 79120350, 79212950, 79305600, 79398300,
	79491050, 79583850, 79676700, 79769600, 79862550, 79955550, 80048600, 80141700, 80234850, 80328050, 80421300, 80514600, 80607950, 80701350, 80794800, 80888300, 80981850, 81075450, 81169100, 81262800, 81356550,
	81450350, 81544200, 81638100, 81732050, 81826050, 81920100, 82014200, 82108350, 82202550, 82296800, 82391100, 82485450, 82579850, 82674300, 82768800, 82863350, 82957950, 83052600, 83147300, 83242050, 83336850,
	83431700, 83526600, 83621550, 83716550, 83811600, 83906700, 84001850, 84097050, 84192300, 84287600, 84382950, 84478350, 84573800, 84669300, 84764850, 84860450, 84956100, 85051800, 85147550, 85243350, 85339200,
	85435100, 85531050, 85627050, 85723100, 85819200, 85915350, 86011550, 86107800, 86204100, 86300450, 86396850, 86493300, 86589800, 86686350, 86782950, 86879600, 86976300, 87073050, 87169850, 87266700, 87363600,
	87460550, 87557550, 87654600, 87751700, 87848850, 87946050, 88043300, 88140600, 88237950, 88335350, 88432800, 88530300, 88627850, 88725450, 88823100, 88920800, 89018550, 89116350, 89214200, 89312100, 89410050,
	89508050, 89606100, 89704200, 89802350, 89900550, 89998800, 90097100, 90195450, 90293850, 90392300, 90490800, 90589350, 90687950, 90786600, 90885300, 90984050, 91082850, 91181700, 91280600, 91379550, 91478550,
	91577600, 91676700, 91775850, 91875050, 91974300, 92073600, 92172950, 92272350, 92371800, 92471300, 92570850, 92670450, 92770100, 92869800, 92969550, 93069350, 93169200, 93269100, 93369050, 93469050, 93569100,
	93669200, 93769350, 93869550, 93969800, 94070100, 94170450, 94270850, 94371300, 94471800, 94572350, 94672950, 94773600, 94874300, 94975050, 95075850, 95176700, 95277600, 95378550, 95479550, 95580600, 95681700,
	95782850, 95884050, 95985300, 96086600, 96187950, 96289350, 96390800, 96492300, 96593850, 96695450, 96797100, 96898800, 97000550, 97102350, 97204200, 97306100, 97408050, 97510050, 97612100, 97714200, 97816350,
	97918550, 98020800, 98123100, 98225450, 98327850, 98430300, 98532800, 98635350, 98737950, 98840600, 98943300, 99046050, 99148850, 99251700, 99354600, 99457550, 99560550, 99663600, 99766700, 99869850, 99973050,
	100076300, 100179600, 100282950, 100386350, 100489800, 100593300, 100696850, 100800450, 100904100, 101007800, 101111550, 101215350, 101319200, 101423100, 101527050, 101631050, 101735100, 101839200, 101943350,
	102047550, 102151800, 102256100, 102360450, 102464850, 102569300, 102673800, 102778350, 102882950, 102987600, 103092300, 103197050, 103301850, 103406700, 103511600, 103616550, 103721550, 103826600, 103931700,
	104036850, 104142050, 104247300, 104352600, 104457950, 104563350, 104668800, 104774300, 104879850, 104985450, 105091100, 105196800, 105302550, 105408350, 105514200, 105620100, 105726050, 105832050, 105938100,
	106044200, 106150350, 106256550, 106362800, 106469100, 106575450, 106681850, 106788300, 106894800, 107001350, 107107950, 107214600, 107321300, 107428050, 107534850, 107641700, 107748600, 107855550, 107962550,
	108069600, 108176700, 108283850, 108391050, 108498300, 108605600, 108712950, 108820350, 108927800, 109035300, 109142850, 109250450, 109358100, 109465800, 109573550, 109681350, 109789200, 109897100, 110005050,
	110113050, 110221100, 110329200, 110437350, 110545550, 110653800, 110762100, 110870450, 110978850, 111087300, 111195800, 111304350, 111412950, 111521600, 111630300, 111739050, 111847850, 111956700, 112065600,
	112174550, 112283550, 112392600, 112501700, 112610850, 112720050, 112829300, 112938600, 113047950, 113157350, 113266800, 113376300, 113485850, 113595450, 113705100, 113814800, 113924550, 114034350, 114144200,
	114254100, 114364050, 114474050, 114584100, 114694200, 114804350, 114914550, 115024800, 115135100, 115245450, 115355850, 115466300, 115576800, 115687350, 115797950, 115908600, 116019300, 116130050, 116240850,
	116351700, 116462600, 116573550, 116684550, 116795600, 116906700, 117017850, 117129050, 117240300, 117351600, 117462950, 117574350, 117685800, 117797300, 117908850, 118020450, 118132100, 118243800, 118355550,
	118467350, 118579200, 118691100, 118803050, 118915050, 119027100, 119139200, 119251350, 119363550, 119475800, 119588100, 119700450, 119812850, 119925300, 120037800, 120150350, 120262950, 120375600, 120488300,
	120601050, 120713850, 120826700, 120939600, 121052550, 121165550, 121278600, 121391700, 121504850, 121618050, 121731300, 121844600, 121957950, 122071350, 122184800, 122298300, 122411850, 122525450, 122639100,
	122752800, 122866550, 122980350, 123094200, 123208100, 123322050, 123436050, 123550100, 123664200, 123778350, 123892550, 124006800, 124121100, 124235450, 124349850, 124464300, 124578800, 124693350, 124807950,
	124922600, 125037300, 125152050, 125266850, 125381700, 125496600, 125611550, 125726550, 125841600, 125956700, 126071850, 126187050, 126302300, 126417600, 126532950, 126648350, 126763800, 126879300, 126994850,
	127110450, 127226100, 127341800, 127457550, 127573350, 127689200, 127805100, 127921050, 128037050, 128153100, 128269200, 128385350, 128501550, 128617800, 128734100, 128850450, 128966850, 129083300, 129199800,
	129316350, 129432950, 129549600, 129666300, 129783050, 129899850, 130016700, 130133600, 130250550, 130367550, 130484600, 130601700, 130718850, 130836050, 130953300, 131070600, 131187950, 131305350, 131422800,
	131540300, 131657850, 131775450, 131893100, 132010800, 132128550, 132246350, 132364200, 132482100, 132600050, 132718050, 132836100, 132954200, 133072350, 133190550, 133308800, 133427100, 133545450, 133663850,
	133782300, 133900800, 134019350, 134137950, 134256600, 134375300, 134494050, 134612850, 134731700, 134850600, 134969550, 135088550, 135207600, 135326700, 135445850, 135565050, 135684300, 135803600, 135922950,
	136042350, 136161800, 136281300, 136400850, 136520450, 136640100, 136759800, 136879550, 136999350, 137119200, 137239100, 137359050, 137479050, 137599100, 137719200, 137839350, 137959550, 138079800, 138200100,
	138320450, 138440850, 138561300, 138681800, 138802350, 138922950, 139043600, 139164300, 139285050, 139405850, 139526700, 139647600, 139768550, 139889550, 140010600, 140131700, 140252850, 140374050, 140495300,
	140616600, 140737950, 140859350, 140980800, 141102300, 141223850, 141345450, 141467100, 141588800, 141710550, 141832350, 141954200, 142076100, 142198050, 142320050, 142442100, 142564200, 142686350, 142808550,
	142930800, 143053100, 143175450, 143297850, 143420300, 143542800, 143665350, 143787950, 143910600, 144033300, 144156050, 144278850, 144401700, 144524600, 144647550, 144770550, 144893600, 145016700, 145139850,
	145263050, 145386300, 145509600, 145632950, 145756350, 145879800, 146003300, 146126850, 146250450, 146374100, 146497800, 146621550, 146745350, 146869200, 146993100, 147117050, 147241050, 147365100, 147489200,
	147613350, 147737550, 147861800, 147986100, 148110450, 148234850, 148359300, 148483800, 148608350, 148732950, 148857600, 148982300, 149107050, 149231850, 149356700, 149481600, 149606550, 149731550, 149856600,
	149981700, 150106850, 150232050, 150357300, 150482600, 150607950, 150733350, 150858800, 150984300, 151109850, 151235450, 151361100, 151486800, 151612550, 151738350, 151864200, 151990100, 152116050, 152242050,
	152368100, 152494200, 152620350, 152746550, 152872800, 152999100, 153125450, 153251850, 153378300, 153504800, 153631350, 153757950, 153884600, 154011300, 154138050, 154264850, 154391700, 154518600, 154645550,
	154772550, 154899600, 155026700, 155153850, 155281050, 155408300, 155535600, 155662950, 155790350, 155917800, 156045300, 156172850, 156300450, 156428100, 156555800, 156683550, 156811350, 156939200, 157067100,
	157195050, 157323050, 157451100, 157579200, 157707350, 157835550, 157963800, 158092100, 158220450, 158348850, 158477300, 158605800, 158734350, 158862950, 158991600, 159120300, 159249050, 159377850, 159506700,
	159635600, 159764550, 159893550, 160022600, 160151700, 160280850, 160410050, 160539300, 160668600, 160797950, 160927350, 161056800, 161186300, 161315850, 161445450, 161575100, 161704800, 161834550, 161964350,
	162094200, 162224100, 162354050, 162484050, 162614100, 162744200, 162874350, 163004550, 163134800, 163265100, 163395450, 163525850, 163656300, 163786800, 163917350, 164047950, 164178600, 164309300, 164440050,
	164570850, 164701700, 164832600, 164963550, 165094550, 165225600, 165356700, 165487850, 165619050, 165750300, 165881600, 166012950, 166144350, 166275800, 166407300, 166538850, 166670450, 166802100, 166933800,
	167065550, 167197350, 167329200, 167461100, 167593050, 167725050, 167857100, 167989200, 168121350, 168253550, 168385800, 168518100, 168650450, 168782850, 168915300, 169047800, 169180350, 169312950, 169445600,
	169578300, 169711050, 169843850, 169976700, 170109600, 170242550, 170375550, 170508600, 170641700, 170774850, 170908050, 171041300, 171174600, 171307950, 171441350, 171574800, 171708300, 171841850, 171975450,
	172109100, 172242800, 172376550, 172510350, 172644200, 172778100, 172912050, 173046050, 173180100, 173314200, 173448350, 173582550, 173716800, 173851100, 173985450, 174119850, 174254300, 174388800, 174523350,
	174657950, 174792600, 174927300, 175062050, 175196850, 175331700, 175466600, 175601550, 175736550, 175871600, 176006700, 176141850, 176277050, 176412300, 176547600, 176682950, 176818350, 176953800, 177089300,
	177224850, 177360450, 177496100, 177631800, 177767550, 177903350, 178039200, 178175100, 178311050, 178447050, 178583100, 178719200, 178855350, 178991550, 179127800, 179264100, 179400450, 179536850, 179673300,
	179809800, 179946350, 180082950, 180219600, 180356300, 180493050, 180629850, 180766700, 180903600, 181040550, 181177550, 181314600, 181451700, 181588850, 181726050, 181863300, 182000600, 182137950, 182275350,
	182412800, 182550300, 182687850, 182825450, 182963100, 183100800, 183238550, 183376350, 183514200, 183652100, 183790050, 183928050, 184066100, 184204200, 184342350, 184480550, 184618800, 184757100, 184895450,
	185033850, 185172300, 185310800, 185449350, 185587950, 185726600, 185865300, 186004050, 186142850, 186281700, 186420600, 186559550, 186698550, 186837600, 186976700, 187115850, 187255050, 187394300, 187533600,
	187672950, 187812350, 187951800, 188091300, 188230850, 188370450, 188510100, 188649800, 188789550, 188929350, 189069200, 189209100, 189349050, 189489050, 189629100, 189769200, 189909350, 190049550, 190189800,
	190330100, 190470450, 190610850, 190751300, 190891800, 191032350, 191172950, 191313600, 191454300, 191595050, 191735850, 191876700, 192017600, 192158550, 192299550, 192440600, 192581700, 192722850, 192864050,
	193005300, 193146600, 193287950, 193429350, 193570800, 193712300, 193853850, 193995450, 194137100, 194278800, 194420550, 194562350, 194704200, 194846100, 194988050, 195130050, 195272100, 195414200, 195556350,
	195698550, 195840800, 195983100, 196125450, 196267850, 196410300, 196552800, 196695350, 196837950, 196980600, 197123300, 197266050, 197408850, 197551700, 197694600, 197837550, 197980550, 198123600, 198266700,
	198409850, 198553050, 198696300, 198839600, 198982950, 199126350, 199269800, 199413300, 199556850, 199700450, 199844100, 199987800, 200131550, 200275350, 200419200, 200563100, 200707050, 200851050, 200995100,
	201139200, 201283350, 201427550, 201571800, 201716100, 201860450, 202004850, 202149300, 202293800, 202438350, 202582950, 202727600, 202872300, 203017050, 203161850, 203306700, 203451600, 203596550, 203741550,
	203886600, 204031700, 204176850, 204322050, 204467300, 204612600, 204757950, 204903350, 205048800, 205194300, 205339850, 205485450, 205631100, 205776800, 205922550, 206068350, 206214200, 206360100, 206506050,
	206652050, 206798100, 206944200, 207090350, 207236550, 207382800, 207529100, 207675450, 207821850, 207968300, 208114800, 208261350, 208407950, 208554600, 208701300, 208848050, 208994850, 209141700, 209288600,
	209435550, 209582550, 209729600, 209876700, 210023850, 210171050, 210318300, 210465600, 210612950, 210760350, 210907800, 211055300, 211202850, 211350450, 211498100, 211645800, 211793550, 211941350, 212089200,
	212237100, 212385050, 212533050, 212681100, 212829200, 212977350, 213125550, 213273800, 213422100, 213570450, 213718850, 213867300, 214015800, 214164350, 214312950, 214461600, 214610300, 214759050, 214907850,
	215056700, 215205600, 215354550, 215503550, 215652600, 215801700, 215950850, 216100050, 216249300, 216398600, 216547950, 216697350, 216846800, 216996300, 217145850, 217295450, 217445100, 217594800, 217744550,
	217894350, 218044200, 218194100, 218344050, 218494050, 218644100, 218794200, 218944350, 219094550, 219244800, 219395100, 219545450, 219695850, 219846300, 219996800, 220147350, 220297950, 220448600, 220599300,
	220750050, 220900850, 221051700, 221202600, 221353550, 221504550, 221655600, 221806700, 221957850, 222109050, 222260300, 222411600, 222562950, 222714350, 222865800, 223017300, 223168850, 223320450, 223472100,
	223623800, 223775550, 223927350, 224079200, 224231100, 224383050, 224535050, 224687100, 224839200, 224991350, 225143550, 225295800, 225448100, 225600450, 225752850, 225905300, 226057800, 226210350, 226362950,
	226515600, 226668300, 226821050, 226973850, 227126700, 227279600, 227432550, 227585550, 227738600, 227891700, 228044850, 228198050, 228351300, 228504600, 228657950, 228811350, 228964800, 229118300, 229271850,
	229425450, 229579100, 229732800, 229886550, 230040350, 230194200, 230348100, 230502050, 230656050, 230810100, 230964200, 231118350, 231272550, 231426800, 231581100, 231735450, 231889850, 232044300, 232198800,
	232353350, 232507950, 232662600, 232817300, 232972050, 233126850, 233281700, 233436600, 233591550, 233746550, 233901600, 234056700, 234211850, 234367050, 234522300, 234677600, 234832950, 234988350, 235143800,
	235299300, 235454850, 235610450, 235766100, 235921800, 236077550, 236233350, 236389200, 236545100, 236701050, 236857050, 237013100, 237169200, 237325350, 237481550, 237637800, 237794100, 237950450, 238106850,
	238263300, 238419800, 238576350, 238732950, 238889600, 239046300, 239203050, 239359850, 239516700, 239673600, 239830550, 239987550, 240144600, 240301700, 240458850, 240616050, 240773300, 240930600, 241087950,
	241245350, 241402800, 241560300, 241717850, 241875450, 242033100, 242190800, 242348550, 242506350, 242664200, 242822100, 242980050, 243138050, 243296100, 243454200, 243612350, 243770550, 243928800, 244087100,
	244245450, 244403850, 244562300, 244720800, 244879350, 245037950, 245196600, 245355300, 245514050, 245672850, 245831700, 245990600, 246149550, 246308550, 246467600, 246626700, 246785850, 246945050, 247104300,
	247263600, 247422950, 247582350, 247741800, 247901300, 248060850, 248220450, 248380100, 248539800, 248699550, 248859350, 249019200, 249179100, 249339050, 249499050, 249659100, 249819200, 249979350, 250139550,
	250299800, 250460100, 250620450, 250780850, 250941300, 251101800, 251262350, 251422950, 251583600, 251744300, 251905050, 252065850, 252226700, 252387600, 252548550, 252709550, 252870600, 253031700, 253192850,
	253354050, 253515300, 253676600, 253837950, 253999350, 254160800, 254322300, 254483850, 254645450, 254807100, 254968800, 255130550, 255292350, 255454200, 255616100, 255778050, 255940050, 256102100, 256264200,
	256426350, 256588550, 256750800, 256913100, 257075450, 257237850, 257400300, 257562800, 257725350, 257887950, 258050600, 258213300, 258376050, 258538850, 258701700, 258864600, 259027550, 259190550, 259353600,
	259516700, 259679850, 259843050, 260006300, 260169600, 260332950, 260496350, 260659800, 260823300, 260986850, 261150450, 261314100, 261477800, 261641550, 261805350, 261969200, 262133100, 262297050, 262461050,
	262625100, 262789200, 262953350, 263117550, 263281800, 263446100, 263610450, 263774850, 263939300, 264103800, 264268350, 264432950, 264597600, 264762300, 264927050, 265091850, 265256700, 265421600, 265586550,
	265751550, 265916600, 266081700, 266246850, 266412050, 266577300, 266742600, 266907950, 267073350, 267238800, 267404300, 267569850, 267735450, 267901100, 268066800, 268232550, 268398350, 268564200, 268730100,
	268896050, 269062050, 269228100, 269394200, 269560350, 269726550, 269892800, 270059100, 270225450, 270391850, 270558300, 270724800, 270891350, 271057950, 271224600, 271391300, 271558050, 271724850, 271891700,
	272058600, 272225550, 272392550, 272559600, 272726700, 272893850, 273061050, 273228300, 273395600, 273562950, 273730350, 273897800, 274065300, 274232850, 274400450, 274568100, 274735800, 274903550, 275071350,
	275239200, 275407100, 275575050, 275743050, 275911100, 276079200, 276247350, 276415550, 276583800, 276752100, 276920450, 277088850, 277257300, 277425800, 277594350, 277762950, 277931600, 278100300, 278269050,
	278437850, 278606700, 278775600, 278944550, 279113550, 279282600, 279451700, 279620850, 279790050, 279959300, 280128600, 280297950, 280467350, 280636800, 280806300, 280975850, 281145450, 281315100, 281484800,
	281654550, 281824350, 281994200, 282164100, 282334050, 282504050, 282674100, 282844200, 283014350, 283184550, 283354800, 283525100, 283695450, 283865850, 284036300, 284206800, 284377350, 284547950, 284718600,
	284889300, 285060050, 285230850, 285401700, 285572600, 285743550, 285914550, 286085600, 286256700, 286427850, 286599050, 286770300, 286941600, 287112950, 287284350, 287455800, 287627300, 287798850, 287970450,
	288142100, 288313800, 288485550, 288657350, 288829200, 289001100, 289173050, 289345050, 289517100, 289689200, 289861350, 290033550, 290205800, 290378100, 290550450, 290722850, 290895300, 291067800, 291240350,
	291412950, 291585600, 291758300, 291931050, 292103850, 292276700, 292449600, 292622550, 292795550, 292968600, 293141700, 293314850, 293488050, 293661300, 293834600, 294007950, 294181350, 294354800, 294528300,
	294701850, 294875450, 295049100, 295222800, 295396550, 295570350, 295744200, 295918100, 296092050, 296266050, 296440100, 296614200, 296788350, 296962550, 297136800, 297311100, 297485450, 297659850, 297834300,
	298008800, 298183350, 298357950, 298532600, 298707300, 298882050, 299056850, 299231700, 299406600, 299581550, 299756550, 299931600, 300106700, 300281850, 300457050, 300632300, 300807600, 300982950, 301158350,
	301333800, 301509300, 301684850, 301860450, 302036100, 302211800, 302387550, 302563350, 302739200, 302915100, 303091050, 303267050, 303443100, 303619200, 303795350, 303971550, 304147800, 304324100, 304500450,
	304676850, 304853300, 305029800, 305206350, 305382950, 305559600, 305736300, 305913050, 306089850, 306266700, 306443600, 306620550, 306797550, 306974600, 307151700, 307328850, 307506050, 307683300, 307860600,
	308037950, 308215350, 308392800, 308570300, 308747850, 308925450, 309103100, 309280800, 309458550, 309636350, 309814200, 309992100, 310170050, 310348050, 310526100, 310704200, 310882350, 311060550, 311238800,
	311417100, 311595450, 311773850, 311952300, 312130800, 312309350, 312487950, 312666600, 312845300, 313024050, 313202850, 313381700, 313560600, 313739550, 313918550, 314097600, 314276700, 314455850, 314635050,
	314814300, 314993600, 315172950, 315352350, 315531800, 315711300, 315890850, 316070450, 316250100, 316429800, 316609550, 316789350, 316969200, 317149100, 317329050, 317509050, 317689100, 317869200, 318049350,
	318229550, 318409800, 318590100, 318770450, 318950850, 319131300, 319311800, 319492350, 319672950, 319853600, 320034300, 320215050, 320395850, 320576700, 320757600, 320938550, 321119550, 321300600, 321481700,
	321662850, 321844050, 322025300, 322206600, 322387950, 322569350, 322750800, 322932300, 323113850, 323295450, 323477100, 323658800, 323840550, 324022350, 324204200, 324386100, 324568050, 324750050, 324932100,
	325114200, 325296350, 325478550, 325660800, 325843100, 326025450, 326207850, 326390300, 326572800, 326755350, 326937950, 327120600, 327303300, 327486050, 327668850, 327851700, 328034600, 328217550, 328400550,
	328583600, 328766700, 328949850, 329133050, 329316300, 329499600, 329682950, 329866350, 330049800, 330233300, 330416850, 330600450, 330784100, 330967800, 331151550, 331335350, 331519200, 331703100, 331887050,
	332071050, 332255100, 332439200, 332623350, 332807550, 332991800, 333176100, 333360450, 333544850, 333729300, 333913800, 334098350, 334282950, 334467600, 334652300, 334837050, 335021850, 335206700, 335391600,
	335576550, 335761550, 335946600, 336131700, 336316850, 336502050, 336687300, 336872600, 337057950, 337243350, 337428800, 337614300, 337799850, 337985450, 338171100, 338356800, 338542550, 338728350, 338914200,
	339100100, 339286050, 339472050, 339658100, 339844200, 340030350, 340216550, 340402800, 340589100, 340775450, 340961850, 341148300, 341334800, 341521350, 341707950, 341894600, 342081300, 342268050, 342454850,
	342641700, 342828600, 343015550, 343202550, 343389600, 343576700, 343763850, 343951050, 344138300, 344325600, 344512950, 344700350, 344887800, 345075300, 345262850, 345450450, 345638100, 345825800, 346013550,
	346201350, 346389200, 346577100, 346765050, 346953050, 347141100, 347329200, 347517350, 347705550, 347893800, 348082100, 348270450, 348458850, 348647300, 348835800, 349024350, 349212950, 349401600, 349590300,
	349779050, 349967850, 350156700, 350345600, 350534550, 350723550, 350912600, 351101700, 351290850, 351480050, 351669300, 351858600, 352047950, 352237350, 352426800, 352616300, 352805850, 352995450, 353185100,
	353374800, 353564550, 353754350, 353944200, 354134100, 354324050, 354514050, 354704100, 354894200, 355084350, 355274550, 355464800, 355655100, 355845450, 356035850, 356226300, 356416800, 356607350, 356797950,
	356988600, 357179300, 357370050, 357560850, 357751700, 357942600, 358133550, 358324550, 358515600, 358706700, 358897850, 359089050, 359280300, 359471600, 359662950, 359854350, 360045800, 360237300, 360428850,
	360620450, 360812100, 361003800, 361195550, 361387350, 361579200, 361771100, 361963050, 362155050, 362347100, 362539200, 362731350, 362923550, 363115800, 363308100, 363500450, 363692850, 363885300, 364077800,
	364270350, 364462950, 364655600, 364848300, 365041050, 365233850, 365426700, 365619600, 365812550, 366005550, 366198600, 366391700, 366584850, 366778050, 366971300, 367164600, 367357950, 367551350, 367744800,
	367938300, 368131850, 368325450, 368519100, 368712800, 368906550, 369100350, 369294200, 369488100, 369682050, 369876050, 370070100, 370264200, 370458350, 370652550, 370846800, 371041100, 371235450, 371429850,
	371624300, 371818800, 372013350, 372207950, 372402600, 372597300, 372792050, 372986850, 373181700, 373376600, 373571550, 373766550, 373961600, 374156700, 374351850, 374547050, 374742300, 374937600, 375132950,
	375328350, 375523800, 375719300, 375914850, 376110450, 376306100, 376501800, 376697550, 376893350, 377089200, 377285100, 377481050, 377677050, 377873100, 378069200, 378265350, 378461550, 378657800, 378854100,
	379050450, 379246850, 379443300, 379639800, 379836350, 380032950, 380229600, 380426300, 380623050, 380819850, 381016700, 381213600, 381410550, 381607550, 381804600, 382001700, 382198850, 382396050, 382593300,
	382790600, 382987950, 383185350, 383382800, 383580300, 383777850, 383975450, 384173100, 384370800, 384568550, 384766350, 384964200, 385162100, 385360050, 385558050, 385756100, 385954200, 386152350, 386350550,
	386548800, 386747100, 386945450, 387143850, 387342300, 387540800, 387739350, 387937950, 388136600, 388335300, 388534050, 388732850, 388931700, 389130600, 389329550, 389528550, 389727600, 389926700, 390125850,
	390325050, 390524300, 390723600, 390922950, 391122350, 391321800, 391521300, 391720850, 391920450, 392120100, 392319800, 392519550, 392719350, 392919200, 393119100, 393319050, 393519050, 393719100, 393919200,
	394119350, 394319550, 394519800, 394720100, 394920450, 395120850, 395321300, 395521800, 395722350, 395922950, 396123600, 396324300, 396525050, 396725850, 396926700, 397127600, 397328550, 397529550, 397730600,
	397931700, 398132850, 398334050, 398535300, 398736600, 398937950, 399139350, 399340800, 399542300, 399743850, 399945450, 400147100, 400348800, 400550550, 400752350, 400954200, 401156100, 401358050, 401560050,
	401762100, 401964200, 402166350, 402368550, 402570800, 402773100, 402975450, 403177850, 403380300, 403582800, 403785350, 403987950, 404190600, 404393300, 404596050, 404798850, 405001700, 405204600, 405407550,
	405610550, 405813600, 406016700, 406219850, 406423050, 406626300, 406829600, 407032950, 407236350, 407439800, 407643300, 407846850, 408050450, 408254100, 408457800, 408661550, 408865350, 409069200, 409273100,
	409477050, 409681050, 409885100, 410089200, 410293350, 410497550, 410701800, 410906100, 411110450, 411314850, 411519300, 411723800, 411928350, 412132950, 412337600, 412542300, 412747050, 412951850, 413156700,
	413361600, 413566550, 413771550, 413976600, 414181700, 414386850, 414592050, 414797300, 415002600, 415207950, 415413350, 415618800, 415824300, 416029850, 416235450, 416441100, 416646800, 416852550, 417058350,
	417264200, 417470100, 417676050, 417882050, 418088100, 418294200, 418500350, 418706550, 418912800, 419119100, 419325450, 419531850, 419738300, 419944800, 420151350, 420357950, 420564600, 420771300, 420978050,
	421184850, 421391700, 421598600, 421805550, 422012550, 422219600, 422426700, 422633850, 422841050, 423048300, 423255600, 423462950, 423670350, 423877800, 424085300, 424292850, 424500450, 424708100, 424915800,
	425123550, 425331350, 425539200, 425747100, 425955050, 426163050, 426371100, 426579200, 426787350, 426995550, 427203800, 427412100, 427620450, 427828850, 428037300, 428245800, 428454350, 428662950, 428871600,
	429080300, 429289050, 429497850, 429706700, 429915600, 430124550, 430333550, 430542600, 430751700, 430960850, 431170050, 431379300, 431588600, 431797950, 432007350, 432216800, 432426300, 432635850, 432845450,
	433055100, 433264800, 433474550, 433684350, 433894200, 434104100, 434314050, 434524050, 434734100, 434944200, 435154350, 435364550, 435574800, 435785100, 435995450, 436205850, 436416300, 436626800, 436837350,
	437047950, 437258600, 437469300, 437680050, 437890850, 438101700, 438312600, 438523550, 438734550, 438945600, 439156700, 439367850, 439579050, 439790300, 440001600, 440212950, 440424350, 440635800, 440847300,
	441058850, 441270450, 441482100, 441693800, 441905550, 442117350, 442329200, 442541100, 442753050, 442965050, 443177100, 443389200, 443601350, 443813550, 444025800, 444238100, 444450450, 444662850, 444875300,
	445087800, 445300350, 445512950, 445725600, 445938300, 446151050, 446363850, 446576700, 446789600, 447002550, 447215550, 447428600, 447641700, 447854850, 448068050, 448281300, 448494600, 448707950, 448921350,
	449134800, 449348300, 449561850, 449775450, 449989100, 450202800, 450416550, 450630350, 450844200, 451058100, 451272050, 451486050, 451700100, 451914200, 452128350, 452342550, 452556800, 452771100, 452985450,
	453199850, 453414300, 453628800, 453843350, 454057950, 454272600, 454487300, 454702050, 454916850, 455131700, 455346600, 455561550, 455776550, 455991600, 456206700, 456421850, 456637050, 456852300, 457067600,
	457282950, 457498350, 457713800, 457929300, 458144850, 458360450, 458576100, 458791800, 459007550, 459223350, 459439200, 459655100, 459871050, 460087050, 460303100, 460519200, 460735350, 460951550, 461167800,
	461384100, 461600450, 461816850, 462033300, 462249800, 462466350, 462682950, 462899600, 463116300, 463333050, 463549850, 463766700, 463983600, 464200550, 464417550, 464634600, 464851700, 465068850, 465286050,
	465503300, 465720600, 465937950, 466155350, 466372800, 466590300, 466807850, 467025450, 467243100, 467460800, 467678550, 467896350, 468114200, 468332100, 468550050, 468768050, 468986100, 469204200, 469422350,
	469640550, 469858800, 470077100, 470295450, 470513850, 470732300, 470950800, 471169350, 471387950, 471606600, 471825300, 472044050, 472262850, 472481700, 472700600, 472919550, 473138550, 473357600, 473576700,
	473795850, 474015050, 474234300, 474453600, 474672950, 474892350, 475111800, 475331300, 475550850, 475770450, 475990100, 476209800, 476429550, 476649350, 476869200, 477089100, 477309050, 477529050, 477749100,
	477969200, 478189350, 478409550, 478629800, 478850100, 479070450, 479290850, 479511300, 479731800, 479952350, 480172950, 480393600, 480614300, 480835050, 481055850, 481276700, 481497600, 481718550, 481939550, 482160600, 482381700, 482602850, 482824050, 483045300, 483266600, 483487950, 483709350, 483930800, 484152300, 484373850, 484595450, 484817100, 485038800, 485260550, 485482350, 485704200, 485926100, 486148050, 486370050, 486592100, 486814200, 487036350, 487258550, 487480800, 487703100, 487925450, 488147850, 488370300, 488592800, 488815350, 489037950, 489260600, 489483300, 489706050, 489928850, 490151700, 490374600, 490597550, 490820550, 491043600, 491266700, 491489850, 491713050, 491936300, 492159600, 492382950, 492606350, 492829800, 493053300, 493276850, 493500450, 493724100, 493947800, 494171550, 494395350, 494619200, 494843100, 495067050, 495291050, 495515100, 495739200, 495963350, 496187550, 496411800, 496636100, 496860450, 497084850, 497309300, 497533800, 497758350, 497982950, 498207600, 498432300, 498657050, 498881850, 499106700, 499331600, 499556550, 499781550, 500006600, 500231700, 500456850, 500682050, 500907300, 501132600, 501357950, 501583350, 501808800, 502034300, 502259850, 502485450, 502711100, 502936800, 503162550, 503388350, 503614200, 503840100, 504066050, 504292050, 504518100, 504744200, 504970350, 505196550, 505422800, 505649100, 505875450, 506101850, 506328300, 506554800, 506781350, 507007950, 507234600, 507461300, 507688050, 507914850, 508141700, 508368600, 508595550, 508822550, 509049600, 509276700, 509503850, 509731050, 509958300, 510185600, 510412950, 510640350, 510867800, 511095300, 511322850, 511550450, 511778100, 512005800, 512233550, 512461350, 512689200, 512917100, 513145050, 513373050, 513601100, 513829200, 514057350, 514285550, 514513800, 514742100, 514970450, 515198850, 515427300, 515655800, 515884350, 516112950, 516341600, 516570300, 516799050, 517027850, 517256700, 517485600, 517714550, 517943550, 518172600, 518401700, 518630850, 518860050, 519089300, 519318600, 519547950, 519777350, 520006800, 520236300, 520465850, 520695450, 520925100, 521154800, 521384550, 521614350, 521844200, 522074100, 522304050, 522534050, 522764100, 522994200, 523224350, 523454550, 523684800, 523915100, 524145450, 524375850, 524606300, 524836800, 525067350, 525297950, 525528600, 525759300, 525990050, 526220850, 526451700, 526682600, 526913550, 527144550, 527375600, 527606700, 527837850, 528069050, 528300300, 528531600, 528762950, 528994350, 529225800, 529457300, 529688850, 529920450, 530152100, 530383800, 530615550, 530847350, 531079200, 531311100, 531543050, 531775050, 532007100, 532239200, 532471350, 532703550, 532935800, 533168100, 533400450, 533632850, 533865300, 534097800, 534330350, 534562950, 534795600, 535028300, 535261050, 535493850, 535726700, 535959600, 536192550, 536425550, 536658600, 536891700, 537124850, 537358050, 537591300, 537824600, 538057950, 538291350, 538524800, 538758300, 538991850, 539225450, 539459100, 539692800, 539926550, 540160350, 540394200, 540628100, 540862050, 541096050, 541330100, 541564200, 541798350, 542032550, 542266800, 542501100, 542735450, 542969850, 543204300, 543438800, 543673350, 543907950, 544142600, 544377300, 544612050, 544846850, 545081700, 545316600, 545551550, 545786550, 546021600, 546256700, 546491850, 546727050, 546962300, 547197600, 547432950, 547668350, 547903800, 548139300, 548374850, 548610450, 548846100, 549081800, 549317550, 549553350, 549789200, 550025100, 550261050, 550497050, 550733100, 550969200, 551205350, 551441550, 551677800, 551914100, 552150450, 552386850, 552623300, 552859800, 553096350, 553332950, 553569600, 553806300, 554043050, 554279850, 554516700, 554753600, 554990550, 555227550, 555464600, 555701700, 555938850, 556176050, 556413300, 556650600, 556887950, 557125350, 557362800, 557600300, 557837850, 558075450, 558313100, 558550800, 558788550, 559026350, 559264200, 559502100, 559740050, 559978050, 560216100, 560454200, 560692350, 560930550, 561168800, 561407100, 561645450, 561883850, 562122300, 562360800, 562599350, 562837950, 563076600, 563315300, 563554050, 563792850, 564031700, 564270600, 564509550, 564748550, 564987600, 565226700, 565465850, 565705050, 565944300, 566183600, 566422950, 566662350, 566901800, 567141300, 567380850, 567620450, 567860100, 568099800, 568339550, 568579350, 568819200, 569059100, 569299050, 569539050, 569779100, 570019200, 570259350, 570499550, 570739800, 570980100, 571220450, 571460850, 571701300, 571941800, 572182350, 572422950, 572663600, 572904300, 573145050, 573385850, 573626700, 573867600, 574108550, 574349550, 574590600, 574831700, 575072850, 575314050, 575555300, 575796600, 576037950, 576279350, 576520800, 576762300, 577003850, 577245450, 577487100, 577728800, 577970550, 578212350, 578454200, 578696100, 578938050, 579180050, 579422100, 579664200, 579906350, 580148550, 580390800, 580633100, 580875450, 581117850, 581360300, 581602800, 581845350, 582087950, 582330600, 582573300, 582816050, 583058850, 583301700, 583544600, 583787550, 584030550, 584273600, 584516700, 584759850, 585003050, 585246300, 585489600, 585732950, 585976350, 586219800, 586463300, 586706850, 586950450, 587194100, 587437800, 587681550, 587925350, 588169200, 588413100, 588657050, 588901050, 589145100, 589389200, 589633350, 589877550, 590121800, 590366100, 590610450, 590854850, 591099300, 591343800, 591588350, 591832950, 592077600, 592322300, 592567050, 592811850, 593056700, 593301600, 593546550, 593791550, 594036600, 594281700, 594526850, 594772050, 595017300, 595262600, 595507950, 595753350, 595998800, 596244300, 596489850, 596735450, 596981100, 597226800, 597472550, 597718350, 597964200, 598210100, 598456050, 598702050, 598948100, 599194200, 599440350, 599686550, 599932800, 600179100, 600425450, 600671850, 600918300, 601164800, 601411350, 601657950, 601904600, 602151300, 602398050, 602644850, 602891700, 603138600, 603385550, 603632550, 603879600, 604126700, 604373850, 604621050, 604868300, 605115600, 605362950, 605610350, 605857800, 606105300, 606352850, 606600450, 606848100, 607095800, 607343550, 607591350, 607839200, 608087100, 608335050, 608583050, 608831100, 609079200, 609327350, 609575550, 609823800, 610072100, 610320450, 610568850, 610817300, 611065800, 611314350, 611562950, 611811600, 612060300, 612309050, 612557850, 612806700, 613055600, 613304550, 613553550, 613802600, 614051700, 614300850, 614550050, 614799300, 615048600, 615297950, 615547350, 615796800, 616046300, 616295850, 616545450, 616795100, 617044800, 617294550, 617544350, 617794200, 618044100, 618294050, 618544050, 618794100, 619044200, 619294350, 619544550, 619794800, 620045100, 620295450, 620545850, 620796300, 621046800, 621297350, 621547950, 621798600, 622049300, 622300050, 622550850, 622801700, 623052600, 623303550, 623554550, 623805600, 624056700, 624307850, 624559050, 624810300, 625061600, 625312950, 625564350, 625815800, 626067300, 626318850, 626570450, 626822100, 627073800, 627325550, 627577350, 627829200, 628081100, 628333050, 628585050, 628837100, 629089200, 629341350, 629593550, 629845800, 630098100, 630350450, 630602850, 630855300, 631107800, 631360350, 631612950, 631865600, 632118300, 632371050, 632623850, 632876700, 633129600, 633382550, 633635550, 633888600, 634141700, 634394850, 634648050, 634901300, 635154600, 635407950, 635661350, 635914800, 636168300, 636421850, 636675450, 636929100, 637182800, 637436550, 637690350, 637944200, 638198100, 638452050, 638706050, 638960100, 639214200, 639468350, 639722550, 639976800, 640231100, 640485450, 640739850, 640994300, 641248800, 641503350, 641757950, 642012600, 642267300, 642522050, 642776850, 643031700, 643286600, 643541550, 643796550, 644051600, 644306700, 644561850, 644817050, 645072300, 645327600, 645582950, 645838350, 646093800, 646349300, 646604850, 646860450, 647116100, 647371800, 647627550, 647883350, 648139200, 648395100, 648651050, 648907050, 649163100, 649419200, 649675350, 649931550, 650187800, 650444100, 650700450, 650956850, 651213300, 651469800, 651726350, 651982950, 652239600, 652496300, 652753050, 653009850, 653266700, 653523600, 653780550, 654037550, 654294600, 654551700, 654808850, 655066050, 655323300, 655580600, 655837950, 656095350, 656352800, 656610300, 656867850, 657125450, 657383100, 657640800, 657898550, 658156350, 658414200, 658672100, 658930050, 659188050, 659446100, 659704200, 659962350, 660220550, 660478800, 660737100, 660995450, 661253850, 661512300, 661770800, 662029350, 662287950, 662546600, 662805300, 663064050, 663322850, 663581700, 663840600, 664099550, 664358550, 664617600, 664876700, 665135850, 665395050, 665654300, 665913600, 666172950, 666432350, 666691800, 666951300, 667210850, 667470450, 667730100, 667989800, 668249550, 668509350, 668769200, 669029100, 669289050, 669549050, 669809100, 670069200, 670329350, 670589550, 670849800, 671110100, 671370450, 671630850, 671891300, 672151800, 672412350, 672672950, 672933600, 673194300, 673455050, 673715850, 673976700, 674237600, 674498550, 674759550, 675020600, 675281700, 675542850, 675804050, 676065300, 676326600, 676587950, 676849350, 677110800, 677372300, 677633850, 677895450, 678157100, 678418800, 678680550, 678942350, 679204200, 679466100, 679728050, 679990050, 680252100, 680514200, 680776350, 681038550, 681300800, 681563100, 681825450, 682087850, 682350300, 682612800, 682875350, 683137950, 683400600, 683663300, 683926050, 684188850, 684451700, 684714600, 684977550, 685240550, 685503600, 685766700, 686029850, 686293050, 686556300, 686819600, 687082950, 687346350, 687609800, 687873300, 688136850, 688400450, 688664100, 688927800, 689191550, 689455350, 689719200, 689983100, 690247050, 690511050, 690775100, 691039200, 691303350, 691567550, 691831800, 692096100, 692360450, 692624850, 692889300, 693153800, 693418350, 693682950, 693947600, 694212300, 694477050, 694741850, 695006700, 695271600, 695536550, 695801550, 696066600, 696331700, 696596850, 696862050, 697127300, 697392600, 697657950, 697923350, 698188800, 698454300, 698719850, 698985450, 699251100, 699516800, 699782550, 700048350, 700314200, 700580100, 700846050, 701112050, 701378100, 701644200, 701910350, 702176550, 702442800, 702709100, 702975450, 703241850, 703508300, 703774800, 704041350, 704307950, 704574600, 704841300, 705108050, 705374850, 705641700, 705908600, 706175550, 706442550, 706709600, 706976700, 707243850, 707511050, 707778300, 708045600, 708312950, 708580350, 708847800, 709115300, 709382850, 709650450, 709918100, 710185800, 710453550, 710721350, 710989200, 711257100, 711525050, 711793050, 712061100, 712329200, 712597350, 712865550, 713133800, 713402100, 713670450, 713938850, 714207300, 714475800, 714744350, 715012950, 715281600, 715550300, 715819050, 716087850, 716356700, 716625600, 716894550, 717163550, 717432600, 717701700, 717970850, 718240050, 718509300, 718778600, 719047950, 719317350, 719586800, 719856300, 720125850, 720395450, 720665100, 720934800, 721204550, 721474350, 721744200, 722014100, 722284050, 722554050, 722824100, 723094200, 723364350, 723634550, 723904800, 724175100, 724445450, 724715850, 724986300, 725256800, 725527350, 725797950, 726068600, 726339300, 726610050, 726880850, 727151700, 727422600, 727693550, 727964550, 728235600, 728506700, 728777850, 729049050, 729320300, 729591600, 729862950, 730134350, 730405800, 730677300, 730948850, 731220450, 731492100, 731763800, 732035550, 732307350, 732579200, 732851100, 733123050, 733395050, 733667100, 733939200, 734211350, 734483550, 734755800, 735028100, 735300450, 735572850, 735845300, 736117800, 736390350, 736662950, 736935600, 737208300, 737481050, 737753850, 738026700, 738299600, 738572550, 738845550, 739118600, 739391700, 739664850, 739938050, 740211300, 740484600, 740757950, 741031350, 741304800, 741578300, 741851850, 742125450, 742399100, 742672800, 742946550, 743220350, 743494200, 743768100, 744042050, 744316050, 744590100, 744864200, 745138350, 745412550, 745686800, 745961100, 746235450, 746509850, 746784300, 747058800, 747333350, 747607950, 747882600, 748157300, 748432050, 748706850, 748981700, 749256600, 749531550, 749806550, 750081600, 750356700, 750631850, 750907050, 751182300, 751457600, 751732950, 752008350, 752283800, 752559300, 752834850, 753110450, 753386100, 753661800, 753937550, 754213350, 754489200, 754765100, 755041050, 755317050, 755593100, 755869200, 756145350, 756421550, 756697800, 756974100, 757250450, 757526850, 757803300, 758079800, 758356350, 758632950, 758909600, 759186300, 759463050, 759739850, 760016700, 760293600, 760570550, 760847550, 761124600, 761401700, 761678850, 761956050, 762233300, 762510600, 762787950, 763065350, 763342800, 763620300, 763897850, 764175450, 764453100, 764730800, 765008550, 765286350, 765564200, 765842100, 766120050, 766398050, 766676100, 766954200, 767232350, 767510550, 767788800, 768067100, 768345450, 768623850, 768902300, 769180800, 769459350, 769737950, 770016600, 770295300, 770574050, 770852850, 771131700, 771410600, 771689550, 771968550, 772247600, 772526700, 772805850, 773085050, 773364300, 773643600, 773922950, 774202350, 774481800, 774761300, 775040850, 775320450, 775600100, 775879800, 776159550, 776439350, 776719200, 776999100, 777279050, 777559050, 777839100, 778119200, 778399350, 778679550, 778959800, 779240100, 779520450, 779800850, 780081300, 780361800, 780642350, 780922950, 781203600, 781484300, 781765050, 782045850, 782326700, 782607600, 782888550, 783169550, 783450600, 783731700, 784012850, 784294050, 784575300, 784856600, 785137950, 785419350, 785700800, 785982300, 786263850, 786545450, 786827100, 787108800, 787390550, 787672350, 787954200, 788236100, 788518050, 788800050, 789082100, 789364200, 789646350, 789928550, 790210800, 790493100, 790775450, 791057850, 791340300, 791622800, 791905350, 792187950, 792470600, 792753300, 793036050, 793318850, 793601700, 793884600, 794167550, 794450550, 794733600, 795016700, 795299850, 795583050, 795866300, 796149600, 796432950, 796716350, 796999800, 797283300, 797566850, 797850450, 798134100, 798417800, 798701550, 798985350, 799269200, 799553100, 799837050, 800121050, 800405100, 800689200, 800973350, 801257550, 801541800, 801826100, 802110450, 802394850, 802679300, 802963800, 803248350, 803532950, 803817600, 804102300, 804387050, 804671850, 804956700, 805241600, 805526550, 805811550, 806096600, 806381700, 806666850, 806952050, 807237300, 807522600, 807807950, 808093350, 808378800, 808664300, 808949850, 809235450, 809521100, 809806800, 810092550, 810378350, 810664200, 810950100, 811236050, 811522050, 811808100, 812094200, 812380350, 812666550, 812952800, 813239100, 813525450, 813811850, 814098300, 814384800, 814671350, 814957950, 815244600, 815531300, 815818050, 816104850, 816391700, 816678600, 816965550, 817252550, 817539600, 817826700, 818113850, 818401050, 818688300, 818975600, 819262950, 819550350, 819837800, 820125300, 820412850, 820700450, 820988100, 821275800, 821563550, 821851350, 822139200, 822427100, 822715050, 823003050, 823291100, 823579200, 823867350, 824155550, 824443800, 824732100, 825020450, 825308850, 825597300, 825885800, 826174350, 826462950, 826751600, 827040300, 827329050, 827617850, 827906700, 828195600, 828484550, 828773550, 829062600, 829351700, 829640850, 829930050, 830219300, 830508600, 830797950, 831087350, 831376800, 831666300, 831955850, 832245450, 832535100, 832824800, 833114550, 833404350, 833694200, 833984100, 834274050, 834564050, 834854100, 835144200, 835434350, 835724550, 836014800, 836305100, 836595450, 836885850, 837176300, 837466800, 837757350, 838047950, 838338600, 838629300, 838920050, 839210850, 839501700, 839792600, 840083550, 840374550, 840665600, 840956700, 841247850, 841539050, 841830300, 842121600, 842412950, 842704350, 842995800, 843287300, 843578850, 843870450, 844162100, 844453800, 844745550, 845037350, 845329200, 845621100, 845913050, 846205050, 846497100, 846789200, 847081350, 847373550, 847665800, 847958100, 848250450, 848542850, 848835300, 849127800, 849420350, 849712950, 850005600, 850298300, 850591050, 850883850, 851176700, 851469600, 851762550, 852055550, 852348600, 852641700, 852934850, 853228050, 853521300, 853814600, 854107950, 854401350, 854694800, 854988300, 855281850, 855575450, 855869100, 856162800, 856456550, 856750350, 857044200, 857338100, 857632050, 857926050, 858220100, 858514200, 858808350, 859102550, 859396800, 859691100, 859985450, 860279850, 860574300, 860868800, 861163350, 861457950, 861752600, 862047300, 862342050, 862636850, 862931700, 863226600, 863521550, 863816550, 864111600, 864406700, 864701850, 864997050, 865292300, 865587600, 865882950, 866178350, 866473800, 866769300, 867064850, 867360450, 867656100, 867951800, 868247550, 868543350, 868839200, 869135100, 869431050, 869727050, 870023100, 870319200, 870615350, 870911550, 871207800, 871504100, 871800450, 872096850, 872393300, 872689800, 872986350, 873282950, 873579600, 873876300, 874173050, 874469850, 874766700, 875063600, 875360550, 875657550, 875954600, 876251700, 876548850, 876846050, 877143300, 877440600, 877737950, 878035350, 878332800, 878630300, 878927850, 879225450, 879523100, 879820800, 880118550, 880416350, 880714200, 881012100, 881310050, 881608050, 881906100, 882204200, 882502350, 882800550, 883098800, 883397100, 883695450, 883993850, 884292300, 884590800, 884889350, 885187950, 885486600, 885785300, 886084050, 886382850, 886681700, 886980600, 887279550, 887578550, 887877600, 888176700, 888475850, 888775050, 889074300, 889373600, 889672950, 889972350, 890271800, 890571300, 890870850, 891170450, 891470100, 891769800, 892069550, 892369350, 892669200, 892969100, 893269050, 893569050, 893869100, 894169200, 894469350, 894769550, 895069800, 895370100, 895670450, 895970850, 896271300, 896571800, 896872350, 897172950, 897473600, 897774300, 898075050, 898375850, 898676700, 898977600, 899278550, 899579550, 899880600, 900181700, 900482850, 900784050, 901085300, 901386600, 901687950, 901989350, 902290800, 902592300, 902893850, 903195450, 903497100, 903798800, 904100550, 904402350, 904704200, 905006100, 905308050, 905610050, 905912100, 906214200, 906516350, 906818550, 907120800, 907423100, 907725450, 908027850, 908330300, 908632800, 908935350, 909237950, 909540600, 909843300, 910146050, 910448850, 910751700, 911054600, 911357550, 911660550, 911963600, 912266700, 912569850, 912873050, 913176300, 913479600, 913782950, 914086350, 914389800, 914693300, 914996850, 915300450, 915604100, 915907800, 916211550, 916515350, 916819200, 917123100, 917427050, 917731050, 918035100, 918339200, 918643350, 918947550, 919251800, 919556100, 919860450, 920164850, 920469300, 920773800, 921078350, 921382950, 921687600, 921992300, 922297050, 922601850, 922906700, 923211600, 923516550, 923821550, 924126600, 924431700, 924736850, 925042050, 925347300, 925652600, 925957950, 926263350, 926568800, 926874300, 927179850, 927485450, 927791100, 928096800, 928402550, 928708350, 929014200, 929320100, 929626050, 929932050, 930238100, 930544200, 930850350, 931156550, 931462800, 931769100, 932075450, 932381850, 932688300, 932994800, 933301350, 933607950, 933914600, 934221300, 934528050, 934834850, 935141700, 935448600, 935755550, 936062550, 936369600, 936676700, 936983850, 937291050, 937598300, 937905600, 938212950, 938520350, 938827800, 939135300, 939442850, 939750450, 940058100, 940365800, 940673550, 940981350, 941289200, 941597100, 941905050, 942213050, 942521100, 942829200, 943137350, 943445550, 943753800, 944062100, 944370450, 944678850, 944987300, 945295800, 945604350, 945912950, 946221600, 946530300, 946839050, 947147850, 947456700, 947765600, 948074550, 948383550, 948692600, 949001700, 949310850, 949620050, 949929300, 950238600, 950547950, 950857350, 951166800, 951476300, 951785850, 952095450, 952405100, 952714800, 953024550, 953334350, 953644200, 953954100, 954264050, 954574050, 954884100, 955194200, 955504350, 955814550, 956124800, 956435100, 956745450, 957055850, 957366300, 957676800, 957987350, 958297950, 958608600, 958919300, 959230050, 959540850, 959851700, 960162600, 960473550, 960784550, 961095600, 961406700, 961717850, 962029050, 962340300, 962651600, 962962950, 963274350, 963585800, 963897300, 964208850, 964520450, 964832100, 965143800, 965455550, 965767350, 966079200, 966391100, 966703050, 967015050, 967327100, 967639200, 967951350, 968263550, 968575800, 968888100, 969200450, 969512850, 969825300, 970137800, 970450350, 970762950, 971075600, 971388300, 971701050, 972013850, 972326700, 972639600, 972952550, 973265550, 973578600, 973891700, 974204850, 974518050, 974831300, 975144600, 975457950, 975771350, 976084800, 976398300, 976711850, 977025450, 977339100, 977652800, 977966550, 978280350, 978594200, 978908100, 979222050, 979536050, 979850100, 980164200, 980478350, 980792550, 981106800, 981421100, 981735450, 982049850, 982364300, 982678800, 982993350, 983307950, 983622600, 983937300, 984252050, 984566850, 984881700, 985196600, 985511550, 985826550, 986141600, 986456700, 986771850, 987087050, 987402300, 987717600, 988032950, 988348350, 988663800, 988979300, 989294850, 989610450, 989926100, 990241800, 990557550, 990873350, 991189200, 991505100, 991821050, 992137050, 992453100, 992769200, 993085350, 993401550, 993717800, 994034100, 994350450, 994666850, 994983300, 995299800, 995616350, 995932950, 996249600, 996566300, 996883050, 997199850, 997516700, 997833600, 998150550, 998467550, 998784600, 999101700, 999418850, 999736050, 1000053300, 1000370600, 1000687950, 1001005350, 1001322800, 1001640300, 1001957850, 1002275450, 1002593100, 1002910800, 1003228550, 1003546350, 1003864200, 1004182100, 1004500050, 1004818050, 1005136100, 1005454200, 1005772350, 1006090550, 1006408800, 1006727100, 1007045450, 1007363850, 1007682300, 1008000800, 1008319350, 1008637950, 1008956600, 1009275300, 1009594050, 1009912850, 1010231700, 1010550600, 1010869550, 1011188550, 1011507600, 1011826700, 1012145850, 1012465050, 1012784300, 1013103600, 1013422950, 1013742350, 1014061800, 1014381300, 1014700850, 1015020450, 1015340100, 1015659800, 1015979550, 1016299350, 1016619200, 1016939100, 1017259050, 1017579050, 1017899100, 1018219200, 1018539350, 1018859550, 1019179800, 1019500100, 1019820450, 1020140850, 1020461300, 1020781800, 1021102350, 1021422950, 1021743600, 1022064300, 1022385050, 1022705850, 1023026700, 1023347600, 1023668550, 1023989550, 1024310600, 1024631700, 1024952850, 1025274050, 1025595300, 1025916600, 1026237950, 1026559350, 1026880800, 1027202300, 1027523850, 1027845450, 1028167100, 1028488800, 1028810550, 1029132350, 1029454200, 1029776100, 1030098050, 1030420050, 1030742100, 1031064200, 1031386350, 1031708550, 1032030800, 1032353100, 1032675450, 1032997850, 1033320300, 1033642800, 1033965350, 1034287950, 1034610600, 1034933300, 1035256050, 1035578850, 1035901700, 1036224600, 1036547550, 1036870550, 1037193600, 1037516700, 1037839850, 1038163050, 1038486300, 1038809600, 1039132950, 1039456350, 1039779800, 1040103300, 1040426850, 1040750450, 1041074100, 1041397800, 1041721550, 1042045350, 1042369200, 1042693100, 1043017050, 1043341050, 1043665100, 1043989200, 1044313350, 1044637550, 1044961800, 1045286100, 1045610450, 1045934850, 1046259300, 1046583800, 1046908350, 1047232950, 1047557600, 1047882300, 1048207050, 1048531850, 1048856700, 1049181600, 1049506550, 1049831550, 1050156600, 1050481700, 1050806850, 1051132050, 1051457300, 1051782600, 1052107950, 1052433350, 1052758800, 1053084300, 1053409850, 1053735450, 1054061100, 1054386800, 1054712550, 1055038350, 1055364200, 1055690100, 1056016050, 1056342050, 1056668100, 1056994200, 1057320350, 1057646550, 1057972800, 1058299100, 1058625450, 1058951850, 1059278300, 1059604800, 1059931350, 1060257950, 1060584600, 1060911300, 1061238050, 1061564850, 1061891700, 1062218600, 1062545550, 1062872550, 1063199600, 1063526700, 1063853850, 1064181050, 1064508300, 1064835600, 1065162950, 1065490350, 1065817800, 1066145300, 1066472850, 1066800450, 1067128100, 1067455800, 1067783550, 1068111350, 1068439200, 1068767100, 1069095050, 1069423050, 1069751100, 1070079200, 1070407350, 1070735550, 1071063800, 1071392100, 1071720450, 1072048850, 1072377300, 1072705800, 1073034350, 1073362950, 1073691600, 1074020300, 1074349050, 1074677850, 1075006700, 1075335600, 1075664550, 1075993550, 1076322600, 1076651700, 1076980850, 1077310050, 1077639300, 1077968600, 1078297950, 1078627350, 1078956800, 1079286300, 1079615850, 1079945450, 1080275100, 1080604800, 1080934550, 1081264350, 1081594200, 1081924100, 1082254050, 1082584050, 1082914100, 1083244200, 1083574350, 1083904550, 1084234800, 1084565100, 1084895450, 1085225850, 1085556300, 1085886800, 1086217350, 1086547950, 1086878600, 1087209300, 1087540050, 1087870850, 1088201700, 1088532600, 1088863550, 1089194550, 1089525600, 1089856700, 1090187850, 1090519050, 1090850300, 1091181600, 1091512950, 1091844350, 1092175800, 1092507300, 1092838850, 1093170450, 1093502100, 1093833800, 1094165550, 1094497350, 1094829200, 1095161100, 1095493050, 1095825050, 1096157100, 1096489200, 1096821350, 1097153550, 1097485800, 1097818100, 1098150450, 1098482850, 1098815300, 1099147800, 1099480350, 1099812950, 1100145600, 1100478300, 1100811050, 1101143850, 1101476700, 1101809600, 1102142550, 1102475550, 1102808600, 1103141700, 1103474850, 1103808050, 1104141300, 1104474600, 1104807950, 1105141350, 1105474800, 1105808300, 1106141850, 1106475450, 1106809100, 1107142800, 1107476550, 1107810350, 1108144200, 1108478100, 1108812050, 1109146050, 1109480100, 1109814200, 1110148350, 1110482550, 1110816800, 1111151100, 1111485450, 1111819850, 1112154300, 1112488800, 1112823350, 1113157950, 1113492600, 1113827300, 1114162050, 1114496850, 1114831700, 1115166600, 1115501550, 1115836550, 1116171600, 1116506700, 1116841850, 1117177050, 1117512300, 1117847600, 1118182950, 1118518350, 1118853800, 1119189300, 1119524850, 1119860450, 1120196100, 1120531800, 1120867550, 1121203350, 1121539200, 1121875100, 1122211050, 1122547050, 1122883100, 1123219200, 1123555350, 1123891550, 1124227800, 1124564100, 1124900450, 1125236850, 1125573300, 1125909800, 1126246350, 1126582950, 1126919600, 1127256300, 1127593050, 1127929850, 1128266700, 1128603600, 1128940550, 1129277550, 1129614600, 1129951700, 1130288850, 1130626050, 1130963300, 1131300600, 1131637950, 1131975350, 1132312800, 1132650300, 1132987850, 1133325450, 1133663100, 1134000800, 1134338550, 1134676350, 1135014200, 1135352100, 1135690050, 1136028050, 1136366100, 1136704200, 1137042350, 1137380550, 1137718800, 1138057100, 1138395450, 1138733850, 1139072300, 1139410800, 1139749350, 1140087950, 1140426600, 1140765300, 1141104050, 1141442850, 1141781700, 1142120600, 1142459550, 1142798550, 1143137600, 1143476700, 1143815850, 1144155050, 1144494300, 1144833600, 1145172950, 1145512350, 1145851800, 1146191300, 1146530850, 1146870450, 1147210100, 1147549800, 1147889550, 1148229350, 1148569200, 1148909100, 1149249050, 1149589050, 1149929100, 1150269200, 1150609350, 1150949550, 1151289800, 1151630100, 1151970450, 1152310850, 1152651300, 1152991800, 1153332350, 1153672950, 1154013600, 1154354300, 1154695050, 1155035850, 1155376700, 1155717600, 1156058550, 1156399550, 1156740600, 1157081700, 1157422850, 1157764050, 1158105300, 1158446600, 1158787950, 1159129350, 1159470800, 1159812300, 1160153850, 1160495450, 1160837100, 1161178800, 1161520550, 1161862350, 1162204200, 1162546100, 1162888050, 1163230050, 1163572100, 1163914200, 1164256350, 1164598550, 1164940800, 1165283100, 1165625450, 1165967850, 1166310300, 1166652800, 1166995350, 1167337950, 1167680600, 1168023300, 1168366050, 1168708850, 1169051700, 1169394600, 1169737550, 1170080550, 1170423600, 1170766700, 1171109850, 1171453050, 1171796300, 1172139600, 1172482950, 1172826350, 1173169800, 1173513300, 1173856850, 1174200450, 1174544100, 1174887800, 1175231550, 1175575350, 1175919200, 1176263100, 1176607050, 1176951050, 1177295100, 1177639200, 1177983350, 1178327550, 1178671800, 1179016100, 1179360450, 1179704850, 1180049300, 1180393800, 1180738350, 1181082950, 1181427600, 1181772300, 1182117050, 1182461850, 1182806700, 1183151600, 1183496550, 1183841550, 1184186600, 1184531700, 1184876850, 1185222050, 1185567300, 1185912600, 1186257950, 1186603350, 1186948800, 1187294300, 1187639850, 1187985450, 1188331100, 1188676800, 1189022550, 1189368350, 1189714200, 1190060100, 1190406050, 1190752050, 1191098100, 1191444200, 1191790350, 1192136550, 1192482800, 1192829100, 1193175450, 1193521850, 1193868300, 1194214800, 1194561350, 1194907950, 1195254600, 1195601300, 1195948050, 1196294850, 1196641700, 1196988600, 1197335550, 1197682550, 1198029600, 1198376700, 1198723850, 1199071050, 1199418300, 1199765600, 1200112950, 1200460350, 1200807800, 1201155300, 1201502850, 1201850450, 1202198100, 1202545800, 1202893550, 1203241350, 1203589200, 1203937100, 1204285050, 1204633050, 1204981100, 1205329200, 1205677350, 1206025550, 1206373800, 1206722100, 1207070450, 1207418850, 1207767300, 1208115800, 1208464350, 1208812950, 1209161600, 1209510300, 1209859050, 1210207850, 1210556700, 1210905600, 1211254550, 1211603550, 1211952600, 1212301700, 1212650850, 1213000050, 1213349300, 1213698600, 1214047950, 1214397350, 1214746800, 1215096300, 1215445850, 1215795450, 1216145100, 1216494800, 1216844550, 1217194350, 1217544200, 1217894100, 1218244050, 1218594050, 1218944100, 1219294200, 1219644350, 1219994550, 1220344800, 1220695100, 1221045450, 1221395850, 1221746300, 1222096800, 1222447350, 1222797950, 1223148600, 1223499300, 1223850050, 1224200850, 1224551700, 1224902600, 1225253550, 1225604550, 1225955600, 1226306700, 1226657850, 1227009050, 1227360300, 1227711600, 1228062950, 1228414350, 1228765800, 1229117300, 1229468850, 1229820450, 1230172100, 1230523800, 1230875550, 1231227350, 1231579200, 1231931100, 1232283050, 1232635050, 1232987100, 1233339200, 1233691350, 1234043550, 1234395800, 1234748100, 1235100450, 1235452850, 1235805300, 1236157800, 1236510350, 1236862950, 1237215600, 1237568300, 1237921050, 1238273850, 1238626700, 1238979600, 1239332550, 1239685550, 1240038600, 1240391700, 1240744850, 1241098050, 1241451300, 1241804600, 1242157950, 1242511350, 1242864800, 1243218300, 1243571850, 1243925450, 1244279100, 1244632800, 1244986550, 1245340350, 1245694200, 1246048100, 1246402050, 1246756050, 1247110100, 1247464200, 1247818350, 1248172550, 1248526800, 1248881100, 1249235450, 1249589850, 1249944300, 1250298800, 1250653350, 1251007950, 1251362600, 1251717300, 1252072050, 1252426850, 1252781700, 1253136600, 1253491550, 1253846550, 1254201600, 1254556700, 1254911850, 1255267050, 1255622300, 1255977600, 1256332950, 1256688350, 1257043800, 1257399300, 1257754850, 1258110450, 1258466100, 1258821800, 1259177550, 1259533350, 1259889200, 1260245100, 1260601050, 1260957050, 1261313100, 1261669200, 1262025350, 1262381550, 1262737800, 1263094100, 1263450450, 1263806850, 1264163300, 1264519800, 1264876350, 1265232950, 1265589600, 1265946300, 1266303050, 1266659850, 1267016700, 1267373600, 1267730550, 1268087550, 1268444600, 1268801700, 1269158850, 1269516050, 1269873300, 1270230600, 1270587950, 1270945350, 1271302800, 1271660300, 1272017850, 1272375450, 1272733100, 1273090800, 1273448550, 1273806350, 1274164200, 1274522100, 1274880050, 1275238050, 1275596100, 1275954200, 1276312350, 1276670550, 1277028800, 1277387100, 1277745450, 1278103850, 1278462300, 1278820800, 1279179350, 1279537950, 1279896600, 1280255300, 1280614050, 1280972850, 1281331700, 1281690600, 1282049550, 1282408550, 1282767600, 1283126700, 1283485850, 1283845050, 1284204300, 1284563600, 1284922950, 1285282350, 1285641800, 1286001300, 1286360850, 1286720450, 1287080100, 1287439800, 1287799550, 1288159350, 1288519200, 1288879100, 1289239050, 1289599050, 1289959100, 1290319200, 1290679350, 1291039550, 1291399800, 1291760100, 1292120450, 1292480850, 1292841300, 1293201800, 1293562350, 1293922950, 1294283600, 1294644300, 1295005050, 1295365850, 1295726700, 1296087600, 1296448550, 1296809550, 1297170600, 1297531700, 1297892850, 1298254050, 1298615300, 1298976600, 1299337950, 1299699350, 1300060800, 1300422300, 1300783850, 1301145450, 1301507100, 1301868800, 1302230550, 1302592350, 1302954200, 1303316100, 1303678050, 1304040050, 1304402100, 1304764200, 1305126350, 1305488550, 1305850800, 1306213100, 1306575450, 1306937850, 1307300300, 1307662800, 1308025350, 1308387950, 1308750600, 1309113300, 1309476050, 1309838850, 1310201700, 1310564600, 1310927550, 1311290550, 1311653600, 1312016700, 1312379850, 1312743050, 1313106300, 1313469600, 1313832950, 1314196350, 1314559800, 1314923300, 1315286850, 1315650450, 1316014100, 1316377800, 1316741550, 1317105350, 1317469200, 1317833100, 1318197050, 1318561050, 1318925100, 1319289200, 1319653350, 1320017550, 1320381800, 1320746100, 1321110450, 1321474850, 1321839300, 1322203800, 1322568350, 1322932950, 1323297600, 1323662300, 1324027050, 1324391850, 1324756700, 1325121600, 1325486550, 1325851550, 1326216600, 1326581700, 1326946850, 1327312050, 1327677300, 1328042600, 1328407950, 1328773350, 1329138800, 1329504300, 1329869850, 1330235450, 1330601100, 1330966800, 1331332550, 1331698350, 1332064200, 1332430100, 1332796050, 1333162050, 1333528100, 1333894200, 1334260350, 1334626550, 1334992800, 1335359100, 1335725450, 1336091850, 1336458300, 1336824800, 1337191350, 1337557950, 1337924600, 1338291300, 1338658050, 1339024850, 1339391700, 1339758600, 1340125550, 1340492550, 1340859600, 1341226700, 1341593850, 1341961050, 1342328300, 1342695600, 1343062950, 1343430350, 1343797800, 1344165300, 1344532850, 1344900450, 1345268100, 1345635800, 1346003550, 1346371350, 1346739200, 1347107100, 1347475050, 1347843050, 1348211100, 1348579200, 1348947350, 1349315550, 1349683800, 1350052100, 1350420450, 1350788850, 1351157300, 1351525800, 1351894350, 1352262950, 1352631600, 1353000300, 1353369050, 1353737850, 1354106700, 1354475600, 1354844550, 1355213550, 1355582600, 1355951700, 1356320850, 1356690050, 1357059300, 1357428600, 1357797950, 1358167350, 1358536800, 1358906300, 1359275850, 1359645450, 1360015100, 1360384800, 1360754550, 1361124350, 1361494200, 1361864100, 1362234050, 1362604050, 1362974100, 1363344200, 1363714350, 1364084550, 1364454800, 1364825100, 1365195450, 1365565850, 1365936300, 1366306800, 1366677350, 1367047950, 1367418600, 1367789300, 1368160050, 1368530850, 1368901700, 1369272600, 1369643550, 1370014550, 1370385600, 1370756700, 1371127850, 1371499050, 1371870300, 1372241600, 1372612950, 1372984350, 1373355800, 1373727300, 1374098850, 1374470450, 1374842100, 1375213800, 1375585550, 1375957350, 1376329200, 1376701100, 1377073050, 1377445050, 1377817100, 1378189200, 1378561350, 1378933550, 1379305800, 1379678100, 1380050450, 1380422850, 1380795300, 1381167800, 1381540350, 1381912950, 1382285600, 1382658300, 1383031050, 1383403850, 1383776700, 1384149600, 1384522550, 1384895550, 1385268600, 1385641700, 1386014850, 1386388050, 1386761300, 1387134600, 1387507950, 1387881350, 1388254800, 1388628300, 1389001850, 1389375450, 1389749100, 1390122800, 1390496550, 1390870350, 1391244200, 1391618100, 1391992050, 1392366050, 1392740100, 1393114200, 1393488350, 1393862550, 1394236800, 1394611100, 1394985450, 1395359850, 1395734300, 1396108800, 1396483350, 1396857950, 1397232600, 1397607300, 1397982050, 1398356850, 1398731700, 1399106600, 1399481550, 1399856550, 1400231600, 1400606700, 1400981850, 1401357050, 1401732300, 1402107600, 1402482950, 1402858350, 1403233800, 1403609300, 1403984850, 1404360450, 1404736100, 1405111800, 1405487550, 1405863350, 1406239200, 1406615100, 1406991050, 1407367050, 1407743100, 1408119200, 1408495350, 1408871550, 1409247800, 1409624100, 1410000450, 1410376850, 1410753300, 1411129800, 1411506350, 1411882950, 1412259600, 1412636300, 1413013050, 1413389850, 1413766700, 1414143600, 1414520550, 1414897550, 1415274600, 1415651700, 1416028850, 1416406050, 1416783300, 1417160600, 1417537950, 1417915350, 1418292800, 1418670300, 1419047850, 1419425450, 1419803100, 1420180800, 1420558550, 1420936350, 1421314200, 1421692100, 1422070050, 1422448050, 1422826100, 1423204200, 1423582350, 1423960550, 1424338800, 1424717100, 1425095450, 1425473850, 1425852300, 1426230800, 1426609350, 1426987950, 1427366600, 1427745300, 1428124050, 1428502850, 1428881700, 1429260600, 1429639550, 1430018550, 1430397600, 1430776700, 1431155850, 1431535050, 1431914300, 1432293600, 1432672950, 1433052350, 1433431800, 1433811300, 1434190850, 1434570450, 1434950100, 1435329800, 1435709550, 1436089350, 1436469200, 1436849100, 1437229050, 1437609050, 1437989100, 1438369200, 1438749350, 1439129550, 1439509800, 1439890100, 1440270450, 1440650850, 1441031300, 1441411800, 1441792350, 1442172950, 1442553600, 1442934300, 1443315050, 1443695850, 1444076700, 1444457600, 1444838550, 1445219550, 1445600600, 1445981700, 1446362850, 1446744050, 1447125300, 1447506600, 1447887950, 1448269350, 1448650800, 1449032300, 1449413850, 1449795450, 1450177100, 1450558800, 1450940550, 1451322350, 1451704200, 1452086100, 1452468050, 1452850050, 1453232100, 1453614200, 1453996350, 1454378550, 1454760800, 1455143100, 1455525450, 1455907850, 1456290300, 1456672800, 1457055350, 1457437950, 1457820600, 1458203300, 1458586050, 1458968850, 1459351700, 1459734600, 1460117550, 1460500550, 1460883600, 1461266700, 1461649850, 1462033050, 1462416300, 1462799600, 1463182950, 1463566350, 1463949800, 1464333300, 1464716850, 1465100450, 1465484100, 1465867800, 1466251550, 1466635350, 1467019200, 1467403100, 1467787050, 1468171050, 1468555100, 1468939200, 1469323350, 1469707550, 1470091800, 1470476100, 1470860450, 1471244850, 1471629300, 1472013800, 1472398350, 1472782950, 1473167600, 1473552300, 1473937050, 1474321850, 1474706700, 1475091600, 1475476550, 1475861550, 1476246600, 1476631700, 1477016850, 1477402050, 1477787300, 1478172600, 1478557950, 1478943350, 1479328800, 1479714300, 1480099850, 1480485450, 1480871100, 1481256800, 1481642550, 1482028350, 1482414200, 1482800100, 1483186050, 1483572050, 1483958100, 1484344200, 1484730350, 1485116550, 1485502800, 1485889100, 1486275450, 1486661850, 1487048300, 1487434800, 1487821350, 1488207950, 1488594600, 1488981300, 1489368050, 1489754850, 1490141700, 1490528600, 1490915550, 1491302550, 1491689600, 1492076700, 1492463850, 1492851050, 1493238300, 1493625600, 1494012950, 1494400350, 1494787800, 1495175300, 1495562850, 1495950450, 1496338100, 1496725800, 1497113550, 1497501350, 1497889200, 1498277100, 1498665050, 1499053050, 1499441100, 1499829200, 1500217350, 1500605550, 1500993800, 1501382100, 1501770450, 1502158850, 1502547300, 1502935800, 1503324350, 1503712950, 1504101600, 1504490300, 1504879050, 1505267850, 1505656700, 1506045600, 1506434550, 1506823550, 1507212600, 1507601700, 1507990850, 1508380050, 1508769300, 1509158600, 1509547950, 1509937350, 1510326800, 1510716300, 1511105850, 1511495450, 1511885100, 1512274800, 1512664550, 1513054350, 1513444200, 1513834100, 1514224050, 1514614050, 1515004100, 1515394200, 1515784350, 1516174550, 1516564800, 1516955100, 1517345450, 1517735850, 1518126300, 1518516800, 1518907350, 1519297950, 1519688600, 1520079300, 1520470050, 1520860850, 1521251700, 1521642600, 1522033550, 1522424550, 1522815600, 1523206700, 1523597850, 1523989050, 1524380300, 1524771600, 1525162950, 1525554350, 1525945800, 1526337300, 1526728850, 1527120450, 1527512100, 1527903800, 1528295550, 1528687350, 1529079200, 1529471100, 1529863050, 1530255050, 1530647100, 1531039200, 1531431350, 1531823550, 1532215800, 1532608100, 1533000450, 1533392850, 1533785300, 1534177800, 1534570350, 1534962950, 1535355600, 1535748300, 1536141050, 1536533850, 1536926700, 1537319600, 1537712550, 1538105550, 1538498600, 1538891700, 1539284850, 1539678050, 1540071300, 1540464600, 1540857950, 1541251350, 1541644800, 1542038300, 1542431850, 1542825450, 1543219100, 1543612800, 1544006550, 1544400350, 1544794200, 1545188100, 1545582050, 1545976050, 1546370100, 1546764200, 1547158350, 1547552550, 1547946800, 1548341100, 1548735450, 1549129850, 1549524300, 1549918800, 1550313350, 1550707950, 1551102600, 1551497300, 1551892050, 1552286850, 1552681700, 1553076600, 1553471550, 1553866550, 1554261600, 1554656700, 1555051850, 1555447050, 1555842300, 1556237600, 1556632950, 1557028350, 1557423800, 1557819300, 1558214850, 1558610450, 1559006100, 1559401800, 1559797550, 1560193350, 1560589200, 1560985100, 1561381050, 1561777050, 1562173100, 1562569200, 1562965350, 1563361550, 1563757800, 1564154100, 1564550450, 1564946850, 1565343300, 1565739800, 1566136350, 1566532950, 1566929600, 1567326300, 1567723050, 1568119850, 1568516700, 1568913600, 1569310550, 1569707550, 1570104600, 1570501700, 1570898850, 1571296050, 1571693300, 1572090600, 1572487950, 1572885350, 1573282800, 1573680300, 1574077850, 1574475450, 1574873100, 1575270800, 1575668550, 1576066350, 1576464200, 1576862100, 1577260050, 1577658050, 1578056100, 1578454200, 1578852350, 1579250550, 1579648800, 1580047100, 1580445450, 1580843850, 1581242300, 1581640800, 1582039350, 1582437950, 1582836600, 1583235300, 1583634050, 1584032850, 1584431700, 1584830600, 1585229550, 1585628550, 1586027600, 1586426700, 1586825850, 1587225050, 1587624300, 1588023600, 1588422950, 1588822350, 1589221800, 1589621300, 1590020850, 1590420450, 1590820100, 1591219800, 1591619550, 1592019350, 1592419200, 1592819100, 1593219050, 1593619050, 1594019100, 1594419200, 1594819350, 1595219550, 1595619800, 1596020100, 1596420450, 1596820850, 1597221300, 1597621800, 1598022350, 1598422950, 1598823600, 1599224300, 1599625050, 1600025850, 1600426700, 1600827600, 1601228550, 1601629550, 1602030600, 1602431700, 1602832850, 1603234050, 1603635300, 1604036600, 1604437950, 1604839350, 1605240800, 1605642300, 1606043850, 1606445450, 1606847100, 1607248800, 1607650550, 1608052350, 1608454200, 1608856100, 1609258050, 1609660050, 1610062100, 1610464200, 1610866350, 1611268550, 1611670800, 1612073100, 1612475450, 1612877850, 1613280300, 1613682800, 1614085350, 1614487950, 1614890600, 1615293300, 1615696050, 1616098850, 1616501700, 1616904600, 1617307550, 1617710550, 1618113600, 1618516700, 1618919850, 1619323050, 1619726300, 1620129600, 1620532950, 1620936350, 1621339800, 1621743300, 1622146850, 1622550450, 1622954100, 1623357800, 1623761550, 1624165350, 1624569200, 1624973100, 1625377050, 1625781050, 1626185100, 1626589200, 1626993350, 1627397550, 1627801800, 1628206100, 1628610450, 1629014850, 1629419300, 1629823800, 1630228350, 1630632950, 1631037600, 1631442300, 1631847050, 1632251850, 1632656700, 1633061600, 1633466550, 1633871550, 1634276600, 1634681700, 1635086850, 1635492050, 1635897300, 1636302600, 1636707950, 1637113350, 1637518800, 1637924300, 1638329850, 1638735450, 1639141100, 1639546800, 1639952550, 1640358350, 1640764200, 1641170100, 1641576050, 1641982050, 1642388100, 1642794200, 1643200350, 1643606550, 1644012800, 1644419100, 1644825450, 1645231850, 1645638300, 1646044800, 1646451350, 1646857950, 1647264600, 1647671300, 1648078050, 1648484850, 1648891700, 1649298600, 1649705550, 1650112550, 1650519600, 1650926700, 1651333850, 1651741050, 1652148300, 1652555600, 1652962950, 1653370350, 1653777800, 1654185300, 1654592850, 1655000450, 1655408100, 1655815800, 1656223550, 1656631350, 1657039200, 1657447100, 1657855050, 1658263050, 1658671100, 1659079200, 1659487350, 1659895550, 1660303800, 1660712100, 1661120450, 1661528850, 1661937300, 1662345800, 1662754350, 1663162950, 1663571600, 1663980300, 1664389050, 1664797850, 1665206700, 1665615600, 1666024550, 1666433550, 1666842600, 1667251700, 1667660850, 1668070050, 1668479300, 1668888600, 1669297950, 1669707350, 1670116800, 1670526300, 1670935850, 1671345450, 1671755100, 1672164800, 1672574550, 1672984350, 1673394200, 1673804100, 1674214050, 1674624050, 1675034100, 1675444200, 1675854350, 1676264550, 1676674800, 1677085100, 1677495450, 1677905850, 1678316300, 1678726800, 1679137350, 1679547950, 1679958600, 1680369300, 1680780050, 1681190850, 1681601700, 1682012600, 1682423550, 1682834550, 1683245600, 1683656700, 1684067850, 1684479050, 1684890300, 1685301600, 1685712950, 1686124350, 1686535800, 1686947300, 1687358850, 1687770450, 1688182100, 1688593800, 1689005550, 1689417350, 1689829200, 1690241100, 1690653050, 1691065050, 1691477100, 1691889200, 1692301350, 1692713550, 1693125800, 1693538100, 1693950450, 1694362850, 1694775300, 1695187800, 1695600350, 1696012950, 1696425600, 1696838300, 1697251050, 1697663850, 1698076700, 1698489600, 1698902550, 1699315550, 1699728600, 1700141700, 1700554850, 1700968050, 1701381300, 1701794600, 1702207950, 1702621350, 1703034800, 1703448300, 1703861850, 1704275450, 1704689100, 1705102800, 1705516550, 1705930350, 1706344200, 1706758100, 1707172050, 1707586050, 1708000100, 1708414200, 1708828350, 1709242550, 1709656800, 1710071100, 1710485450, 1710899850, 1711314300, 1711728800, 1712143350, 1712557950, 1712972600, 1713387300, 1713802050, 1714216850, 1714631700, 1715046600, 1715461550, 1715876550, 1716291600, 1716706700, 1717121850, 1717537050, 1717952300, 1718367600, 1718782950, 1719198350, 1719613800, 1720029300, 1720444850, 1720860450, 1721276100, 1721691800, 1722107550, 1722523350, 1722939200, 1723355100, 1723771050, 1724187050, 1724603100, 1725019200, 1725435350, 1725851550, 1726267800, 1726684100, 1727100450, 1727516850, 1727933300, 1728349800, 1728766350, 1729182950, 1729599600, 1730016300, 1730433050, 1730849850, 1731266700, 1731683600, 1732100550, 1732517550, 1732934600, 1733351700, 1733768850, 1734186050, 1734603300, 1735020600, 1735437950, 1735855350, 1736272800, 1736690300, 1737107850, 1737525450, 1737943100, 1738360800, 1738778550, 1739196350, 1739614200, 1740032100, 1740450050, 1740868050, 1741286100, 1741704200, 1742122350, 1742540550, 1742958800, 1743377100, 1743795450, 1744213850, 1744632300, 1745050800, 1745469350, 1745887950, 1746306600, 1746725300, 1747144050, 1747562850, 1747981700, 1748400600, 1748819550, 1749238550, 1749657600, 1750076700, 1750495850, 1750915050, 1751334300, 1751753600, 1752172950, 1752592350, 1753011800, 1753431300, 1753850850, 1754270450, 1754690100, 1755109800, 1755529550, 1755949350, 1756369200, 1756789100, 1757209050, 1757629050, 1758049100, 1758469200, 1758889350, 1759309550, 1759729800, 1760150100, 1760570450, 1760990850, 1761411300, 1761831800, 1762252350, 1762672950, 1763093600, 1763514300, 1763935050, 1764355850, 1764776700, 1765197600, 1765618550, 1766039550, 1766460600, 1766881700, 1767302850, 1767724050, 1768145300, 1768566600, 1768987950, 1769409350, 1769830800, 1770252300, 1770673850, 1771095450, 1771517100, 1771938800, 1772360550, 1772782350, 1773204200, 1773626100, 1774048050, 1774470050, 1774892100, 1775314200, 1775736350, 1776158550, 1776580800, 1777003100, 1777425450, 1777847850, 1778270300, 1778692800, 1779115350, 1779537950, 1779960600, 1780383300, 1780806050, 1781228850, 1781651700, 1782074600, 1782497550, 1782920550, 1783343600, 1783766700, 1784189850, 1784613050, 1785036300, 1785459600, 1785882950, 1786306350, 1786729800, 1787153300, 1787576850 };
	int levelrp = 0;
	bool ToBank = false;
	void Bank()
	{
		ToBank ? 4 : 1;
	}

	//stealth money
	void uaanlock()
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_FM_CARMOD_1_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_FM_CARMOD_2_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_FM_CARMOD_3_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_FM_CARMOD_4_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_FM_CARMOD_5_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_FM_CARMOD_6_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_FM_CARMOD_7_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FMRALLYWONDRIVE"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FMRALLYWONNAV"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FMWINSEARACE"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FMWINAIRRACE"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_NUMBER_TURBO_STARTS_IN_RACE"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_USJS_COMPLETED"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_RACES_FASTEST_LAP"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_NUMBER_SLIPSTREAMS_IN_RACE"), 100, 1);
	}
	void SetRank(int rpvalue)
	{
		if (rpvalue < 0 && rpvalue > 8000)
		{
			rpvalue = 8000;
		}
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CHAR_XP_FM"), Levels[rpvalue], 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_XP_FM"), Levels[rpvalue], 0);

	}
	void UnlockSnacks()
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_NO_BOUGHT_YUM_SNACKS"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_NO_BOUGHT_HEALTH_SNACKS"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_NO_BOUGHT_EPIC_SNACKS"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_NUMBER_OF_ORANGE_BOUGHT"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CIGARETTES_BOUGHT"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_NO_BOUGHT_YUM_SNACKS"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_NO_BOUGHT_HEALTH_SNACKS"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_NO_BOUGHT_EPIC_SNACKS"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_NUMBER_OF_ORANGE_BOUGHT"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CIGARETTES_BOUGHT"), 2000000000, 1);
		
	}
	void UnlockArmor()
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MP_CHAR_ARMOUR_1_COUNT"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MP_CHAR_ARMOUR_2_COUNT"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MP_CHAR_ARMOUR_3_COUNT"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MP_CHAR_ARMOUR_4_COUNT"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MP_CHAR_ARMOUR_5_COUNT"), 2000000000, 1);
		//
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MP_CHAR_ARMOUR_1_COUNT"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MP_CHAR_ARMOUR_2_COUNT"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MP_CHAR_ARMOUR_3_COUNT"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MP_CHAR_ARMOUR_4_COUNT"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MP_CHAR_ARMOUR_5_COUNT"), 2000000000, 1);
		
	}
	void UnlockStats()
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STAM"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STRN"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_LUNG"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_DRIV"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_FLY"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_SHO"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STL"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STAM"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STRN"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_LUNG"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_DRIV"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_FLY"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_SHO"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STL"), 100, 0);
	}
	void UnlockFireworks()
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_FIREWORK_TYPE_1_WHITE"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_FIREWORK_TYPE_1_RED"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_FIREWORK_TYPE_1_BLUE"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_FIREWORK_TYPE_2_WHITE"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_FIREWORK_TYPE_2_RED"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_FIREWORK_TYPE_2_BLUE"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_FIREWORK_TYPE_3_WHITE"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_FIREWORK_TYPE_3_RED"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_FIREWORK_TYPE_3_BLUE"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_FIREWORK_TYPE_4_WHITE"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_FIREWORK_TYPE_4_RED"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_FIREWORK_TYPE_4_BLUE"), 2000000000, 1);
		//
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_FIREWORK_TYPE_1_WHITE"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_FIREWORK_TYPE_1_RED"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_FIREWORK_TYPE_1_BLUE"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_FIREWORK_TYPE_2_WHITE"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_FIREWORK_TYPE_2_RED"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_FIREWORK_TYPE_2_BLUE"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_FIREWORK_TYPE_3_WHITE"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_FIREWORK_TYPE_3_RED"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_FIREWORK_TYPE_3_BLUE"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_FIREWORK_TYPE_4_WHITE"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_FIREWORK_TYPE_4_RED"), 2000000000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_FIREWORK_TYPE_4_BLUE"), 2000000000, 1);
		g_Logger->notify("UnlockFireworks");
	}
	void ChromeRimsr()
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_WIN_CAPTURES"), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_DROPOFF_CAP_PACKAGES"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_KILL_CARRIER_CAPTURE"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FINISH_HEISTS"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FINISH_HEIST_SETUP_JOB"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_WIN_LAST_TEAM_STANDINGS"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_ONLY_PLAYER_ALIVE_LTS"), 50, 1);
    }
	void Unlockall()
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STAM"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STRN"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_LUNG"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_DRIV"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_FLY"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_SHO"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STL"), 100, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP1_AWD_FMRACEWORLDRECHOLDER"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_ENEMYDRIVEBYKILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_USJS_COMPLETED"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_USJS_FOUND"), 50, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP1_AWD_FMWINALLRACEMODES"), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP1_AWD_FMWINEVERYGAMEMODE"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_DB_PLAYER_KILLS"), 1000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_KILLS_PLAYERS"), 1000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FMHORDWAVESSURVIVE"), 21, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_TDM_MVP"), 60, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_HOLD_UP_SHOPS"), 20, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_RACES_WON"), 101, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_NO_ARMWRESTLING_WINS"), 21, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP1_AWD_FMATTGANGHQ"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FMBBETWIN"), 50000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_DM_WINS"), 51, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP1_AWD_FMFULLYMODDEDCAR"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_DM_TOTALKILLS"), 500, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MPPLY_DM_TOTAL_DEATHS"), 412, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_PLAYER_HEADSHOTS"), 623, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_DM_WINS"), 63, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_TDM_WINS"), 13, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_GTA_RACES_WON"), 12, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_GOLF_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STAM"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STRN"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_LUNG"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_DRIV"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_FLY"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_SHO"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STL"), 100, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP1_AWD_FMRACEWORLDRECHOLDER"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_ENEMYDRIVEBYKILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_USJS_COMPLETED"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_USJS_FOUND"), 50, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP1_AWD_FMWINALLRACEMODES"), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP1_AWD_FMWINEVERYGAMEMODE"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_DB_PLAYER_KILLS"), 1000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_KILLS_PLAYERS"), 1000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FMHORDWAVESSURVIVE"), 21, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_TDM_MVP"), 60, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_HOLD_UP_SHOPS"), 20, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_RACES_WON"), 101, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_NO_ARMWRESTLING_WINS"), 21, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_8"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_9"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_10"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_OUTFIT"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_5"), -1, 1);;
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_8"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_9"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_13"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_RM_BS_10"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_RM_BS_11"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_RM_BS_12"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_8"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_9"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_10"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_OUTFIT"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_TORSO"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL2_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_DECL"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_TEETH"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_TEETH_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_TEETH_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_TORSO"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL2_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_DECL"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_TEETH"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STAM"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STRN"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_LUNG"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_DRIV"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_FLY"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_SHO"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STL"), 100, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_ENEMYDRIVEBYKILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_USJS_COMPLETED"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_USJS_FOUND"), 50, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP0_AWD_FMWINALLRACEMODES"), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DB_PLAYER_KILLS"), 1000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_KILLS_PLAYERS"), 1000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FMHORDWAVESSURVIVE"), 21, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_TDM_MVP"), 60, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_HOLD_UP_SHOPS"), 20, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_RACES_WON"), 101, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_NO_ARMWRESTLING_WINS"), 21, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP0_AWD_FMATTGANGHQ"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FMBBETWIN"), 50000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 51, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP0_AWD_FMFULLYMODDEDCAR"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_DM_TOTALKILLS"), 500, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_DM_TOTAL_DEATHS"), 412, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_PLAYER_HEADSHOTS"), 623, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 63, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_TDM_WINS"), 13, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_GTA_RACES_WON"), 12, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_GOLF_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_TG_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_RT_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_CT_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_GRAN_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_TENNIS_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_0"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_8"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_9"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_10"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_11"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_12"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_13"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_14"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_15"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_16"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_17"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_18"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_19"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_21"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_22"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_23"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_24"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_24"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_25"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_26"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_27"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_28"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_29"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_30"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_31"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_32"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_33"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_34"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_35"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_36"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_37"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_38"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_39"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_40"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_41"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_42"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_43"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_44"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_45"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_46"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_47"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_48"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_49"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_50"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_51"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_52"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_53"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_54"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_55"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_FMRACEWORLDRECHOLDER"), 1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_ENEMYDRIVEBYKILLS"), 600, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_USJS_COMPLETED"), 50, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_USJS_FOUND"), 50, 0);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP2_AWD_FMWINALLRACEMODES"), 1, 0);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP2_AWD_FMWINEVERYGAMEMODE"), 1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_DB_PLAYER_KILLS"), 1000, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_KILLS_PLAYERS"), 1000, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_FMHORDWAVESSURVIVE"), 21, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_FM_TDM_MVP"), 60, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_HOLD_UP_SHOPS"), 20, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_RACES_WON"), 101, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_NO_ARMWRESTLING_WINS"), 21, 0);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP2_AWD_FMATTGANGHQ"), 1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_FMBBETWIN"), 50000, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_FM_DM_WINS"), 51, 0);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP2_AWD_FMFULLYMODDEDCAR"), 1, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_FM_DM_TOTALKILLS"), 500, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_MPPLY_DM_TOTAL_DEATHS"), 412, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_PLAYER_HEADSHOTS"), 623, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_FM_DM_WINS"), 63, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_FM_TDM_WINS"), 13, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_FM_GTA_RACES_WON"), 12, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_FM_GOLF_WON"), 2, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_FM_SHOOTRANG_TG_WON"), 2, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_FM_SHOOTRANG_RT_WON"), 2, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_FM_SHOOTRANG_CT_WON"), 2, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_FM_SHOOTRANG_GRAN_WON"), 2, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_FM_TENNIS_WON"), 2, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_MPPLY_TENNIS_MATCHES_WON"), 2, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_MPPLY_TOTAL_RACES_WON"), 101, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_MPPLY_TOTAL_RACES_LOST"), 36, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_25_KILLS_STICKYBOMBS"), 50, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_50_KILLS_GRENADES"), 50, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_GRENADE_ENEMY_KILLS "), 50, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_20_KILLS_MELEE"), 50, 0);
	}
	void Parachutes()
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_1_FM_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_2_FM_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_3_FM_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_4_FM_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_5_FM_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_6_FM_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_7_FM_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_8_FM_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_9_FM_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_10_FM_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_11_FM_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_12_FM_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHASE"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHASE2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHASE3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHASE4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHASE5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHASE6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHASE7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHASE8"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHASE9"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHASE10"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHASE11"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHASE12"), -1, 1);
	}
	void UnlockTattoos()
	{
		
		if (125) {

			return;
		}
		// MP0_AWD_FMATTGANGHQ MP0_AWD_FMWINEVERYGAMEMODE MP0_AWD_FMRACEWORLDRECHOLDER MP0_AWD_FMFULLYMODDEDCAR MP0_AWD_FMMOSTKILLSSURVIVE MP0_AWD_FMKILL3ANDWINGTARACE MP0_AWD_FMKILLSTREAKSDM
		Hash Tattoos[] = { 0x49e3d35b, 0xbdda53b4, 0x655e0bad, 0xe9472bb4, 0xc41b8767, 0x43d56fad, 0x3099c3fe, 0x2039515C, 0x4AE88781, 0x90867F4C, 0xE7C84055, 0x98FF48A5, 0xBE3FD785, 0xF3D60861 };
		for (Hash h : Tattoos)
			STATS::STAT_SET_BOOL(h, 1, 1);

		STATS::STAT_SET_INT(0x12f3b311, 20, 1); // MP0_AWD_HOLD_UP_SHOPS
		STATS::STAT_SET_INT(0x36177F20, 20, 1); // MP0_AWD_HOLD_UP_SHOPS

												// MP0_AWD_LAPDANCES MP0_AWD_SECURITY_CARS_ROBBED MP0_AWD_FMKILLBOUNTY MP0_AWD_CAR_BOMBS_ENEMY_KILLS
		Hash Stats25[] = { 0x4314583e, 0x5413e4e9, 0xfb6b31f1, 0xaae88a2f, 0xF29D01D9, 0x5413E4E9, 0x4F6CDED8, 0x1AF2DE9E };
		for (Hash h : Stats25)
			STATS::STAT_SET_INT(h, 25, 1);


		Hash Stats50[] = { 0x4c2e3849, 0xc479c331, 0x54305ac6, 0xb2f3860f, 0x34069BE5, 0x2199954E, 0x43BDA5D0, 0x52326867 };
		for (Hash h : Stats50)
			STATS::STAT_SET_INT(h, 50, 1);

		STATS::STAT_SET_INT(0xfac3eb18, 500, 1); // MP0_AWD_FM_DM_TOTALKILLS
		STATS::STAT_SET_INT(0x76DA8DDE, 500, 1); // MP1_AWD_FM_DM_TOTALKILLS

		STATS::STAT_SET_INT(0xee25f949, 500, 1); // MP0_PLAYER_HEADSHOTS
		STATS::STAT_SET_INT(0x3363CBA7, 500, 1); // MP1_PLAYER_HEADSHOTS
		STATS::STAT_SET_INT(0xcff5c480, 1000, 1); // MP0_DB_PLAYER_KILLS
		STATS::STAT_SET_INT(0xEEC100C9, 1000, 1); // MP1_DB_PLAYER_KILLS
		STATS::STAT_SET_INT(0xaba179f2, 50000, 1); // MP0_AWD_FMBBETWIN
		STATS::STAT_SET_INT(0xF678DE96, 50000, 1); // MP1_AWD_FMBBETWIN
	}
	void UnlockHairstyles()
	{
		if (125) {

		}
		// MP0_CLTHS_AVAILABLE_HAIR MP0_CLTHS_AVAILABLE_HAIR_1 MP0_CLTHS_AVAILABLE_HAIR_2 MP0_CLTHS_AVAILABLE_HAIR_3 MP0_CLTHS_AVAILABLE_HAIR_4 MP0_CLTHS_AVAILABLE_HAIR_5 MP0_CLTHS_AVAILABLE_HAIR_6 MP0_CLTHS_AVAILABLE_HAIR_7
		Hash HairStyles[] = { 0x3cc6316a, 0x50763097 ,0x67ad5f05 ,0x2d1769da, 0x4269947e, 0x2c646868, 0x42e09560, 0xa07a3af, 0x2A9FD8CE, 0x485A4609, 0x569FE294, 0xD6F4633B, 0xAC7E0E4F, 0xF94D47F, 0x1DC670E2, 0x81DA390C };
		for (Hash h : HairStyles)
			STATS::STAT_SET_INT(h, -1, 1);
	}
	void UnlockClothes()
	{

		if (125) {
			
	
		}
		Hash Clothes[] =
		{
			// MP0_CLTHS_AVAILABLE_HAIR MP0_CLTHS_AVAILABLE_HAIR_1 MP0_CLTHS_AVAILABLE_HAIR_2 MP0_CLTHS_AVAILABLE_HAIR_3 MP0_CLTHS_AVAILABLE_HAIR_4
			//0x3cc6316a, 0x50763097, 0x67ad5f05, 0x2d1769da, 0x4269947e,
			// MP0_CLTHS_AVAILABLE_HAIR_5 MP0_CLTHS_AVAILABLE_HAIR_6 MP0_CLTHS_AVAILABLE_HAIR_7
			//0x2c646868, 0x42e09560, 0xa07a3af,
			// MP0_CLTHS_AVAILABLE_JBIB MP0_CLTHS_AVAILABLE_JBIB_1 MP0_CLTHS_AVAILABLE_JBIB_2 MP0_CLTHS_AVAILABLE_JBIB_3 MP0_CLTHS_AVAILABLE_JBIB_4
			0x106936D7, 0x69EE4187, 0xea3729c5, 0x8c5f29f1, 0x65915c56, 0x67d160d6, 0xd143b3d5, 0x32D0534C, 0x676DBC86, 0xEA68AF9,
			// MP0_CLTHS_AVAILABLE_JBIB_5 MP0_CLTHS_AVAILABLE_JBIB_6 MP0_CLTHS_AVAILABLE_JBIB_7
			0xe38ad863, 0xb0e672ff, 0xc027119c, 0x4450F64D, 0x28A2BEED, 0x16C71B36,
			// MP0_CLTHS_AVAILABLE_LEGS MP0_CLTHS_AVAILABLE_LEGS_1 MP0_CLTHS_AVAILABLE_LEGS_2 MP0_CLTHS_AVAILABLE_LEGS_3 MP0_CLTHS_AVAILABLE_LEGS_4
			0xb8b3e0c6, 0xd1ebfd1,  0xc3aeacfa, 0xd7c408c,  0xe81375c3, 0xA17820E7, 0x942B0F3C, 0x2536B8B, 0xFC27DF34, 0xEA593B97,
			// MP0_CLTHS_AVAILABLE_LEGS_5 MP0_CLTHS_AVAILABLE_LEGS_6 MP0_CLTHS_AVAILABLE_LEGS_7
			0xb1730883, 0xce014193, 0xdf45e41c, 0xD7B3164B, 0x45B8725C, 0x355AD1A1,
			// MP0_CLTHS_AVAILABLE_FEET MP0_CLTHS_AVAILABLE_FEET_1 MP0_CLTHS_AVAILABLE_FEET_2 MP0_CLTHS_AVAILABLE_FEET_3 MP0_CLTHS_AVAILABLE_FEET_4
			0x97573104, 0x93ed984b, 0x623c34e5, 0x7369d740, 0x1cb129e0, 0xF48915A2, 0x5067864E, 0x5E3A21F3, 0x7BCC5D17, 0x8985F88A,
			// MP0_CLTHS_AVAILABLE_FEET_5 MP0_CLTHS_AVAILABLE_FEET_6 MP0_CLTHS_AVAILABLE_FEET_7
			0x2ce3ca45, 0xfb1866ab, 0x9a003be, 0x177C1478, 0x2D023F84, 0x3FB0E4E5,
			// MP0_CLTHS_AVAILABLE_BERD MP0_CLTHS_AVAILABLE_BERD_1 MP0_CLTHS_AVAILABLE_BERD_2 MP0_CLTHS_AVAILABLE_BERD_3 MP0_CLTHS_AVAILABLE_BERD_4
			0x14b08e07, 0x6f8f492d, 0x21a72d5e, 0x74f2d3f8, 0x269db74f, 0x72F2DA40, 0xE0B6E4BD, 0xCE604010, 0xCE1A3F84, 0xBC0C9B69,
			// MP0_CLTHS_AVAILABLE_BERD_5 MP0_CLTHS_AVAILABLE_BERD_6 MP0_CLTHS_AVAILABLE_BERD_7
			0x4f5708c1, 0x8133ec7a, 0xca99ff41, 0xE989F65B, 0xD8F75536, 0x8F4F41DF,
			// MP0_CLTHS_AVAILABLE_PROPS MP0_CLTHS_AVAILABLE_PROPS_1 MP0_CLTHS_AVAILABLE_PROPS_2 MP0_CLTHS_AVAILABLE_PROPS_3 MP0_CLTHS_AVAILABLE_PROPS_4
			0xb051c305, 0x7d5c4692, 0x7555b685, 0x62da918f, 0xd8217c1b, 0xC6EF3846, 0xB4FC36E4, 0xA641196E, 0xD967FFBB, 0xBAA5C237,
			// MP0_CLTHS_AVAILABLE_PROPS_5 MP0_CLTHS_AVAILABLE_PROPS_6 MP0_CLTHS_AVAILABLE_PROPS_7 MP0_CLTHS_AVAILABLE_PROPS_8 MP0_CLTHS_AVAILABLE_PROPS_9
			0xc665d8a4, 0xb6e439a1, 0xa431143b, 0xda520080, 0x9ca5f70, 0x59A48036, 0x8F1FEB2C, 0x7E7A49E1, 0xAF9B2C26, 0x22ED12C8,
			// MP0_CLTHS_AVAILABLE_PROPS_10 MP0_CLTHS_AVAILABLE_OUTFIT MP0_CLTHS_ACQUIRED_HAIR MP0_CLTHS_ACQUIRED_HAIR_1 MP0_CLTHS_ACQUIRED_HAIR_2
			0x4c7f28e9, 0xd4b41ccb, 0xa01511e1, 0x2415af29, 0x12630bc4, 0x5985C64E, 0x39BD13C2, 0xDD89D4C6, 0xE012DCE9, 0xCAECB29D,
			// MP0_CLTHS_ACQUIRED_HAIR_3 MP0_CLTHS_ACQUIRED_HAIR_4 MP0_CLTHS_ACQUIRED_HAIR_5 MP0_CLTHS_ACQUIRED_HAIR_6 MP0_CLTHS_ACQUIRED_HAIR_7
			0x41e4eabf, 0x2f96c623, 0x2b48bd87, 0x1922193a, 0x888a7809, 0xBD9917F6, 0x7340035D, 0xA58EE7FA, 0x5FBB5C54, 0x81C7A06C,
			// MP0_CLTHS_ACQUIRED_JBIB MP0_CLTHS_ACQUIRED_JBIB_1 MP0_CLTHS_ACQUIRED_JBIB_2 MP0_CLTHS_ACQUIRED_JBIB_3 MP0_CLTHS_ACQUIRED_JBIB_4
			0xaea92fe3, 0xa05ef149, 0x93bfd80b, 0x7a90a5ad, 0x69730372, 0x262E94CA, 0xA89BC9DF, 0x8EDA965D, 0xFBCBF03E, 0xF205DCB2,
			// MP0_CLTHS_ACQUIRED_JBIB_5 MP0_CLTHS_ACQUIRED_JBIB_6 MP0_CLTHS_ACQUIRED_JBIB_7
			0x5e0eeca6, 0x281f80d4, 0x1d856ba0, 0x6790C7CA, 0x5553234F, 0x4B2A0EFD,
			// MP0_CLTHS_ACQUIRED_LEGS MP0_CLTHS_ACQUIRED_LEGS_1 MP0_CLTHS_ACQUIRED_LEGS_2 MP0_CLTHS_ACQUIRED_LEGS_3 MP0_CLTHS_ACQUIRED_LEGS_4
			0x66e4ca67, 0x1b3dca99, 0x598d4737, 0x7c223a2,  0x3ce78dec, 0x7AD6ED44, 0x3180E8E0, 0x23384C4F, 0xDFE21DB, 0xFFA88530,
			// MP0_CLTHS_ACQUIRED_LEGS_5 MP0_CLTHS_ACQUIRED_LEGS_6 MP0_CLTHS_ACQUIRED_LEGS_7
			0x6b266a69, 0xa01cd459, 0x4df12fff, 0xFA5B7A96, 0xED0CDFF9, 0xD6C6B36D,
			// MP0_CLTHS_ACQUIRED_FEET MP0_CLTHS_ACQUIRED_FEET_1 MP0_CLTHS_ACQUIRED_FEET_2 MP0_CLTHS_ACQUIRED_FEET_3 MP0_CLTHS_ACQUIRED_FEET_4
			0x12b66dab, 0xcfd67d8b, 0x7964d0a9, 0xaeaf3b3d, 0x56a80b30, 0xBD702716, 0x2EEE3A4B, 0x212A9EC4, 0x824A6102, 0xAED8BA1E,
			// MP0_CLTHS_ACQUIRED_FEET_5 MP0_CLTHS_ACQUIRED_FEET_6 MP0_CLTHS_ACQUIRED_FEET_7
			0x88eaefb5, 0x327342bf, 0x63b5254a, 0x661BA8A5, 0x58760D5A, 0xCB61F32C,
			// MP0_CLTHS_ACQUIRED_BERD MP0_CLTHS_ACQUIRED_BERD_1 MP0_CLTHS_ACQUIRED_BERD_2 MP0_CLTHS_ACQUIRED_BERD_3 MP0_CLTHS_ACQUIRED_BERD_4
			0x2de14803, 0x19299a7d, 0x2b3e3ea6, 0x7574d312, 0x87e277ed, 0xD7C1EC04, 0x1039C4E0, 0x4A183894, 0x3D529F09, 0x6727F2B3,
			// MP0_CLTHS_ACQUIRED_BERD_5 MP0_CLTHS_ACQUIRED_BERD_6 MP0_CLTHS_ACQUIRED_BERD_7
			0x74a9d180, 0x86d375d3, 0x50ec0a05, 0x58ED563E, 0xD711D285, 0x88E6B630,
			// MP0_CLTHS_ACQUIRED_PROPS MP0_CLTHS_ACQUIRED_PROPS_1 MP0_CLTHS_ACQUIRED_PROPS_2 MP0_CLTHS_ACQUIRED_PROPS_3 MP0_CLTHS_ACQUIRED_PROPS_4
			0xd846c640, 0x18ea3634, 0x3460aec,  0xa1d5c80d, 0x5573af4a, 0xEF73F981, 0xF889C25C, 0xEB4F27E7, 0xD820818A, 0xC971E42D,
			// MP0_CLTHS_ACQUIRED_PROPS_5 MP0_CLTHS_ACQUIRED_PROPS_6 MP0_CLTHS_ACQUIRED_PROPS_7 MP0_CLTHS_ACQUIRED_PROPS_8 MP0_CLTHS_ACQUIRED_PROPS_9
			0x3f3182c6, 0x6ad05a03, 0xeaecda3a, 0x9d25bead, 0x87779351, 0xC47CDA43, 0xB6C33ED0, 0xA35917FC, 0x7C96CA7C, 0x6BC528D9,
			// MP0_CLTHS_ACQUIRED_PROPS_10 MP0_CLTHS_ACQUIRED_OUTFIT MP0_CLTHS_AVAILABLE_TORSO MP0_CLTHS_AVAILABLE_SPECIAL MP0_CLTHS_AVAILABLE_SPECIAL_1
			0x466c7ee5, 0xe667df2c, 0x8eb5a109, 0x135b7256, 0x17e66c11, 0x8987AF23, 0x558AD3B, 0x594926A5, 0xF72A91D0, 0x1AEE2BA3,
			// MP0_CLTHS_AVAILABLE_SPECIAL_2 MP0_CLTHS_AVAILABLE_SPECIAL_3 MP0_CLTHS_AVAILABLE_SPECIAL_4 MP0_CLTHS_AVAILABLE_SPECIAL_5 MP0_CLTHS_AVAILABLE_SPECIAL_6
			0x5e5b78fa, 0x2f9c9b7d, 0xeb7a1335, 0x11f3e7f,  0x753cae8, 0x6895C6F5, 0xE5D2416C, 0xD3A01D08, 0xE1E6B995, 0x2F8E54E3,
			// MP0_CLTHS_AVAILABLE_SPECIAL_7 MP0_CLTHS_AVAILABLE_DECL MP0_CLTHS_AVAILABLE_TEETH MP0_CLTHS_AVAILABLE_TEETH_1 MP0_CLTHS_AVAILABLE_TEETH_2
			0x1c91f564, 0x9c7866c7, 0xba50aedd, 0x2e99d7e,  0x112339f1, 0xACDA4F79, 0xA45F8FA5, 0x50EE4BB3, 0xA38FAC3D, 0x91C108A0,
			// MP0_CLTHS_ACQUIRED_TORSO MP0_CLTHS_ACQUIRED_SPECIAL MP0_CLTHS_ACQUIRED_SPECIAL_1 MP0_CLTHS_ACQUIRED_SPECIAL_2 MP0_CLTHS_ACQUIRED_SPECIAL_3
			0x85648a0a, 0xd1c336af, 0x5a1bdf57, 0x70020b23, 0x7cc0249f, 0xC7E1C824, 0x93CD00B9, 0xE1034060, 0x60FEC059, 0x733D64D6,
			// MP0_CLTHS_ACQUIRED_SPECIAL_4 MP0_CLTHS_ACQUIRED_SPECIAL_5 MP0_CLTHS_ACQUIRED_SPECIAL_6 MP0_CLTHS_ACQUIRED_SPECIAL_7 MP0_CLTHS_ACQUIRED_SPECIAL2
			0x42733006, 0xa132ed84, 0xd96fddfd, 0xe5b1f681, 0x8803887c, 0xA08CBF74, 0xAAD1D3FE, 0x2A4D52F7, 0x3BD5F608, 0x5E745104,
			// MP0_CLTHS_ACQUIRED_SPECIAL2_1 MP0_CLTHS_ACQUIRED_DECL MP0_CLTHS_ACQUIRED_TEETH MP0_CLTHS_ACQUIRED_TEETH_1 MP0_CLTHS_ACQUIRED_TEETH_2
			0x7e9b5630, 0x9e36043,  0xa1425b8,  0x91050cea, 0x68fc3cd5, 0x662CE27A, 0xAFF1B575, 0x9919F993, 0xDEC71135, 0xF48A3CBB,
			// MP0_DLC_APPAREL_ACQUIRED_0 MP0_DLC_APPAREL_ACQUIRED_1 MP0_DLC_APPAREL_ACQUIRED_2 MP0_DLC_APPAREL_ACQUIRED_3 MP0_DLC_APPAREL_ACQUIRED_4
			0x58087574, 0x4dffe16f, 0x402645bc, 0xf0942689, 0xea6a1a35, 0x94B71349, 0x9F8628E7, 0xAE0945ED, 0xBBCAE170, 0xDDF4A5C3,
			// MP0_DLC_APPAREL_ACQUIRED_5 MP0_DLC_APPAREL_ACQUIRED_6 MP0_DLC_APPAREL_ACQUIRED_7 MP0_DLC_APPAREL_ACQUIRED_8 MP0_DLC_APPAREL_ACQUIRED_9
			0x1b87fc70, 0x6e4d32a,  0xb80eb57f, 0xd156e80f, 0xa00e858b, 0xEC6E42B6, 0x9A319E42, 0xA9003BDF, 0x26AE3735, 0x31554C83,
			// MP0_DLC_APPAREL_ACQUIRED_10 MP0_DLC_APPAREL_ACQUIRED_11 MP0_DLC_APPAREL_ACQUIRED_12 MP0_DLC_APPAREL_ACQUIRED_13 MP0_DLC_APPAREL_ACQUIRED_14
			0x786ce981, 0x5e25b4f3, 0x851d82e2, 0xfa586d56, 0xb14a5b3b, 0x5E1EBA6B, 0x31BD61A9, 0x7BE775FC, 0x6C21D671, 0x966C2AF5,
			// MP0_DLC_APPAREL_ACQUIRED_15 MP0_DLC_APPAREL_ACQUIRED_16 MP0_DLC_APPAREL_ACQUIRED_17 MP0_DLC_APPAREL_ACQUIRED_18 MP0_DLC_APPAREL_ACQUIRED_19
			0x978b27bd, 0x41c27c29, 0x2fffd8a4, 0xde5e3562, 0xcca491ef, 0x85AD8978, 0xB2B6E38A, 0xA3F54607, 0x5D32B883, 0x50781F0E,
			// MP0_DLC_APPAREL_ACQUIRED_21 MP0_DLC_APPAREL_ACQUIRED_22 MP0_DLC_APPAREL_ACQUIRED_23 MP0_DLC_APPAREL_ACQUIRED_24 MP0_DLC_APPAREL_ACQUIRED_24
			0x6bc7cf17, 0xc7a886d7, 0xd543220c, 0x1d1931b7, 0x1d1931b7, 0xBE78FC56, 0xC8F61150, 0xC1D1831B, 0xB7606E39, 0xED675A46,
			// MP0_DLC_APPAREL_ACQUIRED_25 MP0_DLC_APPAREL_ACQUIRED_26 MP0_DLC_APPAREL_ACQUIRED_27 MP0_DLC_APPAREL_ACQUIRED_28 MP0_DLC_APPAREL_ACQUIRED_29
			0x32be5d01, 0xd594a2b7, 0xeb77ce7d, 0x3304dd96, 0x40c67919, 0xD33D25F2, 0x7ECB7D10, 0x6D3CD9F3, 0x9A6F3457, 0x889F90B8,
			// MP0_DLC_APPAREL_ACQUIRED_30 MP0_DLC_APPAREL_ACQUIRED_31 MP0_DLC_APPAREL_ACQUIRED_32 MP0_DLC_APPAREL_ACQUIRED_33 MP0_DLC_APPAREL_ACQUIRED_34
			0x21993997, 0x76cee405, 0x3d23f0ac, 0x32addbc0, 0xe09e37a2, 0xE7D8D00D, 0xDA163488, 0xCB5D9717, 0xB5C26BE1, 0x11CC23F7,
			// MP0_DLC_APPAREL_ACQUIRED_35 MP0_DLC_APPAREL_ACQUIRED_36 MP0_DLC_APPAREL_ACQUIRED_37 MP0_DLC_APPAREL_ACQUIRED_38 MP0_DLC_APPAREL_ACQUIRED_39
			0xce3492cf, 0x94611f25, 0x2c57bf0,  0x98902783, 0x865d831e, 0x30D867A, 0xED4D5AFA, 0xDE8FBD7F, 0x59E5B429, 0x442C88B7,
			// MP0_DLC_APPAREL_ACQUIRED_40 MP0_ADMIN_CLOTHES_GV_BS_1 MP0_ADMIN_CLOTHES_GV_BS_2 MP0_ADMIN_CLOTHES_GV_BS_3 MP0_ADMIN_CLOTHES_GV_BS_4
			0xd3c59cd1, 0x62e2d64,  0xbc5d19bb, 0xaaedf6dd, 0xd130c362, 0x64AC5C36, 0xF8AA28B5, 0x5EC2F4E9, 0x4EC854F4, 0x3C77B053,
			// MP0_ADMIN_CLOTHES_GV_BS_5 MP0_ADMIN_CLOTHES_GV_BS_6 MP0_ADMIN_CLOTHES_GV_BS_7 MP0_ADMIN_CLOTHES_GV_BS_8 MP0_ADMIN_CLOTHES_GV_BS_9
			0xcf3cbf7a, 0x65536ba9, 0x4f824007, 0x85d0aca3, 0x746309c8, 0x32E59D2F, 0x979E669F, 0x8C104F83, 0x7A00AB64, 0xDEA074A6,
			// MP0_ADMIN_CLOTHES_GV_BS_10 MP0_ADMIN_CLOTHES_GV_BS_11 MP0_ADMIN_CLOTHES_GV_BS_12 MP0_ADMIN_CLOTHES_GV_BS_13
			0xcb76a780, 0xe6a9dde6, 0xefe2f058, 0x1f90cd, 0xE5B0D20F, 0xFC21FEF1, 0xD2D02C32, 0xE267CB61
		};
		for (Hash h : Clothes)
			STATS::STAT_SET_INT(h, -1, 1);

		//tshirts
		STATS::STAT_SET_BOOL(0x9cf3d019, 1, 1); // MP0_AWD_FINISH_HEIST_NO_DAMAGE
		STATS::STAT_SET_BOOL(0x59D644B9, 1, 1); // MP1_AWD_FINISH_HEIST_NO_DAMAGE

		STATS::STAT_SET_BOOL(0x45b6712, 1, 1); // MP0_AWD_STORE_20_CAR_IN_GARAGES
		STATS::STAT_SET_BOOL(0xA5F06324, 1, 1); // MP1_AWD_STORE_20_CAR_IN_GARAGES

		STATS::STAT_SET_INT(0x2ae837e4, 1, 1); // MP0_AWD_FMPICKUPDLCCRATE1ST also in trophies
		STATS::STAT_SET_INT(0x3804231B, 1, 1); // MP1_AWD_FMPICKUPDLCCRATE1ST also in trophies

		STATS::STAT_SET_INT(0x833d3192, 10, 1); // MP0_AWD_FMHORDWAVESSURVIVE also in trophies
		STATS::STAT_SET_INT(0x18F27D05, 10, 1); // MP1_AWD_FMHORDWAVESSURVIVE also in trophies

												// MP0_AWD_WIN_CAPTURE_DONT_DYING MP0_AWD_DO_HEIST_AS_MEMBER MP0_AWD_WIN_GOLD_MEDAL_HEISTS MP0_AWD_KILL_TEAM_YOURSELF_LTS MP0_AWD_DO_HEIST_AS_THE_LEADER
		Hash Stats25[] = { 0x68d14c4e, 0x470055dc, 0x9f9ff03c, 0x4930d051, 0xc32a1dd9, 0x7B245DB0, 0xFFCB5243, 0x3D6A96C, 0x5C7450F8, 0xC13E46BC };
		for (Hash h : Stats25)
			STATS::STAT_SET_INT(h, 25, 1);

		STATS::STAT_SET_INT(0x30418014, 100, 1); // MP0_AWD_PICKUP_CAP_PACKAGES
		STATS::STAT_SET_INT(0x87B6D2D, 100, 1); // MP1_AWD_PICKUP_CAP_PACKAGES

		STATS::STAT_SET_INT(0xe2a9b0c4, 100, 1); // MP0_AWD_KILL_PSYCHOPATHS
		STATS::STAT_SET_INT(0xE5E29EEA, 100, 1); // MP1_AWD_KILL_PSYCHOPATHS

		g_Logger->Infos("Unlock Clothes...");
	}
	void OfficeStatue()
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_LIFETIME_BUY_COMPLETE"), 2000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_LIFETIME_BUY_UNDERTAKEN"), 2000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_LIFETIME_SELL_COMPLETE"), 2000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_LIFETIME_SELL_UNDERTAKEN"), 2000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_LIFETIME_BUY_COMPLETE"), 2000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_LIFETIME_BUY_UNDERTAKEN"), 2000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_LIFETIME_SELL_COMPLETE"), 2000, true);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_LIFETIME_SELL_UNDERTAKEN"), 2000, true);
		
	}
	void adminc()
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, TRUE);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, TRUE);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, TRUE);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, TRUE);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, TRUE);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_2"), -1, TRUE);
		
	}
	void MaxNightClubPopularity(){
		char sbuf[50];
		int stat_r;
		STATS::STAT_GET_INT($("MPPLY_LAST_MP_CHAR"), &stat_r, 1);
		snprintf(sbuf, sizeof(sbuf), "MP%i%s", stat_r, "CLUB_POPULARITY");
		STATS::STAT_SET_INT($(sbuf), 1000, 1);
	}
	void UnlockAllHeistVehicles()
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_CHAR_FM_VEHICLE_1_UNLCK"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_CHAR_FM_VEHICLE_2_UNLCK"), -1, 1);
	}
	void unloooo()
	{
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_WIN_CAPTURES"), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_DROPOFF_CAP_PACKAGES"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_KILL_CARRIER_CAPTURE"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_FINISH_HEISTS"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_FINISH_HEIST_SETUP_JOB"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_WIN_LAST_TEAM_STANDINGS"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP2_AWD_ONLY_PLAYER_ALIVE_LTS"), 50, 1);
	}

	bool Mapweck = false;
	void mapweck()
	{
		if (Mapweck) {
			HUD::DISPLAY_RADAR(false);
		}
		else {
			HUD::DISPLAY_RADAR(true);
		}
	}
	//Prots
	bool protecc3;
	bool AntiKick;
	bool AntiKick2;
	bool protecc2;
	bool noRemoveWeps;
	bool noGiveWeps;
	enum eRockstarEvent {
		GAME_CLOCK_EVENT = 0x6,
		GAME_WEATHER_EVENT = 0x7,
		REVENT_SCRIPT_ARRAY_DATA_VERIFY_EVENT,
		REVENT_REQUEST_CONTROL_EVENT,
		REVENT_GIVE_CONTROL_EVENT,
		REVENT_WEAPON_DAMAGE_EVENT,
		REVENT_REQUEST_PICKUP_EVENT,
		REVENT_REQUEST_MAP_PICKUP_EVENT,
		REVENT_GAME_CLOCK_EVENT,
		REVENT_GAME_WEATHER_EVENT,
		REVENT_RESPAWN_PLAYER_PED_EVENT,
		REVENT_GIVE_WEAPON_EVENT,
		NETWORK_PTFX_EVENT,
		REVENT_REMOVE_WEAPON_EVENT,
		REVENT_REMOVE_ALL_WEAPONS_EVENT,
		NETWORK_CLEAR_PED_TASKS_EVENT,
		REVENT_VEHICLE_COMPONENT_CONTROL_EVENT,
		REVENT_FIRE_EVENT,
		REVENT_EXPLOSION_EVENT,
		REVENT_START_PROJECTILE_EVENT,
		REVENT_ALTER_WANTED_LEVEL_EVENT,
		REVENT_CHANGE_RADIO_STATION_EVENT,
		REVENT_RAGDOLL_REQUEST_EVENT,
		REVENT_PLAYER_TAUNT_EVENT,
		REVENT_PLAYER_CARD_STAT_EVENT,
		REVENT_DOOR_BREAK_EVENT,
		REVENT_SCRIPTED_GAME_EVENT,
		REVENT_REMOTE_SCRIPT_INFO_EVENT,
		REVENT_REMOTE_SCRIPT_LEAVE_EVENT,
		REVENT_MARK_AS_NO_LONGER_NEEDED_EVENT,
		REVENT_CONVERT_TO_SCRIPT_ENTITY_EVENT,
		REVENT_SCRIPT_WORLD_STATE_EVENT,
		REVENT_INCIDENT_ENTITY_EVENT,
		REVENT_CLEAR_AREA_EVENT,
		REVENT_CLEAR_RECTANGLE_AREA_EVENT,
		REVENT_NETWORK_REQUEST_SYNCED_SCENE_EVENT,
		REVENT_NETWORK_START_SYNCED_SCENE_EVENT,
		REVENT_NETWORK_UPDATE_SYNCED_SCENE_EVENT,
		REVENT_NETWORK_STOP_SYNCED_SCENE_EVENT,
		REVENT_GIVE_PED_SCRIPTED_TASK_EVENT,
		REVENT_GIVE_PED_SEQUENCE_TASK_EVENT,
		REVENT_NETWORK_CLEAR_PED_TASKS_EVENT,
		REVENT_NETWORK_START_PED_ARREST_EVENT,
		REVENT_NETWORK_START_PED_UNCUFF_EVENT,
		REVENT_NETWORK_SOUND_CAR_HORN_EVENT,
		REVENT_NETWORK_ENTITY_AREA_STATUS_EVENT,
		REVENT_NETWORK_GARAGE_OCCUPIED_STATUS_EVENT,
		REVENT_PED_CONVERSATION_LINE_EVENT,
		REVENT_SCRIPT_ENTITY_STATE_CHANGE_EVENT,
		REVENT_NETWORK_PLAY_SOUND_EVENT,
		REVENT_NETWORK_STOP_SOUND_EVENT,
		REVENT_NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT,
		REVENT_NETWORK_BANK_REQUEST_EVENT,
		REVENT_REQUEST_DOOR_EVENT,
		REVENT_NETWORK_TRAIN_REQUEST_EVENT,
		REVENT_NETWORK_TRAIN_REPORT_EVENT,
		REVENT_NETWORK_INCREMENT_STAT_EVENT,
		REVENT_MODIFY_VEHICLE_LOCK_WORD_STATE_DATA,
		REVENT_REQUEST_PHONE_EXPLOSION_EVENT,
		REVENT_REQUEST_DETACHMENT_EVENT,
		REVENT_KICK_VOTES_EVENT,
		REVENT_GIVE_PICKUP_REWARDS_EVENT,
		REVENT_NETWORK_CRC_HASH_CHECK_EVENT,
		REVENT_BLOW_UP_VEHICLE_EVENT,
		REVENT_NETWORK_SPECIAL_FIRE_EQUIPPED_WEAPON,
		REVENT_NETWORK_RESPONDED_TO_THREAT_EVENT,
		REVENT_NETWORK_SHOUT_TARGET_POSITION,
		REVENT_PICKUP_DESTROYED_EVENT,
		REVENT_UPDATE_PLAYER_SCARS_EVENT,
		REVENT_NETWORK_CHECK_EXE_SIZE_EVENT,
		REVENT_NETWORK_PTFX_EVENT,
		REVENT_NETWORK_PED_SEEN_DEAD_PED_EVENT,
		REVENT_REMOVE_STICKY_BOMB_EVENT,
		REVENT_NETWORK_CHECK_CODE_CRCS_EVENT,
		REVENT_INFORM_SILENCED_GUNSHOT_EVENT,
		REVENT_PED_PLAY_PAIN_EVENT,
		REVENT_CACHE_PLAYER_HEAD_BLEND_DATA_EVENT,
		REVENT_REMOVE_PED_FROM_PEDGROUP_EVENT,
		REVENT_REPORT_MYSELF_EVENT,
		REVENT_REPORT_CASH_SPAWN_EVENT,
		REVENT_ACTIVATE_VEHICLE_SPECIAL_ABILITY_EVENT,
		REVENT_NETWORK_CHECK_CATALOG_CRC,
		REVENT_END
	};
	static std::vector<void*> EventPtr;
	static char EventRestore[REVENT_END] = {};
	void patchEvent(eRockstarEvent e, bool b) {
		if (EventPtr.size() == 0) return;
		static const BYTE ret = 0xC3;
		BYTE* ptr = (BYTE*)EventPtr[e];
		if (b) {
			if (EventRestore[e] == 0) EventRestore[e] = ptr[0];
			*ptr = ret;
		}
		else if (EventRestore[e] != 0) *ptr = EventRestore[e];
	}
	void defuseEvent(eRockstarEvent e, bool toggle)
	{
		static const unsigned char retn = 0xC3;
		char* p = (char*)EventPtr[e];
		if (toggle)
		{
			if (EventRestore[e] == 0)
				EventRestore[e] = p[0];
			*p = retn;
		}
		else
		{
			if (EventRestore[e] != 0)
				*p = EventRestore[e];
		}
	}
	bool Cageebool = false;
	void Cage()
	{

	}
	bool Reportbool = true;
	void Report()
	{

	}
	bool Kickbool = true;
	void Kick()
	{

	}
	bool sbool = true;
	void sick()
	{

	}
	bool sTeleport = true;
	void Teleports()
	{

	}
	bool DisablePhone = true;
	void sDisablePhone()
	{

	}
	bool RAGDOLL = false;
	void REQUESTEVENT()
	{
		patchEvent(REVENT_RAGDOLL_REQUEST_EVENT, true);
	}
	bool aatt = false;
	void aantiattacks()
	{
		patchEvent(REVENT_KICK_VOTES_EVENT, true);
	}
	bool revweapons = false;
	void remoweapons()
	{
		patchEvent(REVENT_REMOVE_ALL_WEAPONS_EVENT, true);
	}
	bool votes = false;
	void kickvotes()
	{
		patchEvent(REVENT_KICK_VOTES_EVENT, true);
	}
	bool NETWORKCRC = false;
	void NETWORK_CRC()
	{
		patchEvent(REVENT_NETWORK_CRC_HASH_CHECK_EVENT, true);
	}
	bool bypass = false;
	void moneyBypass()
	{
		patchEvent(REVENT_REQUEST_PICKUP_EVENT, true);
	}
	bool new2 = false;
	void new22()
	{
		patchEvent(REVENT_GAME_WEATHER_EVENT, true);
	}
	bool new222 = false;
	void new223()
	{
		patchEvent(NETWORK_PTFX_EVENT, true);
	}
	bool nedw2s22 = true;
	void new2sf23()
	{
		patchEvent(REVENT_NETWORK_SPECIAL_FIRE_EQUIPPED_WEAPON, true);
	}//
	bool nedw2f22 = true;
	void nedw2yxc23()
	{
		patchEvent(REVENT_VEHICLE_COMPONENT_CONTROL_EVENT, true);
	}
	bool newd2yxc22 = true;
	void nedw22yxc3()
	{
		patchEvent(REVENT_FIRE_EVENT, true);
	}
	bool newd2sd22 = true;
	void newd2gdsg23()
	{
		patchEvent(REVENT_BLOW_UP_VEHICLE_EVENT, true);
	}
	bool newd2bcv22 = true;
	void newd2xv23()
	{
		patchEvent(REVENT_PED_PLAY_PAIN_EVENT, true);
	}
	bool neddsfw2s22 = true;
	void neasfw2sf23()
	{
		patchEvent(REVENT_EXPLOSION_EVENT, true);
	}
	bool ndefsw2s22 = true;
	void neafdw2sf23()
	{
		patchEvent(REVENT_REMOVE_PED_FROM_PEDGROUP_EVENT, true);
	}
	bool nedw2asds22 = true;
	void nedw2sfgbf23()
	{
		patchEvent(REVENT_NETWORK_CLEAR_PED_TASKS_EVENT, true);
	}
	bool new2asds22 = true;
	void newd2sfgbf23()
	{
		patchEvent(REVENT_MARK_AS_NO_LONGER_NEEDED_EVENT, true);
	}
	bool new2dasds22 = true;
	void newdd2sfgbf23()
	{
		patchEvent(REVENT_REQUEST_CONTROL_EVENT, true);
	}
	bool newasd2asds22 = true;
	void newd2dsasfgbf23()
	{
		patchEvent(REVENT_ALTER_WANTED_LEVEL_EVENT, true);
	}
	bool newasdf2asds22 = true;
	void newsd2dssasfgbf23()
	{
		patchEvent(NETWORK_CLEAR_PED_TASKS_EVENT, true);
	}
	bool REMOVE_WEAPON_EVENT;
	//Outfits
	void Outfit(std::string name)
	{
		std::string iniPath = "C:\\Juice\\Outfits\\" + name + "juice."; 
		char test1[255];
		char test2[255];
		char test3[255];
		char test4[255];
		char test5[255];
		char test6[255];
		char test7[255];
		char test8[255];
		char test9[255];
		char test10[255];
		char test11[255];
		char test12[255];
		char test13[255];
		char test14[255];
		char test15[255];
		GetPrivateProfileStringA("Outfit", "Face", "", test1, 255, iniPath.c_str());
		GetPrivateProfileStringA("Outfit", "Head", "", test2, 255, iniPath.c_str());
		GetPrivateProfileStringA("Outfit", "Hair", "", test3, 255, iniPath.c_str());
		GetPrivateProfileStringA("Outfit", "Torso", "", test4, 255, iniPath.c_str());
		GetPrivateProfileStringA("Outfit", "Legs", "", test5, 255, iniPath.c_str());
		GetPrivateProfileStringA("Outfit", "Hands", "", test6, 255, iniPath.c_str());
		GetPrivateProfileStringA("Outfit", "Feet", "", test7, 255, iniPath.c_str());
		GetPrivateProfileStringA("Outfit", "Eyes", "", test8, 255, iniPath.c_str());
		GetPrivateProfileStringA("Outfit", "Accessories", "", test9, 255, iniPath.c_str());
		GetPrivateProfileStringA("Outfit", "Tasks", "", test10, 255, iniPath.c_str());
		GetPrivateProfileStringA("Outfit", "Textures", "", test11, 255, iniPath.c_str());
		GetPrivateProfileStringA("Outfit", "Torso2", "", test12, 255, iniPath.c_str());
		GetPrivateProfileStringA("Outfit", "HeadProp", "", test13, 255, iniPath.c_str());
		GetPrivateProfileStringA("Outfit", "EyeProp", "", test14, 255, iniPath.c_str());
		GetPrivateProfileStringA("Outfit", "EarProp", "", test15, 255, iniPath.c_str());

		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 0, atoi(test1), 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 1, atoi(test2), 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 2, atoi(test3), 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 3, atoi(test4), 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 4, atoi(test5), 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 5, atoi(test6), 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 6, atoi(test7), 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 7, atoi(test8), 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 8, atoi(test9), 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 9, atoi(test10), 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 10, atoi(test11), 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 11, atoi(test12), 0, 0);
		PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 1, atoi(test13), 0, 0);
		PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 2, atoi(test14), 0, 0);
		PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 3, atoi(test15), 0, 0);
	}
	void RandomOutfit()
	{
		PED::SET_PED_RANDOM_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), true);
	}
	bool ShadowfitExist()
	{
		DWORD dwAttrib = GetFileAttributesA("C:\\Juice\\Outfits");
		return (dwAttrib != INVALID_FILE_ATTRIBUTES && dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
	}
	bool SolOutfitExist()
	{
		DWORD dwAttrib = GetFileAttributesA("C:\\Juice\\Outfits");
		return (dwAttrib != INVALID_FILE_ATTRIBUTES && dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
	}
	//TELEPORT
	void SecretArmyTower()
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
		Vector3 Coords;
		Coords.x = -2358.946045f; Coords.y = 3252.216797f; Coords.z = 101.450424f;
		TPto(Coords);
	}
    void tptowp()
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
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
    void pbback()
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
		NativeVector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 100.0, 0.0);
		int Handle = PLAYER::PLAYER_PED_ID();
		if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
			Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
	}
	void twofront()
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
		NativeVector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 2.0, 0.0);
		int Handle = PLAYER::PLAYER_PED_ID();
		if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
			Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
	}
    /// 
    void dd()
	{}
	void PrintBottomLeft()
	   {
		HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
		HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Your Rank Is Set.");
		HUD::END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT_WITH_CREW_TAG_AND_ADDITIONAL_ICON("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "~b~[Juice Info]", "", 1, "", 9, 0);
		HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(8000, 1);
	}
	void PrintBottom()
	{
		HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
		HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("We have Delete your Reports                 For GTA:O");
		HUD::END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT_WITH_CREW_TAG_AND_ADDITIONAL_ICON("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 4, "Rockstar Info", "", 1, "", 4, 0);
		HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(8000, 1);
	}
	void Welecome()
	{
		HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
		HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Open Key ~p~[F7] ~w~Unlode ~p~[F1]");
		HUD::END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT_WITH_CREW_TAG_AND_ADDITIONAL_ICON("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 4, "", "~p~[Juice]", 1, "", 4, 0);
		HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(8000, 1);
	}	
	void SendTextMessage(char* msg)
	{
		int handle[13];
		NETWORK::NETWORK_HANDLE_FROM_PLAYER(g_SelectedPlayer, &handle[0], 13);
		NETWORK::NETWORK_SEND_TEXT_MESSAGE(msg, &handle[0]);
	}
	void SendTextMessage(int player)
	{
		int handle[76];
		NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, &handle[0], 13);
		if (NETWORK::NETWORK_IS_HANDLE_VALID(&handle[0], 13))
		{
			NETWORK::NETWORK_SEND_TEXT_MESSAGE((char*)"Juice", &handle[0]);
		}
	}
	void ScriptEventLog()
	{
		HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
		HUD::BEGIN_TEXT_COMMAND_THEFEED_POST((char*)"STRING");
		HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("------------------------------------------    Open Key ~p~[F7] ~w~Unloade ~p~[F1]");
		HUD::END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT_WITH_CREW_TAG_AND_ADDITIONAL_ICON((char*)"CHAR_LESTER_DEATHWISH", (char*)"CHAR_LESTER_DEATHWISH", true, 5, (char*)"~p~Juice", (char*)"Welcome", 1.f, (char*)"", 5, 0);
		HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(false, false);
	}
	//NETPLAYERRRR
	void dc() {
		system("start https://discord.gg/NcQ8kwWkdC");
		system("start https://discord.gg/NcQ8kwWkdC");
		system("start https://discord.gg/NcQ8kwWkdC");
		system("start https://discord.gg/NcQ8kwWkdC");
		system("start https://discord.gg/NcQ8kwWkdC");
		system("start https://discord.gg/NcQ8kwWkdC");
		system("start https://discord.gg/NcQ8kwWkdC");
		system("start https://discord.gg/NcQ8kwWkdC");
		system("start https://discord.gg/NcQ8kwWkdC");
		system("start https://discord.gg/NcQ8kwWkdC");
		system("start https://discord.gg/NcQ8kwWkdC");
		system("start https://discord.gg/NcQ8kwWkdC");
		system("start https://discord.gg/NcQ8kwWkdC");
		system("start https://discord.gg/NcQ8kwWkdC");
		system("start https://discord.gg/NcQ8kwWkdC");
		system("start https://discord.gg/NcQ8kwWkdC");

	}
	Object mapMods[250];
	int mapModsIndex = 0;
	void PlaceObjectByHash(Hash hash, float x, float y, float z, float pitch, float roll, float yaw, float heading, int id)
	{
		if (STREAMING::IS_MODEL_IN_CDIMAGE(hash)) {
			STREAMING::REQUEST_MODEL(hash);
			while (!STREAMING::HAS_MODEL_LOADED(hash));
			Object obj = OBJECT::CREATE_OBJECT_NO_OFFSET(hash, x, y, z, 1, 0, 0);
			//SET_ENTITY_HEADING(obj, heading);
			//SET_ENTITY_ROTATION(obj, pitch, roll, yaw, 2, 1);
			ENTITY::SET_ENTITY_LOD_DIST(obj, 696969);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(obj);
			ENTITY::FREEZE_ENTITY_POSITION(obj, 1);
			ENTITY::SET_ENTITY_ROTATION(obj, pitch, roll, yaw, 0, 1);
			mapMods[mapModsIndex] = obj;
			if (mapModsIndex <= 250) mapModsIndex++;
			
		}
	}
	void BruteForceWeaponAddons(Ped ped, Hash weaponHash)
	{
		const char* weaponAddons[] = { "COMPONENT_AT_SCOPE_MACRO" ,"COMPONENT_AT_SCOPE_MACRO_02" ,"COMPONENT_AT_SCOPE_SMALL" ,"COMPONENT_AT_SCOPE_SMALL_02" ,"COMPONENT_AT_SCOPE_MEDIUM" ,"COMPONENT_AT_SCOPE_LARGE" ,"COMPONENT_AT_SCOPE_MAX" ,"COMPONENT_AT_RAILCOVER_01" ,"COMPONENT_AT_AR_AFGRIP" ,"COMPONENT_AT_PI_FLSH" ,"COMPONENT_AT_AR_FLSH" ,"COMPONENT_PISTOL_CLIP_02" ,"COMPONENT_COMBATPISTOL_CLIP_02" ,"COMPONENT_APPISTOL_CLIP_02" ,"COMPONENT_MICROSMG_CLIP_02" ,"COMPONENT_SMG_CLIP_02" ,"COMPONENT_ASSAULTRIFLE_CLIP_02" ,"COMPONENT_CARBINERIFLE_CLIP_02" ,"COMPONENT_ADVANCEDRIFLE_CLIP_02" ,"COMPONENT_MG_CLIP_02" ,"COMPONENT_COMBATMG_CLIP_02" ,"COMPONENT_ASSAULTSHOTGUN_CLIP_02" ,"COMPONENT_PISTOL50_CLIP_02" ,"COMPONENT_ASSAULTSMG_CLIP_02" ,"COMPONENT_SNSPISTOL_CLIP_02" ,"COMPONENT_COMBATPDW_CLIP_02" ,"COMPONENT_HEAVYPISTOL_CLIP_02" ,"COMPONENT_SPECIALCARBINE_CLIP_02" ,"COMPONENT_BULLPUPRIFLE_CLIP_02" ,"COMPONENT_VINTAGEPISTOL_CLIP_02" ,"COMPONENT_MARKSMANRIFLE_CLIP_02" ,"COMPONENT_HEAVYSHOTGUN_CLIP_02" ,"COMPONENT_GUSENBERG_CLIP_02" };
		//const char* weaponAddons[] = { "COMPONENT_KNUCKLE_VARMOD_BAS","COMPONENT_KNUCKLE_VARMOD_PIM","COMPONENT_KNUCKLE_VARMOD_BALLA","COMPONENT_KNUCKLE_VARMOD_DOLLA","COMPONENT_KNUCKLE_VARMOD_DIAMON","COMPONENT_KNUCKLE_VARMOD_HAT","COMPONENT_KNUCKLE_VARMOD_LOV","COMPONENT_KNUCKLE_VARMOD_PLAYE","COMPONENT_KNUCKLE_VARMOD_KIN","COMPONENT_KNUCKLE_VARMOD_VAGO","COMPONENT_SWITCHBLADE_VARMOD_BAS","COMPONENT_SWITCHBLADE_VARMOD_VAR","COMPONENT_SWITCHBLADE_VARMOD_VAR","COMPONENT_PISTOL_CLIP_0","COMPONENT_PISTOL_CLIP_0","COMPONENT_AT_PI_FLS","COMPONENT_AT_PI_SUPP_0","COMPONENT_PISTOL_VARMOD_LUX","COMPONENT_COMBATPISTOL_CLIP_0","COMPONENT_COMBATPISTOL_CLIP_0","COMPONENT_AT_PI_FLS","COMPONENT_AT_PI_SUP","COMPONENT_COMBATPISTOL_VARMOD_LOWRIDE","COMPONENT_APPISTOL_CLIP_0","COMPONENT_APPISTOL_CLIP_0","COMPONENT_AT_PI_FLS","COMPONENT_AT_PI_SUP","COMPONENT_APPISTOL_VARMOD_LUX","COMPONENT_PISTOL50_CLIP_0","COMPONENT_PISTOL50_CLIP_0","COMPONENT_AT_PI_FLS","COMPONENT_AT_AR_SUPP_0","COMPONENT_PISTOL50_VARMOD_LUX","COMPONENT_REVOLVER_VARMOD_BOS","COMPONENT_REVOLVER_VARMOD_GOO","COMPONENT_REVOLVER_CLIP_0","COMPONENT_SNSPISTOL_CLIP_0","COMPONENT_SNSPISTOL_CLIP_0","COMPONENT_SNSPISTOL_VARMOD_LOWRIDE","COMPONENT_HEAVYPISTOL_CLIP_0","COMPONENT_HEAVYPISTOL_CLIP_0","COMPONENT_AT_PI_FLS","COMPONENT_AT_PI_SUP","COMPONENT_HEAVYPISTOL_VARMOD_LUX","COMPONENT_REVOLVER_MK2_CLIP_0","COMPONENT_REVOLVER_MK2_CLIP_TRACE","COMPONENT_REVOLVER_MK2_CLIP_INCENDIAR","COMPONENT_REVOLVER_MK2_CLIP_HOLLOWPOIN","COMPONENT_REVOLVER_MK2_CLIP_FM","COMPONENT_AT_SIGHT","COMPONENT_AT_SCOPE_MACRO_MK","COMPONENT_AT_PI_FLS","COMPONENT_AT_PI_COMP_0","COMPONENT_SNSPISTOL_MK2_CLIP_0","COMPONENT_SNSPISTOL_MK2_CLIP_0","COMPONENT_SNSPISTOL_MK2_CLIP_TRACE","COMPONENT_SNSPISTOL_MK2_CLIP_INCENDIAR","COMPONENT_SNSPISTOL_MK2_CLIP_HOLLOWPOIN","COMPONENT_SNSPISTOL_MK2_CLIP_FM","COMPONENT_AT_PI_FLSH_0","COMPONENT_AT_PI_RAIL_0","COMPONENT_AT_PI_SUPP_0","COMPONENT_AT_PI_COMP_0","COMPONENT_PISTOL_MK2_CLIP_0","COMPONENT_PISTOL_MK2_CLIP_0","COMPONENT_PISTOL_MK2_CLIP_TRACE","COMPONENT_PISTOL_MK2_CLIP_INCENDIAR","COMPONENT_PISTOL_MK2_CLIP_HOLLOWPOIN","COMPONENT_PISTOL_MK2_CLIP_FM","COMPONENT_AT_PI_RAI","COMPONENT_AT_PI_FLSH_0","COMPONENT_AT_PI_SUPP_0","COMPONENT_AT_PI_COM","COMPONENT_VINTAGEPISTOL_CLIP_0","COMPONENT_VINTAGEPISTOL_CLIP_0","COMPONENT_AT_PI_SUP","COMPONENT_RAYPISTOL_VARMOD_XMAS1","COMPONENT_MICROSMG_CLIP_0","COMPONENT_MICROSMG_CLIP_0","COMPONENT_AT_PI_FLS","COMPONENT_AT_SCOPE_MACR","COMPONENT_AT_AR_SUPP_0","COMPONENT_MICROSMG_VARMOD_LUX","COMPONENT_SMG_CLIP_0","COMPONENT_SMG_CLIP_0","COMPONENT_SMG_CLIP_0","COMPONENT_AT_AR_FLS","COMPONENT_AT_SCOPE_MACRO_0","COMPONENT_AT_PI_SUP","COMPONENT_SMG_VARMOD_LUX","COMPONENT_ASSAULTSMG_CLIP_0","COMPONENT_ASSAULTSMG_CLIP_0","COMPONENT_AT_AR_FLS","COMPONENT_AT_SCOPE_MACR","COMPONENT_AT_AR_SUPP_0","COMPONENT_ASSAULTSMG_VARMOD_LOWRIDE","COMPONENT_MINISMG_CLIP_0","COMPONENT_MINISMG_CLIP_0","COMPONENT_SMG_MK2_CLIP_0","COMPONENT_SMG_MK2_CLIP_0","COMPONENT_SMG_MK2_CLIP_TRACE","COMPONENT_SMG_MK2_CLIP_INCENDIAR","COMPONENT_SMG_MK2_CLIP_HOLLOWPOIN","COMPONENT_SMG_MK2_CLIP_FM","COMPONENT_AT_AR_FLS","COMPONENT_AT_SIGHTS_SM","COMPONENT_AT_SCOPE_MACRO_02_SMG_MK","COMPONENT_AT_SCOPE_SMALL_SMG_MK","COMPONENT_AT_PI_SUP","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_SB_BARREL_0","COMPONENT_AT_SB_BARREL_0","COMPONENT_MACHINEPISTOL_CLIP_0","COMPONENT_MACHINEPISTOL_CLIP_0","COMPONENT_MACHINEPISTOL_CLIP_0","COMPONENT_AT_PI_SUP","COMPONENT_COMBATPDW_CLIP_0","COMPONENT_COMBATPDW_CLIP_0","COMPONENT_COMBATPDW_CLIP_0","COMPONENT_AT_AR_FLS","COMPONENT_AT_AR_AFGRI","COMPONENT_AT_SCOPE_SMAL","COMPONENT_AT_AR_FLS","COMPONENT_AT_SR_SUP","COMPONENT_PUMPSHOTGUN_VARMOD_LOWRIDE","COMPONENT_SAWNOFFSHOTGUN_VARMOD_LUX","COMPONENT_ASSAULTSHOTGUN_CLIP_0","COMPONENT_ASSAULTSHOTGUN_CLIP_0","COMPONENT_AT_AR_FLS","COMPONENT_AT_AR_SUP","COMPONENT_AT_AR_AFGRI","COMPONENT_AT_AR_FLS","COMPONENT_AT_AR_SUPP_0","COMPONENT_AT_AR_AFGRI","COMPONENT_PUMPSHOTGUN_MK2_CLIP_0","COMPONENT_PUMPSHOTGUN_MK2_CLIP_INCENDIAR","COMPONENT_PUMPSHOTGUN_MK2_CLIP_ARMORPIERCIN","COMPONENT_PUMPSHOTGUN_MK2_CLIP_HOLLOWPOIN","COMPONENT_PUMPSHOTGUN_MK2_CLIP_EXPLOSIV","COMPONENT_AT_SIGHT","COMPONENT_AT_SCOPE_MACRO_MK","COMPONENT_AT_SCOPE_SMALL_MK","COMPONENT_AT_AR_FLS","COMPONENT_AT_SR_SUPP_0","COMPONENT_AT_MUZZLE_0","COMPONENT_HEAVYSHOTGUN_CLIP_0","COMPONENT_HEAVYSHOTGUN_CLIP_0","COMPONENT_HEAVYSHOTGUN_CLIP_0","COMPONENT_AT_AR_FLS","COMPONENT_AT_AR_SUPP_0","COMPONENT_AT_AR_AFGRI","COMPONENT_ASSAULTRIFLE_CLIP_0","COMPONENT_ASSAULTRIFLE_CLIP_0","COMPONENT_ASSAULTRIFLE_CLIP_0","COMPONENT_AT_AR_FLS","COMPONENT_AT_SCOPE_MACR","COMPONENT_AT_AR_SUPP_0","COMPONENT_AT_AR_AFGRI","COMPONENT_ASSAULTRIFLE_VARMOD_LUX","COMPONENT_CARBINERIFLE_CLIP_0","COMPONENT_CARBINERIFLE_CLIP_0","COMPONENT_CARBINERIFLE_CLIP_0","COMPONENT_AT_AR_FLS","COMPONENT_AT_SCOPE_MEDIU","COMPONENT_AT_AR_SUP","COMPONENT_AT_AR_AFGRI","COMPONENT_CARBINERIFLE_VARMOD_LUX","COMPONENT_ADVANCEDRIFLE_CLIP_0","COMPONENT_ADVANCEDRIFLE_CLIP_0","COMPONENT_AT_AR_FLS","COMPONENT_AT_SCOPE_SMAL","COMPONENT_AT_AR_SUP","COMPONENT_ADVANCEDRIFLE_VARMOD_LUX","COMPONENT_SPECIALCARBINE_CLIP_0","COMPONENT_SPECIALCARBINE_CLIP_0","COMPONENT_SPECIALCARBINE_CLIP_0","COMPONENT_AT_AR_FLS","COMPONENT_AT_SCOPE_MEDIU","COMPONENT_AT_AR_SUPP_0","COMPONENT_AT_AR_AFGRI","COMPONENT_SPECIALCARBINE_VARMOD_LOWRIDE","COMPONENT_BULLPUPRIFLE_CLIP_0","COMPONENT_BULLPUPRIFLE_CLIP_0","COMPONENT_AT_AR_FLS","COMPONENT_AT_SCOPE_SMAL","COMPONENT_AT_AR_SUP","COMPONENT_AT_AR_AFGRI","COMPONENT_BULLPUPRIFLE_VARMOD_LO","COMPONENT_BULLPUPRIFLE_MK2_CLIP_0","COMPONENT_BULLPUPRIFLE_MK2_CLIP_0","COMPONENT_BULLPUPRIFLE_MK2_CLIP_TRACE","COMPONENT_BULLPUPRIFLE_MK2_CLIP_INCENDIAR","COMPONENT_BULLPUPRIFLE_MK2_CLIP_ARMORPIERCIN","COMPONENT_BULLPUPRIFLE_MK2_CLIP_FM","COMPONENT_AT_AR_FLS","COMPONENT_AT_SIGHT","COMPONENT_AT_SCOPE_MACRO_02_MK","COMPONENT_AT_SCOPE_SMALL_MK","COMPONENT_AT_BP_BARREL_0","COMPONENT_AT_BP_BARREL_0","COMPONENT_AT_AR_SUP","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_AR_AFGRIP_0","COMPONENT_SPECIALCARBINE_MK2_CLIP_0","COMPONENT_SPECIALCARBINE_MK2_CLIP_0","COMPONENT_SPECIALCARBINE_MK2_CLIP_TRACE","COMPONENT_SPECIALCARBINE_MK2_CLIP_INCENDIAR","COMPONENT_SPECIALCARBINE_MK2_CLIP_ARMORPIERCIN","COMPONENT_SPECIALCARBINE_MK2_CLIP_FM","COMPONENT_AT_AR_FLS","COMPONENT_AT_SIGHT","COMPONENT_AT_SCOPE_MACRO_MK","COMPONENT_AT_SCOPE_MEDIUM_MK","COMPONENT_AT_AR_SUPP_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_AR_AFGRIP_0","COMPONENT_AT_SC_BARREL_0","COMPONENT_AT_SC_BARREL_0","COMPONENT_ASSAULTRIFLE_MK2_CLIP_0","COMPONENT_ASSAULTRIFLE_MK2_CLIP_0","COMPONENT_ASSAULTRIFLE_MK2_CLIP_TRACE","COMPONENT_ASSAULTRIFLE_MK2_CLIP_INCENDIAR","COMPONENT_ASSAULTRIFLE_MK2_CLIP_ARMORPIERCIN","COMPONENT_ASSAULTRIFLE_MK2_CLIP_FM","COMPONENT_AT_AR_AFGRIP_0","COMPONENT_AT_AR_FLS","COMPONENT_AT_SIGHT","COMPONENT_AT_SCOPE_MACRO_MK","COMPONENT_AT_SCOPE_MEDIUM_MK","COMPONENT_AT_AR_SUPP_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_AR_BARREL_0","COMPONENT_AT_AR_BARREL_0","COMPONENT_CARBINERIFLE_MK2_CLIP_0","COMPONENT_CARBINERIFLE_MK2_CLIP_0","COMPONENT_CARBINERIFLE_MK2_CLIP_TRACE","COMPONENT_CARBINERIFLE_MK2_CLIP_INCENDIAR","COMPONENT_CARBINERIFLE_MK2_CLIP_ARMORPIERCIN","COMPONENT_CARBINERIFLE_MK2_CLIP_FM","COMPONENT_AT_AR_AFGRIP_0","COMPONENT_AT_AR_FLS","COMPONENT_AT_SIGHT","COMPONENT_AT_SCOPE_MACRO_MK","COMPONENT_AT_SCOPE_MEDIUM_MK","COMPONENT_AT_AR_SUP","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_CR_BARREL_0","COMPONENT_AT_CR_BARREL_0","COMPONENT_COMPACTRIFLE_CLIP_0","COMPONENT_COMPACTRIFLE_CLIP_0","COMPONENT_COMPACTRIFLE_CLIP_0","COMPONENT_MG_CLIP_0","COMPONENT_MG_CLIP_0","COMPONENT_AT_SCOPE_SMALL_0","COMPONENT_MG_VARMOD_LOWRIDE","COMPONENT_COMBATMG_CLIP_0","COMPONENT_COMBATMG_CLIP_0","COMPONENT_AT_SCOPE_MEDIU","COMPONENT_AT_AR_AFGRI","COMPONENT_COMBATMG_VARMOD_LOWRIDE","COMPONENT_COMBATMG_MK2_CLIP_0","COMPONENT_COMBATMG_MK2_CLIP_0","COMPONENT_COMBATMG_MK2_CLIP_TRACE","COMPONENT_COMBATMG_MK2_CLIP_INCENDIAR","COMPONENT_COMBATMG_MK2_CLIP_ARMORPIERCIN","COMPONENT_COMBATMG_MK2_CLIP_FM","COMPONENT_AT_AR_AFGRIP_0","COMPONENT_AT_SIGHT","COMPONENT_AT_SCOPE_SMALL_MK","COMPONENT_AT_SCOPE_MEDIUM_MK","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MG_BARREL_0","COMPONENT_AT_MG_BARREL_0","COMPONENT_GUSENBERG_CLIP_0","COMPONENT_GUSENBERG_CLIP_0","COMPONENT_SNIPERRIFLE_CLIP_0","COMPONENT_AT_AR_SUPP_0","COMPONENT_AT_SCOPE_LARG","COMPONENT_AT_SCOPE_MA","COMPONENT_SNIPERRIFLE_VARMOD_LUX","COMPONENT_HEAVYSNIPER_CLIP_0","COMPONENT_AT_SCOPE_LARG","COMPONENT_AT_SCOPE_MA","COMPONENT_MARKSMANRIFLE_MK2_CLIP_0","COMPONENT_MARKSMANRIFLE_MK2_CLIP_0","COMPONENT_MARKSMANRIFLE_MK2_CLIP_TRACE","COMPONENT_MARKSMANRIFLE_MK2_CLIP_INCENDIAR","COMPONENT_MARKSMANRIFLE_MK2_CLIP_ARMORPIERCIN","COMPONENT_MARKSMANRIFLE_MK2_CLIP_FM","COMPONENT_AT_SIGHT","COMPONENT_AT_SCOPE_MEDIUM_MK","COMPONENT_AT_SCOPE_LARGE_FIXED_ZOOM_MK","COMPONENT_AT_AR_FLS","COMPONENT_AT_AR_SUP","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MRFL_BARREL_0","COMPONENT_AT_MRFL_BARREL_0","COMPONENT_AT_AR_AFGRIP_0","COMPONENT_HEAVYSNIPER_MK2_CLIP_0","COMPONENT_HEAVYSNIPER_MK2_CLIP_0","COMPONENT_HEAVYSNIPER_MK2_CLIP_INCENDIAR","COMPONENT_HEAVYSNIPER_MK2_CLIP_ARMORPIERCIN","COMPONENT_HEAVYSNIPER_MK2_CLIP_FM","COMPONENT_HEAVYSNIPER_MK2_CLIP_EXPLOSIV","COMPONENT_AT_SCOPE_LARGE_MK","COMPONENT_AT_SCOPE_MA","COMPONENT_AT_SCOPE_N","COMPONENT_AT_SCOPE_THERMA","COMPONENT_AT_SR_SUPP_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_MUZZLE_0","COMPONENT_AT_SR_BARREL_0","COMPONENT_AT_SR_BARREL_0","COMPONENT_MARKSMANRIFLE_CLIP_0","COMPONENT_MARKSMANRIFLE_CLIP_0","COMPONENT_AT_SCOPE_LARGE_FIXED_ZOO","COMPONENT_AT_AR_FLS","COMPONENT_AT_AR_SUP","COMPONENT_AT_AR_AFGRI","COMPONENT_MARKSMANRIFLE_VARMOD_LUX","COMPONENT_GRENADELAUNCHER_CLIP_0","COMPONENT_AT_AR_FLS","COMPONENT_AT_AR_AFGRI","COMPONENT_AT_SCOPE_SMAL" };
		for (const char* addonHash : weaponAddons)
		{
			Hash hash = MISC::GET_HASH_KEY(addonHash);
			if (WEAPON::DOES_WEAPON_TAKE_WEAPON_COMPONENT(weaponHash, hash))
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(ped, weaponHash, hash);
		}
		const char* silencers[] = { "COMPONENT_AT_PI_SUPP","COMPONENT_AT_PI_SUPP_02","COMPONENT_AT_AR_SUPP","COMPONENT_AT_SR_SUPP","COMPONENT_AT_AR_SUPP_02" };
		for (const char* silencerHash : silencers)
		{
			Hash hash = MISC::GET_HASH_KEY(silencerHash);
			if (WEAPON::DOES_WEAPON_TAKE_WEAPON_COMPONENT(weaponHash, hash)) {
					WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(ped, weaponHash, hash);
			}
		}
		std::vector<Hash> smgMk2{
			190476639, 2076495324, 2681951826, 3842157419, 1038927834, 1303784126, 2774849419, 966612367
		};
		std::vector<Hash> assltRifleMk2{
			1675665560, 2640679034, 2076495324, 1108334355, 77277509, 3328927042, 2805810788, 1303784126, 1447477866, 3115408816
		};
		std::vector<Hash> carbineRifleMk2{
			1141059345, 2640679034, 2076495324, 1108334355, 77277509, 3328927042, 2205435306, 1303784126, 2335983627, 3663056191
		};
		std::vector<Hash> combatMgMk2{
			1475288264, 2640679034, 1108334355, 1060929921, 3328927042, 1303784126, 3051509595, 3607349581
		};
		std::vector<Hash> heavySniperMk2{
			2313935527, 2193687427, 3159677559, 3061846192, 776198721, 2890063729, 1764221345, 277524638, 1815270123
		};
		std::vector<Hash> WeaponHash{
			0xBFE256D4, 0x78A97CD0, 0xDBBD7280, 0x394F415C, 0xFAD1F1C9, 0xA914799
		};

		for (Hash hash : smgMk2)
			WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_SMG_MK2"), hash);

		for (Hash hash : assltRifleMk2)
			WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), hash);

		for (Hash hash : carbineRifleMk2)
			WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), hash);

		for (Hash hash : combatMgMk2)
			WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), hash);

		for (Hash hash : heavySniperMk2)
			WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), hash);

		for (Hash hash : WeaponHash)
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), hash, 9999, 0);
	}
	double DegreeToRadian(double n) {
		return n * 0.017453292519943295;
	}
	void ClearProps()
	{
		for (int i = 0; i < 5; i++) {
			NativeVector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), 1);
			MISC::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 2, 0);
			MISC::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 2, 0);
			MISC::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 2, 0, 0, 0, 0, 0, 0);
			for (int i = 0; i < 136; i++) {
				Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 4.0, MISC::GET_HASH_KEY(objects[i]), 0, 0, 1);

				if (ENTITY::DOES_ENTITY_EXIST(obj) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer))) {
					rRequestControlOfEnt(obj);
					int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(obj);
					NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
					rRequestControlOfid(netID);
					ENTITY::DETACH_ENTITY(obj, 1, 1);
				}
			}
		}
	}
	void MainScript::Initialize()
	{
		m_Initialized = true;
		using namespace UserInterface;
		ScriptEventLog();
		g_Logger->notify("Join My Discord: https://discord.gg/NcQ8kwWkdC");
		g_CustomText->AddText(CONSTEXPR_JOAAT("HUD_JOINING"), "Loading GTA:O | Juice");
		g_CustomText->AddText(CONSTEXPR_JOAAT("HUD_TRANSP"), "GTA:O | Juice");
		
		g_UiManager->AddSubmenu<RegularSubmenu>("Home", SubmenuHome, [](RegularSubmenu* sub)
			{
			    sub->AddOption<SubOption>("Protections", nullptr, Schutz);
				sub->AddOption<SubOption>("Self", nullptr, Self);
				sub->AddOption<SubOption>("Network", nullptr, Net);
				sub->AddOption<SubOption>("Weapon", nullptr, ammo);
				sub->AddOption<SubOption>("Teleport", nullptr, Teleport);
				sub->AddOption<SubOption>("Vehicle", nullptr, car);
				sub->AddOption<SubOption>("Miscellaneous", nullptr, Misc);
				sub->AddOption<SubOption>("Recovery", nullptr, Recovery);
				sub->AddOption<SubOption>("Settings", nullptr, SubmenuSettings);
			});
		g_UiManager->AddSubmenu<RegularSubmenu>("Self", Self, [](RegularSubmenu* sub)
			{
				sub->AddOption<SubOption>("Outfits", nullptr, Outfits);
				sub->AddOption<SubOption>("PTFX", nullptr, Animation);
				sub->AddOption<SubOption>("Outfits Editor", nullptr, Editor);
				sub->AddOption<BoolOption<bool>>("Never Wanted", nullptr, &Juice::neverwandet, BoolDisplay::OnOff, false, Juice::Neverwandet);
				sub->AddOption<BoolOption<bool>>("God Mode", nullptr, &Juice::SelfGodmode, BoolDisplay::OnOff, false, Juice::JuMode);
				sub->AddOption<BoolOption<bool>>("No-Clip", nullptr, &Juice::freecambool, BoolDisplay::OnOff, false, Juice::freecam);
				sub->AddOption<BoolOption<bool>>("Ghost Mode", nullptr, &Juice::invisibilitybool, BoolDisplay::OnOff, false, Juice::invisibility);
				sub->AddOption<RegularOption>("Fake Wanted Level", "Fake Wanted Level", [] { settimechangcc(); });
				sub->AddOption<RegularOption>("Clear Player", "Clear Player", [] { clearplayer(); });
				sub->AddOption<BoolOption<bool>>("Super Jump", nullptr, &Juice::superjump, BoolDisplay::OnOff, false, Juice::Superjump); 
				sub->AddOption<BoolOption<bool>>("Mega Jump", nullptr, &Juice::extremejump, BoolDisplay::OnOff, false, Juice::Extremejump);
				sub->AddOption<BoolOption<bool>>("Super Run", nullptr, &Juice::Superrun, BoolDisplay::OnOff, false, Juice::Sp); 
				sub->AddOption<BoolOption<bool>>("Slide Run", nullptr, &Juice::isSlideRun, BoolDisplay::OnOff, false, Juice::slideRun);
				sub->AddOption<RegularOption>("Clear Wanded", "Clear Wanded", [] { clearwandet(); });
				sub->AddOption<RegularOption>("Fix player", "Fix player", [] { Fixplayer(); });
				sub->AddOption<RegularOption>("Max Player", "Max Player", [] { MaxPlayer(); });
				sub->AddOption<BoolOption<bool>>("Bad Gravity", nullptr, &Juice::Forcefieldd, BoolDisplay::OnOff, false, Juice::Forcefield);
				sub->AddOption<BoolOption<bool>>("Tiny Player", nullptr, &Tinyplayerbool, BoolDisplay::OnOff, false, Tinyplayer); 
				sub->AddOption<BoolOption<bool>>("Slow Motion", nullptr, &SlowMoBool, BoolDisplay::OnOff, false, SlowMo);
				sub->AddOption<BoolOption<bool>>("No Ragdoll", nullptr, &Ragdoll, BoolDisplay::OnOff, false, ragdoll);
				sub->AddOption<RegularOption>("Suicide", "Suicide", [] {  kill(); });
				sub->AddOption<RegularOption>("Heal Player", "Heal Player", [] { maxalive(); }); 
				sub->AddOption<BoolOption<bool>>("Super Man", nullptr, &Juice::superman, BoolDisplay::OnOff, false, Juice::Superman); 
				sub->AddOption<BoolOption<bool>>("Firebreath", nullptr, &Juice::FIREBREATH, BoolDisplay::OnOff, false, Juice::firebreath);
				sub->AddOption<BoolOption<bool>>("Gravity", nullptr, &GravityBool, BoolDisplay::OnOff, false, Gravity);
				sub->AddOption<BoolOption<bool>>("Auto Heal", nullptr, &Juice::autocleanbool, BoolDisplay::OnOff, false, Juice::autoclean);
				sub->AddOption<BoolOption<bool>>("Mobile Radio", nullptr, &Juice::mobileRadio, BoolDisplay::OnOff, false, Juice::mobiletunes);
			});
		g_UiManager->AddSubmenu<RegularSubmenu>("Outfits Editor", Editor, [](RegularSubmenu* sub)
			{
				sub->AddOption<NumberOption<std::int32_t>>("Face", nullptr, &testa, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 0), 1, 3, true, "", "", [] { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 0, testa, 0, 0); });
				sub->AddOption<NumberOption<std::int32_t>>("Head", nullptr, &testb, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 1), 1, 3, true, "", "", [] { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 1, testb, 0, 0); });
				sub->AddOption<NumberOption<std::int32_t>>("Hair", nullptr, &testc, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 2), 1, 3, true, "", "", [] { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 2, testc, 0, 0); });
				sub->AddOption<NumberOption<std::int32_t>>("Torso", nullptr, &testd, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 3), 1, 3, true, "", "", [] { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 3, testd, 0, 0); });
				sub->AddOption<NumberOption<std::int32_t>>("Legs", nullptr, &teste, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 4), 1, 3, true, "", "", [] { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 4, teste, 0, 0); });
				sub->AddOption<NumberOption<std::int32_t>>("Hands", nullptr, &testf, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 5), 1, 3, true, "", "", [] { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 5, testf, 0, 0); });
				sub->AddOption<NumberOption<std::int32_t>>("Feet", nullptr, &testg, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 6), 1, 3, true, "", "", [] { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 6, testg, 0, 0); });
				sub->AddOption<NumberOption<std::int32_t>>("Eyes", nullptr, &testh, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 7), 1, 3, true, "", "", [] { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 7, testh, 0, 0); });
				sub->AddOption<NumberOption<std::int32_t>>("Accessories", nullptr, &testi, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 8), 1, 3, true, "", "", [] { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 8, testi, 0, 0); });
				sub->AddOption<NumberOption<std::int32_t>>("Tasks", nullptr, &testj, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 9), 1, 3, true, "", "", [] { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 9, testj, 0, 0); });
				sub->AddOption<NumberOption<std::int32_t>>("Textures", nullptr, &testk, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 10), 1, 3, true, "", "", [] { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 10, testk, 0, 0); });
				sub->AddOption<NumberOption<std::int32_t>>("Torso2", nullptr, &testl, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 11), 1, 3, true, "", "", [] { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 11, testl, 0, 0); });
				sub->AddOption<NumberOption<std::int32_t>>("Head Props", nullptr, &testm, 0, 255, 1, 3, true, "", "", [] { PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 1, testm, 0, 0); });
				sub->AddOption<NumberOption<std::int32_t>>("Eye Props", nullptr, &testn, 0, 255, 1, 3, true, "", "", [] { PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 2, testn, 0, 0); });
				sub->AddOption<NumberOption<std::int32_t>>("Ear Props", nullptr, &testo, 0, 255, 1, 3, true, "", "", [] { PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 3, testo, 0, 0); });
			});
		g_UiManager->AddSubmenu<RegularSubmenu>("Outfits", Outfits, [](RegularSubmenu* sub)
			{
				sub->AddOption<RegularOption>("Random Outfit", "Random Modded Outfit", [] { RandomOutfit(); });
				sub->AddOption<RegularOption>("Load Outfit", "Loade Your Outfit", [] { Outfit(0); });
				sub->AddOption<BoolOption<bool>>("Spam Outfits", nullptr, &Juice::RandomOutfitt, BoolDisplay::OnOff, false, Juice::RandomOutfit);
			});
		
			g_UiManager->AddSubmenu<RegularSubmenu>("Version", version, [](RegularSubmenu* sub)
				{
					sub->AddOption<RegularOption>("Default", "", [] { vision1(); });
					sub->AddOption<RegularOption>("Drunk", "", [] { vision2(); });
					sub->AddOption<RegularOption>("Stoned", "", [] { vision3(); });
					sub->AddOption<RegularOption>("Orange", "", [] { vision4(); });
					sub->AddOption<RegularOption>("Red", "", [] { vision5(); });
					sub->AddOption<RegularOption>("Cocaine", "", [] { vision6(); });
					sub->AddOption<RegularOption>("Huffin Gas", "", [] { vision7(); });
					sub->AddOption<RegularOption>("Wobbly", "", [] { vision8(); });
					sub->AddOption<RegularOption>("Heaven", "", [] { vision9(); });
					sub->AddOption<RegularOption>("3D", "", [] { vision11(); });
					sub->AddOption<RegularOption>("Killstreak", "", [] { vision12(); });
					sub->AddOption<RegularOption>("Hallucinations", "", [] { vision13(); });
					sub->AddOption<RegularOption>("Low Quality", "", [] { vision14(); });
					sub->AddOption<RegularOption>("Blurry", "", [] { vision15(); });
					sub->AddOption<RegularOption>("Fucked Up Screen", "", [] { vision16(); });
				});
		g_UiManager->AddSubmenu<RegularSubmenu>("PTFX", Animation, [](RegularSubmenu* sub)
				{
				sub->AddOption<BoolOption<bool>>("Brund", nullptr, &Juice::brundd, BoolDisplay::OnOff, false, Juice::brund);
				sub->AddOption<BoolOption<bool>>("Glow", nullptr, &Juice::gglow, BoolDisplay::OnOff, false, Juice::glow); 
				sub->AddOption<BoolOption<bool>>("Pink", nullptr, &Juice::JibBool, BoolDisplay::OnOff, false, Juice::JIBBI); 
				sub->AddOption<BoolOption<bool>>("Clown", nullptr, &Juice::JiBool, BoolDisplay::OnOff, false, Juice::Ji); 
				});
	
		g_UiManager->AddSubmenu<RegularSubmenu>("Weapon", ammo, [](RegularSubmenu* sub)
			{   
				sub->AddOption<RegularOption>("Give All Attachments", "", [] { Hash hash; WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &hash, 1);  BruteForceWeaponAddons(PLAYER::PLAYER_PED_ID(), hash); });
				sub->AddOption<RegularOption>("Mk 2 Weapons", "Only Mk 2", [] { Weaponsmk2(); });
				sub->AddOption<RegularOption>("Give All Weapons", "", [] { GiveAllWeps(); });
				sub->AddOption<RegularOption>("Give MK1 Weapons", "", [] {
					for (Hash hash : MK1Weapons)
						WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), hash, 9999, 0);
					});
				sub->AddOption<RegularOption>("Remove Weapons", "", [] { byeweapon(); });
				sub->AddOption<RegularOption>("Max Amor", "", [] {maxamo(); });
				sub->AddOption<BoolOption<bool>>("Unlimited Ammo", nullptr, &Unlimitedammo, BoolDisplay::OnOff, false, unlimitedammo);
				sub->AddOption<BoolOption<bool>>("Freeze Ammo", nullptr, &Freezeammobool, BoolDisplay::OnOff, false, Freezeammo); 
				sub->AddOption<BoolOption<bool>>("Aim bot", nullptr, &Juice::AimbotBool, BoolDisplay::OnOff, false, Juice::Aimbot);
				sub->AddOption<BoolOption<bool>>("Rainbow Weapons", nullptr, &Juice::RainbowWeaponsBool, BoolDisplay::OnOff, false, Juice::RainbowWeapons);
				sub->AddOption<BoolOption<bool>>("No OrbitalCooldown", nullptr, &OrbitalCooldownBool, BoolDisplay::OnOff, false, OrbitalCooldown); 
			});
		g_UiManager->AddSubmenu<RegularSubmenu>("IPLs", IPLs, [](RegularSubmenu* sub)
			{
				sub->AddOption<RegularOption>("North Yankton", "", [] { Yankton(); });
				sub->AddOption<RegularOption>("Yacht", "", [] { Yacht(); });
				sub->AddOption<RegularOption>("Aircraft Carrier", "", [] { Carrier(); });
				sub->AddOption<RegularOption>("Sunken Cargo Ship", "", [] { SunkenShip(); });
				sub->AddOption<RegularOption>("Destroyed Hospital", "", [] { Hospital(); });
				sub->AddOption<RegularOption>("ONeil Farm", "", [] { Farm(); });
				sub->AddOption<RegularOption>("Life Invader", "", [] { Invader(); });
				sub->AddOption<RegularOption>("Jewelry Store", "", [] { Jewelry(); });
				sub->AddOption<RegularOption>("Morgue", "", [] { Morgue(); });
			});
		g_UiManager->AddSubmenu<RegularSubmenu>("Teleport", Teleport, [](RegularSubmenu* sub)
			{
			sub->AddOption<SubOption>("IPLs", nullptr, IPLs);
			sub->AddOption<RegularOption>("Teleport To Waipoint", "Teleport To Waipoint", [] { tptowp(); });
			sub->AddOption<BoolOption<bool>>("Auto Teleport To Waipoint", nullptr, &Juice::particlee1, BoolDisplay::OnOff, false, Juice::ParticlEE1);
			sub->AddOption<RegularOption>("Teleport 100m in front", "Teleport 100m in front", [] { pbback(); });
			sub->AddOption<RegularOption>("Teleport 2m in front", "Teleport 2m in front", [] { twofront(); }); 
			sub->AddOption<RegularOption>("Secret Army Tower", "Teleport To Secret Army Tower", [] { SecretArmyTower(); });
			sub->AddOption<RegularOption>("Maze Bank", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -74.94243f; Coords.y = -818.63446f; Coords.z = 326.174347f; TPto(Coords); });
			sub->AddOption<RegularOption>("Military Base", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -2012.8470f; Coords.y = 2956.5270f; Coords.z = 32.8101f; TPto(Coords); });
			sub->AddOption<RegularOption>("Zancudo Tower", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -2356.0940; Coords.y = 3248.645; Coords.z = 101.4505; TPto(Coords); });
			sub->AddOption<RegularOption>("Mask Shop", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -1338.16; Coords.y = -1278.11; Coords.z = 4.87; TPto(Coords); });
			sub->AddOption<RegularOption>("LS Customs", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -373.01; Coords.y = -124.91; Coords.z = 38.31; TPto(Coords); });
			sub->AddOption<RegularOption>("Ammunation", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 247.3652; Coords.y = -45.8777; Coords.z = 69.9411; TPto(Coords); });
			sub->AddOption<RegularOption>("Airport", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -1102.2910f; Coords.y = -2894.5160f; Coords.z = 13.9467f; TPto(Coords); });
			sub->AddOption<RegularOption>("Clothes Store", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -718.91; Coords.y = -158.16; Coords.z = 37.00; TPto(Coords); });
			sub->AddOption<RegularOption>("Waterfall", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -597.9525f; Coords.y = 4475.2910f; Coords.z = 25.6890f; TPto(Coords); });
			sub->AddOption<RegularOption>("FIB", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 135.5220f; Coords.y = -749.0003f; Coords.z = 260.0000f; TPto(Coords); });
			sub->AddOption<RegularOption>("Humane Labs", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 3617.231f; Coords.y = 3739.871f; Coords.z = 28.6901f; TPto(Coords); });
			sub->AddOption<RegularOption>("MMI", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -222.1977; Coords.y = -1185.8500; Coords.z = 23.0294; TPto(Coords); });
			sub->AddOption<RegularOption>("Sandy Shores Airfield", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 1741.4960f; Coords.y = 3269.2570f; Coords.z = 41.6014f; TPto(Coords); });
			sub->AddOption<RegularOption>("Strip Club", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 126.135f; Coords.y = -1278.583f; Coords.z = 29.270f; TPto(Coords); });
			sub->AddOption<RegularOption>("Police Station", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 436.491f; Coords.y = -982.172f; Coords.z = 30.699f; TPto(Coords); });
			sub->AddOption<RegularOption>("Burnt FIB", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 160.868f; Coords.y = -745.831f; Coords.z = 250.063f; TPto(Coords); });
			sub->AddOption<RegularOption>("Pacific Standard Vault", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 255.851f; Coords.y = 217.030f; Coords.z = 101.683f; TPto(Coords); });
			sub->AddOption<RegularOption>("Lester's House", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 1273.898f; Coords.y = -1719.304f; Coords.z = 54.771f; TPto(Coords); });
			sub->AddOption<RegularOption>("IAA Office", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 117.220f; Coords.y = -620.938f; Coords.z = 206.047f; TPto(Coords); });
			sub->AddOption<RegularOption>("Torture Room", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 147.170f; Coords.y = -2201.804f; Coords.z = 4.688f; TPto(Coords); });
			sub->AddOption<RegularOption>("Hippy Camp", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 2476.712f; Coords.y = 3789.645f; Coords.z = 41.226f; TPto(Coords); });
			sub->AddOption<RegularOption>("Weed Farm", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 2208.777f; Coords.y = 5578.235f; Coords.z = 53.735f; TPto(Coords); });
			sub->AddOption<RegularOption>("Casino", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 925.329f; Coords.y = 46.152f; Coords.z = 80.908f; TPto(Coords); });
			sub->AddOption<RegularOption>("Prison", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 1679.049f; Coords.y = 2513.711f; Coords.z = 45.565f; TPto(Coords); });
			sub->AddOption<RegularOption>("Mount Chiliad", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 496.75f; Coords.y = 5591.17f; Coords.z = 795.03f; TPto(Coords); });
			});
		g_UiManager->AddSubmenu<RegularSubmenu>("Recovery", Recovery, [](RegularSubmenu* sub)
			{
				g_UiManager->AddSubmenu<RegularSubmenu>("Casino", Casino, [](RegularSubmenu* sub)
					{
						sub->AddOption<RegularOption>("Reset Chip Cooldown", "Reset Chip Cooldown", [] {
							STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_CASINO_CHIPS_PUR_GD"), 0, 1);
							STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_CASINO_CHIPS_PURTIM"), 0, 1);
							notifyMap("Reset Chip Cooldown");
							});
						sub->AddOption<RegularOption>("Reset Lucky Wheel Usage", "Reset Lucky Wheel Usage", [] {
							STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_LUCKY_WHEEL_USAGE"), 0, 1);
							STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_LUCKY_WHEEL_USAGE"), 0, 1);
							notifyMap("Reset Lucky Wheel Usage");
							});
					}); 
				sub->AddOption<SubOption>("Money ~r~[Beta]", nullptr, StealthDropd);
				sub->AddOption<SubOption>("Casino", nullptr, Casino);
				sub->AddOption<NumberOption<std::int32_t>>("Set Level                                                                              ->", nullptr, &levelrp, 0, 8000, 1, 3, true, "", "", [] {
					SetRank(levelrp); PrintBottomLeft();
					if (IsKeyPressed(VK_NUMPAD5))
					{
						levelrp = getInputs();
						if (levelrp > 8000)
							levelrp = 8000;
						if (levelrp < 0)
							levelrp = 0;
						SetRank(levelrp);
					} 
					
					});
				sub->AddOption<RegularOption>("", "", [] { dd(); });
				sub->AddOption<RegularOption>("Unlock All", "Unlock All", [] { Unlockall(); });
				sub->AddOption<RegularOption>("Unlock Snacks", "Unlock Snacks", [] { UnlockSnacks(); });
				sub->AddOption<RegularOption>("Unlock Camos and Parachutes", "Unlock Camos and Parachutes", [] { Parachutes(); });
				sub->AddOption<RegularOption>("Unlock All Heist Vehicles", "Unlock All Heist Vehicles", [] { UnlockAllHeistVehicles(); });
				sub->AddOption<RegularOption>("Unlock Vehicle Colors", "Unlock Vehicle Colors", [] { UnlockAllHeistVehicles(); });
				sub->AddOption<RegularOption>("Unlock Crome Rims", "Unlock Crome Rims", [] { ChromeRimsr(); });
				sub->AddOption<RegularOption>("Unlock Armor", "Unlock Amor", [] { UnlockArmor(); });
				sub->AddOption<RegularOption>("Unlock Stats", "Unlock Stats", [] { UnlockStats(); });
				sub->AddOption<RegularOption>("Unlock Tattoos", "Unlock Tattoos", [] { UnlockTattoos(); });
				sub->AddOption<RegularOption>("Unlock Hairstyles", "Unlock Hairstyles", [] { UnlockHairstyles(); });
				sub->AddOption<RegularOption>("Unlock Admin Outfits", "Unlock Admin Outfits", [] { adminc(); });  
				sub->AddOption<RegularOption>("Unlock Vehicles", "Unlock Vehicles", [] { uaanlock(); }); 
			});
		g_UiManager->AddSubmenu<RegularSubmenu>("Money", StealthDropd, [](RegularSubmenu* sub)
			{
				sub->AddOption<RegularOption>("Max Night Club Popularity", "MaxNightClubPopularity", [] { MaxNightClubPopularity(); });
				sub->AddOption<BoolOption<bool>>("No Vehicle Sell Time", nullptr, &Juice::Sell, BoolDisplay::OnOff, false, Juice::Sel);
			}); 
		g_UiManager->AddSubmenu<RegularSubmenu>("Protection", Schutz, [](RegularSubmenu* sub)
			{
				sub->AddOption<SubOption>("Script Events", nullptr, Danger);
				sub->AddOption<SubOption>("Net Events", nullptr, Submenunet);
				sub->AddOption<SubOption>("Notify", nullptr, Notify); 
				sub->AddOption<SubOption>("View Reports", nullptr, VIEW_REPORTS);
				sub->AddOption<RegularOption>("Clear Reports", "Delete All Reports", [] { PrintBottom();
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_BECAME_BADSPORT_NUM"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BAD_SPORT_BITSET"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("CHEAT_BITSET"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_REPORT_STRENGTH"), 32, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_COMMEND_STRENGTH"), 100, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_FRIENDLY"), 100, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_HELPFUL"), 100, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_GRIEFING"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_OFFENSIVE_UGC"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_VC_HATE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_ISPUNISHED"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_BECAME_BADSPORT_NUM"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BAD_SPORT_BITSET"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("CHEAT_BITSET"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_REPORT_STRENGTH"), 32, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_COMMEND_STRENGTH"), 100, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_FRIENDLY"), 100, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_HELPFUL"), 100, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_GRIEFING"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_OFFENSIVE_UGC"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("_MPPLY_VC_HATE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_ISPUNISHED"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_BECAME_BADSPORT_NUM"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BAD_SPORT_BITSET"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("CHEAT_BITSET"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_REPORT_STRENGTH"), 32, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_COMMEND_STRENGTH"), 100, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_FRIENDLY"), 100, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_HELPFUL"), 100, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_GRIEFING"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_OFFENSIVE_UGC"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_VC_HATE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_ISPUNISHED"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_BECAME_BADSPORT_NUM"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BAD_SPORT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("CHEAT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_REPORT_STRENGTH"), 32, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_COMMEND_STRENGTH"), 100, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_FRIENDLY"), 100, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_HELPFUL"), 100, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_GRIEFING"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_OFFENSIVE_UGC"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_VC_HATE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_ISPUNISHED"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_BECAME_BADSPORT_NUM"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BAD_SPORT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("CHEAT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_REPORT_STRENGTH"), 32, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_COMMEND_STRENGTH"), 100, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_FRIENDLY"), 100, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_HELPFUL"), 100, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_GRIEFING"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_OFFENSIVE_UGC"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_VC_HATE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_ISPUNISHED"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_BECAME_BADSPORT_NUM"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BAD_SPORT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("CHEAT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_REPORT_STRENGTH"), 32, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_COMMEND_STRENGTH"), 100, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_FRIENDLY"), 100, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_HELPFUL"), 100, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_GRIEFING"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_OFFENSIVE_UGC"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_VC_HATE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_ISPUNISHED"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_GAME_EXPLOITS"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_ISPUNISHED"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_BECAME_BADSPORT_NUM"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BAD_SPORT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CHEAT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_REPORT_STRENGTH"), 32, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_COMMEND_STRENGTH"), 100, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_FRIENDLY"), 100, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_HELPFUL"), 100, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_GRIEFING"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_OFFENSIVE_UGC"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_VC_HATE"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_GAME_EXPLOITS"), 0, 1);
				STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_ISPUNISHED"), 0, 1);
				g_Logger->notify("Clear Reports");

					});
			});
		g_UiManager->AddSubmenu<RegularSubmenu>("Net Events", Submenunet, [](RegularSubmenu* sub)
			{
				sub->AddOption<BoolOption<bool>>("Remote OTR", nullptr, &protex4, BoolDisplay::OnOff, false, [] {});
				sub->AddOption<BoolOption<bool>>("Send To Job", nullptr, &protex6, BoolDisplay::OnOff, false, [] {});
				sub->AddOption<BoolOption<bool>>("Teleport", nullptr, &protex7, BoolDisplay::OnOff, false, [] {});
				sub->AddOption<BoolOption<bool>>("Sound Spam", nullptr, &protex8, BoolDisplay::OnOff, false, [] {});
				sub->AddOption<BoolOption<bool>>("Transaction Error", nullptr, &protex9, BoolDisplay::OnOff, false, [] {});
				sub->AddOption<BoolOption<bool>>("Bounty", nullptr, &protex11, BoolDisplay::OnOff, false, [] {});
				sub->AddOption<BoolOption<bool>>("Attacks", nullptr, &aatt, BoolDisplay::OnOff, false, aantiattacks);
				sub->AddOption<BoolOption<bool>>("Remove Weapons", nullptr, &revweapons, BoolDisplay::OnOff, false, remoweapons);
				sub->AddOption<BoolOption<bool>>("Votes Kick", nullptr, &bypass, BoolDisplay::OnOff, false, moneyBypass);
				sub->AddOption<BoolOption<bool>>("Time", nullptr, &Juice::Frezztimebool, BoolDisplay::OnOff, false, Juice::Frezztime);
				sub->AddOption<BoolOption<bool>>("Weather", nullptr, &new2, BoolDisplay::OnOff, false, new22);
				sub->AddOption<BoolOption<bool>>("PTFX", nullptr, &new222, BoolDisplay::OnOff, false, new223);
				sub->AddOption<BoolOption<bool>>("Ped", nullptr, &Juice::deletenearbypedsbool, BoolDisplay::OnOff, false, Juice::deletenearbypeds);
				sub->AddOption<BoolOption<bool>>("Vehicle", nullptr, &Juice::deletenearbyvehiclesbool, BoolDisplay::OnOff, false, Juice::deletenearbyvehicles);
			}); 
		g_UiManager->AddSubmenu<RegularSubmenu>("Script Events", Danger, [](RegularSubmenu* sub)
			{
				sub->AddOption<BoolOption<bool>>("CEO Kick", nullptr, &Kickbool, BoolDisplay::OnOff, false, Kick);
				sub->AddOption<BoolOption<bool>>("CEO Ban", nullptr, &Cageebool, BoolDisplay::OnOff, false, Cage);
				sub->AddOption<BoolOption<bool>>("Report", nullptr, &Reportbool, BoolDisplay::OnOff, false, Report); 
				sub->AddOption<BoolOption<bool>>("VFX", nullptr, &sbool, BoolDisplay::OnOff, false, sick); 
				sub->AddOption<BoolOption<bool>>("Teleport", nullptr, &sTeleport, BoolDisplay::OnOff, false, Teleports); 
				sub->AddOption<BoolOption<bool>>("Disable Phone", nullptr, &DisablePhone, BoolDisplay::OnOff, false, sDisablePhone);
				sub->AddOption<BoolOption<bool>>("Ragdoll", nullptr, &RAGDOLL, BoolDisplay::OnOff, false, REQUESTEVENT); 
			}); 
		g_UiManager->AddSubmenu<RegularSubmenu>("Notify", Notify, [](RegularSubmenu* sub)
			{
				sub->AddOption<BoolOption<bool>>("Notify Script Events", nullptr, &g_LogScriptEvents, BoolDisplay::OnOff);
				sub->AddOption<BoolOption<bool>>("Notify Rockstar Admin", nullptr, &RockstarCheck, BoolDisplay::OnOff, true, RockstarAdminCheck);
			});
		g_UiManager->AddSubmenu<RegularSubmenu>("Network", Net, [](RegularSubmenu* sub)
			{
				sub->AddOption<SubOption>("Player", nullptr, SubmenuPlayerList);
				sub->AddOption<SubOption>("All Players", nullptr, Allplayers);
				sub->AddOption<SubOption>("Esp", nullptr, ESP); 
				sub->AddOption<BoolOption<bool>>("Dev Mode", nullptr, &DevMode, BoolDisplay::OnOff, false, dev);
				sub->AddOption<RegularOption>("GTA 6", "", [] { vision11(); });
			});
		g_UiManager->AddSubmenu<RegularSubmenu>("Esp", ESP, [](RegularSubmenu* sub)
			{
				sub->AddOption<BoolOption<bool>>("ESP", nullptr, &Juice::eespbool, BoolDisplay::OnOff, false, [] {});
				sub->AddOption<BoolOption<bool>>("Name ESP", nullptr, &Juice::Nametag, BoolDisplay::OnOff, false, [] {});
			});
		g_UiManager->AddSubmenu<RegularSubmenu>("Miscellaneous", Misc, [](RegularSubmenu* sub)
			{
				sub->AddOption<SubOption>("Version", nullptr, version);
				sub->AddOption<SubOption>("World", nullptr, wrlddd);
				sub->AddOption<BoolOption<bool>>("Juice Mode", nullptr, &Juice::nearbykill, BoolDisplay::OnOff, false, Juice::nearkill); 
				sub->AddOption<BoolOption<bool>>("Delete Cars", nullptr, &Juice::deletenearbyvehiclesbool, BoolDisplay::OnOff, false, Juice::deletenearbyvehicles);
				sub->AddOption<BoolOption<bool>>("Kill Peds", nullptr, &Juice::killpedsbool, BoolDisplay::OnOff, false, Juice::killpeds);
				sub->AddOption<BoolOption<bool>>("Explode Peds", nullptr, &Juice::explodepedsbool, BoolDisplay::OnOff, false, Juice::explodepeds);
			    sub->AddOption<BoolOption<bool>>("Repair Nearby Vehicles", nullptr, &Juice::repairnearbyvehicless, BoolDisplay::OnOff, false, Juice::repairnearbyvehicles);
				sub->AddOption<BoolOption<bool>>("Clear Area", nullptr, &Juice::clearareabool, BoolDisplay::OnOff, false, Juice::clearArea);
			}); 
		g_UiManager->AddSubmenu<RegularSubmenu>("World", wrlddd, [](RegularSubmenu* sub)
			{
		sub->AddOption<ChooseOption<const char*, std::size_t>>("Weather", nullptr, &Weathers, &Lists::DemoListPos27, false, [] { MISC::SET_OVERRIDE_WEATHER((char*)Weathers[Lists::DemoListPos27]); });
		sub->AddOption<BoolOption<bool>>("No Gravity", nullptr, &GravityBool, BoolDisplay::OnOff, false, Gravity);
		sub->AddOption<BoolOption<bool>>("Pink World", nullptr, &Juice::pip, BoolDisplay::OnOff, false, Juice::pi);
		sub->AddOption<BoolOption<bool>>("Vehicle Go Up", nullptr, &Juice::Forcefeldd, BoolDisplay::OnOff, false, Juice::forcefeldd);
		sub->AddOption<BoolOption<bool>>("Zoom Cam", nullptr, &Juice::gameCamZoom, BoolDisplay::OnOff, false, Juice::zoomCam);
			});
		g_UiManager->AddSubmenu<RegularSubmenu>("All Players", Allplayers, [](RegularSubmenu* sub)
			{
				sub->AddOption<BoolOption<bool>>("Explode  [All]", nullptr, &Juice::WaterGunn, BoolDisplay::OnOff, false, Juice::watergunn); 
				sub->AddOption<BoolOption<bool>>("Party Lobby [All]", nullptr, &Juice::ShakeLobbyy, BoolDisplay::OnOff, false, Juice::ShakeLobby);
				sub->AddOption<RegularOption>("Give Weps  [All]", "Give Weps  [All]", [] { cloneplayer(); });
				sub->AddOption<RegularOption>("Clone  [All]", "Clone  [All]", [] { cloneplayer(); });
			    sub->AddOption<RegularOption>("Kick From Vehicle [All]", "Kick From Vehicle [All]", [] { KickallfromVehicle(); });
				sub->AddOption<RegularOption>("Cage  [All]", "Cage  [All]", [] { CageAll(); });
				sub->AddOption<RegularOption>("Valkyrie Cannon  [All]", "Valkyrie Cannon [All]", [] { Features::ValkyrieCannonAllPlayer(); });
				sub->AddOption<RegularOption>("Explode  [All]", "Explode  [All]", [] { axall(); });
				sub->AddOption<RegularOption>("Take Weapons  [All]", "Take Weapons  [All]", [] { noweapon(); });
			}); 
		g_UiManager->AddSubmenu<RegularSubmenu>("Attach [All]", Attach, [](RegularSubmenu* sub)
			{
			sub->AddOption<RegularOption>("Toilet", "", [] { attachobjects222,("prop_ld_toilet_01"); });
			sub->AddOption<RegularOption>("Guitar", "", [] { attachobjects222, ("prop_acc_guitar_01_d1"); });
			sub->AddOption<RegularOption>("Dildo", "", [] { attachobjects222, ("prop_cs_dildo_01"); });
			sub->AddOption<RegularOption>("Ufo", "", [] { attachobjects222, ("p_spinning_anus_s"); });
			sub->AddOption<RegularOption>("Egg Clock", "", [] { attachobjects222, ("prop_egg_clock_01"); });
			sub->AddOption<RegularOption>("Orange Ball", "", [] { attachobjects222, ("prop_juicestand"); });
			sub->AddOption<RegularOption>("Ferris Wheel", "", [] { attachobjects222, ("prop_Ld_ferris_wheel"); });
			sub->AddOption<RegularOption>("Stunt Ramp BIG", "", [] { attachobjects222, ("stt_prop_ramp_multi_loop_rb"); });
			sub->AddOption<RegularOption>("Christmas Tree", "", [] { attachobjects222, ("prop_xmas_tree_int"); });
			sub->AddOption<RegularOption>("Boxing Glove", "", [] { attachobjects222, ("prop_boxing_glove_01"); });
			sub->AddOption<RegularOption>("EMP", "", [] { attachobjects222, ("hei_prop_heist_emp"); });
			sub->AddOption<RegularOption>("Cash Pile", "", [] { attachobjects222, ("prop_anim_cash_pile_02"); });
			sub->AddOption<RegularOption>("Cargo", "", [] { attachobjects222, ("prop_air_cargo_01a"); });
			sub->AddOption<RegularOption>("Stunt Ramp BIG", "", [] { attachobjects222, ("stt_prop_ramp_multi_loop_rb"); });
			sub->AddOption<RegularOption>("Radar", "", [] { attachobjects222, ("prop_air_bigradar"); });
			});
		g_UiManager->AddSubmenu<RegularSubmenu>("Trolling", gerneral, [](RegularSubmenu* sub)
			{
				Ped SelectedCoords = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
				NativeVector3 SelectCoords = ENTITY::GET_ENTITY_COORDS(SelectedCoords, true);
				GRAPHICS::DRAW_MARKER(3, SelectCoords.x, SelectCoords.y, SelectCoords.z + 1.25, 0, 0, 0, 0, 180, 0, 0.25, 0.25, 0.25, 200, 94, 100, 255, 1, 1, 1, 0, 0, 0, 0);
				sub->AddOption<BoolOption<bool>>("Freeze", nullptr, &Juice::Freezee, BoolDisplay::OnOff, false, Juice::Freeze);
				sub->AddOption<BoolOption<bool>>("Water Loop", nullptr, &Juice::Water, BoolDisplay::OnOff, false, Juice::WaterLoop);
				sub->AddOption<BoolOption<bool>>("Fire Loop", nullptr, &Juice::Fire, BoolDisplay::OnOff, false, Juice::FireLoop);
				sub->AddOption<BoolOption<bool>>("Fuck Cam", nullptr, &Features::camshaker, BoolDisplay::OnOff, false, Features::shakecam);
				sub->AddOption<BoolOption<bool>>("Fuck Handling", nullptr, &Juice::FuckCamBool, BoolDisplay::OnOff, false, Juice::FuckTheirCam);
				sub->AddOption<RegularOption>("Remove Weapons", "", [] { WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), true); });
				sub->AddOption<RegularOption>("Clone Player", "Clone Player", [] { Juice::PES(); });
				sub->AddOption<RegularOption>("Cage Player", "Cage Player", [] { trapcageee(g_SelectedPlayer); }); 
				sub->AddOption<RegularOption>("Bock Player", "Bock Player", [] { trapcageeeee(g_SelectedPlayer); });
				sub->AddOption<RegularOption>("Big Explode", "Big Explode", [] { Features::ExplodeVehicle(g_SelectedPlayer); });
				sub->AddOption<RegularOption>("Explode Player", "Explode Player", [] {Features::ExplodeLoopPlayer(g_SelectedPlayer); });
			});
				g_UiManager->AddSubmenu<RegularSubmenu>("General", Trolling, [](RegularSubmenu* sub)
					{
				Ped SelectedCoords = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer); 
				NativeVector3 SelectCoords = ENTITY::GET_ENTITY_COORDS(SelectedCoords, true); 
				GRAPHICS::DRAW_MARKER(3, SelectCoords.x, SelectCoords.y, SelectCoords.z + 1.25, 0, 0, 0, 0, 180, 0, 0.25, 0.25, 0.25, 200, 94, 100, 255, 1, 1, 1, 0, 0, 0, 0); 
				sub->AddOption<RegularOption>("Give All Weapons", "", [] { for (int i = 0; i < (sizeof(Weaponss) / 4); i++) { WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), Weaponss[i], 9999, 1); }});
				sub->AddOption<RegularOption>("Give All MK2 Weapons", "", [] { for (int i = 0; i < (sizeof(MK2Weapons) / 4); i++) { WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer), MK2Weapons[i], 9999, 1); }});
				sub->AddOption<RegularOption>("Astro Player", "Astro Player", [] { trapcageeee(g_SelectedPlayer); });
				sub->AddOption<RegularOption>("Join Crew", "Join Crew", [] { JoinCrew(g_SelectedPlayer); });
			}); 
				
		g_UiManager->AddSubmenu<RegularSubmenu>("Drop", Friendly, [](RegularSubmenu* sub) 
			{
			Ped SelectedCoords = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
			NativeVector3 SelectCoords = ENTITY::GET_ENTITY_COORDS(SelectedCoords, true);
			GRAPHICS::DRAW_MARKER(3, SelectCoords.x, SelectCoords.y, SelectCoords.z + 1.25, 0, 0, 0, 0, 180, 0, 0.25, 0.25, 0.25, 200, 94, 100, 255, 1, 1, 1, 0, 0, 0, 0); 
			});
		
		g_UiManager->AddSubmenu<RegularSubmenu>("Vehicle Spawner", VEHICLESPAWN, [](RegularSubmenu* sub)
			{
			
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Super", nullptr, &Super1, &Lists::DemoListPos1, false, [] { Juice::SpawnVehicle((char*)Super1[Lists::DemoListPos1]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Sports", nullptr, &Sports1, &Lists::DemoListPos2, false, [] { Juice::SpawnVehicle((char*)Sports1[Lists::DemoListPos2]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Sport Classic", nullptr, &SportsClassics1, &Lists::DemoListPos3, false, [] { Juice::SpawnVehicle((char*)SportsClassics1[Lists::DemoListPos3]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Offroad", nullptr, &OffRoad1, &Lists::DemoListPos4, false, [] { Juice::SpawnVehicle((char*)OffRoad1[Lists::DemoListPos4]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Sedans", nullptr, &Sedans1, &Lists::DemoListPos5, false, [] { Juice::SpawnVehicle((char*)Sedans1[Lists::DemoListPos5]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Coupes", nullptr, &Coupes1, &Lists::DemoListPos6, false, [] { Juice::SpawnVehicle((char*)Coupes1[Lists::DemoListPos6]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Muscle", nullptr, &Muscle1, &Lists::DemoListPos7, false, [] { Juice::SpawnVehicle((char*)Muscle1[Lists::DemoListPos7]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Boats", nullptr, &Boats1, &Lists::DemoListPos8, false, [] { Juice::SpawnVehicle((char*)Boats1[Lists::DemoListPos8]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Commercial", nullptr, &Commercial1, &Lists::DemoListPos9, false, [] { Juice::SpawnVehicle((char*)Commercial1[Lists::DemoListPos9]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Compacts", nullptr, &Compacts1, &Lists::DemoListPos10, false, [] { Juice::SpawnVehicle((char*)Compacts1[Lists::DemoListPos10]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Cycles", nullptr, &Cycles1, &Lists::DemoListPos11, false, [] { Juice::SpawnVehicle((char*)Cycles1[Lists::DemoListPos11]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Emergency", nullptr, &Emergency1, &Lists::DemoListPos12, false, [] { Juice::SpawnVehicle((char*)Emergency1[Lists::DemoListPos12]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Helicopters", nullptr, &Helicopters1, &Lists::DemoListPos14, false, [] { Juice::SpawnVehicle((char*)Helicopters1[Lists::DemoListPos14]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Industrial", nullptr, &Industrial1, &Lists::DemoListPos15, false, [] { Juice::SpawnVehicle((char*)Industrial1[Lists::DemoListPos15]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Military", nullptr, &Military1, &Lists::DemoListPos16, false, [] { Juice::SpawnVehicle((char*)Military1[Lists::DemoListPos16]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Motorcycles", nullptr, &Motorcycles1, &Lists::DemoListPos17, false, [] { Juice::SpawnVehicle((char*)Motorcycles1[Lists::DemoListPos17]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Planes", nullptr, &Planes1, &Lists::DemoListPos18, false, [] { Juice::SpawnVehicle((char*)Planes1[Lists::DemoListPos18]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Service", nullptr, &Service1, &Lists::DemoListPos19, false, [] { Juice::SpawnVehicle((char*)Service1[Lists::DemoListPos19]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("SUV", nullptr, &SUVs1, &Lists::DemoListPos20, false, [] { Juice::SpawnVehicle((char*)SUVs1[Lists::DemoListPos20]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Trailer", nullptr, &Trailer1, &Lists::DemoListPos21, false, [] { Juice::SpawnVehicle((char*)Trailer1[Lists::DemoListPos21]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Trains", nullptr, &Trains1, &Lists::DemoListPos22, false, [] { Juice::SpawnVehicle((char*)Trains1[Lists::DemoListPos22]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Utility", nullptr, &Utility1, &Lists::DemoListPos23, false, [] { Juice::SpawnVehicle((char*)Utility1[Lists::DemoListPos23]);	});
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Vans", nullptr, &Vans1, &Lists::DemoListPos24, false, [] { Juice::SpawnVehicle((char*)Vans1[Lists::DemoListPos24]);	});
			});
				g_UiManager->AddSubmenu<RegularSubmenu>("Vehicle", car, [](RegularSubmenu* sub)
				{
			   Vehicle vehicle; vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			   VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(vehicle, Lists::DemoListPos26);
			   sub->AddOption<SubOption>("Vehicle Mods", nullptr, VEHICLEspawn);
			   sub->AddOption<SubOption>("Vehicle Spawner", nullptr, VEHICLESPAWN);
			   sub->AddOption<SubOption>("Vehicle Teleports", nullptr, Tp);
			   Ped ped = PLAYER::PLAYER_PED_ID();
			   rRequestControlOfEnt(ped);
			   bool inVehicle = PED::IS_PED_IN_ANY_VEHICLE(ped, 0);
			   std::ostringstream VehicleModel; VehicleModel;
			   if (inVehicle) {
			sub->AddOption<SubOption>("Juice Customs", nullptr, MOBILELSC);
			sub->AddOption<SubOption>("Vehicle Flips", nullptr, flip);
			   }
				});
				g_UiManager->AddSubmenu<RegularSubmenu>("Vehicle", VEHICLEspawn, [](RegularSubmenu* sub)
				{
				static int EntityAlpha = { 0 };
				Vehicle vehicle; vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false); 
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(vehicle, Lists::DemoListPos26);
				sub->AddOption<BoolOption<bool>>("Fly Mode", nullptr, &Juice::fcbool, BoolDisplay::OnOff, false, Juice::FlyingCarLoop);
				sub->AddOption<BoolOption<bool>>("Horn Boost", nullptr, &Juice::hornboostt, BoolDisplay::OnOff, false, Juice::Hornboostt);
				sub->AddOption<BoolOption<bool>>("Auto Fix", nullptr, &Juice::fixlooping, BoolDisplay::OnOff, false, Juice::fixloopin);
				sub->AddOption<ChooseOption<const char*, std::size_t>>("Plate", nullptr, &PlateRegions, &Lists::DemoListPos26, false);
				sub->AddOption<BoolOption<bool>>("Matrix Plate", nullptr, &Juice::MatrixPlates, BoolDisplay::OnOff, false, Juice::MatrixPlate);
				sub->AddOption<RegularOption>("Chrome Paint", "Chrome Paint", [] { crome(); }); 
				sub->AddOption<RegularOption>("Max Vehicle", "Max Car", [] { maxvehicle(); });
				sub->AddOption<RegularOption>("Add Ramp", "", [] { AddRamp(); }); 
				sub->AddOption<NumberOption<std::int32_t>>("Vehicle Alpha", nullptr, &EntityAlpha, 0, 255, 1, 3, true, "", "", [] {
					ENTITY::SET_ENTITY_ALPHA(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), EntityAlpha, true);
					if (IsKeyPressed(VK_NUMPAD5))
					{


						EntityAlpha = getInputs();
						if (EntityAlpha > 255)
							EntityAlpha = 255;
						if (EntityAlpha < 0)
							EntityAlpha = 0;
						ENTITY::SET_ENTITY_ALPHA(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), EntityAlpha, true);
					}

					});
				sub->AddOption<BoolOption<bool>>("Rainbow Neon", nullptr, &Features::Rneon, BoolDisplay::OnOff, false, Features::RainbowNeon);
				sub->AddOption<BoolOption<bool>>("Clean Rainbow Paint", nullptr, &Juice::rainbowbool, BoolDisplay::OnOff, false, Juice::rainbow);
				sub->AddOption<BoolOption<bool>>("Rainbow Paint", nullptr, &Juice::RainbowPaintLoop, BoolDisplay::OnOff, false, Juice::HasPaintLoop);
			    sub->AddOption<BoolOption<bool>>("Vehicle God Mode", nullptr, &cargodmodebool, BoolDisplay::OnOff, false, cargodmode); 
				sub->AddOption<BoolOption<bool>>("Juice Plate", nullptr, &Juice::testbool, BoolDisplay::OnOff, false, Juice::test);
				sub->AddOption<RegularOption>("Fix Car", "", [] { fixcar1(); });
				sub->AddOption<RegularOption>("Random Print", "", [] { print(); });
				sub->AddOption<RegularOption>("Breake", "", [] { stoppi(); });
				sub->AddOption<NumberOption<std::int32_t>>("Boost Level", nullptr, &Juice::boostlevel, 0, 1000, 10, 3, true, "", "", [] {
				if (IsKeyPressed(VK_NUMPAD5))
				{
					

					Juice::boostlevel = getInputs();
						if (Juice::boostlevel > 1000)
							Juice::boostlevel = 1000;
						if (Juice::boostlevel < 0)
							Juice::boostlevel = 0;
						
				}

				});
				sub->AddOption<RegularOption>("Log Car  [Juice]", "Log Car  [Juice]", [] { Juice::loggi(); });
				sub->AddOption<BoolOption<bool>>("Ghost Car", nullptr, &InvisibleCarBool, BoolDisplay::OnOff, false, InvisibleCar);
				sub->AddOption<BoolOption<bool>>("Play Radio", nullptr, &mobileRadio, BoolDisplay::OnOff, false, mobiletunes); 
				sub->AddOption<BoolOption<bool>>("Sticky", nullptr, &Juice::StickyBool, BoolDisplay::OnOff, false, Juice::Sticky);
				sub->AddOption<BoolOption<bool>>("Drift Mode", nullptr, &Juice::Drift, BoolDisplay::OnOff, false, Juice::DriftMode);
				sub->AddOption<RegularOption>("Delete Vehicle", "", [] { DeleteVeh(); });
				sub->AddOption<RegularOption>("Open Doors", "", [] { OpenDoors(); });
				sub->AddOption<RegularOption>("Close Doors", "", [] { open(); });
				sub->AddOption<BoolOption<bool>>("Vehicle Alarm", nullptr, &Juice::ALARM, BoolDisplay::OnOff, false, Juice::alarm);
				});
			
				g_UiManager->AddSubmenu<RegularSubmenu>("Juice Customs", MOBILELSC, [](RegularSubmenu* sub)
	            {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
				VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
				sub->AddOption<NumberOption<std::int32_t>>("Spoiler", nullptr, &Spoiler, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_SPOILER), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_SPOILER, Spoiler, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Front Bumper", nullptr, &FBumper, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_FRONTBUMPER), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_FRONTBUMPER, FBumper, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Rear Bumper", nullptr, &RBumper, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_REARBUMPER), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_REARBUMPER, RBumper, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Side Skirt", nullptr, &SSkirt, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_SIDESKIRT), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_SIDESKIRT, SSkirt, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Exhaust", nullptr, &Exhaust, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_EXHAUST), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_EXHAUST, Exhaust, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Grille", nullptr, &Grille, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_GRILLE), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_GRILLE, Grille, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Chassis", nullptr, &Chasis, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_CHASSIS), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_CHASSIS, Chasis, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Hood", nullptr, &Hood, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_HOOD), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_HOOD, Hood, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Fender", nullptr, &Fender, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_FENDER), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_FENDER, Fender, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Right Fender", nullptr, &RFender, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_RIGHTFENDER), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_RIGHTFENDER, RFender, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Roof", nullptr, &Roof, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_ROOF), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_ROOF, Roof, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Engine", nullptr, &Engine, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_ENGINE), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_ENGINE, Engine, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Brakes", nullptr, &Brakes, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_BRAKES), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_BRAKES, Brakes, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Transmission", nullptr, &Transmission, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_TRANSMISSION), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_TRANSMISSION, Transmission, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Horns", nullptr, &Horns, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_HORNS), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_HORNS, Horns, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Suspension", nullptr, &Suspension, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_SUSPENSION), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_SUSPENSION, Suspension, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Armor", nullptr, &Armor, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_ARMOR), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_ARMOR, Armor, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Turbo", nullptr, &Turbo, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_TURBO), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_TURBO, Turbo, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Tire Smoke", nullptr, &TSmoke, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_TIRESMOKE), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_TIRESMOKE, TSmoke, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Xenon", nullptr, &Xenon, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_XENONLIGHTS), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_XENONLIGHTS, Xenon, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Wheels", nullptr, &Wheels, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_FRONTWHEELS), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_FRONTWHEELS, Wheels, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Windows", nullptr, &Windows, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_WINDOWS), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_WINDOWS, Windows, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Plate Holder", nullptr, &Plateholder, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_PLATEHOLDER), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_PLATEHOLDER, Plateholder, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Vanity Plates", nullptr, &Vanity, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_VANITY_PLATES), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_VANITY_PLATES, Vanity, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Trim", nullptr, &Trims, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_TRIM), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_TRIM, Trims, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Ornaments", nullptr, &Ornaments, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_ORNAMENTS), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_ORNAMENTS, Ornaments, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Dashboard", nullptr, &Dashboard, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_DASHBOARD), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_DASHBOARD, Dashboard, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Dial", nullptr, &Dial, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_DIAL), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_DIAL, Dial, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Door Speaker", nullptr, &DoorSpeaker, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_DOOR_SPEAKER), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_DOOR_SPEAKER, DoorSpeaker, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Seats", nullptr, &Seats, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_SEATS), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_SEATS, Seats, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Steering Wheel", nullptr, &SteeringWheel, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_STEERINGWHEEL), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_STEERINGWHEEL, SteeringWheel, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Shifting Levers", nullptr, &Shifter, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_SHIFTER_LEAVERS), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_SHIFTER_LEAVERS, Shifter, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Plaques", nullptr, &Plaques, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_PLAQUES), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_PLAQUES, Plaques, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Speakers", nullptr, &Speakers, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_SPEAKERS), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_SPEAKERS, Speakers, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Trunk", nullptr, &Trunk, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_TRUNK), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_TRUNK, Trunk, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Hydraulics", nullptr, &Hydraulics, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_HYDRULICS), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_HYDRULICS, Hydraulics, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Engine Block", nullptr, &EngineBlock, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_ENGINE_BLOCK), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_ENGINE_BLOCK, EngineBlock, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Air Filter", nullptr, &Filter, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_AIR_FILTER), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_AIR_FILTER, Filter, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Struts", nullptr, &Struts, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_STRUTS), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_STRUTS, Struts, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Arch Cover", nullptr, &Arch, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_ARCH_COVER), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_ARCH_COVER, Arch, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Aerials", nullptr, &Aerials, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_AERIALS), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_AERIALS, Aerials, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Trim 2", nullptr, &TrimTwo, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_TRIM_2), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_TRIM_2, TrimTwo, false); });
				sub->AddOption<NumberOption<std::int32_t>>("Tank", nullptr, &Tank, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_TANK), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_TANK, Tank, false); });
			    sub->AddOption<NumberOption<std::int32_t>>("Livery", nullptr, &Livery, 0, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_LIVERY), 1, 3, true, "", "", [veh] { VEHICLE::SET_VEHICLE_MOD(veh, MOD_LIVERY, Livery, false); });
				int32_t Spoiler, FBumper, RBumper, SSkirt, Exhaust, Grille, Chasis, Hood, Fender, RFender, Roof, Engine, Brakes, Transmission, Horns, Suspension, Armor, Turbo, TSmoke, Xenon, Wheels, Windows, Plateholder, Vanity, Trims, Ornaments, Dashboard, Dial, DoorSpeaker, Seats, SteeringWheel, Shifter, Plaques, Speakers, Trunk, Hydraulics, EngineBlock, Filter, Struts, Arch, Aerials, TrimTwo, Tank, Livery = 1;
				
				
			});
				g_UiManager->AddSubmenu<RegularSubmenu>("Vehicle Teleports", Tp, [](RegularSubmenu* sub)
					{
				sub->AddOption<RegularOption>("Teleport Personal Vehicle To Me", "", [] { TeleportPersonalVehicletome(); });
				sub->AddOption<RegularOption>("Maze Bank", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -74.94243f; Coords.y = -818.63446f; Coords.z = 326.174347f; TPto(Coords); });
				sub->AddOption<RegularOption>("Military Base", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -2012.8470f; Coords.y = 2956.5270f; Coords.z = 32.8101f; TPto(Coords); });
				sub->AddOption<RegularOption>("Zancudo Tower", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -2356.0940; Coords.y = 3248.645; Coords.z = 101.4505; TPto(Coords); });
				sub->AddOption<RegularOption>("Mask Shop", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -1338.16; Coords.y = -1278.11; Coords.z = 4.87; TPto(Coords); });
				sub->AddOption<RegularOption>("LS Customs", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -373.01; Coords.y = -124.91; Coords.z = 38.31; TPto(Coords); });
				sub->AddOption<RegularOption>("Ammunation", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 247.3652; Coords.y = -45.8777; Coords.z = 69.9411; TPto(Coords); });
				sub->AddOption<RegularOption>("Airport", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -1102.2910f; Coords.y = -2894.5160f; Coords.z = 13.9467f; TPto(Coords); });
				sub->AddOption<RegularOption>("Clothes Store", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -718.91; Coords.y = -158.16; Coords.z = 37.00; TPto(Coords); });
				sub->AddOption<RegularOption>("Waterfall", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -597.9525f; Coords.y = 4475.2910f; Coords.z = 25.6890f; TPto(Coords); });
				sub->AddOption<RegularOption>("FIB", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 135.5220f; Coords.y = -749.0003f; Coords.z = 260.0000f; TPto(Coords); });
				sub->AddOption<RegularOption>("Humane Labs", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 3617.231f; Coords.y = 3739.871f; Coords.z = 28.6901f; TPto(Coords); });
				sub->AddOption<RegularOption>("MMI", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = -222.1977; Coords.y = -1185.8500; Coords.z = 23.0294; TPto(Coords); });
				sub->AddOption<RegularOption>("Sandy Shores Airfield", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 1741.4960f; Coords.y = 3269.2570f; Coords.z = 41.6014f; TPto(Coords); });
				sub->AddOption<RegularOption>("Strip Club", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 126.135f; Coords.y = -1278.583f; Coords.z = 29.270f; TPto(Coords); });
				sub->AddOption<RegularOption>("Police Station", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 436.491f; Coords.y = -982.172f; Coords.z = 30.699f; TPto(Coords); });
				sub->AddOption<RegularOption>("Burnt FIB", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 160.868f; Coords.y = -745.831f; Coords.z = 250.063f; TPto(Coords); });
				sub->AddOption<RegularOption>("Pacific Standard Vault", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 255.851f; Coords.y = 217.030f; Coords.z = 101.683f; TPto(Coords); });
				sub->AddOption<RegularOption>("Lester's House", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 1273.898f; Coords.y = -1719.304f; Coords.z = 54.771f; TPto(Coords); });
				sub->AddOption<RegularOption>("IAA Office", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 117.220f; Coords.y = -620.938f; Coords.z = 206.047f; TPto(Coords); });
				sub->AddOption<RegularOption>("Torture Room", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 147.170f; Coords.y = -2201.804f; Coords.z = 4.688f; TPto(Coords); });
				sub->AddOption<RegularOption>("Hippy Camp", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 2476.712f; Coords.y = 3789.645f; Coords.z = 41.226f; TPto(Coords); });
				sub->AddOption<RegularOption>("Weed Farm", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 2208.777f; Coords.y = 5578.235f; Coords.z = 53.735f; TPto(Coords); });
				sub->AddOption<RegularOption>("Casino", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 925.329f; Coords.y = 46.152f; Coords.z = 80.908f; TPto(Coords); });
				sub->AddOption<RegularOption>("Prison", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 1679.049f; Coords.y = 2513.711f; Coords.z = 45.565f; TPto(Coords); });
				sub->AddOption<RegularOption>("Mount Chiliad", "", [] {STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
				GRAPHICS::USE_PARTICLE_FX_ASSET("scr_rcbarry2");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false); Vector3 Coords; Coords.x = 496.75f; Coords.y = 5591.17f; Coords.z = 795.03f; TPto(Coords); });
					});
		g_UiManager->AddSubmenu<RegularSubmenu>("Flips", flip, [](RegularSubmenu* sub)
			{
				sub->AddOption<RegularOption>("Front Flip", "Only Use In Car", [] { Front(); });
				sub->AddOption<RegularOption>("Back Flip", "Only Use In Car", [] { back(); });
				sub->AddOption<RegularOption>("Kick Flip", "Only Use In Car", [] { kickflip(); });
				sub->AddOption<RegularOption>("Heel Flip", "Only Use In Car", [] { HeelFlip(); });
				sub->AddOption<RegularOption>("Jump Up", "Only Use In Car", [] { sky(); });
				sub->AddOption<RegularOption>("Go Down", "Only Use In Car", [] { CrushVehicle(); });
				sub->AddOption<RegularOption>("Go To Sky", "Only Use In Car", [] { high(); });
				sub->AddOption<RegularOption>("Bunney Hop", "Only Use In Car", [] { BunneyHop(); });
			});
		g_UiManager->AddSubmenu<RegularSubmenu>("Infos", Infos, [](RegularSubmenu* sub)
			{
				sub->AddOption<RegularOption>("Join My Discord", "Join My Discord", [] { dc(); });
				sub->AddOption<RegularOption>("Since 2021", "08.03.2021", [] {});
				sub->AddOption<RegularOption>("Gta Version 1.54", "", [] {});
				sub->AddOption<RegularOption>("Fly [DEV]", "", [] {});
			});
				
		g_UiManager->AddSubmenu<RegularSubmenu>("Settings", SubmenuSettings, [](RegularSubmenu* sub)
			{
				sub->AddOption<SubOption>("Infos", nullptr, Infos);
				sub->AddOption<SubOption>("UI Settings", nullptr, Ui); 
				sub->AddOption<SubOption>("Displays ", nullptr, Displays);
				sub->AddOption<BoolOption<bool>>("Juice.Vip", nullptr, &Juice::Gayforcebool, BoolDisplay::OnOff, false, Juice::Gayforce);
				sub->AddOption<RegularOption>("u Crash?", "~b~U Crash?", [] { exit(0); });
				sub->AddOption<RegularOption>("Unload", "Unload Juice", []
					{
						g_Running = false;
					});
			});
		g_UiManager->AddSubmenu<RegularSubmenu>("Displays", Displays, [](RegularSubmenu* sub)
			{
				sub->AddOption<BoolOption<bool>>("No Map", nullptr, &Mapweck, BoolDisplay::OnOff, false, mapweck);
				sub->AddOption<BoolOption<bool>>("Juice Logo", nullptr, &Juice::Display, BoolDisplay::OnOff, false, Juice::Displays);
				sub->AddOption<BoolOption<bool>>("Fps", nullptr, &Juice::DisplayFPS, BoolDisplay::OnOff, false, Juice::featureDisplayFPS);
				sub->AddOption<BoolOption<bool>>("Status", nullptr, &Juice::dDisplays, BoolDisplay::OnOff, false, Juice::dDisplayss);
			});
		g_UiManager->AddSubmenu<RegularSubmenu>("Ui", Ui, [](RegularSubmenu* sub)
			{
				sub->AddOption<SubOption>("Header", nullptr, SubmenuSettingsHeader);
				sub->AddOption<SubOption>("Infobar", nullptr, SubmenuSettingsSubmenuBar);
				sub->AddOption<SubOption>("Options", nullptr, SubmenuSettingsOption);
				sub->AddOption<SubOption>("Footer", nullptr, SubmenuSettingsFooter);
				sub->AddOption<SubOption>("Description", nullptr, SubmenuSettingsDescription);
				sub->AddOption<SubOption>("Input", nullptr, SubmenuSettingsInput);
				sub->AddOption<NumberOption<float>>("X Position", nullptr, &g_UiManager->m_PosX, 0.f, 1.f, 0.01f, 2);
				sub->AddOption<NumberOption<float>>("Y Position", nullptr, &g_UiManager->m_PosY, 0.f, 1.f, 0.01f, 2);
		   });
		g_UiManager->AddSubmenu<RegularSubmenu>("View reports", VIEW_REPORTS, [](RegularSubmenu* sub)//
			{
				int reportkek2;
				STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_REPORT_STRENGTH"), &reportkek2, -1);
				const auto& reportstringkek2 = "Report Strenght: ~w~"s + std::to_string(reportkek2);
				sub->AddOption<RegularOption>(reportstringkek2.c_str(), "", [] {});

				int reportkek;
				STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), &reportkek, -1);
				const auto& reportstringkek = "Gameplay Exploits: ~w~"s + std::to_string(reportkek);
				sub->AddOption<RegularOption>(reportstringkek.c_str(), "", [] {});

				int reportkek4;
				STATS::STAT_GET_INT(MISC::GET_HASH_KEY("BADSPORT_NUMDAYS_1ST_OFFENCE"), &reportkek4, -1);
				const auto& reportstringkek4 = "Badsport: ~w~"s + std::to_string(reportkek4);
				sub->AddOption<RegularOption>(reportstringkek4.c_str(), "", [] {});

				int reportkek7;
				STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_GRIEFING"), &reportkek7, -1);
				const auto& reportstringkek7 = "Griefing: ~w~"s + std::to_string(reportkek7);
				sub->AddOption<RegularOption>(reportstringkek7.c_str(), "", [] {});

				int reportkek3;
				STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_COMMEND_STRENGTH"), &reportkek3, -1);
				const auto& reportstringkek3 = "Commend Strenght: ~w~"s + std::to_string(reportkek3);
				sub->AddOption<RegularOption>(reportstringkek3.c_str(), "", [] {});

				int reportkek5;
				STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_FRIENDLY"), &reportkek5, -1);
				const auto& reportstringkek5 = "Friendly Stuff: ~w~"s + std::to_string(reportkek5);
				sub->AddOption<RegularOption>(reportstringkek5.c_str(), "", [] {});

				int reportkek6;
				STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_HELPFUL"), &reportkek6, -1);
				const auto& reportstringkek6 = "Helpful Stuff: ~w~"s + std::to_string(reportkek6);
				sub->AddOption<RegularOption>(reportstringkek6.c_str(), "", [] {});


			});
		g_UiManager->AddSubmenu<RegularSubmenu>("Infobar", SubmenuSettingsSubmenuBar, [](RegularSubmenu* sub)
			{
				sub->AddOption<NumberOption<float>>("Height", nullptr, &g_UiManager->m_SubmenuBarHeight, 0.01f, 0.1f, 0.001f, 3);
				sub->AddOption<NumberOption<float>>("Text Size", nullptr, &g_UiManager->m_SubmenuBarTextSize, 0.01f, 1.f, 0.01f, 2);

				sub->AddOption<NumberOption<std::uint8_t>>("Background R", nullptr, &g_UiManager->m_SubmenuBarBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Background G", nullptr, &g_UiManager->m_SubmenuBarBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Background B", nullptr, &g_UiManager->m_SubmenuBarBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Background A", nullptr, &g_UiManager->m_SubmenuBarBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Text R", nullptr, &g_UiManager->m_SubmenuBarTextColor.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Text G", nullptr, &g_UiManager->m_SubmenuBarTextColor.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Text B", nullptr, &g_UiManager->m_SubmenuBarTextColor.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Text A", nullptr, &g_UiManager->m_SubmenuBarTextColor.a, '\0', static_cast<std::uint8_t>(255));
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Options", SubmenuSettingsOption, [](RegularSubmenu* sub)
			{
				sub->AddOption<NumberOption<float>>("Height", nullptr, &g_UiManager->m_OptionHeight, 0.01f, 0.1f, 0.001f, 3);
				sub->AddOption<NumberOption<float>>("Text Size", nullptr, &g_UiManager->m_OptionTextSize, 0.01f, 1.f, 0.01f, 2);

				sub->AddOption<NumberOption<std::uint8_t>>("Selected Background R", nullptr, &g_UiManager->m_OptionSelectedBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Selected Background G", nullptr, &g_UiManager->m_OptionSelectedBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Selected Background B", nullptr, &g_UiManager->m_OptionSelectedBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Selected Background A", nullptr, &g_UiManager->m_OptionSelectedBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Unselected Background R", nullptr, &g_UiManager->m_OptionUnselectedBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Unselected Background G", nullptr, &g_UiManager->m_OptionUnselectedBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Unselected Background B", nullptr, &g_UiManager->m_OptionUnselectedBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Unselected Background A", nullptr, &g_UiManager->m_OptionUnselectedBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));

				sub->AddOption<NumberOption<std::uint8_t>>("Selected Text R", nullptr, &g_UiManager->m_OptionSelectedTextColor.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Selected Text G", nullptr, &g_UiManager->m_OptionSelectedTextColor.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Selected Text B", nullptr, &g_UiManager->m_OptionSelectedTextColor.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Selected Text A", nullptr, &g_UiManager->m_OptionSelectedTextColor.a, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Unselected Text R", nullptr, &g_UiManager->m_OptionUnselectedTextColor.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Unselected Text G", nullptr, &g_UiManager->m_OptionUnselectedTextColor.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Unselected Text B", nullptr, &g_UiManager->m_OptionUnselectedTextColor.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Unselected Text A", nullptr, &g_UiManager->m_OptionUnselectedTextColor.a, '\0', static_cast<std::uint8_t>(255));
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Footer", SubmenuSettingsFooter, [](RegularSubmenu* sub)
			{
				sub->AddOption<NumberOption<float>>("Height", nullptr, &g_UiManager->m_FooterHeight, 0.01f, 0.1f, 0.001f, 3);
				sub->AddOption<NumberOption<float>>("Sprite Size", nullptr, &g_UiManager->m_FooterSpriteSize, 0.01f, 1.f, 0.001f, 3);

				sub->AddOption<NumberOption<std::uint8_t>>("Background R", nullptr, &g_UiManager->m_FooterBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Background G", nullptr, &g_UiManager->m_FooterBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Background B", nullptr, &g_UiManager->m_FooterBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Background A", nullptr, &g_UiManager->m_FooterBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Sprite R", nullptr, &g_UiManager->m_FooterSpriteColor.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Sprite G", nullptr, &g_UiManager->m_FooterSpriteColor.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Sprite B", nullptr, &g_UiManager->m_FooterSpriteColor.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Sprite A", nullptr, &g_UiManager->m_FooterSpriteColor.a, '\0', static_cast<std::uint8_t>(255));
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Header", SubmenuSettingsHeader, [](RegularSubmenu* sub)
			{



				sub->AddOption<ChooseOption<const char*, std::size_t>>("Type", nullptr, &Lists::HeaderTypesFrontend, &Lists::HeaderTypesPosition, true, []
					{
						g_UiManager->m_HeaderType = Lists::HeaderTypesBackend[Lists::HeaderTypesPosition];
					});

				switch (g_UiManager->m_HeaderType)
				{
				case HeaderType::Static:
					sub->AddOption<SubOption>("Background", nullptr, SubmenuSettingsHeaderStaticBackground);
					break;
				case HeaderType::Gradient:
					sub->AddOption<SubOption>("Gradient", nullptr, SubmenuSettingsHeaderGradientBackground);
					break;
				}


				sub->AddOption<SubOption>("Text", nullptr, SubmenuSettingsHeaderText);
				sub->AddOption<NumberOption<float>>("Height", nullptr, &g_UiManager->m_HeaderHeight, 0.01f, 0.2f, 0.001f, 3);
			});


		g_UiManager->AddSubmenu<RegularSubmenu>("Header Background", SubmenuSettingsHeaderStaticBackground, [](RegularSubmenu* sub)
			{
				sub->AddOption<NumberOption<std::uint8_t>>("R", nullptr, &g_UiManager->m_HeaderBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("G", nullptr, &g_UiManager->m_HeaderBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("B", nullptr, &g_UiManager->m_HeaderBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("A", nullptr, &g_UiManager->m_HeaderBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Header Gradient", SubmenuSettingsHeaderGradientBackground, [](RegularSubmenu* sub)
			{
				sub->AddOption<BoolOption<bool>>("Transparent", nullptr, &g_UiManager->m_HeaderGradientTransparent, BoolDisplay::YesNo);
				sub->AddOption<BoolOption<bool>>("Flip", nullptr, &g_UiManager->m_HeaderGradientFlip, BoolDisplay::YesNo);

				sub->AddOption<NumberOption<std::uint8_t>>("R1", nullptr, &g_UiManager->m_HeaderGradientColorLeft.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("G1", nullptr, &g_UiManager->m_HeaderGradientColorLeft.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("B1", nullptr, &g_UiManager->m_HeaderGradientColorLeft.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("A1", nullptr, &g_UiManager->m_HeaderGradientColorLeft.a, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("R2", nullptr, &g_UiManager->m_HeaderGradientColorRight.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("G2", nullptr, &g_UiManager->m_HeaderGradientColorRight.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("B2", nullptr, &g_UiManager->m_HeaderGradientColorRight.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("A2", nullptr, &g_UiManager->m_HeaderGradientColorRight.a, '\0', static_cast<std::uint8_t>(255));
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Header Text", SubmenuSettingsHeaderText, [](RegularSubmenu* sub)
			{

				sub->AddOption<NumberOption<float>>("Size", nullptr, &g_UiManager->m_HeaderTextSize, 0.1f, 2.f, 0.01f, 2);
				sub->AddOption<NumberOption<std::uint8_t>>("R", nullptr, &g_UiManager->m_HeaderTextColor.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("G", nullptr, &g_UiManager->m_HeaderTextColor.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("B", nullptr, &g_UiManager->m_HeaderTextColor.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("A", nullptr, &g_UiManager->m_HeaderTextColor.a, '\0', static_cast<std::uint8_t>(255));
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Description", SubmenuSettingsDescription, [](RegularSubmenu* sub)
			{
				sub->AddOption<NumberOption<float>>("Padding", "Padding before the description rect.", &g_UiManager->m_DescriptionHeightPadding, 0.01f, 1.f, 0.001f,
					3);
				sub->AddOption<NumberOption<float>>("Height", "Size of the description rect.", &g_UiManager->m_DescriptionHeight, 0.02f, 2.f, 0.002f, 3);
				sub->AddOption<NumberOption<float>>("Text Size", "Size of the description text.", &g_UiManager->m_DescriptionTextSize, 0.1f, 2.f, 0.01f, 2);
			});


		g_UiManager->AddSubmenu<RegularSubmenu>("Players", SubmenuPlayerList, [](RegularSubmenu* sub)
			{
				for (std::uint32_t i = 0; i < 32; ++i)
				{
					if (sub->GetSelectedOption() == sub->GetNumOptions()) {
					
					}
					if (auto ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))
					{
						sub->AddOption<SubOption>(PlayerName(i).c_str(), nullptr, SubmenuSelectedPlayer, [=]
							{
								g_SelectedPlayer = i;
							});
					}
				}
				
			});                              
		g_UiManager->AddSubmenu<RegularSubmenu>("Crash/Kick", crashkick, [](RegularSubmenu* sub)
			{
				Ped SelectedCoords = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
				NativeVector3 SelectCoords = ENTITY::GET_ENTITY_COORDS(SelectedCoords, true);
				GRAPHICS::DRAW_MARKER(3, SelectCoords.x, SelectCoords.y, SelectCoords.z + 1.25, 0, 0, 0, 0, 180, 0, 0.25, 0.25, 0.25, 200, 94, 100, 255, 1, 1, 1, 0, 0, 0, 0);

			}); 
			g_UiManager->AddSubmenu<RegularSubmenu>("Attach Objects", SELECTEDATTACH, [](RegularSubmenu* sub)
				{
					Ped SelectedCoords = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
					NativeVector3 SelectCoords = ENTITY::GET_ENTITY_COORDS(SelectedCoords, true);
					GRAPHICS::DRAW_MARKER(3, SelectCoords.x, SelectCoords.y, SelectCoords.z + 1.25, 0, 0, 0, 0, 180, 0, 0.25, 0.25, 0.25, 200, 94, 100, 255, 1, 1, 1, 0, 0, 0, 0);
					sub->AddOption<RegularOption>("Attach To Player", "Attach To Player", [] { Attachhhhhh(); });
					sub->AddOption<RegularOption>("Detach To Player", "Detach To Player", [] { Detach(); });
					sub->AddOption<RegularOption>("Detach Objects", "", [] { ClearProps(); });
				});

		g_UiManager->AddSubmenu<RegularSubmenu>("Vehicle", Vehiclee, [](RegularSubmenu* sub)
			{
			Ped SelectedCoords = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer); 
			NativeVector3 SelectCoords = ENTITY::GET_ENTITY_COORDS(SelectedCoords, true);
			GRAPHICS::DRAW_MARKER(3, SelectCoords.x, SelectCoords.y, SelectCoords.z + 1.25, 0, 0, 0, 0, 180, 0, 0.25, 0.25, 0.25, 200, 94, 100, 255, 1, 1, 1, 0, 0, 0, 0);
			sub->AddOption<BoolOption<bool>>("Ban From Vehicle", nullptr, &Juice::KickFromVehicleebool, BoolDisplay::OnOff, false, Juice::KickFromVehiclee);
			sub->AddOption<RegularOption>("Max Vehicle", "Max Vehicle", [] { maxvehiclee(); }); 
			sub->AddOption<RegularOption>("Fix Car", "Fix Car", [] { fixcar12(); });
			sub->AddOption<RegularOption>("Kick From Vehicle", "Kick From Vehicle", [] { Features::KickFromVehicle(g_SelectedPlayer); });
			sub->AddOption<RegularOption>("Pop Tires", "Pop Tires", [] { Features::PopTires(g_SelectedPlayer); });
			sub->AddOption<RegularOption>("Explode Vehicle", "Explode Vehicle", [] { Features::ExplodeVehicle(g_SelectedPlayer); });
			}); 
		g_UiManager->AddSubmenu<RegularSubmenu>("Kick/Crash", tpayertpppp, [](RegularSubmenu* sub)
			{
				Ped SelectedCoords = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
				NativeVector3 SelectCoords = ENTITY::GET_ENTITY_COORDS(SelectedCoords, true);
				GRAPHICS::DRAW_MARKER(3, SelectCoords.x, SelectCoords.y, SelectCoords.z + 1.25, 0, 0, 0, 0, 180, 0, 0.25, 0.25, 0.25, 200, 94, 100, 255, 1, 1, 1, 0, 0, 0, 0);
				sub->AddOption<RegularOption>("Teleport To Player", "Teleport To Player", [] { Features::TeleportToPlayer(g_SelectedPlayer); });
				sub->AddOption<RegularOption>("Teleport In Vehicle", "Teleport In Vehicle", [] { Features::tpcar(g_SelectedPlayer); });
				sub->AddOption<RegularOption>("Teleport In Player", "Teleport In Player", [] { Attachhhhhh(); });
				sub->AddOption<RegularOption>("Teleport Out Player", "Teleport Out Player", [] { Detach(); });
			});
		g_UiManager->AddSubmenu<PlayerSubmenu>(&g_SelectedPlayer, SubmenuSelectedPlayer, [](PlayerSubmenu* sub)
			{
				Ped SelectedCoords = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
				NativeVector3 SelectCoords = ENTITY::GET_ENTITY_COORDS(SelectedCoords, true);
				GRAPHICS::DRAW_MARKER(3, SelectCoords.x, SelectCoords.y, SelectCoords.z + 1.25, 0, 0, 0, 0, 180, 0, 0.25, 0.25, 0.25, 200, 94, 100, 255, 1, 1, 1, 0, 0, 0, 0);
				sub->AddOption<SubOption>("Trolling", nullptr, gerneral);
				sub->AddOption<SubOption>("General", nullptr, Trolling);
				//sub->AddOption<SubOption>("Drop", nullptr, Friendly);
				sub->AddOption<SubOption>("Atach", nullptr, SELECTEDATTACH);
				sub->AddOption<SubOption>("Teleport", nullptr, tpayertpppp);
				sub->AddOption<SubOption>("Vehicle", nullptr, Vehiclee); 
				sub->AddOption<SubOption>("Crash/Kick", nullptr, crashkick);
				sub->AddOption<BoolOption<bool>>("Spectate", nullptr, &Juice::SpectateList[g_SelectedPlayer], BoolDisplay::OnOff, false, [] { Juice::Spectate(Juice::SpectateList[g_SelectedPlayer]); });

			});
	}
	
	void MainScript::Destroy()
	{
		
		g_UiManager.reset();
	}

	void MainScript::Tick()
	{
		g_UiManager->OnTick();
	}
}
