vector SAFEZONE_LOACTION = "7500 0 7500"; //Map coords (position of the safe zone)
float  SAFEZONE_RADIUS   = 500; //In meter
string ENTRY_MESSAGE     = "Welcome to The SafeZone! Godmode ENABLED!";
string EXIT_MESSAGE      = "You Have Left The SafeZone! Godmode DISABLED!";

//Runs every tick (Stat time tick!) IMPORANT: Does reduce about 120 FPS when server is High-Full Pop!
void SafeZoneHandle(PlayerBase player)
{
	float distance;
	string ZoneCheck, GUID;
	GUID = player.GetIdentity().GetPlainId(); //Steam 64
	Param1<string> Msgparam;

	distance = vector.Distance(player.GetPosition(),SAFEZONE_LOACTION);
	if (distance <= SAFEZONE_RADIUS) //Player Inside Zone
	{
		g_Game.GetProfileString("SafeZoneStatus"+ GUID, ZoneCheck);
		if (ZoneCheck == "true") //Already in zone
		{
			return;
		}
		else
		{
			g_Game.SetProfileString("SafeZoneStatus"+ GUID, "true");
			Msgparam = new Param1<string>( ENTRY_MESSAGE );
			GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, player.GetIdentity());
		}
	}
	else if (distance > SAFEZONE_RADIUS) //Plauer Outside of Zone
	{
		g_Game.GetProfileString("SafeZoneStatus"+ GUID, ZoneCheck);
		if (ZoneCheck == "false")
		{
			return;
		}
		else
		{
			g_Game.SetProfileString("SafeZoneStatus"+ GUID, "false");
			Msgparam = new Param1<string>( EXIT_MESSAGE );
			GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, player.GetIdentity());
		}
	}
}