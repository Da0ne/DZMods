class CfgMods
{
	class VanillaPlusPlus
	{
	    dir = "VanillaPlusPlus";
	    picture = "";
	    action = "";
	    hideName = 1;
	    hidePicture = 1;
	    name = "Vanilla++";
	    credits = "DaOne";
	    author = "DaOne";
	    authorID = "0";
	    version = "0.4";
	    extra = 0;
	    type = "mod";

	    dependencies[] = {"Game", "World", "Mission"};

	    class defs
	    {
			class imageSets
			{
				files[]={"VanillaPP/scripts/GUI/Textures/dayz_gui_vpp.imageset"};
			};
			
			class gameScriptModule
			{
				value = "";
				files[] = {"VanillaPP/scripts/3_Game"};
			};
	        class worldScriptModule
            {
                value = "";
                files[] = {"VanillaPP/scripts/4_World"};
            };
			class missionScriptModule
			{
				value = "";
				files[] = {"VanillaPP/scripts/5_Mission"};
			};
        };
    };
};
