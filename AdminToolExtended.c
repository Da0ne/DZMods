						switch(chat_params.param3) {
									case "/ammo":
									EntityAI CurrentWeapon = playerAdmin.GetHumanInventory().GetEntityInHands();
									if( CurrentWeapon )
										{
											CurrentWeapon.SetHealth( CurrentWeapon.GetMaxHealth( "", "" ) );
											Magazine foundMag = ( Magazine ) CurrentWeapon.GetAttachmentByConfigTypeName( "DefaultMagazine" );
											if( foundMag && foundMag.IsMagazine())
											{
												foundMag.ServerSetAmmoMax();
											}
																				
											Object Suppressor = ( Object ) CurrentWeapon.GetAttachmentByConfigTypeName( "SuppressorBase" );
											if( Suppressor )
											{
												Suppressor.SetHealth( Suppressor.GetMaxHealth( "", "" ) );
											}
											string displayName = CurrentWeapon.ConfigGetString("displayName");

											Msgparam = new Param1<string>( "Weapon " + displayName + "Reloaded and Repaired" );
											GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerAdmin.GetIdentity());
										}
									break;
									
									case "/freecam":
										 PlayerBase pBody = playerAdmin;

										 if (m_FreeCamera)
											{
												GetGame().SelectPlayer(playerAdmin.GetIdentity(), pBody);
												m_FreeCamera = false;
												Msgparam = new Param1<string>( "Exiting FreeCam!" );
												GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerAdmin.GetIdentity());
											}
											else
											{
												GetGame().SelectPlayer(playerAdmin.GetIdentity(), NULL);
												GetGame().SelectSpectator(playerAdmin.GetIdentity(), "freedebugcamera", playerAdmin.GetPosition());
												m_FreeCamera = true;
												Msgparam = new Param1<string>( "FreeCam Spawned!" );
												GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerAdmin.GetIdentity());
											}

									break;

									case "/debug":
										  if (m_IsDebugRunning)
											 {
												Msgparam = new Param1<string>( "DeBug Monitor (Status Monitor) Disabled!" );
												GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerAdmin.GetIdentity());
												GetGame().SetDebugMonitorEnabled(0);
												m_IsDebugRunning = false;
											 }
											 else
											 {
												Msgparam = new Param1<string>( "DeBug Monitor (Status Monitor) Enabled!" );
												GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerAdmin.GetIdentity());
												GetGame().SetDebugMonitorEnabled(1);
												m_IsDebugRunning = true;
											 }

									break;

									case "/nighttime":

										GetGame().GetWorld().SetDate( 1988, 5, 23, 22, 0 );
										Msgparam = new Param1<string>( "NIGHT TIME!!" );
										GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerAdmin.GetIdentity());
									break;

									case "/daytime":

										GetGame().GetWorld().SetDate( 1988, 5, 23, 12, 0 );
										Msgparam = new Param1<string>( "DAY TIME!!" );
										GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerAdmin.GetIdentity());
									break;
						
									case "/heal":
										 Msgparam = new Param1<string>( "Player Healed!" );
										 GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerAdmin.GetIdentity());
										 playerAdmin.SetHealth( playerAdmin.GetMaxHealth( "", "" ) );
										 playerAdmin.SetHealth( "","Blood", playerAdmin.GetMaxHealth( "", "Blood" ) );
									break;

									case "/kill":
										  playerAdmin.SetHealth(0);
									break;
																		
									case "/tpalltome":
										 int tpCount = TeleportAllPlayersTo(playerAdmin);
										 string msgc = "All " + tpCount.ToString() + " Players Teleported to my POS!";
										 Msgparam = new Param1<string>( msgc );
										 GetGame().RPCSingleParam(playerAdmin, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerAdmin.GetIdentity());
									break;
																		
									case "/killall":
										 for ( int ig = 0; ig < players.Count(); ++ig )
											 {
												PlayerBase Target = players.Get(ig);
												if ( (Target.GetIdentity()) == identityT )
													{
																					
													}else{

														Target = players.Get(ig);
														Target.SetHealth(0);
													}

											 }
									break;
									
									case "/spawncar":
									EntityAI MyV3S;

									vector NewPosition;
									vector OldPosition;

									OldPosition = playerAdmin.GetPosition();

									NewPosition[0] = OldPosition[0] + 1.5;
									NewPosition[1] = OldPosition[1] + 0.2;
									NewPosition[2] = OldPosition[2] + 1.5;

									MyV3S = GetGame().CreateObject( "OffroadHatchback", NewPosition, false, true, true );
																			
									MyV3S.GetInventory().CreateAttachment("HatchbackHood");
									MyV3S.GetInventory().CreateAttachment("HatchbackTrunk");
									MyV3S.GetInventory().CreateAttachment("HatchbackDoors_CoDriver");
									MyV3S.GetInventory().CreateAttachment("HatchbackWheel");
									MyV3S.GetInventory().CreateAttachment("HatchbackWheel");
									MyV3S.GetInventory().CreateAttachment("HatchbackWheel");
									MyV3S.GetInventory().CreateAttachment("HatchbackWheel");
									MyV3S.GetInventory().CreateAttachment("SparkPlug");
									MyV3S.GetInventory().CreateAttachment("EngineBelt");
									MyV3S.GetInventory().CreateAttachment("CarBattery");
									break;
								}