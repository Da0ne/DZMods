#include "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\Modules\\CustomBuildings\\SpawnedBuilding.c"

typedef array<ref SpawnedBuilding> CustomBuildings;

class BuildingSpawner extends ModuleManager
{
	ref CustomBuildings customBuildings;

	void BuildingSpawner( DayZSurvival m_MissionServer, CustomBuildings customBuildings )
	{
		this.customBuildings = customBuildings;
	}

	void ~BuildingSpawner()
	{
		
	}

	override void Init()
	{
		Print("BuildingSpawner::Init: Starting...");

		if(!customBuildings){
			Print("Array not found.");
			return;
		}

		if(customBuildings.Count() == 0)
		{
			Print("BuildingSpawner::spawnCustomBuildings: buildings Array is Empty.");
			return;
		}
		EntityAI buildAI;

		for(int i = 0; i < customBuildings.Count(); i++)
		{
			ref SpawnedBuilding building = customBuildings.Get(i);

			Print("BuildingSpawner::spawnCustomBuildings: Spawning:(" + building.getName() + ") at: <" + building.getLocation() + ">.");
			
			Object obj = GetGame().CreateObject(building.getName(), building.getLocation().ToVector(), false, true);
			obj.SetOrientation(building.getOrientation().ToVector());
			obj.SetDirection(obj.GetDirection());
		}
		Print("Buildings Spawned: " + customBuildings.Count().ToString());
	}
	
	void setCustomBuildings(CustomBuildings buildings) {
		this.customBuildings = buildings;
	}
}