class BuildingSpawner
{
	void Init()
	{
		Print("BuildingSpawner:: Spawning custom scripted buildings....");
		Object obj;
		obj = GetGame().CreateObject( "Land_Airfield_Hangar_Green", "11990.633789 146.099136 12485.503906", false, true );
		obj.SetOrientation("-157.000046 -1.000000 -0.000000");
		obj.SetDirection(obj.GetDirection());
	}
};