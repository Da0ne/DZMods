	array<string> ConstructCargoArray(ItemBase SentItem)
	{
		//Gets cargo within cargo as well
		array<string> ret = new array<string>;
		InventoryItem item;
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

				if (inventoryItem.GetInventory().GetCargo()) //Check for Cargo within cargo
				{
					CargoBase Subcargo = inventoryItem.GetInventory().GetCargo();
					for (j = 0; j < Subcargo.GetItemCount(); ++j)
					{
						InventoryItemBase SubinventoryItem;
						Class.CastTo(SubinventoryItem, Subcargo.GetItem(j));
						ret.Insert(SubinventoryItem.GetType());
					}
				}
				else
				{
					if (SubinventoryItem.GetInventory().AttachmentCount())
					{
						for (j = 0; j < SubinventoryItem.GetInventory().AttachmentCount(); ++j)
						{
							InventoryItemBase SubAtt;
							Class.CastTo(SubAtt, SubinventoryItem);
							ret.Insert(SubAtt.GetInventory().GetAttachmentFromIndex(j).GetType());
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

		Hands    = player.GetHumanInventory().GetEntityInHands();
		Shoulder = player.GetHumanInventory().FindAttachment(InventorySlots.SHOULDER);
		Melee    = player.GetHumanInventory().FindAttachment(InventorySlots.MELEE);
		HeadGear = player.GetHumanInventory().FindAttachment(InventorySlots.HEADGEAR);
		Mask     = player.GetHumanInventory().FindAttachment(InventorySlots.MASK);
		EyeWear  = player.GetHumanInventory().FindAttachment(InventorySlots.EYEWEAR);
		Gloves   = player.GetHumanInventory().FindAttachment(InventorySlots.GLOVES);
		Armband  = player.GetHumanInventory().FindAttachment(InventorySlots.ARMBAND);
		Body     = player.GetHumanInventory().FindAttachment(InventorySlots.BODY);
		Vest     = player.GetHumanInventory().FindAttachment(InventorySlots.VEST);
		Back     = player.GetHumanInventory().FindAttachment(InventorySlots.BACK);
		Legs     = player.GetHumanInventory().FindAttachment(InventorySlots.LEGS);
		Feet     = player.GetHumanInventory().FindAttachment(InventorySlots.FEET);

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
	}