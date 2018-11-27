class SpawnedBuilding{
	string m_name;
	string m_location;
	string direction_facing;

	void SpawnedBuilding(string building_name, string location, string orientation){
		this.m_name = building_name;
		this.m_location = location;
		this.direction_facing = orientation;
	}

	void ~SpawnedBuilding(){
	}

	string getName(){
		return this.m_name;
	}

	string getLocation(){
		return this.m_location;
	}

	string getOrientation(){
		return this.direction_facing;
	}
};