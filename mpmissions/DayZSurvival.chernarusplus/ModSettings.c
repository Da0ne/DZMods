m_CustomLoadouts  	  = true;  //Set to true to Spawn Players with custom loadouts, set false to spawn with Vanilla DayZ gear
m_StaticLoadouts	  = true;  //TO USE U MUST SET --> 'm_CustomLoadouts' to true! (picks random loadout preset you have created using the admin command /export )
m_RandomizedLoadouts  = false; //TO USE U MUST SET --> 'm_CustomLoadouts' to true! (picks random item to spawn on player from each catagory in 'LoaOuts\RandomlyGenerated')

m_SpawnArmed 	      = false; //Spawn fresh spawns with a pistol, weapon types can be changed in 'ScriptedMods\LoadOuts\wpnOnSpawn' All the way at the bottom in fucntion 'StartingEquipSetup'
m_StaminaStatus       = true;  //set to true to disable stamina
m_SafeZone	          = true;  //set true to Enable Safe Zone
m_CustomBuildings     = true;  //Spawns the buildings you add in file BuildingSpawner.c
m_SessionFeed	      = true;  //Set to true to enable Disconnect/Connect Messages
m_ZedHordes	          = true;  //Random zombie hordes that spawn on the map (The tunables for this mod can be found in 'InfectedHordes.c')
m_ProxyExportMode     = false; //Set to ture to export a new loot positions xml (export can be found in your Storage folder).
m_LogInTimerLength    = 1;     //in seconds the spawn timer when players login!


m_Debugmode   		  = false; //Set true to disable db for faster server loading and for testing purposes

/*Paths:: !!JUST DONT MESS AROUND WITH THESE UNLESS YOU KNOW WHAT YOU ARE DOING!!*/
m_RandomLoadoutsPath = "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\LoadOuts\\RandomlyGenerated\\";
m_AdminListPath      = "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\";
