int TIME_BT_EACH_MSG = 60000; //in ms
int TIME_INTERVAL = TIME_BT_EACH_MSG + Math.RandomIntInclusive(5000,15000); //5 sec - 15 sec Random addition to TIME_BT_EACH_MSG

void CustomMOTD()
{
   TStringArray Messages = {"Welcome to My Server!","DayZ Modded Survival By DaOne"};
   GetGame().ChatPlayer(5,Messages.GetRandomElement());
}