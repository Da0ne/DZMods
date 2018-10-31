TStringArray LoadParameterArray(map<string, TStringArray> itemsMap,string param_name)
{
	if ( itemsMap.Contains(param_name) )
	{
		return itemsMap.Get(param_name);
	}

	return NULL;
}

int GimmeRandom(int Max)
{
	int count = Math.RandomIntInclusive(0,Max - 1);
	return count;
}

void SpawnLoadout(PlayerBase player, bool status, array<string> Directorys)
{
	ref map<string,map<string,map<string,map<string,map<string, TStringArray>>>>> SavedData = new map<string,map<string,map<string,map<string,map<string, TStringArray>>>>>;
	
	ref TStringArray arrAttachments = new TStringArray;
	ref map<string, TStringArray> ItemInSlotChildren = new map<string, TStringArray>;
	ref map<string,map<string, TStringArray>> ItemInInentory = new map<string,map<string, TStringArray>>;
	ref map<string,map<string,map<string, TStringArray>>> ItemInSlot = new map<string,map<string,map<string, TStringArray>>>;
	ref map<string,map<string,map<string,map<string, TStringArray>>>> ContainerObject = new map<string,map<string,map<string,map<string, TStringArray>>>>;

	string MainDirectoy = "$profile:Static_Loadouts";

	if (status)
	{
		string SelectedLoadout = Directorys.Get(GimmeRandom(Directorys.Count()));

		TStringArray stSlots = {"Hands","Shoulder","Melee","HeadGear","Mask","EyeWear","Gloves","Armband","Body","Vest","Back","Legs","Feet"};
		string CurentCatagory;

		for (int i = 0; i < stSlots.Count(); ++i)
		{
			CurentCatagory = stSlots.Get(i);
			string jsonSavePath = MainDirectoy + "\\" + SelectedLoadout + "\\" + CurentCatagory +".json";

			if (FileExist(jsonSavePath))
			{
				JsonFileLoader<map<string,map<string,map<string,map<string,map<string, TStringArray>>>>>>.JsonLoadFile(jsonSavePath, SavedData);

				arrAttachments     = new TStringArray;
				ItemInSlotChildren = new map<string, TStringArray>;
				ItemInInentory     = new map<string,map<string, TStringArray>>;
				ItemInSlot 		   = new map<string,map<string,map<string, TStringArray>>>;
				ContainerObject    = new map<string,map<string,map<string,map<string, TStringArray>>>>;

				string mKey,strAttachments,strClassName,strType,strSlot,strFatherslot;
				int x = 0;
				//Read maps
				for (x = 0; x < SavedData.Count(); ++x)
				{
					mKey    = SavedData.GetKey(x);
					strFatherslot = mKey;
					ContainerObject = SavedData.Get(mKey);
				}
				for (x = 0; x < ContainerObject.Count(); ++x)
				{
					mKey = ContainerObject.GetKey(x);
					strSlot = mKey;
					ItemInSlot = ContainerObject.Get(mKey);
				}
				for (x = 0; x < ItemInSlot.Count(); ++x)
				{
					mKey = ItemInSlot.GetKey(x);
					strType = mKey;
					ItemInInentory = ItemInSlot.Get(mKey);
				}
				for (x = 0; x < ItemInInentory.Count(); ++x)
				{
					mKey = ItemInInentory.GetKey(x);
					strClassName = mKey;
					ItemInSlotChildren = ItemInInentory.Get(mKey);
				}
				arrAttachments = LoadParameterArray(ItemInSlotChildren,"Inventory");

				ItemBase itemBs;
				EntityAI itemEnt;
				TStringArray ExtrasArray;
				TStringArray AttachmentsArray;
				int j = 0;
				
				if (GetGame().IsKindOf( strClassName, "Rifle_Base"))
				{
					ExtrasArray = {};
					AttachmentsArray = {};
					if (arrAttachments.Count() >= 1)
					{
						for (j = 0; j < arrAttachments.Count(); ++j)
						{
							if (GetGame().IsKindOf( arrAttachments.Get(j), "Magazine_Base") && ! (GetGame().IsKindOf( arrAttachments.Get(j), "Ammunition_Base")) )
							{
								ExtrasArray.Insert( arrAttachments.Get(j) );
							}
							else
							{
								AttachmentsArray.Insert( arrAttachments.Get(j) );
							}
						}
					}
					SpawnGunIn( player , strClassName, true, AttachmentsArray, ExtrasArray );
				}
				else
				{
					itemEnt = player.GetInventory().CreateInInventory( strClassName );
					itemBs = ItemBase.Cast(itemEnt);
					if (arrAttachments.Count() >= 1)
					{
						for (j = 0; j < arrAttachments.Count(); ++j)
						{
							ExtrasArray = {};
							AttachmentsArray = {};

							if (GetGame().IsKindOf( arrAttachments.Get(j), "Pistol_Base"))
							{
								if (GetGame().IsKindOf( arrAttachments.Get(j), "Magazine_Base") && ! (GetGame().IsKindOf( arrAttachments.Get(j), "Ammunition_Base")) )
								{
									ExtrasArray.Insert( arrAttachments.Get(j) );
								}
								else
								{
									AttachmentsArray.Insert( arrAttachments.Get(j) );
								}
								SpawnGunIn( player , arrAttachments.Get(j), false, AttachmentsArray, ExtrasArray );
							}
							else
							{
								itemBs.GetInventory().CreateInInventory( arrAttachments.Get(j) );
							}
						}
					}
				}
			}
		}
    }
    else
    {
    	//Do Vanilla if no other loadouts are found
    	ItemBase TrashBase;
		EntityAI ShitBase;

		ShitBase = player.GetInventory().CreateInInventory( "Rag" );
		TrashBase = ItemBase.Cast(ShitBase);							
		TrashBase.SetQuantity(1);
		Print("StartingEquipSetup>>ERROR:: No Static Custom Loadouts were found!");
    }
}
		
bool LoadRandomStaticLD(PlayerBase player)
{
	array<string> LoadoutDirectorys = new array<string>;
	FindFileHandle FileSearch;
	FileHandle LoadOutDir;
	string MainDirectoy = "$profile:Static_Loadouts";

	//Search and compile loadouts
	string FolderName;
	int 	file_attr;
	int		flags;

	if (FileExist(MainDirectoy))
	{
		string m_Path = "$profile:\\Static_Loadouts";
		string path_find_pattern = m_Path + "\\*";

		FileSearch = FindFile(path_find_pattern, FolderName, file_attr, flags);

		bool found = true;
		while (found)
		{
			if ( file_attr & FileAttr.DIRECTORY )
			{
				LoadoutDirectorys.Insert(FolderName);
			}
			
			found = FindNextFile(FileSearch, FolderName, file_attr);
		}
		CloseFindFile(FileSearch);
	}

	//Check b4 we go n spawn gear!
	if (LoadoutDirectorys.Count() >= 1)
	{
		player.RemoveAllItems();
		SpawnLoadout(player,true,LoadoutDirectorys);
		return true;
	}
	else
	{
		SpawnLoadout(player,false,LoadoutDirectorys);
		return false;
	}
}