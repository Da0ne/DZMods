class SpawnPointsManager extends VPPModuleManager
{	
	float DEFAULT_COOL_DOWN_INTERVAL = 900.0; //20 minutes
	
	string STR_FILE_PATH = "$profile:SpawnPoints.json";
	ref map<string, ref map<string,float>> m_MapSpawnPoints;

	void SpawnPointsManager(  DayZSurvival serverMission )
	{
		m_MapSpawnPoints = new map<string, ref map<string,float>>;
		if (FileExist(STR_FILE_PATH))
        {
        	//Hotfix...dont ask why. (ref problems)
        	GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.CompilePoints, 1200, false);
        }
        else
        {
        	MakeDefualtSpawnPoints();
        	Print("Custom Spawn points not found....Loading deafult template!");
        }
	}

	void ~SpawnPointsManager()
	{

	}

	override void Init()
	{
		
	}

	override void onUpdate(float timeslice)
	{

	}

	void CompilePoints()
	{
		ref map<string, map<string,float>> m_Map = new map<string, map<string,float>>;
        JsonFileLoader<ref map<string, map<string,float>>>.JsonLoadFile( STR_FILE_PATH, m_Map );

		for (int i = 0; i < m_Map.Count(); ++i)
	    {
	    	string TownName = m_Map.GetKey(i);
    		map<string,float> PosInfo = m_Map.Get(TownName);
	        m_MapSpawnPoints.Insert(TownName,PosInfo);
	    }
	    Print("Loaded "+ m_MapSpawnPoints.Count() + " Spawn Points!");
	}

	ref map<string, ref map<string,float>> GetMap()
	{
		return m_MapSpawnPoints;
	}

	vector GetPosByName(string Name, int key)
	{
	    for (int i = 0; i < m_MapSpawnPoints.Count(); ++i)
	    {
	    	string TownName = m_MapSpawnPoints.GetKey(i);
	    	if (TownName == Name)
	    	{
	    		ref map<string,float> PosInfo = m_MapSpawnPoints.Get(TownName);
		        for (int x = 0; x < PosInfo.Count(); ++x)
		        {
		          string posStr  = PosInfo.GetKey(x);
			      float cooldown = PosInfo.Get(posStr);
		        }
	    	}
	    }
		return posStr.ToVector();
	}

	ref array<string> GetAllSpawnsNames()
	{
		ref array<string> Locations = new array<string>;
	    for (int i = 0; i < m_MapSpawnPoints.Count(); ++i)
	    {
	    	string PointName = m_MapSpawnPoints.GetKey(i);
	    	Locations.Insert(PointName);
	    }
	    Print("Total Points: "+Locations.Count().ToString());
		return Locations;
	}

	vector GetRandomSpawnPoint()
	{
		int TotalPoints = m_MapSpawnPoints.Count();
		int oRandom     = Math.RandomIntInclusive(0,TotalPoints);

		string TownName = m_MapSpawnPoints.GetKey(oRandom);
		ref map<string,float> m_PosInfo = m_MapSpawnPoints.Get(TownName);

	    for (int i = 0; i < m_PosInfo.Count(); ++i)
	    {
	       string posStr = m_PosInfo.GetKey(i);
	   	   float timer   = m_PosInfo.Get(posStr);
	    }
		return posStr.ToVector();
	}

	float GetCooldownInterval()
	{
		return DEFAULT_COOL_DOWN_INTERVAL;
	}

	void MakeDefualtSpawnPoints()
	{
		ref map<string,float> m_Position = new map<string,float>;
		m_Position.Insert("8294.81 0 2915.43",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("6052.60 0 1868.23",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("8212.17 0 2781.53",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("12480.87 0 3567.60",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("6133.28 0 2021.43",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13439.89 0 5374.18",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("11846.80 0 3477.80",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("10820.40 0 2257.40",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("11914.30 0 3402.00",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("9691.70 0 1750.40",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("9529.70 0 1791.20",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("9193.700 0 1935.70",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("14047.80 0 11338.82",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("11049.30 0 2801.60",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("6218.78 0 2113.35",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("11824.08 0 3381.01",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("10875.80 0 2518.90",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13374.40 0 6454.30",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13426.60 0 5747.30",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13440.40 0 5624.23",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13429.40 0 6679.20",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13441.60 0 5262.20",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13485.64 0 5894.26",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("10427.39 0 1921.14",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("14410.37 0 13316.80",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("12004.95 0 3422.10",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("8491.93 0 2458.95",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("15135.10 0 13901.10",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("8391.22 0 2412.53",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("8285.94 0 2404.75",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("14749.70 0 13248.70",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("14586.68 0 13343.90",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("8057.56 0 2807.67",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("15017.80 0 13892.40",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13516.61 0 11061.47",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13207.05 0 10428.54",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("10917.01 0 2615.05",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("8340.27 0 2558.35",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("8659.26 0 2220.42",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("12991.96 0 8494.20",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13262.80 0 7225.80",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("12978.90 0 9727.80",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("12868.70 0 9054.50",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("12354.50 0 3480.00",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("12929.70 0 8578.30",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13084.90 0 7938.60",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13169.18 0 7491.12",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("12917.30 0 9356.60",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("12889.90 0 8792.80",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13048.10 0 8357.60",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13607.30 0 11232.61",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("14326.70 0 13012.22",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("10567.46 0 2031.55",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("7080.94 0 2482.06",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("8830.18 0 2145.05",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("7430.73 0 2589.35",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13542.07 0 6088.35",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13311.50 0 7028.93",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("12899.06 0 9182.89",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("10647.47 0 2100.81",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13076.36 0 8045.23",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("10862.03 0 2380.13",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("9814.53 0 1781.71",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13190.13 0 10227.21",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13053.61 0 9536.82",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("12215.67 0 3425.20",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("7173.87 0 2555.93",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("14263.27 0 13033.67",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("9875.13 0 1763.90",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("9107.57 0 1918.01",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13082.70 0 8112.25",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13427.16 0 5547.37",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13084.31 0 9648.43",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13485.84 0 5996.81",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("9621.27 0 1722.75",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13246.81 0 10595.75",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13306.58 0 10703.12",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("14499.25 0 13309.64",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("12954.36 0 8721.21",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13001.47 0 9497.56",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("11085.15 0 2918.78",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13227.35 0 7366.54",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("11083.43 0 2731.88",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13000.41 0 9809.74",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("12997.78 0 9380.88",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13572.62 0 11127.85",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13227.64 0 10298.00",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("14339.32 0 12861.29",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13528.04 0 6464.11",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("14606.92 0 13275.15",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13531.71 0 6155.58",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("8572.02 0 2302.69",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13300.82 0 7123.74",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13488.46 0 6538.60",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13127.29 0 8337.39",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("12930.02 0 9276.75",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13244.69 0 10138.84",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("14326.32 0 13333.03",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13536.13 0 6229.02",DEFAULT_COOL_DOWN_INTERVAL);
		m_Position.Insert("13587.80 0 6026.50",DEFAULT_COOL_DOWN_INTERVAL);

	    for (int i = 0; i < m_Position.Count(); ++i)
	    {
	    	string LocationName   = "Costal-" + i.ToString();

	    	string positionStr    = m_Position.GetKey(i);
	    	float  CoolDown       = m_Position.Get(positionStr);

	    	ref map<string,float> posInfo = new map<string,float>;
	    	posInfo.Insert(positionStr,CoolDown);

	    	m_MapSpawnPoints.Insert(LocationName,posInfo);
	    }
	    JsonFileLoader<ref map<string, ref map<string,float>>>.JsonSaveFile( STR_FILE_PATH, m_MapSpawnPoints );
	}
}
