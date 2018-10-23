
	ref map<string, string>	m_AdminList = new map<string, string>; //UID, name
	ref map<string, vector>	m_TPLocations = new map<string, vector>; //name of town, pos
	
	bool m_FreeCamera;
    bool m_IsDebugRunning = false;

	void AdminTool()
	{
		Print("Class AdminTool:: Loading Scripted Mods...");

		//Add Towns to TP array
		m_TPLocations.Insert( "Severograd", "8428.0 0.0 12767.1" );
        m_TPLocations.Insert( "Krasnostav", "11172.0 0.0 12314.1" );
        m_TPLocations.Insert( "Mogilevka", "7583.0 0.0 5159.4" );
        m_TPLocations.Insert( "Stary Sobor", "6072.0 0.0 7852.5" );
        m_TPLocations.Insert( "Msta", "11207.0 0.0 5380.54" );
        m_TPLocations.Insert( "Vybor", "3729.51 0.0 8935.56" );
        m_TPLocations.Insert( "Gorka", "9787.1 0.0 8767.19" );
        m_TPLocations.Insert( "Solnicni", "13393.1 0.0 6159.8" );
        m_TPLocations.Insert( "Airport Vybor", "4828.9 0.0 10219.5" );
        m_TPLocations.Insert( "Airport Balota", "4791.53 0.0 2557.47" );
        m_TPLocations.Insert( "Airport Krasnostav", "12004.3 0.0 12655.3" );
        m_TPLocations.Insert( "Chernogorsk Center", "6893.07 0.0 2618.13" );
        m_TPLocations.Insert( "Chernogorsk West", "6546.03 0.0 2317.56" );
        m_TPLocations.Insert( "Chernogorsk East", "7105.76 0.0 2699.53" );
        m_TPLocations.Insert( "Elektrozavodsk Center", "10459.8 0.0 2322.72" );
        m_TPLocations.Insert( "Elektrozavodsk East", "10414.5 0.0 2569.42" );
        m_TPLocations.Insert( "Berezino Center", "12296.9 0.0 9470.51" );
        m_TPLocations.Insert( "Berezino West", "12035.4 0.0 9143.49" );
        m_TPLocations.Insert( "Berezino East", "12932.3 0.0 10172.7" );
        m_TPLocations.Insert( "Svetlojarsk Center", "13835.3 0.0 13202.3" );	
        m_TPLocations.Insert( "Zelenogorsk Center", "2660.99 0.0 5299.28" );
        m_TPLocations.Insert( "Zelenogorsk West", "2489.45 0.0 5080.41" );
	}

	int TeleportAllPlayersTo(PlayerBase PlayerAdmin)
	{
		//Collectes Arry of players
		array<Man> players = new array<Man>;
	    GetGame().GetPlayers( players );

	    vector AdminPos;
	    AdminPos = PlayerAdmin.GetPosition();

	    for ( int i = 0; i < players.Count(); ++i )
		{
			PlayerBase Target = players.Get(i);
			Target.SetPosition( AdminPos );
		}
		return i;
	}

	void oSpawnItemFunc(bool ground, PlayerBase player, string ClassName)
	{
		EntityAI item;
		ItemBase itemBs

		vector NewPosition;
		vector OldPosition;

		if (ground)
		{
			OldPosition = player.GetPosition();

			NewPosition[0] = OldPosition[0] + 1.5;
			NewPosition[1] = OldPosition[1] + 0.1;
			NewPosition[2] = OldPosition[2] + 1.5;

			item = GetGame().CreateObject( ClassName, NewPosition, false, true );
		}else{

			item = player.GetInventory().CreateInInventory( ClassName );
			itemBs = ItemBase.Cast(item);	
			itemBs.SetQuantity(1);
		}
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

	//---------------------------------------------------------------------------------
	override void OnEvent(EventType eventTypeId, Param params) 
	{
		super.OnEvent(eventTypeId,params);

		PlayerIdentity identity;
		PlayerBase player;
		int counter = 0;

		switch(eventTypeId)
		{
			case ChatMessageEventTypeID:
	        ChatMessageEventParams chat_params = ChatMessageEventParams.Cast( params );

			        array<Man> players = new array<Man>;
			    	GetGame().GetPlayers( players );

					int length = chat_params.param3.Length();
					string strSub, strCommand, strCodeline, strMessage, selectedPName;

					PlayerBase selectedPlayer;
					PlayerIdentity selectedIdentity;

					Param1<string> Msgparam;
					if (chat_params.param1 == 0 && chat_params.param2 != "") { //trigger only when channel is Global == 0 and Player Name does not equal to null

	                for ( int i = 0; i < players.Count(); ++i )
	                {
						PlayerBase playerAdmin = players.Get(i);
						PlayerIdentity identityT = playerAdmin.GetIdentity();
						string PlayerUID = identityT.GetPlainId();
						string GUID = playerAdmin.GetIdentity().GetPlainId(); //Steam 64

							if( m_AdminList.Contains(PlayerUID) && playerAdmin.GetIdentity().GetName() == chat_params.param2)
							{
									if (length > 4)
					                {
					                	strSub = chat_params.param3.Substring(0,4);
					                	string strTpCheck = chat_params.param3.Substring(0,5);
					                	string strLength6 = chat_params.param3.Substring(0,6);

					                	if (strLength6 == "/strip")
					                	{
					                		selectedPName = chat_params.param3.Substring(7,length);
					                		if ( selectedPName != "" )
					                		{
					                			for ( int a = 0; a < players.Count(); ++a )
					                			{
					                				selectedPlayer = players.Get(a);
													selectedIdentity = selectedPlayer.GetIdentity();
					                				if ( selectedIdentity.GetName() == selectedPName )
					                				{
														selectedPlayer.RemoveAllItems();
														Msgparam = new Param1<string>( "Player Stripped!" );
					                				    GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerAdmin.GetIdentity());
													}
												}
											}
					                	}

					                	if (strTpCheck == "/tppm")
					                	{
					                		selectedPName = chat_params.param3.Substring(6,length);
					                		if ( selectedPName != "" )
					                		{
					                			for ( int zm = 0; zm < players.Count(); ++zm )
					                			{
					                				selectedPlayer = players.Get(zm);
					                				selectedIdentity = selectedPlayer.GetIdentity();
					                				if ( selectedIdentity.GetName() == selectedPName )
					                				{
					                				   playerAdmin.SetPosition(selectedPlayer.GetPosition());

					                				   strMessage = "You were teleported to player " + selectedPName;
					                				   Msgparam = new Param1<string>( strMessage );
					                				   GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerAdmin.GetIdentity());
					                				}
					                			}
					                		}
					                	}

					                	if (strSub == "/tpp")
					                	{
					                		selectedPName = chat_params.param3.Substring(5,length);
					                		if ( selectedPName != "" )
					                		{
					                			for ( int z = 0; z < players.Count(); ++z )
					                			{
					                				selectedPlayer = players.Get(z);
					                				selectedIdentity = selectedPlayer.GetIdentity();
					                				if ( selectedIdentity.GetName() == selectedPName )
					                				{
					                				   selectedPlayer.SetPosition(playerAdmin.GetPosition());

					                				   Msgparam = new Param1<string>( "You were teleported by the admin!" );
					                				   GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, selectedIdentity);
					                				  
					                				   strMessage = "Player " + selectedPName + " was teleported to your location!";
					                				   Msgparam = new Param1<string>( strMessage );
					                				   GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerAdmin.GetIdentity());
					                				}
					                			}
					                		}
					                	}

					                	if (strTpCheck == "/tpto")
					                	{
					                		vector position = "0 0 0";
					                		string selectedTown = chat_params.param3.Substring(6,length);
					                		if (m_TPLocations.Contains(selectedTown))
					                		{
					                			m_TPLocations.Find( selectedTown, position );

					                			vector ofixPlayerPos;
												ofixPlayerPos[0] = position[0];
												ofixPlayerPos[2] = position[2];

												ofixPlayerPos = SnapToGround( ofixPlayerPos );

					                			playerAdmin.SetPosition(ofixPlayerPos);

					                			strMessage = "Teleported To Location: " + selectedTown;
					                			Msgparam = new Param1<string>( strMessage );
					                			GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerAdmin.GetIdentity());
					                		}
					                		else
					                		{
					                			strMessage = "Teleport Failed! Location: " + selectedTown + " Is not on the list!";
					                			Msgparam = new Param1<string>( strMessage );
					                			GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerAdmin.GetIdentity());
					                		}
					                	}

					                	if (strSub == "/spi")
					                	{
					                		strCodeline = chat_params.param3.Substring(5,length);
					                		oSpawnItemFunc(false,playerAdmin,strCodeline);
					                		strMessage = "Admin Commands: Item " + strCodeline + " Added in Inventory!";
					                		Msgparam = new Param1<string>( strMessage );
					                		GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerAdmin.GetIdentity());
					                	}

					                	if (strSub == "/spg")
					                	{
					                		strCodeline = chat_params.param3.Substring(5,length);
					                		oSpawnItemFunc(true,playerAdmin,strCodeline);
					                		strMessage = "Admin Commands: Item " + strCodeline + " Spawned around you!";
					                		Msgparam = new Param1<string>( strMessage );
					                		GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerAdmin.GetIdentity());
					                	}

					                	if (strSub == "/tpc")
					                	{
					                		strCodeline = chat_params.param3.Substring(5,length);
					                		vector tpPos = strCodeline.ToVector();

					                		vector fixPlayerPos;
											fixPlayerPos[0] = tpPos[0];
											fixPlayerPos[2] = tpPos[2];

											fixPlayerPos = SnapToGround( fixPlayerPos );
											playerAdmin.SetPosition(fixPlayerPos);

											strMessage = "Teleported to:: " + tpPos;
											Msgparam = new Param1<string>( strMessage );
					                		GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerAdmin.GetIdentity());
					                	}
					                }
									
								//Less Cluttred Only Simple commands with the switch case are in 'AdminToolExtended.c'
								#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\AdminToolExtended.c"
						}
	                }
	            }
	        break;
		}
	}