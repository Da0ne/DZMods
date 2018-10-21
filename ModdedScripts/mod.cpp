class CfgMods
{
	class ModdedScripts
	{
	    dir = "ModdedScripts";
	    picture = "";
	    action = "";
	    hideName = 1;
	    hidePicture = 1;
	    name = "ModdedScripts";
	    credits = "DaOne";
	    author = "DaOne";
	    authorID = "0";
	    version = "1.0";
	    extra = 0;
	    type = "mod";

	    dependencies[] = {"World"};

	    class defs
	    {
	        class worldScriptModule
            {
                value = "";
                files[] = {"ModdedScripts/scripts/4_World"};
            };
        };
    };
};