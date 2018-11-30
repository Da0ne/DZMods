class SpawnedBuilding
{
	string m_name;
	string m_location;
	string orientation;

	void SpawnedBuilding(string building_name, string location, string orientation)
	{
		this.m_name = building_name;
		this.m_location = location;
		this.orientation = orientation;
	}

	void ~SpawnedBuilding(){
	}

	string getName()
	{
		return this.m_name;
	}

	string getLocation()
	{
		return this.m_location;
	}

	string getOrientation()
	{
		return this.orientation;
	}
};