#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\AdminModuleManager.c"
#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Tunables.c"
#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Modules\\AdminTool\\AdminTool.c"
#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Modules\\AdvancedLoadouts\\AdvancedLoadouts.c"
//#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Modules\\CustomBuildings\\BuildingSpawner.c"
//#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Modules\\Misc\\BuildingSpawner.c"
#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Modules\\SafeZone\\SafeZoneFunctions.c"
#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Modules\\ServerEvents\\InfectedHordes.c"
#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Modules\\ServerMission\\SpawnPointsManager.c"
#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Modules\\ServerMission\\SpawnCoolDownSystem.c"

class DayZSurvival : MissionServer
{
	private ref set<ref AdminModuleManager> m_Modules;
	ref InfectedHordes m_ZombieEvents;
	protected float m_LogInTimerLength = 1;     //The timer for players who join the server  (in seconds)
	protected int   m_UseSpawnMenu = GetGame().ServerConfigGetInt("SpawnSelectionMenu");
	bool m_StaminaStatus = false;

	string m_SpawnPoint = "";
	string m_SkinStr = "";
	vector m_pos = "0 0 0";

	ref map<int, string> m_Gear;

	void DayZSurvival()
	{
		Print("VANILLA++ IS ALIVE!!");
		//=============RPC's====================
		GetRPCManager().AddRPC( "RPC_GetSpawnPoints", "GetSpawnPoints", this, SingeplayerExecutionType.Server );
		GetRPCManager().AddRPC( "RPC_SpawnStartKit", "SpawnStartKit", this, SingeplayerExecutionType.Server );
		GetRPCManager().AddRPC( "RPC_CoolDownHandler", "CoolDownHandler", this, SingeplayerExecutionType.Server );
		GetRPCManager().AddRPC( "RPC_GetSpawnVectors", "GetSpawnVectors", this, SingeplayerExecutionType.Server );
		//======================================

		m_Modules = new set<ref AdminModuleManager>;
		RegisterModules();
	}
	
	void ~DayZSurvival()
	{
		
	}

	void RegisterModules()
	{
		m_Modules.Insert(new ModTunables(this));
		m_Modules.Insert(new SpawnPointsManager(this));
		m_Modules.Insert(new SpawnCoolDownSystem(this));
		
		if (ModTunables.Cast(GetModule(ModTunables)).IsActive("AdminTools"))
		{
			m_Modules.Insert(new AdminTool(this));
		}

		if (ModTunables.Cast(GetModule(ModTunables)).IsActive("AdvancedLoadouts"))
		{
			m_Modules.Insert(new AdvancedLoadouts(this));
		}

		if (ModTunables.Cast(GetModule(ModTunables)).IsActive("SafeZone"))
		{
			m_Modules.Insert(new SafeZone(this));
		}

		/*if (ModTunables.Cast(GetModule(ModTunables)).IsActive("Misc"))
		{
			m_Modules.Insert(new BuildingSpawner(this));
		}*/
	}
	
	void InitModules()
	{
		for ( int i = 0; i < m_Modules.Count(); ++i)
		{
			m_Modules.Get(i).Init();
		}
	}
	
