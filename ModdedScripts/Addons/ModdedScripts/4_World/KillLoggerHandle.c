static string FileLocation = "$profile:ScoreTracker.json";

class ScoreTrackerHandle
{
    ref map<string, map<string, string>> JsonData = new map<string, map<string, string>>();
	
	//------------------------------------------
    map<string, map<string, string>> LoadData()
    {
        ref map<string, map<string, string>> data = new map<string, map<string, string>>();

        if ( FileExist(FileLocation) ) 
		{
            JsonFileLoader<map<string, map<string, string>>>.JsonLoadFile(FileLocation, data);
        } 
		else 
		{
            JsonFileLoader<map<string, map<string, string>>>.JsonSaveFile(FileLocation, data);
        }

        return data;
    }
	//------------------------------------------
	void PlayerConnectHandler(string GUID, string name)
    {
        JsonData = LoadData();
        ref map<string, string> KillData = new map<string, string>();

        KillData.Set("InGameName", name);
        JsonData.Insert(GUID, KillData);
        Save( JsonData );
    }
	//------------------------------------------

    void KillHandler(string GUID)
    {
        JsonData = LoadData();
        ref map<string, string> KillData = new map<string, string>();

        if (JsonData.Contains(GUID)) {
        KillData = JsonData.Get(GUID);
        if (KillData.Contains("Kills")) {
                int killCount = KillData.Get("Kills").ToInt();
                killCount = killCount + 1;
                KillData.Set("Kills", killCount.ToString());
            } else {
                KillData.Set("Kills", "1");
            }
        } else {
            KillData.Set("Kills", "1");
        }

        JsonData.Insert( GUID, KillData );
        Save( JsonData );
    }
	
    void DeathHandler(string GUID)
    {
        JsonData = LoadData();
        ref map<string, string> KillData = new map<string, string>();

        if (JsonData.Contains(GUID)) {

         KillData = JsonData.Get(GUID);
         if ( KillData.Contains("Deaths") ) {
             int DeathCount = KillData.Get("Deaths").ToInt();
             DeathCount = DeathCount + 1;
             KillData.Set("Deaths", DeathCount.ToString());
          } 
		  else 
		  {
             KillData.Set("Deaths", "1");
          }
        } 
		else 
		{
            KillData.Set("Deaths", "1");
        }

        JsonData.Insert(GUID, KillData);
        Save( JsonData );
    }

    void Save(map<string, map<string, string>> JsonData)
    {
        JsonFileLoader<map<string, map<string, string>>>.JsonSaveFile(FileLocation, JsonData);
    }
}
