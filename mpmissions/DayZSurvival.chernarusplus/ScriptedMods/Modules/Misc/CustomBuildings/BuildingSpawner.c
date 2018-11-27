#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Modules\\Misc\\CustomBuildings\\SpawnedBuilding.c"
typedef array<ref SpawnedBuilding> CustomBuildings;

class BuildingSpawner{
	void Init(){
		Print("BuildingSpawner::Init: Starting...");
	   /*
		* Configuration Here:
			function SpawnedBuilding(string buildingclass_name, vector location, vector orientation);
				buildingclass_name:
					Name of the building.
				location:
					Location of where the building will spawn.
				orientation:
					The direction the building will face.
				Example:
					new SpawnedBuilding("Land_Airfield_Hangar_Green", "11990.633789 146.399136 12485.503906", "-157.000046 -1.000000 -0.000000")
	    */
		ref CustomBuildings buildings = {
			//Add new SpawnedBuilding here.
			new SpawnedBuilding("Land_Airfield_Hangar_Green", "11990.633789 146.399136 12485.503906", "-157.000046 -1.000000 -0.000000"),
		};
		spawnCustomBuildings(buildings);
	}
	
	void spawnCustomBuildings(ref CustomBuildings collection)
	{
		if(collection.Count() == 0){
			Print("BuildingSpawner::spawnCustomBuildings: buildings Array is Empty.");
			return;
		}

		for(int i = 0; i < collection.Count(); i++)
		{
			SpawnedBuilding building = collection.Get(i);

			Print("BuildingSpawner::spawnCustomBuildings: Spawning:(" + building.getName() + ") at: <" + building.getLocation() + ">.");
			
			EntityAI buildAI = GetGame().CreateObject(building.getName(), building.getLocation().ToVector(), false, true);
			Object obj = Object.Cast(buildAI);
			
			obj.SetOrientation(building.getOrientation().ToVector());
			obj.SetDirection(obj.GetDirection());
		}
	}	
}