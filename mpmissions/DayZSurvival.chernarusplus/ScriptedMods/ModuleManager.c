class ModuleManager
{
	protected DayZSurvival m_MissionServer;
	
	void ModuleManager( DayZSurvival m_MissionServer )
	{
		this.m_MissionServer = m_MissionServer;
	}
	
	void ~ModuleManager()
	{
		m_MissionServer = NULL;
	}
	
	void Init()
	{
		
	}
	
	void onUpdate( float timeslice ) 
	{
		
	}
	
	void onMissionStart()
	{
		
	}
	
	void onMissionFinish()
	{
		
	}
	
	void onMissionLoaded()
	{
		
	}
	
	string GetModuleName()
	{
		return ClassName();
	}

	typename GetModuleType()
	{
		return GetModuleName().ToType();
	}
}
