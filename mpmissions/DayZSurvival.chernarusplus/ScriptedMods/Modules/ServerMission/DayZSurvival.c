#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\ModuleManager.c"
#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Tunables.c"
#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Modules\\AdminTool\\AdminTool.c"
#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Modules\\AdvancedLoadouts\\AdvancedLoadouts.c"
#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Modules\\Misc\\BuildingSpawner.c"
#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Modules\\SafeZone\\SafeZoneFunctions.c"

//#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Modules\\Misc\\MOTDMessages.c"

class DayZSurvival : MissionServer
{
	private ref set<ref ModuleManager> m_Modules;
	protected float m_LogInTimerLength = 1;     //in seconds the spawn timer when players login!
	bool m_StaminaStatus = false;

	void DayZSurvival()
	{
		Print("VANILLA PLUS PLUS IS ALIVE!!");
		m_Modules = new set<ref ModuleManager>;
		RegisterModules();
	}
	
	void ~DayZSurvival()
	{
		
	}
	
	void RegisterModules()
	{
		m_Modules.Insert(new ModTunables(this));
		
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
	}
	
	void InitModules()
	{
		for ( int i = 0; i < m_Modules.Count(); ++i)
		{
			m_Modules.Get(i).Init();
		}
	}
	
	ModuleManager GetModule(typename moduleType)
	{
		for ( int i = 0; i < m_Modules.Count(); ++i)
		{
			ModuleManager module = m_Modules.Get(i);
			if (module.GetModuleType() == moduleType) 
			{
				return module;
			}
		}
		return NULL;
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

		if (ModTunables.Cast(GetModule(ModTunables)).IsActiveMisc("ProxyExportMode"))
		{
			CETesting TestHive = GetTesting();
			TestHive.ExportProxyProto();
			TestHive.ExportProxyData( "7500 0 7500", 15000 );
		}

		if (ModTunables.Cast(GetModule(ModTunables)).IsActiveMisc("SessionFeed"))
		{
			g_Game.SetProfileString("SessionFeed", "true");
		}
		else
		{
			g_Game.SetProfileString("SessionFeed", "false");
		}

		if (ModTunables.Cast(GetModule(ModTunables)).IsActiveMisc("CustomBuildings"))
		{
			ref BuildingSpawner bldspnwer = new BuildingSpawner;
			bldspnwer.Init();
		}

		if (ModTunables.Cast(GetModule(ModTunables)).IsActiveMisc("StaminaStatus"))
		{
			m_StaminaStatus = true; //Disable Stamina
		}
		
		//-----------
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.PlayerCounter, 110000, true);  //Default 120000 2 mins Looped
		//GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.CustomMOTD, TIME_INTERVAL, true);  //Default 120000 2 mins Looped
		//-----------
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

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;

		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");
		Class.CastTo(m_player, playerEnt);
		
		GetGame().SelectPlayer(identity, m_player);
		return m_player;
	}
	
	override void OnEvent(EventType eventTypeId, Param params) 
	{
		super.OnEvent(eventTypeId,params);
		
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
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		ItemBase itemBs;
		EntityAI itemEnt;
		
		if (GetModule(AdvancedLoadouts))
		{
			if (AdvancedLoadouts.Cast(GetModule(AdvancedLoadouts)).CheckTunables("StaticLoadouts"))
			{
				bool reqld = AdvancedLoadouts.Cast(GetModule(AdvancedLoadouts)).LoadRandomStaticLD(player);
			}
			else if (AdvancedLoadouts.Cast(GetModule(AdvancedLoadouts)).CheckTunables("RandomizedLoadouts"))
			{
				AdvancedLoadouts.Cast(GetModule(AdvancedLoadouts)).LoadRndGenLoadout(player);
			}
			else
			{
				//Vanilla
				itemEnt = player.GetInventory().CreateInInventory( "Rag" );
				itemBs = ItemBase.Cast(itemEnt);							
				itemBs.SetQuantity(6);
			}

			if (AdvancedLoadouts.Cast(GetModule(AdvancedLoadouts)).CheckTunables("SpawnArmed"))
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
		}
		else
		{
			//Vanilla
			itemEnt = player.GetInventory().CreateInInventory( "Rag" );
			itemBs = ItemBase.Cast(itemEnt);							
			itemBs.SetQuantity(6);
		}
	}
}