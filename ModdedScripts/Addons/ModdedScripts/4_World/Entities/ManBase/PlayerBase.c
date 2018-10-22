modded class PlayerBase
{
    ref ScoreTrackerHandle KillTracker;
	string KillLogFileLocation = "$profile:KillActivity.txt";
	
	string GetDate()
	{
		int year, month, day, hour, minute, second;
		
		GetYearMonthDay(year, month, day);
		GetHourMinuteSecond(hour, minute, second);

		string date = "[" + "Hour: " + hour.ToStringLen(2) + " -- "+ "Minute: " + minute.ToStringLen(2) +"] " + " || " + "[Month: " +month.ToStringLen(2) + " -- " + "Day: " + day.ToStringLen(2) + "]";
		return date;
	}
	
	void CheckPlayerName()
	{
		ref SurvivorBase ChachedSB = this;
		string CurrentPlayerName,NewName;
		
		TStringArray preSetNames = {
									"101WaysToMeetYourMaker",
									"3D Waffle",
									"57 Pixels",
									"Accidental Genius",
									"Acid Gosling",
									"Admiral Tot",
									"AgentHercules",
									"Airport Hobo",
									"Alley Frog",
									"Alpha",
									"AlphaReturns",
									"Angel",
									"AngelsCreed",
									"Arsenic Coo",
									"Atomic Blastoid",
									"Automatic Slicer",
									"Baby Brown",
									"Back Bett",
									"Bad Bunny",
									"Bazooka Hardehar",
									"Bearded Angler",
									"Beetle King",
									"Betty Cricket",
									"Bit Sentinel",
									"Bitmap",
									"BlacKitten",
									"Blister",
									"Blistered Outlaw",
									"Blitz",
									"BloodEater",
									"Bonzai",
									"BoomBeachLuvr",
									"BoomBlaster",
									"Bootleg Taximan",
									"Bowie",
									"Bowler",
									"Breadmaker",
									"Broomspun",
									"Buckshot",
									"Bug Blitz",
									"Bug Fire",
									"Bugger",
									"Cabbie",
									"Candy Butcher",
									"Capital F",
									"Captain Peroxide",
									"Celtic Charger",
									"Centurion Sherman",
									"Cereal Killer",
									"Chasm Face",
									"Chew Chew",
									"Chicago Blackout",
									"Chip Queen",
									"ChocoNutsX",
									"Chocolate Thunder",
									"Chuckles",
									"Club Nola",
									"CoB@lt",
									"CobraBite",
									"Cocktail",
									"CollaterolDamage",
									"CommandX",
									"Commando",
									"Congo Wire",
									"Cool Iris",
									"Cool Whip",
									"Cosmo",
									"Crash Override",
									"Crash Test",
									"Crazy Eights",
									"Criss Cross",
									"Cross Thread",
									"Cujo",
									"Cupid Dust",
									"Daffy Girl",
									"Dahlia Bumble",
									"DaisyCraft",
									"Dancing Madman",
									"Dangle",
									"DanimalDaze",
									"Dark Horse",
									"Darkside Orbit",
									"Darling Peacock",
									"Day Hawk",
									"Desert Haze",
									"Desperado",
									"Devil Blade",
									"Devil Chick",
									"Dexter",
									"Diamond Gamer",
									"Digger",
									"Disco Potato",
									"Disco Thunder",
									"DiscoMate",
									"Don Stab",
									"Doz Killer",
									"Dredd",
									"DriftDetector",
									"DriftManiac",
									"Drop Stone",
									"Dropkick",
									"Drugstore Cowboy",
									"DuckDuck",
									"Earl of Arms",
									"Easy Sweep",
									"Eerie Mizzen",
									"ElactixNova",
									"Elder Pogue",
									"Electric Player",
									"Electric Saturn",
									"Ember Rope",
									"Esquire",
									"ExoticAlpha",
									"EyeShooter",
									"Fabulous",
									"Fast Draw",
									"FastLane",
									"Father Abbot",
									"FenderBoyXXX",
									"Fennel Dove",
									};
		
		
		CurrentPlayerName = this.GetIdentity().GetName();
		if (CurrentPlayerName.Contains("Survivor"))
		{
			NewName = preSetNames.GetRandomElement();
			Print("Player: ["+ this.GetIdentity().GetPlainId() +"]" + " has deafult name! Changning to "+NewName);
			ChachedSB.SetPlayerName(NewName);
		}
	}

	override void OnConnect()
    {
        Debug.Log("Player connected:"+this.ToString(),"Connect");
        ref SurvivorBase ChachedSB = this;
		ChachedSB.SetPlayerID(this.GetIdentity().GetPlainId());
				
		CheckPlayerName(); 
		
		string cmdLine;
		if (GetGame().CommandlineGetParam("SessionFeed",cmdLine))
		{
			string Message = "Player " + ChachedSB.GetPlayerName() + " Joined!";
			GetGame().ChatPlayer(1,Message); //Global Chat
		}

        KillTracker = new ScoreTrackerHandle;
        KillTracker.PlayerConnectHandler(ChachedSB.GetPlayerID(), ChachedSB.GetPlayerName());
		//-----Kill Activiy shit-----
		if ( !FileExist(KillLogFileLocation) ) 
		{
			FileHandle KillLogs = OpenFile(KillLogFileLocation, FileMode.WRITE);
			FPrintln(KillLogs,"          -------------- KILL ACTIVITY LOGS v0.1 By DaOne --------------"); //Print Start Line
			FPrintln(KillLogs,"-------------- TIME CREATED: "+ GetDate() +"--------------"); //Print Start Line
			CloseFile(KillLogs);
		}
        // NEW STATS API
        StatRegister("playtime");
        StatRegister("dist");
    }
	
	void OnDisconnect()
	{
		Debug.Log("Player disconnected:"+this.ToString(),"Connect");
		ref SurvivorBase ChachedSB = this;
		string cmdLine;
		if (GetGame().CommandlineGetParam("SessionFeed",cmdLine))
		{
			string Message = "Player " + ChachedSB.GetPlayerName() + " Disconnected!";
			GetGame().ChatPlayer(1,Message); //Global Chat
		}
		
		
		// force update of the stats
		// if player disconnect too soon, UpdatePlayersStats() is not called
		StatUpdateByTime("playtime");
		StatUpdateByPosition("dist");
		StatSyncToClient();
		
		ScriptAnalytics.PlayerDisconnected( g_Game.GetDatabaseID(), "Disconnect" );
		m_AnalyticsTimer.Stop();
		UpdatePlayerMeasures();
	}

    override void EEKilled( Object killer )
    {
		FileHandle KillLogs;
		string TimeStamp;
        ref SurvivorBase SurvivorKilled = this;
        ref SurvivorBase SurvivorKiller = killer;
        ref Man KillerDude = killer;
		
		string KillerName = SurvivorKiller.GetPlayerName();
		string KilledName = SurvivorKilled.GetPlayerName();
		float distance;
		int Rounded;
		string Message;
		
		//-------------------KillTracker-------------------
        if (GetGame().IsServer()) {
			
		   if (KillerDude.IsMan() && SurvivorKiller.GetPlayerID() != SurvivorKilled.GetPlayerID()) 
		   {
			    KillTracker.KillHandler(SurvivorKiller.GetPlayerID());  //Record Killer kill
				
				distance = vector.Distance(SurvivorKilled.GetPosition(),SurvivorKiller.GetPosition());
				Rounded = Math.Round(distance);
				
				Message = KillerName + " Killed " + KilledName + " with " + "["+ SurvivorKiller.GetHumanInventory().GetEntityInHands().GetDisplayName() +"]" + " ("+ Rounded.ToString() + "m" +")";
				GetGame().ChatPlayer(1,Message); //Global Chat
				
				if ( FileExist(KillLogFileLocation) ) 
				{
					KillLogs = OpenFile(KillLogFileLocation, FileMode.APPEND);
					TimeStamp = GetDate();
					FPrintln(KillLogs,"\n");
					FPrintln(KillLogs,"-->TIME STAMP: "+ TimeStamp +" ===>: "+Message);
					FPrintln(KillLogs,"---------------------------------------------------------");
					CloseFile(KillLogs);
				}

		   }else if (KillerDude.IsMan() && SurvivorKiller.GetPlayerID() == SurvivorKilled.GetPlayerID())  //SUICIDE
		   {
			   
				Message = "Player: " + KilledName + " Committed Suicide";
				GetGame().ChatPlayer(1,Message); //Global Chat
				
				if ( FileExist(KillLogFileLocation) ) 
				{
					KillLogs = OpenFile(KillLogFileLocation, FileMode.APPEND);
					TimeStamp = GetDate();
					FPrintln(KillLogs,"\n");
					FPrintln(KillLogs,"-->TIME STAMP: "+ TimeStamp +" ===>: "+Message);
					FPrintln(KillLogs,"---------------------------------------------------------");
					CloseFile(KillLogs);
				}
		   }
          
		  KillTracker.DeathHandler(SurvivorKilled.GetPlayerID()); //Record Player death
        }

        if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT ) {
            // @NOTE: this branch does not happen, EEKilled is called only on server
            if ( GetGame().GetPlayer() == this ) {
                super.EEKilled( killer );
            }
            if (GetHumanInventory().GetEntityInHands())
                GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ServerDropEntity,1000,false,( GetHumanInventory().GetEntityInHands() ));
        }
        else if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER)//server
        {        
            if( GetBleedingManager() ) delete GetBleedingManager();
			
            if( GetHumanInventory().GetEntityInHands() )
			{
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ServerDropEntity,1000,false,( GetHumanInventory().GetEntityInHands() ));
			}

        }

        if ( GetSoftSkillManager() ) {
            delete GetSoftSkillManager();
        }

        GetStateManager().OnPlayerKilled();

        // kill character in database
        if (GetHive()) {
            GetHive().CharacterKill(this);
        }
    }
	
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, string component, string ammo, vector modelPos)
	{
		super.EEHitBy(damageResult, damageType, source, component, ammo, modelPos);
		
		string AdminGmodeCheck, SafeZoneGmodeCheck;
	    ref SurvivorBase SBPlayer = this;

		string GUID = SBPlayer.GetPlayerID();
		g_Game.GetProfileString("AdminGmode"+GUID,AdminGmodeCheck);
		g_Game.GetProfileString("SafeZoneStatus"+GUID,SafeZoneGmodeCheck);
		
		if (AdminGmodeCheck == "true" || SafeZoneGmodeCheck == "true")
		{
			if (SafeZoneGmodeCheck == "true") //SafeZone
			{
				if ( damageResult != null )
				{
					float HlthdmgDone = damageResult.GetDamage(component, "");
					float BlddmgDone  = damageResult.GetDamage(component, "Blood");
					float ShcdmgDone  = damageResult.GetDamage(component, "Shock");
					//We dont want to give players full heath on each hit, as that would make safezone a heal centre..
					SetHealth( GetHealth("","") + HlthdmgDone );
					SetHealth( "","Blood", GetHealth("","Blood") + BlddmgDone);
					SetHealth( "","Shock", GetHealth( "","Shock") + ShcdmgDone);
				}
				
			}
			else if (AdminGmodeCheck == "true") //For admins give heal on each hit.
			{
				SetHealth( GetMaxHealth( "", "") );
				SetHealth( "","Blood", GetMaxHealth( "", "Blood" ) );
				SetHealth( "","Shock", GetMaxHealth( "","Shock") );
				GetStatStamina().Set(1000);
				GetStatEnergy().Set(1000);
				GetStatWater().Set(1000);
				GetStatStomachSolid().Set(300);		
				GetStatStomachWater().Set(300);
				GetStatStomachEnergy().Set(300);
				GetStatHeatComfort().Set(0);
			}
		}
		else
		{
			if( damageResult != null && damageResult.GetDamage(component, "Shock") > 0)
			{
				m_LastShockHitTime = GetGame().GetTime();
			}
			
			//new bleeding computation
			//---------------------------------------
			if ( damageResult != null && GetBleedingManager() )
			{
				float dmg = damageResult.GetDamage(component, "Blood");
				GetBleedingManager().ProcessHit(dmg, component, ammo, modelPos);
			}
			//---------------------------------------
		}
	}
}