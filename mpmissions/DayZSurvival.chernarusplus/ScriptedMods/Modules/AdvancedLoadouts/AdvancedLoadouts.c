class AdvancedLoadouts extends ModuleManager
{	
	//=============Mod Tunables=============
	protected bool m_StaticLoadouts     = true;  //TO USE U MUST HAVE --> AdvancedLoadouts mod active! (picks random loadout preset you have created using the admin command /export )
	protected bool m_RandomizedLoadouts = false; //TO USE U MUST HAVE --> AdvancedLoadouts mod active! (picks random item to spawn on player from each catagory in 'LoaOuts\RandomlyGenerated')
	protected bool m_SpawnArmed		    = true;  //Spawn fresh spawns with a pistol, weapon types can be changed in 'DayZSurvival.c' All the way at the bottom in fucntion 'StartingEquipSetup'
	//======================================

	string m_RandomLoadoutsPath = "$CurrentDir:\\mpmissions\\DayZSurvival.chernarusplus\\ScriptedMods\\LoadOuts\\RandomlyGenerated\\";
	ref TStringArray LoadoutCatagories = {"Bags","Gloves","Vests","Tops","Pants","Boots","HeadGear"}; //Add any new catagories here, make sure the name matches everywhere used including file
	ref map<string,string> PoweredOptics; //Type of optics, type of battery

	ref TStringArray Bags = {};
	ref TStringArray Gloves = {};
	ref TStringArray Vests = {};
	ref TStringArray Tops = {};
	ref TStringArray Pants = {};
	ref TStringArray Boots = {};
	ref TStringArray HeadGear = {};

	void AdvancedLoadouts( DayZSurvival serverMission )
	{

	}

	void ~AdvancedLoadouts()
	{

	}

	bool CheckTunables(string type)
	{
		switch(type)
		{
			case "StaticLoadouts":
			return m_StaticLoadouts;
			break;

			case "RandomizedLoadouts":
			return m_RandomizedLoadouts;
			break;

			case "SpawnArmed":
			return m_SpawnArmed;
			break;
		}
		return false;
	}

	override void Init()
	{
		Print("AdvancedLoadouts:: Init!");

		PoweredOptics = new map<string,string>;
		PoweredOptics.Insert("m4_carryhandleoptic","");
		PoweredOptics.Insert("buisoptic","");
		PoweredOptics.Insert("M68Optic","Battery9V");
		PoweredOptics.Insert("m4_t3nrdsoptic","Battery9V");
		PoweredOptics.Insert("fnp45_mrdsoptic","Battery9V");
		PoweredOptics.Insert("crossbow_redpointoptic","Battery9V");
		PoweredOptics.Insert("reflexoptic","Battery9V");
		PoweredOptics.Insert("acogoptic","");
		PoweredOptics.Insert("puscopeoptic","");
		PoweredOptics.Insert("kashtanoptic","");
		PoweredOptics.Insert("huntingoptic","");
		PoweredOptics.Insert("pistoloptic","");
		PoweredOptics.Insert("pso1optic","");
		PoweredOptics.Insert("pso11optic","Battery9V");
		PoweredOptics.Insert("grozaoptic","");
		PoweredOptics.Insert("kobraoptic","Battery9V");

		ConstructLoadouts(false);
	}

	//=====================Export Functions====================
	array<string> ConstructCargoArray(ItemBase SentItem)
	{
		//Gets cargo within cargo as well
		InventoryItem item;
		array<string> ret = new array<string>;
		Class.CastTo(item, SentItem);
	
		if (!item) return NULL;
	
		if (item.GetInventory().GetCargo())
		{
			CargoBase cargo = item.GetInventory().GetCargo();
			for (int j = 0; j < cargo.GetItemCount(); j++)
			{
				InventoryItemBase inventoryItem;
				Class.CastTo(inventoryItem, cargo.GetItem(j));
				ret.Insert(inventoryItem.GetType());
				
				CargoBase Subcargo = inventoryItem.GetInventory().GetCargo();
				if (Subcargo) //Check for Cargo within cargo
				{
					for (j = 0; j < Subcargo.GetItemCount(); ++j)
					{
						InventoryItemBase cargoItem;
						Class.CastTo(cargoItem, Subcargo.GetItem(j));
						ret.Insert(cargoItem.GetType());
					}
				}
				else
				{
					if (inventoryItem.GetInventory().AttachmentCount())
					{
						for (j = 0; j < inventoryItem.GetInventory().AttachmentCount(); ++j)
						{
							ret.Insert(inventoryItem.GetInventory().GetAttachmentFromIndex(j).GetType());
						}
					}
				}
			}
		}
		else
		{
			for (j = 0; j < item.GetInventory().AttachmentCount(); j++)
			{	
				Class.CastTo(inventoryItem, item.GetInventory().GetAttachmentFromIndex(j));
				ret.Insert(inventoryItem.GetType());
			}
		}

		return ret;
	}

	void ExportInventory(PlayerBase player)
    {    
        ItemBase Hands,Shoulder,Melee,HeadGear,Mask,EyeWear,Gloves,Armband,Body,Vest,Back,Legs,Feet;

        Class.CastTo(Hands, player.GetHumanInventory().GetEntityInHands());
        Class.CastTo(Shoulder, player.GetHumanInventory().FindAttachment(InventorySlots.SHOULDER));
        Class.CastTo(Melee, player.GetHumanInventory().FindAttachment(InventorySlots.MELEE));
        Class.CastTo(HeadGear, player.GetHumanInventory().FindAttachment(InventorySlots.HEADGEAR));
        Class.CastTo(Mask, player.GetHumanInventory().FindAttachment(InventorySlots.MASK));
        Class.CastTo(EyeWear, player.GetHumanInventory().FindAttachment(InventorySlots.EYEWEAR));
        Class.CastTo(Gloves, player.GetHumanInventory().FindAttachment(InventorySlots.GLOVES));
        Class.CastTo(Armband, player.GetHumanInventory().FindAttachment(InventorySlots.ARMBAND));
        Class.CastTo(Body, player.GetHumanInventory().FindAttachment(InventorySlots.BODY));
        Class.CastTo(Vest, player.GetHumanInventory().FindAttachment(InventorySlots.VEST));
        Class.CastTo(Back, player.GetHumanInventory().FindAttachment(InventorySlots.BACK));
        Class.CastTo(Legs, player.GetHumanInventory().FindAttachment(InventorySlots.LEGS));
        Class.CastTo(Feet, player.GetHumanInventory().FindAttachment(InventorySlots.FEET));

        ExportToJSON(Hands,Shoulder,Melee,HeadGear,Mask,EyeWear,Gloves,Armband,Body,Vest,Back,Legs,Feet);
    }

	void ExportToJSON(ItemBase Hands, ItemBase Shoulder, ItemBase Melee ,ItemBase HeadGear,ItemBase Mask,ItemBase EyeWear,ItemBase Gloves,ItemBase Armband,ItemBase Body,ItemBase Vest,ItemBase Back,ItemBase Legs,ItemBase Feet)
	{
		ref array<string> ItemCargo;

		int folderKey = Math.RandomIntInclusive(1,10000);

		if(Body)
		{
			ItemCargo 		= ConstructCargoArray(Body);
			WriteToJSON(folderKey,"Body",Body,ItemCargo);
		}
		if (Hands)
		{
			ItemCargo 		= ConstructCargoArray(Hands);
			WriteToJSON(folderKey,"Hands",Hands,ItemCargo);
		}
		if(Melee)
		{
			ItemCargo 		= ConstructCargoArray(Melee);
			WriteToJSON(folderKey,"Melee",Melee,ItemCargo);
		}
		if(Shoulder)
		{
			ItemCargo 		= ConstructCargoArray(Shoulder);
			WriteToJSON(folderKey,"Shoulder",Shoulder,ItemCargo);
		}
		if(HeadGear)
		{
			ItemCargo 		= ConstructCargoArray(HeadGear);
			WriteToJSON(folderKey,"HeadGear",HeadGear,ItemCargo);
		}
		if(Mask)
		{
			ItemCargo 		= ConstructCargoArray(Mask);
			WriteToJSON(folderKey,"Mask",Mask,ItemCargo);
		}
		if(EyeWear)
		{
			ItemCargo 		= ConstructCargoArray(EyeWear);
			WriteToJSON(folderKey,"EyeWear",EyeWear,ItemCargo);
		}
		if(Gloves)
		{
			ItemCargo 		= ConstructCargoArray(Gloves);
			WriteToJSON(folderKey,"Gloves",Gloves,ItemCargo);
		}
		if(Armband)
		{
			ItemCargo 		= ConstructCargoArray(Armband);
			WriteToJSON(folderKey,"Armband",Armband,ItemCargo);
		}
		if(Vest)
		{
			ItemCargo 		= ConstructCargoArray(Vest);
			WriteToJSON(folderKey,"Vest",Vest,ItemCargo);
		}
		if(Back)
		{
			ItemCargo 		= ConstructCargoArray(Back);
			WriteToJSON(folderKey,"Back",Back,ItemCargo);
		}
		if(Legs)
		{
			ItemCargo 		= ConstructCargoArray(Legs);
			WriteToJSON(folderKey,"Legs",Legs,ItemCargo);
		}
		if(Feet)
		{
			ItemCargo 		= ConstructCargoArray(Feet);
			WriteToJSON(folderKey,"Feet",Feet,ItemCargo);
		}
	}

	void WriteToJSON(int folderKey, string Catagory, ItemBase BaseItem, ref array<string> ItemCargo)
	{
		string static_dir  = "$profile:Static_Loadouts";
		string file_dir    = "$profile:Static_Loadouts\\Loadout_"+ folderKey.ToString();
		string file_path   =  file_dir + "\\" + Catagory;
		

		ref array<string> attachments = new array<string>;
		ref map<string, ref array<string>> ItemInSlotChildren = new map<string, ref array<string>>;
		ref map<string,map<string, ref array<string>>> ItemInInentory = new map<string,map<string, ref array<string>>>;
		ref map<string,map<string,map<string, ref array<string>>>> ItemInSlot = new map<string,map<string,map<string, ref array<string>>>>;
		ref map<string,map<string,map<string,map<string, ref array<string>>>>> ContainerObject = new map<string,map<string,map<string,map<string, ref array<string>>>>>;
		ref map<string,map<string,map<string,map<string,map<string, ref array<string>>>>>> SlotData = new map<string,map<string,map<string,map<string,map<string, ref array<string>>>>>>;

		if (ItemCargo)
		{
			for (int i = 0; i < ItemCargo.Count(); ++i)
			{
				attachments.Insert(ItemCargo.Get(i));
			}
		}

		ItemInSlotChildren.Insert("Inventory",attachments);
		ItemInInentory.Insert(BaseItem.GetType(),ItemInSlotChildren);
		ItemInSlot.Insert("Type",ItemInInentory);
		ContainerObject.Insert(Catagory,ItemInSlot);
		SlotData.Insert("Slot",ContainerObject);
		
		if (FileExist(static_dir))
        {
        	if (FileExist(file_dir))
        	{
        		JsonFileLoader<map<string,map<string,map<string,map<string,map<string, ref array<string>>>>>>>.JsonSaveFile(file_path + ".json", SlotData);
        	}
        	else
        	{
        		MakeDirectory(file_dir);
        		JsonFileLoader<map<string,map<string,map<string,map<string,map<string, ref array<string>>>>>>>.JsonSaveFile(file_path + ".json", SlotData);
        	}
        }
        else
        {
        	MakeDirectory("$profile:Static_Loadouts");
        	if (FileExist(file_dir))
        	{
        		JsonFileLoader<map<string,map<string,map<string,map<string,map<string, ref array<string>>>>>>>.JsonSaveFile(file_path + ".json", SlotData);
        	}
        	else
        	{
        		MakeDirectory(file_dir);
        		JsonFileLoader<map<string,map<string,map<string,map<string,map<string, ref array<string>>>>>>>.JsonSaveFile(file_path + ".json", SlotData);
        	}
        }

        Print("File " + file_path + " was writen by the use of the export command.");
	}

	//=========================Import + Spwn Loadout Functions =================================
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
						if (CurentCatagory == "Shoulder")
						{
							SpawnGunIn( player , strClassName, false, AttachmentsArray, ExtrasArray );
						}
						else { SpawnGunIn( player , strClassName, true, AttachmentsArray, ExtrasArray ); }
					}
					else
					{
						itemEnt = player.GetInventory().CreateInInventory( strClassName );
						Class.CastTo(itemBs, itemEnt);

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
			Class.CastTo(TrashBase, ShitBase);							
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

	void LoadRndGenLoadout(PlayerBase player)
	{
		ItemBase itemBs;
		EntityAI itemEnt;
		player.RemoveAllItems();

		if (Bags.Count() > 0) { player.GetInventory().CreateInInventory( Bags.GetRandomElement() );  }
		if (Gloves.Count() > 0) { player.GetInventory().CreateInInventory( Gloves.GetRandomElement() ); }
		if (Vests.Count() > 0) { player.GetInventory().CreateInInventory( Vests.GetRandomElement() ); }
		if (Tops.Count() > 0) { player.GetInventory().CreateInInventory( Tops.GetRandomElement() ); }
		if (Pants.Count() > 0) { player.GetInventory().CreateInInventory( Pants.GetRandomElement() ); }
		if (Boots.Count() > 0) { player.GetInventory().CreateInInventory( Boots.GetRandomElement() ); }
		if (HeadGear.Count() > 0) { player.GetInventory().CreateInInventory( HeadGear.GetRandomElement() ); }

		player.GetInventory().CreateInInventory( "Battery9V" );
		
		itemEnt = player.GetInventory().CreateInInventory( "Rag" );
		Class.CastTo(itemBs, itemEnt);
		itemBs.SetQuantity(6);

		player.SetQuickBarEntityShortcut(itemBs, 0, true);
	}

	//==============================Misc=================================

	void ConstructLoadouts(bool update)
	{
		FileHandle currentFile;
		string line_content = "";

		if (update) {
			if (m_RandomizedLoadouts)
			{
				Bags.Clear();
				Gloves.Clear();
				Vests.Clear();
				Tops.Clear();
				Pants.Clear();
				Boots.Clear();
				HeadGear.Clear();
			}
		}

		if (m_RandomizedLoadouts)
		{
			//Load randomized ld items
			for ( int i = 0; i < LoadoutCatagories.Count(); ++i )
			{
				string currentCatagory = LoadoutCatagories.Get(i);
				currentFile = OpenFile(m_RandomLoadoutsPath + currentCatagory + ".txt", FileMode.READ);
				if (currentFile != 0)
				{
					line_content = "";
					while ( FGets(currentFile,line_content) > 0 )
					{
						switch(currentCatagory)
						{
							case "Bags":
							Bags.Insert(line_content);
							break;

							case "Gloves":
							Gloves.Insert(line_content);
							break;

							case "Vests":
							Vests.Insert(line_content);
							break;

							case "Tops":
							Tops.Insert(line_content);
							break;

							case "Pants":
							Pants.Insert(line_content);
							break;

							case "Boots":
							Boots.Insert(line_content);
							break;

							case "HeadGear":
							HeadGear.Insert(line_content);
							break;
						}
					}
					CloseFile(currentFile);
			    }
			}
		}
	}

	void SpawnGunIn(PlayerBase player, string item, bool isMainGun, array<string> attachments, array<string> Extras)
	{
		EntityAI itemAI;

		EntityAI myAttachmentAI;
		EntityAI myAttachmentIB;

		EntityAI ExtraEntity;

		int MinQuantity;
		Magazine mag;

		if (isMainGun)
		{
			itemAI = player.GetHumanInventory().CreateInHands( item );

			player.SetQuickBarEntityShortcut(itemAI, 2, true); //Puts gun on hotkey 3

			if ( attachments != NULL )
			{
					
				for (int i = 0; i < attachments.Count(); ++i)
				{
					myAttachmentAI = itemAI.GetInventory().CreateInInventory( attachments.Get(i) );
					if (PoweredOptics.Contains(attachments.Get(i)))
					{
						myAttachmentAI.GetInventory().CreateInInventory( "Battery9V" );
					}
				}
			}
				
			if ( Extras != NULL )
			{
				for (int ii = 0; ii < Extras.Count(); ++ii)
				{
					if (GetGame().IsKindOf( Extras.Get(ii), "Magazine_Base") && ! (GetGame().IsKindOf( Extras.Get(ii), "Ammunition_Base")) )
					{
						Class.CastTo(mag, player.GetHumanInventory().CreateInInventory(Extras.Get(ii)));
						MinQuantity = 2;
						if (mag)
						{
							mag.ServerSetAmmoCount(Math.RandomIntInclusive(MinQuantity,mag.GetAmmoMax()));
							player.SetQuickBarEntityShortcut(mag, 0, true);  //Puts main weapons mag on hotkey 1
						}
					}
					else
					{
						ExtraEntity = player.GetInventory().CreateInInventory( Extras.Get(ii) );
					}
				}
			}
		}
		else
		{
			//For Pistols/Secondary that spawn in inevntory
			if ( item != "" ) 
			{
				itemAI = player.GetHumanInventory().CreateInInventory( item );

				player.SetQuickBarEntityShortcut(itemAI, 3, true);  //Puts the Secondary weapon on hotkey 4
			
				if ( attachments != NULL && attachments.Count() > 0 )
				{
					for (int iz = 0; iz < attachments.Count(); ++iz)
					{
						Class.CastTo(myAttachmentIB, itemAI.GetInventory().CreateAttachment( attachments.Get(iz) ));
						if (PoweredOptics.Contains(attachments.Get(iz)))
						{
							myAttachmentIB.GetInventory().CreateInInventory( "Battery9V" );
						}
					}
				}
				
				if ( Extras != NULL && Extras.Count() > 0 )
				{
					for (int ip = 0; ip < Extras.Count(); ++ip)
					{
						if (GetGame().IsKindOf( Extras.Get(ip), "Magazine_Base") && ! (GetGame().IsKindOf( Extras.Get(ip), "Ammunition_Base")) )
						{
							Class.CastTo(mag, player.GetInventory().CreateInInventory( Extras.Get(ip) ));
							player.SetQuickBarEntityShortcut(mag, 1, true);   //Puts the mag for the secondary on hotkey 2

							MinQuantity = 2;
							mag.ServerSetAmmoCount(Math.RandomIntInclusive(MinQuantity,mag.GetAmmoMax()));
						}
						else
						{
							ExtraEntity = player.GetInventory().CreateInInventory( Extras.Get(ip) );
						}
					}
				}
			}
		}
	}
}