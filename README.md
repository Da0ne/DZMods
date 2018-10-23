# DayZ Chat Based Admin Toolset by DaOne v0.2

## Installation:

#### -Download and extract the files `AdminTool.c` & `AdminToolExtended` into your mission folder `dayzOffline.chernarusplus`.

#### - Locate the following *class* in the file `init.c`
 `class CustomMission: MissionServer{
}`
#### In the vanilla "init.c" it should be located around line 30 OR 35
![](https://i.gyazo.com/4ea9b5e58f61c85c015c60501a207f3b.png)

#### - Just under the open curly bracket add the following line: 

    #include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\AdminTool.c"

#### It Should look like this: 
![](https://i.gyazo.com/83ccb4e67e7e7ccabbc964e03f96e704.png)

#### - Under that new line you just added, copy and paste the following:
    override void OnInit()
	{
		AdminTool();
		string m_AdminListPath = "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\";	
		FileHandle AdminUIDSFile = OpenFile(m_AdminListPath + "Admins.txt", FileMode.READ);
    	if (AdminUIDSFile != 0)
	    {
			string line_content = "";
			while ( FGets(AdminUIDSFile,line_content) > 0 )
			{
				m_AdminList.Insert(line_content,"null"); //UID , NAME
				Print("Adding Admin: "+ line_content + " To the Admin List!");
			}
			CloseFile(AdminUIDSFile);
		}
    }
   #### NOTE: If you get any errors on startup relating to " override void OnInit() already exists " Check if the function is already there from other mods you have installed. If so, simply copy the code within the

     override  void OnInit()
     {
     }
   #### And place it into the already existing `override void OnInit()`
   #### Make sure that the path matches where your `Admin.txt` file is
   

    string m_AdminListPath = "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\";
#### - Save and exit out of `init.c` , open up the file `AdminTool.c` and scroll down to `LINE: 260`
![](https://i.gyazo.com/a1b0b333ba1f7b273c7b7cf3d66de66b.png)
#### Make sure the path is correct according to where mission is.

#### - Create a new text file in your mission folder (default: dayzOffline.chernarusplus). Name it: `Admins.txt`Open it and add the steam 64 ID's of your admins. You can obtain the 64 ID using: [Steam IO](https://steamid.io/)

#### Should look like this:

![](https://i.gyazo.com/88f1d7acc7d135279e15400c3e46bb2f.png)

#### Save and exit. Run the server and in game login as admin using the #login Password command.
#### Here is a list of the commands you can use: [Commands List](https://pastebin.com/Xe1Rmwp5)
#### (The godmode feature is currently not implemented, will be added in future updates)
