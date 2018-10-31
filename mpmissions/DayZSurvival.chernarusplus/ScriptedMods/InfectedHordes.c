class InfectedHordes
{
	ref map<string, vector> m_HordePositions = new map<string, vector>;

	string m_NewHordeMsg 	  = "A New Horde of Zombies Showed up Around: ";
	string m_LastSennHordeMsg = "The Horde of Zombies Was Last Seen Around: ";

	int CURRENT_STAMP;
	int CURRENT_STAMP_MSG;
	int MESSAGE_INTERVAL     = 300000;   //in ms time between each message 300000
	int COOL_DOWN_INTERVAL   = 1800000;  //In ms the time between each event
	int UPDATE_INTERVAL      = 5000;   //In ms the time between each update ( don't change unless you know what you are doing :) )
	int INT_MAX_ZOMBIES      = 125;     //Maximum amount of zombies
	int INT_MIN_ZOMBIES      = 65;      //Minimum amount of zombies

	bool m_EventOnGoing	 = false;

	ref array<EntityAI> m_SpawnedZombies = new array<EntityAI>;

	string m_CurrentZone;
	vector m_CurrentZonePos;

	void InfectedHordes()
	{
		//All possible spawn points of hordes
		m_HordePositions.Insert( "Severograd", "8428 0 12767" ); //string Name of location, vector centre position
        m_HordePositions.Insert( "Stary", "6046 0 7733" );
        m_HordePositions.Insert( "Vybor", "3784 0 8923" );
        m_HordePositions.Insert( "NWAFS", "4540 0 9645" );
		m_HordePositions.Insert( "NWAFC", "4823 0 10457" );
		m_HordePositions.Insert( "NWAFN", "4214 0 10977" );
        m_HordePositions.Insert( "Balota Air Strip", "4467 0 2496" );
        m_HordePositions.Insert( "Cherno City Centre", "6649 0 2710" );
        m_HordePositions.Insert( "Cherno West", "6374 0 2361" );
        m_HordePositions.Insert( "Cherno East", "7331 0 2850" );
        m_HordePositions.Insert( "Elektro West", "10077 0 1988" );
        m_HordePositions.Insert( "Elektro East", "10553 0 2313" );
        m_HordePositions.Insert( "Berezino City Centre", "12319 0 9530" );
        m_HordePositions.Insert( "Berezino South", "11991 0 9116" );
        m_HordePositions.Insert( "Berezino North", "12823 0 10078" );
        m_HordePositions.Insert( "Svetlojarsk", "13900 0 13258" );	
        m_HordePositions.Insert( "Zelenogorsk South", "2572 0 5105" );
        m_HordePositions.Insert( "Zelenogorsk North", "2741 0 5416" );
		m_HordePositions.Insert( "Novaya Petrovka", "3395 0 13013" );
		
		CURRENT_STAMP = GetGame().GetTime();
		CURRENT_STAMP_MSG = GetGame().GetTime();
		m_SpawnedZombies.Clear();
		SelectZone();
		SpawnHorde();
		string message = m_NewHordeMsg + m_CurrentZone;
		GlobalNotifier("inform",message);

		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.onUpdate, UPDATE_INTERVAL, true);
	}

	vector SnapToGround(vector pos)
    {
        float pos_x = pos[0];
        float pos_z = pos[2];
        float pos_y = GetGame().SurfaceY( pos_x, pos_z );
        vector tmp_pos = Vector( pos_x, pos_y, pos_z );
        tmp_pos[1] = tmp_pos[1] + pos[1];

        return tmp_pos;
    }

	void SpawnHorde()
	{
		m_EventOnGoing = true;

		int oRandValue   = Math.RandomIntInclusive(INT_MIN_ZOMBIES,INT_MAX_ZOMBIES);

		if (oRandValue != 0)
		{
			for (int i = 0; i < oRandValue; ++i)
			{
				EntityAI AIzmb;

				int rndX = Math.RandomIntInclusive(50,350);
				int rndY = Math.RandomIntInclusive(50,350);
				int oSkin 		 = Math.RandomIntInclusive(0,5);
				
				vector pos = SnapToGround(Vector(m_CurrentZonePos[0] + rndX, m_CurrentZonePos[1], m_CurrentZonePos[2] + rndY));

				AIzmb = GetGame().CreateObject( ZombieClasses.GetRandomElement(), pos, false, true );

				if (oSkin == 5)
				{
					if (AIzmb != NULL)
					{
						AIzmb.SetObjectMaterial( 0, "DZ\\data\\data\\laser.rvmat" );
						AIzmb.SetObjectMaterial( 1, "DZ\\data\\data\\laser.rvmat" );
						AIzmb.SetObjectMaterial( 2, "DZ\\data\\data\\laser.rvmat" );
					}
				}

				ZombieBase Bszmb = ZombieBase.Cast(AIzmb);
				int dropChance = Math.RandomIntInclusive(0,1);
				if (Bszmb != NULL)
				{
					Bszmb.AttachEventHandle(PossibleLootDrops,PossibleWeaponDrops,dropChance);
				}
				m_SpawnedZombies.Insert(AIzmb);
			}
		}
	}

	void SelectZone()
	{
		int totalPossibleTowns  = m_HordePositions.Count();
		int oRandValue = Math.RandomIntInclusive(0,totalPossibleTowns);

		string TownName = m_HordePositions.GetKey(oRandValue);
		vector TownPosition = m_HordePositions.Get(TownName);
		m_CurrentZone    = TownName;
		m_CurrentZonePos = TownPosition;
	}

	void GlobalNotifier(string task, string message)
	{
		switch(task)
		{
			case "inform":
			GetGame().ChatPlayer(5,message);
			break;
		}
	}

	void CleanUp()
	{
		for (int i = 0; i < m_SpawnedZombies.Count(); ++i)
		{
			EntityAI zmb = m_SpawnedZombies.Get(i);
			GetGame().ObjectDelete(zmb);
		}
		m_SpawnedZombies.Clear();
	}

	void onUpdate()
	{
		int newStamp = GetGame().GetTime();
		string message;

		if (newStamp - CURRENT_STAMP >= COOL_DOWN_INTERVAL)
		{
			//Select new area
			if (m_EventOnGoing)
			{
				CleanUp();
				SelectZone();
				SpawnHorde();
				message = m_NewHordeMsg + m_CurrentZone;
				GlobalNotifier("inform",message);
			}
			CURRENT_STAMP = GetGame().GetTime();
		}

		if (newStamp - CURRENT_STAMP_MSG >= MESSAGE_INTERVAL)
		{
			//Do Message
			if (m_EventOnGoing)
			{
				message = m_LastSennHordeMsg + m_CurrentZone;
				GlobalNotifier("inform",message);
			}
			CURRENT_STAMP_MSG = GetGame().GetTime();
		}
	}

	ref TStringArray PossibleLootDrops = {
		"ammo_45acp", "ammo_308win", "ammo_9x19", "ammo_380", "ammo_556x45", "ammo_762x54", "ammo_762x54tracer", "ammo_762x39", "ammo_9x39", "ammo_22", "ammo_12gapellets",
		"mag_cmag_10rnd", "mag_cmag_10rnd_black", "mag_cmag_10rnd_green", "mag_cmag_20rnd", "mag_cmag_20rnd_black", "mag_cmag_20rnd_green", 
		"mag_cmag_30rnd", "mag_cmag_30rnd_black", "mag_cmag_30rnd_green", "mag_cmag_40rnd", "mag_cmag_40rnd_black", "mag_cmag_40rnd_green",
	};

	ref TStringArray PossibleWeaponDrops = {
		"AKM", "M4A1", "izh18", "mp5k", "ump45", "svd", "mosin9130","mosin9130_black",
		"mosin9130_green","mosin9130_camo",
	};


	ref TStringArray ZombieClasses = {
	"ZmbM_HermitSkinny_Base","ZmbM_HermitSkinny_Beige","ZmbM_HermitSkinny_Black","ZmbM_HermitSkinny_Green",
	"ZmbM_HermitSkinny_Red","ZmbM_FarmerFat_Base","ZmbM_FarmerFat_Beige","ZmbM_FarmerFat_Blue","ZmbM_FarmerFat_Brown",
	"ZmbM_FarmerFat_Green","ZmbF_CitizenANormal_Base","ZmbF_CitizenANormal_Beige","ZmbF_CitizenANormal_Brown",
	"ZmbF_CitizenANormal_Blue","ZmbM_CitizenASkinny_Base","ZmbM_CitizenASkinny_Blue","ZmbM_CitizenASkinny_Brown",
	"ZmbM_CitizenASkinny_Grey","ZmbM_CitizenASkinny_Red","ZmbM_CitizenBFat_Base","ZmbM_CitizenBFat_Blue","ZmbM_CitizenBFat_Red",
	"ZmbM_CitizenBFat_Green","ZmbF_CitizenBSkinny_Base","ZmbF_CitizenBSkinny","ZmbM_PrisonerSkinny_Base","ZmbM_PrisonerSkinny",
	"ZmbM_FirefighterNormal_Base","ZmbM_FirefighterNormal","ZmbM_FishermanOld_Base","ZmbM_FishermanOld_Blue","ZmbM_FishermanOld_Green",
	"ZmbM_FishermanOld_Grey","ZmbM_FishermanOld_Red","ZmbM_JournalistSkinny_Base","ZmbM_JournalistSkinny","ZmbF_JournalistNormal_Base",
	"ZmbF_JournalistNormal_Blue","ZmbF_JournalistNormal_Green","ZmbF_JournalistNormal_Red","ZmbF_JournalistNormal_White",
	"ZmbM_ParamedicNormal_Base","ZmbM_ParamedicNormal_Blue","ZmbM_ParamedicNormal_Green","ZmbM_ParamedicNormal_Red",
	"ZmbM_ParamedicNormal_Black","ZmbF_ParamedicNormal_Base","ZmbF_ParamedicNormal_Blue","ZmbF_ParamedicNormal_Green",
	"ZmbF_ParamedicNormal_Red","ZmbM_HikerSkinny_Base","ZmbM_HikerSkinny_Blue","ZmbM_HikerSkinny_Green","ZmbM_HikerSkinny_Yellow",
	"ZmbF_HikerSkinny_Base","ZmbF_HikerSkinny_Blue","ZmbF_HikerSkinny_Grey","ZmbF_HikerSkinny_Green","ZmbF_HikerSkinny_Red",
	"ZmbM_HunterOld_Base","ZmbM_HunterOld_Autumn","ZmbM_HunterOld_Spring","ZmbM_HunterOld_Summer","ZmbM_HunterOld_Winter",
	"ZmbF_SurvivorNormal_Base","ZmbF_SurvivorNormal_Blue","ZmbF_SurvivorNormal_Orange","ZmbF_SurvivorNormal_Red",
	"ZmbF_SurvivorNormal_White","ZmbM_SurvivorDean_Base","ZmbM_SurvivorDean_Black","ZmbM_SurvivorDean_Blue","ZmbM_SurvivorDean_Grey",
	"ZmbM_PolicemanFat_Base","ZmbM_PolicemanFat","ZmbF_PoliceWomanNormal_Base","ZmbF_PoliceWomanNormal","ZmbM_PolicemanSpecForce_Base",
	"ZmbM_PolicemanSpecForce","ZmbM_SoldierNormal_Base","ZmbM_SoldierNormal","ZmbM_usSoldier_normal_Base",
	"ZmbM_usSoldier_normal_Woodland","ZmbM_usSoldier_normal_Desert","ZmbM_CommercialPilotOld_Base","ZmbM_CommercialPilotOld_Blue",
	"ZmbM_CommercialPilotOld_Olive","ZmbM_CommercialPilotOld_Brown","ZmbM_CommercialPilotOld_Grey","ZmbM_PatrolNormal_Base",
	"ZmbM_PatrolNormal_PautRev","ZmbM_PatrolNormal_Autumn","ZmbM_PatrolNormal_Flat","ZmbM_PatrolNormal_Summer","ZmbM_JoggerSkinny_Base",
	"ZmbM_JoggerSkinny_Blue","ZmbM_JoggerSkinny_Green","ZmbM_JoggerSkinny_Red","ZmbF_JoggerSkinny_Base","ZmbF_JoggerSkinny_Blue",
	"ZmbF_JoggerSkinny_Brown","ZmbF_JoggerSkinny_Green","ZmbF_JoggerSkinny_Red","ZmbM_MotobikerFat_Base","ZmbM_MotobikerFat_Beige",
	"ZmbM_MotobikerFat_Black","ZmbM_MotobikerFat_Blue","ZmbM_VillagerOld_Base","ZmbM_VillagerOld_Blue","ZmbM_VillagerOld_Green",
	"ZmbM_VillagerOld_White","ZmbM_SkaterYoung_Base","ZmbM_SkaterYoung_Blue","ZmbM_SkaterYoung_Brown","ZmbM_SkaterYoung_Green",
	"ZmbM_SkaterYoung_Grey","ZmbF_SkaterYoung_Base","ZmbF_SkaterYoung_Brown","ZmbF_SkaterYoung_Striped","ZmbF_SkaterYoung_Violet",
	"ZmbF_DoctorSkinny_Base","ZmbF_DoctorSkinny","ZmbF_BlueCollarFat_Base","ZmbF_BlueCollarFat_Blue","ZmbF_BlueCollarFat_Green",
	"ZmbF_BlueCollarFat_Red","ZmbF_BlueCollarFat_White","ZmbF_MechanicNormal_Base","ZmbF_MechanicNormal_Beige","ZmbF_MechanicNormal_Green",
	"ZmbF_MechanicNormal_Grey","ZmbF_MechanicNormal_Orange","ZmbM_MechanicSkinny_Base","ZmbM_MechanicSkinny_Blue","ZmbM_MechanicSkinny_Grey",
	"ZmbM_MechanicSkinny_Green","ZmbM_MechanicSkinny_Red","ZmbM_ConstrWorkerNormal_Base","ZmbM_ConstrWorkerNormal_Beige",
	"ZmbM_ConstrWorkerNormal_Black","ZmbM_ConstrWorkerNormal_Green","ZmbM_ConstrWorkerNormal_Grey","ZmbM_HeavyIndustryWorker_Base",
	"ZmbM_HeavyIndustryWorker","ZmbM_OffshoreWorker_Base","ZmbM_OffshoreWorker_Green","ZmbM_OffshoreWorker_Orange","ZmbM_OffshoreWorker_Red",
	"ZmbM_OffshoreWorker_Yellow","ZmbF_NurseFat_Base","ZmbF_NurseFat","ZmbM_HandymanNormal_Base","ZmbM_HandymanNormal_Beige",
	"ZmbM_HandymanNormal_Blue","ZmbM_HandymanNormal_Green","ZmbM_HandymanNormal_Grey","ZmbM_HandymanNormal_White","ZmbM_DoctorFat_Base",
	"ZmbM_DoctorFat","ZmbM_Jacket_Base","ZmbM_Jacket_beige","ZmbM_Jacket_black","ZmbM_Jacket_blue","ZmbM_Jacket_bluechecks",
	"ZmbM_Jacket_brown","ZmbM_Jacket_greenchecks","ZmbM_Jacket_grey","ZmbM_Jacket_khaki","ZmbM_Jacket_magenta","ZmbM_Jacket_stripes",
	"ZmbF_PatientOld_Base","ZmbF_PatientOld","ZmbM_PatientSkinny_Base","ZmbM_PatientSkinny","ZmbF_ShortSkirt_Base","ZmbF_ShortSkirt_beige",
	"ZmbF_ShortSkirt_black","ZmbF_ShortSkirt_brown","ZmbF_ShortSkirt_green","ZmbF_ShortSkirt_grey","ZmbF_ShortSkirt_checks",
	"ZmbF_ShortSkirt_red","ZmbF_ShortSkirt_stripes","ZmbF_ShortSkirt_white","ZmbF_ShortSkirt_yellow","ZmbF_VillagerOld_Base",
	"ZmbF_VillagerOld_Blue","ZmbF_VillagerOld_Green","ZmbF_VillagerOld_Red","ZmbF_VillagerOld_White","ZmbM_Soldier","ZmbM_SoldierAlice",
	"ZmbM_SoldierHelmet","ZmbM_SoldierVest","ZmbM_SoldierAliceHelmet","ZmbM_SoldierVestHelmet","ZmbF_MilkMaidOld_Base",
	"ZmbF_MilkMaidOld_Beige","ZmbF_MilkMaidOld_Black","ZmbF_MilkMaidOld_Green","ZmbF_MilkMaidOld_Grey","ZmbM_priestPopSkinny_Base",
	"ZmbM_priestPopSkinny","ZmbM_ClerkFat_Base","ZmbM_ClerkFat_Brown","ZmbM_ClerkFat_Grey","ZmbM_ClerkFat_Khaki","ZmbM_ClerkFat_White",
	"ZmbF_Clerk_Normal_Base","ZmbF_Clerk_Normal_Blue","ZmbF_Clerk_Normal_White","ZmbF_Clerk_Normal_Green","ZmbF_Clerk_Normal_Red",
	};
}
