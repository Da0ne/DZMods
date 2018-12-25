#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Modules\\ServerMission\\DayZSurvival.c"

Mission CreateCustomMission(string path)
{
	return new DayZSurvival();
}

void main()
{
	//INIT WEATHER BEFORE ECONOMY INIT------------------------
	Weather weather = g_Game.GetWeather();

	weather.MissionWeather(false);    // false = use weather controller from Weather.c

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
	weather.GetRain().Set( 0, 0, 1);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);
	
	weather.GetRain().SetLimits( 0, 0.1 );

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year;
	int month;
	int day;
	int hour;
	int minute;

	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

    if (((month <= 9) && (day < 20)) || ((month >= 10) && (day > 20)))
    {
        month = 9;
        day = 20;
		
		GetGame().GetWorld().SetDate(year, month, day, hour, minute);
	}
	
	//-----------------------X-mas
	array<vector> treePositions = { "6560.29 0 2462.12",
									"1652.66 0 14230.71",
									"3801.06 0 8847.76",
									"9442.32 0 8829.03",
									"7903.16 0 12576.52",
									"11617.75 0 14663.98",
									"12830.08 0 10115.18",
									"11221.94 0 12225.89",
									"3471.93 0 12988.33",
									"13933.42 0 13228.44",
									"12022.64 0 9082.89",
									"10468.54 0 2373.16",
									"2725.48 0 5288.75",
	};
	

	Object treeEntity;
	for ( int i=0; i < treePositions.Count(); i++ )
	{
		vector treePos = treePositions[i];
		float posY = GetGame().SurfaceY(treePos[0], treePos[2]);
		treeEntity = GetGame().CreateObject("ChristmasTree", Vector( treePos[0], posY, treePos[2]), false);

	}
}