	AdminModuleManager GetModule(typename moduleType)
	{
		for ( int i = 0; i < m_Modules.Count(); ++i)
		{
			AdminModuleManager module = m_Modules.Get(i);
			if (module.GetModuleType() == moduleType) 
			{
				return module;
			}
		}
		return NULL;
	}
	
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		for ( int i = 0; i < m_Modules.Count(); ++i)
		{
			m_Modules.Get(i).onUpdate(timeslice);
		}
	}

	override void OnInit()
	{
		super.OnInit();
		InitModules();
		
		if (!ModTunables.Cast(GetModule(ModTunables)).IsActiveMisc("Debugmode"))
		{
			Hive ce = CreateHive();
			if (ce)
			ce.InitOffline();
		}

		if (ModTunables.Cast(GetModule(ModTunables)).IsActiveMisc("SessionFeed"))
		{
			g_Game.SetProfileString("SessionFeed", "true");
		}
		else
		{
			g_Game.SetProfileString("SessionFeed", "false");
		}

		if (ModTunables.Cast(GetModule(ModTunables)).IsActiveMisc("StaminaStatus"))
		{
			m_StaminaStatus = true; //Disable Stamina
		}
		
		if (ModTunables.Cast(GetModule(ModTunables)).IsActive("InfectedHordes"))
		{
			m_ZombieEvents = new InfectedHordes;
		}

		if (ModTunables.Cast(GetModule(ModTunables)).IsActiveMisc("ProxyExportMode"))
		{
			CETesting TestHive = GetTesting();
			TestHive.ExportProxyProto();
			TestHive.ExportProxyData( "7500 0 7500", 15000 );
		}
		
		//-----------
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.PlayerCounter, 110000, true);  //Default 120000 2 mins Looped
		//-----------
	}

	void GetSpawnVectors( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		Param1< string > data;
        if ( !ctx.Read( data ) ) return;

        if (type == CallType.Server)
        {
        	ref map<string, ref map<string,float>> m_MapSpawnPoints = SpawnPointsManager.Cast(GetModule(SpawnPointsManager)).GetMap();
        	ref map<string, string> m_dataMap = new map<string, string>;

    	    for (int i = 0; i < m_MapSpawnPoints.Count(); ++i)
    	    {
    	    	string LocationName = m_MapSpawnPoints.GetKey(i);
    	    	ref map<string,float> m_PointsMap =  m_MapSpawnPoints.Get(LocationName);
	    	    for (int x = 0; x < m_PointsMap.Count(); ++x)
	    	    {
	    	    	string positionC = m_PointsMap.GetKey(x);
	    	    	float clTime = m_PointsMap.Get(positionC);
	    	    	m_dataMap.Insert(LocationName,positionC);
	    	    }
    	    }
    	    Param1<ref map<string, string>> map_param = new Param1<ref map<string, string>>(m_dataMap);
        	GetRPCManager().SendRPC( "RPC_SortPositions", "SortPositions", map_param, true, sender );
        }
	}

	void CoolDownHandler( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		Param3<string,string,bool> data;
        if ( !ctx.Read( data ) ) return;
       
        if (type == CallType.Server)
        {
        	if (data.param2 != "randomPos")
        	{
	        	if (data.param3)
	        	{
	        		SpawnCoolDownSystem.Cast(GetModule(SpawnCoolDownSystem)).AddCooldown(data.param1,data.param2);
	        	}
	        	else
	        	{
	        		SpawnCoolDownSystem.Cast(GetModule(SpawnCoolDownSystem)).RemoveCooldown(data.param1,data.param2);
	        	}
        	}
        }
	}

	void GetSpawnPoints( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		Param1<string> data;
        if ( !ctx.Read( data ) ) return;

        if (type == CallType.Server)
        {
        	ref array<string> m_Locations = new array<string>;
        	m_Locations = SpawnPointsManager.Cast(GetModule(SpawnPointsManager)).GetAllSpawnsNames();
        	
        	Param1<ref array<string>> map_param = new Param1<ref array<string>>(m_Locations);
        	GetRPCManager().SendRPC( "RPC_SpawnPointsHandle", "SpawnPointsHandle", map_param, true, sender );
        }
	}

	override void OnPreloadEvent(PlayerIdentity identity, out bool useDB, out vector pos, out float yaw, out int queueTime)
	{
		if (GetHive())
		{
			useDB = true;
			queueTime = m_LogInTimerLength;
		}
		else
		{
			useDB = false;
			pos = "7500 0 7500";
			yaw = 0;
			queueTime = m_LogInTimerLength;
		}
	}

	override void TickScheduler(float timeslice)
	{
		GetGame().GetWorld().GetPlayerList(m_Players);
		if( m_Players.Count() == 0 ) return;
		for(int i = 0; i < SCHEDULER_PLAYERS_PER_TICK; i++)
		{
			if(m_currentPlayer >= m_Players.Count() )
			{
				m_currentPlayer = 0;
			}

			PlayerBase currentPlayer = PlayerBase.Cast(m_Players.Get(m_currentPlayer));
			currentPlayer.OnTick();

			if (m_StaminaStatus) {
			currentPlayer.GetStaminaHandler().SyncStamina(1000,1000);
            currentPlayer.GetStatStamina().Set(currentPlayer.GetStaminaHandler().GetStaminaCap());
			}
			if (GetModule(SafeZone)) { SafeZone.Cast(GetModule(SafeZone)).SafeZoneHandle(currentPlayer); }
			m_currentPlayer++;
		}
	}

	PlayerBase CreateCharacter(PlayerIdentity identity, string posName, int MapKey,ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		if (posName == "randomPos")
		{
			//Get Random SpawnPoint
			playerEnt = GetGame().CreatePlayer(identity, characterName, SpawnPointsManager.Cast(GetModule(SpawnPointsManager)).GetRandomSpawnPoint(), 0, "NONE");
			Class.CastTo(m_player, playerEnt);
			GetGame().SelectPlayer(identity, m_player);
		}
		else
		{
			playerEnt = GetGame().CreatePlayer(identity, characterName, SpawnPointsManager.Cast(GetModule(SpawnPointsManager)).GetPosByName(posName,MapKey), 0, "NONE");
			Class.CastTo(m_player, playerEnt);
			GetGame().SelectPlayer(identity, m_player);
		}
		return m_player;
	}

	override void OnEvent(EventType eventTypeId, Param params) 
	{
		super.OnEvent(eventTypeId,params);

		PlayerIdentity identity;
		switch(eventTypeId)
		{
			case ChatMessageEventTypeID:
			 ChatMessageEventParams chat_params = ChatMessageEventParams.Cast(params);
			 if (chat_params.param1 == 0 && chat_params.param2 != "") //trigger only when channel is Global == 0 and Player Name does not equal to null
				{
					Param4<int,string,string,string> request_info = new Param4<int,string,string,string>(chat_params.param1, chat_params.param2, chat_params.param3, chat_params.param4);
					AdminTool.Cast(GetModule(AdminTool)).RequestHandler(request_info); //Send the param to Admintools
				}
			break;
		}
	}

	override PlayerBase OnClientNewEvent(PlayerIdentity identity, vector pos, ParamsReadContext ctx)
	{
		int m_MapKey;
		ProcessData(ctx, m_SkinStr, m_SpawnPoint, m_MapKey);
		if (CreateCharacter(identity, m_SpawnPoint, m_MapKey,ctx, m_SkinStr))
		{
			GetGame().RPCSingleParam(m_player, ERPCs.RPC_CHARACTER_EQUIPPED, NULL, true, m_player.GetIdentity());
		}
		return m_player;
	}

	void SpawnStartKit( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		Param2<string,string> data;
        if ( !ctx.Read( data ) ) return;

        if (type == CallType.Server)
        {
        	string LoadOutName;
			string UID;
        	if (AdvancedLoadouts.Cast(GetModule(AdvancedLoadouts)).CheckTunables("StaticLoadouts"))
        	{
        		LoadOutName = data.param1;
	        	UID		   = data.param2;
	        	AdvancedLoadouts.Cast(GetModule(AdvancedLoadouts)).SpawnStaticLoadout(LoadOutName,UID);
        	}
        	else
        	{
        		string JsonData = data.param1;
	        	UID		= data.param2;
	        	m_Gear = new map<int, string>;
	        	PlayerBase player;
				if (JsonData != "random")
				{
					JsonFileLoader<ref map<int,string>>.JsonLoadData( JsonData,m_Gear );
					player = PlayerBase.Cast(GetPlayerByUID(UID));
				    for (int i = 0; i < m_Gear.Count(); ++i)
				    {
				    	ItemBase itemBs;
				    	int oKey = m_Gear.GetKey(i);
				    	string Item = m_Gear.Get(oKey);
				    	itemBs = ItemBase.Cast( player.GetInventory().CreateInInventory( Item ) );
				    }
				    if (AdvancedLoadouts.Cast(GetModule(AdvancedLoadouts)).CheckTunables("SpawnArmed")) { RandomWeaponOnStartup(player); }
				}
				else
				{
					player = PlayerBase.Cast(GetPlayerByUID(UID));
					StartingEquipSetup(player,false);
				}
        	}
        }
	}

	PlayerBase GetPlayerByUID(string UID)
	{
		array<Man> players = new array<Man>;
	    GetGame().GetPlayers( players );
	    PlayerBase selectedPlayer;
   	    for (int i = 0; i < players.Count(); ++i)
   	    {
   	    	string PUID = players.Get(i).GetIdentity().GetId();
   	    	if (PUID == UID)
   	    	{
   	    		selectedPlayer = players.Get(i);
   	    	}
   	    }
   	    return selectedPlayer;
	}

	void ProcessData(ParamsReadContext ctx, out string Skin, out string SpawnPoint, out int MapKey)
	{
		ref Param1<string> skinParam = new Param1<string>(Skin);
		if (ctx.Read(skinParam))
		{
			Skin = skinParam.param1;
		}
		ref Param1<string> SpawnPointParam = new Param1<string>(SpawnPoint);
		if (ctx.Read(SpawnPointParam))
		{
			SpawnPoint = SpawnPointParam.param1;
		}
		ref Param1<int> SPPKeyParam = new Param1<int>(MapKey);
		if (ctx.Read(SPPKeyParam))
		{
			MapKey = SPPKeyParam.param1;
		}
	}

	void GlobalMessage(int Channel, string Message)
	{
		if (Message != "")
		{
			GetGame().ChatPlayer(Channel,Message);
		}
	}

	void PlayerCounter()
	{
		array<Man> players = new array<Man>;
	    GetGame().GetPlayers( players );
	    int numbOfplayers = players.Count();
	    GlobalMessage(1,"Online Players: "+ numbOfplayers.ToString());
	}

	void RandomWeaponOnStartup(PlayerBase player)
	{
	    //Gun spawner Handle
		//SpawnGunIn( PlayerBase player, string ClassName, bool isPrimary, TstringArray Attachments, TstringArray Extras) NOTE: Set bool to 'true' IF weapon was primary
		int oRandValue = Math.RandomIntInclusive(0,2);
		switch(oRandValue.ToString())
		{
			case "0":
			AdvancedLoadouts.Cast(GetModule(AdvancedLoadouts)).SpawnGunIn( player , "fnx45", true, {"fnp45_mrdsoptic","PistolSuppressor"},{"mag_fnx45_15rnd","mag_fnx45_15rnd"} );
			break;

			case "1":
			AdvancedLoadouts.Cast(GetModule(AdvancedLoadouts)).SpawnGunIn( player , "CZ75", true, {"PistolSuppressor"} , {"Mag_CZ75_15Rnd","Mag_CZ75_15Rnd"} );
			break;

			case "2":
			AdvancedLoadouts.Cast(GetModule(AdvancedLoadouts)).SpawnGunIn( player , "makarovij70", true, {"PistolSuppressor"} , {"mag_ij70_8rnd","mag_ij70_8rnd"} );
			break;
		}
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
/*
		player.RemoveAllItems();

		EntityAI item = player.GetInventory().CreateInInventory(topsArray.GetRandomElement());
		EntityAI item2 = player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		EntityAI item3 = player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
*/
		EntityAI itemEnt;
		ItemBase itemBs;
		
		itemEnt = player.GetInventory().CreateInInventory("Rag");
		itemBs = ItemBase.Cast(itemEnt);
		itemBs.SetQuantity(4);
		//SetRandomHealth(itemEnt);

		itemEnt = player.GetInventory().CreateInInventory("RoadFlare");
		itemBs = ItemBase.Cast(itemEnt);
	}
}
