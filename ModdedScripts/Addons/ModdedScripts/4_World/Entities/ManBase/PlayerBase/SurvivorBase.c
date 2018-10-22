modded class SurvivorBase
{
	private string PlayerName = "null";
    private string PlayerID = "null";
	
	void SetPlayerID(string Identity)
	{
		PlayerID = Identity;
	}

    void SetPlayerName(string name)
    {
        PlayerName = name;
    }

    string GetPlayerID()
    {
        return PlayerID;
    }
	
	string GetPlayerName()
    {
        return PlayerName;
    }
}