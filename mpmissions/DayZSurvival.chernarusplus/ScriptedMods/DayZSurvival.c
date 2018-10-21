class DayZSurvival : MissionServer
{
	// Called within class as extentions NOT class mainscope DO NOT DEFINE CLASS IN FILE! 
	#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\BuildingSpawner.c"
	#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\MOTDMessages.c" //Custom MOTD fucns
	#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\SafeZoneFunctions.c" //Safe zone script
	#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\AdminTool\\AdminTool.c" //Adds other voids to class (so this .c file stays a little more clean)

	string SelectedPos;
	string m_LoadoutsPath = "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\LoadOuts\\";
	string m_AdminListPath = "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\";

	ref TStringArray LoadoutCatagories = {"Bags","Gloves","Vests","Tops","Pants","Boots","HeadGear"}; //Add any new catagories here, make sure the name matches everywhere used including file

	ref TStringArray Bags = {};
	ref TStringArray Gloves = {};
	ref TStringArray Vests = {};
	ref TStringArray Tops = {};
	ref TStringArray Pants = {};
	ref TStringArray Boots = {};
	ref TStringArray HeadGear = {};

	ref map<string,string>	PoweredOptics = new map<string,string>; //Type of optics, type of battery
	bool m_VanillaLoadouts;
	bool m_SpawnArmed;
	bool m_StaminaStatus;
	bool m_SafeZone;
	bool m_CustomBuildings;

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
			if (m_StaminaStatus) { currentPlayer.GetStatStamina().Set(1000); }
			if (m_SafeZone) { SafeZoneHandle(currentPlayer); } //Check if player is near safezone
			currentPlayer.OnTick();
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

	void ConstructLoadouts(bool update)
	{
		if (update) {
			Bags.Clear();
			Gloves.Clear();
			Vests.Clear();
			Tops.Clear();
			Pants.Clear();
			Boots.Clear();
			HeadGear.Clear();
		}

		for ( int i = 0; i < LoadoutCatagories.Count(); ++i )
		{
			string currentCatagory = LoadoutCatagories.Get(i);
			string checkEmpty;
			FileHandle currentFile = OpenFile(m_LoadoutsPath + currentCatagory + ".txt", FileMode.READ);
			if (currentFile != 0)
			{
				FGets(currentFile,checkEmpty);
				if (checkEmpty != "")
				{
					string line_content = "";
					while ( FGets(currentFile,line_content) > 0 )
					{
						switch(currentCatagory)
						{
							case "Bags":
							Bags.Insert(line_content);
							break;

							case "Gloves":
							Gloves.Insert(line_content);
							break;

							case "Vests":
							Vests.Insert(line_content);
							break;

							case "Tops":
							Tops.Insert(line_content);
							break;

							case "Pants":
							Pants.Insert(line_content);
							break;

							case "Boots":
							Boots.Insert(line_content);
							break;

							case "HeadGear":
							HeadGear.Insert(line_content);
							break;
						}
					}
				}
				CloseFile(currentFile);
		    }
		}
	}

	override void OnInit()
	{
		Hive ce = CreateHive();
		if (ce)
		ce.InitOffline();
		//---------------
		string cmdLine;
		if (GetGame().CommandlineGetParam("VanillaSpawnLD", cmdLine))
		{
			m_VanillaLoadouts = true;
		} else {
			m_VanillaLoadouts = false;
		}

		if (GetGame().CommandlineGetParam("SpawnArmed", cmdLine))
		{
			m_SpawnArmed = true;
		} else {
			m_SpawnArmed = false;
		}

		if (GetGame().CommandlineGetParam("DisableStamina",cmdLine))
		{
			m_StaminaStatus = true;
		} else {
			m_StaminaStatus = false;
		}

		if (GetGame().CommandlineGetParam("SafeZone",cmdLine))
		{
			m_SafeZone = true;
		} else {
			m_SafeZone = false;
		}

		if (GetGame().CommandlineGetParam("CustomBuildings",cmdLine))
		{
			m_CustomBuildings = true;
		} else {
			m_CustomBuildings = false;
		}

		//-----Add Admins from txt-----
		FileHandle AdminUIDSFile = OpenFile(m_AdminListPath + "Admins.txt", FileMode.READ);
		if (AdminUIDSFile != 0)
		{
			string line_content = "";
			while ( FGets(AdminUIDSFile,line_content) > 0 )
			{
				m_AdminList.Insert(line_content,"null"); //UID , NAME
				Print("Adding Admin: "+ line_content + " To the Admin List!");
			}
			CloseFile(AdminUIDSFile);
		}

		//-----------
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.PlayerCounter, 110000, true);  //Default 120000 2 mins Looped
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.CustomMOTD, TIME_INTERVAL, true);  //Default 120000 2 mins Looped
		//----------------------------------
		AdminTool(); //Call for admin tool scripts
		if (m_CustomBuildings) { BuildingSpawner(); } //Spawn for custom buildings
		ConstructLoadouts(false); //Read and construct loadouts Array from files.
		//----------------------------------

		//-----------------------------
		PoweredOptics.Insert("m4_carryhandleoptic","");
		PoweredOptics.Insert("buisoptic","");
		PoweredOptics.Insert("M68Optic","Battery9V");
		PoweredOptics.Insert("m4_t3nrdsoptic","Battery9V");
		PoweredOptics.Insert("fnp45_mrdsoptic","Battery9V");
		PoweredOptics.Insert("crossbow_redpointoptic","Battery9V");
		PoweredOptics.Insert("reflexoptic","Battery9V");
		PoweredOptics.Insert("acogoptic","");
		PoweredOptics.Insert("puscopeoptic","");
		PoweredOptics.Insert("kashtanoptic","");
		PoweredOptics.Insert("huntingoptic","");
		PoweredOptics.Insert("pistoloptic","");
		PoweredOptics.Insert("pso1optic","");
		PoweredOptics.Insert("pso11optic","Battery9V");
		PoweredOptics.Insert("grozaoptic","");
		PoweredOptics.Insert("kobraoptic","Battery9V");
		//-----------------------------
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
	
	void SpawnGunIn(PlayerBase player, string item = "", bool isMainGun = true, TStringArray attachments = NULL, TStringArray Extras = NULL)
	{
		ItemBase itemAI;

		EntityAI myAttachmentAI;
		ItemBase myAttachmentIB;

		EntityAI ExtraEntity;
		ItemBase magEntity;

		if (isMainGun)
		{
			if ( item != "" ) 
			{
				itemAI = player.GetHumanInventory().CreateInHands( item );
				Weapon_Base wpn = Weapon_Base.Cast(itemAI);

				player.SetQuickBarEntityShortcut(itemAI, 2, true); //Puts gun on hotkey 3

				if ( attachments != NULL && attachments.Count() > 0 )
				{
					
					for (int i = 0; i < attachments.Count(); ++i)
					{
						myAttachmentAI = itemAI.GetInventory().CreateInInventory( attachments.Get(i) );

						if (PoweredOptics.Contains(attachments.Get(i)))
						{
							myAttachmentAI.GetInventory().CreateInInventory( "Battery9V" );
						}
					}
				}
				
				if ( Extras != NULL && Extras.Count() > 0 )
				{
					for (int ii = 0; ii < Extras.Count(); ++ii)
					{
						if (GetGame().IsKindOf( Extras.Get(ii), "Magazine_Base") && ! (GetGame().IsKindOf( Extras.Get(ii), "Ammunition_Base")) )
						{
							magEntity = player.GetHumanInventory().CreateInInventory(Extras.Get(ii));
							Magazine mag = Magazine.Cast(magEntity);
							player.GetWeaponManager().AttachMagazine(mag);
							ExtraEntity = player.GetInventory().CreateInInventory( Extras.Get(ii) );
							player.SetQuickBarEntityShortcut(ExtraEntity, 0, true);  //Puts main weapons mag on hotkey 1
						}
						else
						{
							ExtraEntity = player.GetInventory().CreateInInventory( Extras.Get(ii) );
						}
					}
				}
			
			}
		}
		else
		{
			//For Pistols/Secondary that spawn in inevntory
			if ( item != "" ) 
			{
				itemAI = player.GetHumanInventory().CreateInInventory( item );

				player.SetQuickBarEntityShortcut(itemAI, 3, true);  //Puts the Secondary weapon on hotkey 4
			
				if ( attachments != NULL && attachments.Count() > 0 )
				{
					myAttachmentAI;
					myAttachmentIB;
					
					for (int iz = 0; iz < attachments.Count(); ++iz)
					{
						myAttachmentIB = itemAI.GetInventory().CreateAttachment( attachments.Get(iz) );
						if (PoweredOptics.Contains(attachments.Get(iz)))
						{
							myAttachmentIB.GetInventory().CreateInInventory( "Battery9V" );
						}
					}
				}
				
				if ( Extras != NULL && Extras.Count() > 0 )
				{
					for (int ip = 0; ip < Extras.Count(); ++ip)
					{
						if (GetGame().IsKindOf( Extras.Get(ip), "Magazine_Base") && ! (GetGame().IsKindOf( Extras.Get(ip), "Ammunition_Base")) )
						{
							ExtraEntity = player.GetInventory().CreateInInventory( Extras.Get(ip) );
							player.SetQuickBarEntityShortcut(ExtraEntity, 1, true);   //Puts the mag for the secondary on hotkey 2
						}
						else
						{
							ExtraEntity = player.GetInventory().CreateInInventory( Extras.Get(ip) );
						}
					}
				}
			
			}
		}
		
	} 

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI EntityRifle;
		ItemBase itemRifle;
			
		EntityAI EntityPistol;
		ItemBase itemPistol;

		ItemBase itemBs;
		EntityAI itemEnt;
		
		if (m_VanillaLoadouts)
		{
			itemEnt = player.GetInventory().CreateInInventory( "Rag" );
			itemBs = ItemBase.Cast(itemEnt);							
			itemBs.SetQuantity(6);
		}
		else
		{
			player.RemoveAllItems();
			//Edit loadouts Via the LOADOUTS folder in ScriptedMods folder!
			//If you wish for an item from a specific catagory to not be spawned just hash out this part:: player.GetInventory().CreateInInventory( Bags.GetRandomElement() );
			
			if (Bags.Count() > 0) { player.GetInventory().CreateInInventory( Bags.GetRandomElement() );  }
			if (Gloves.Count() > 0) { player.GetInventory().CreateInInventory( Gloves.GetRandomElement() ); }
			if (Vests.Count() > 0) { player.GetInventory().CreateInInventory( Vests.GetRandomElement() ); }
			if (Tops.Count() > 0) { player.GetInventory().CreateInInventory( Tops.GetRandomElement() ); }
			if (Pants.Count() > 0) { player.GetInventory().CreateInInventory( Pants.GetRandomElement() ); }
			if (Boots.Count() > 0) { player.GetInventory().CreateInInventory( Boots.GetRandomElement() ); }
			if (HeadGear.Count() > 0) { player.GetInventory().CreateInInventory( HeadGear.GetRandomElement() ); }

			player.GetInventory().CreateInInventory( "Battery9V" );
			
			itemEnt = player.GetInventory().CreateInInventory( "Rag" );
			itemBs = ItemBase.Cast(itemEnt);							
			itemBs.SetQuantity(6);

			player.SetQuickBarEntityShortcut(itemBs, 0, true);
		   }
			
		  if (m_SpawnArmed)
		  {
				//Gun spawner Handle
			    //SpawnGunIn( PlayerBase player, string ClassName, bool isPrimary, TstringArray Attachments, TstringArray Extras) NOTE: Set bool to 'true' IF weapon was primary
				int oRandValue = Math.RandomIntInclusive(0,2);
				switch(oRandValue.ToString())
				{
					case "0":
					SpawnGunIn( player , "fnx45", true, {"fnp45_mrdsoptic","PistolSuppressor"},{"mag_fnx45_15rnd","mag_fnx45_15rnd","ammo_45acp","ammo_45acp"} );
					break;

					case "1":
					SpawnGunIn( player , "CZ75", true, {"PistolSuppressor"} , {"Mag_CZ75_15Rnd","Mag_CZ75_15Rnd","ammo_9x19","ammo_9x19"} );
					break;

					case "2":
					SpawnGunIn( player , "makarovij70", true, {"PistolSuppressor"} , {"mag_ij70_8rnd","mag_ij70_8rnd","ammo_380","ammo_380"} );
					break;
				}
		  }
	}
};