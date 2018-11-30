class BuildingSpawner
{
	void Init()
	{
		Print("BuildingSpawner:: Spawning custom scripted buildings....");
		Object obj;
		//--------------------SAFE ZONE-------------------------
		obj = GetGame().CreateObject("Land_Castle_Bergfrit", "6131.64 375.55 6931.89");
		obj.SetOrientation("-128 0 -0");
		obj.SetPosition("6131.64 375.55 6931.89");
		obj.SetOrientation("-128 0 -0");
		//---------------------------------------------
		obj = GetGame().CreateObject("Land_Castle_Stairs", "6130.79 365.586 6920.77");
		obj.SetOrientation("-41 0 0");
		obj.SetPosition("6130.79 365.586 6920.77");
		obj.SetOrientation("-41 0 0");
		//---------------------------------------------
		obj = GetGame().CreateObject("Land_Mil_CamoNet_Roof_east", "6131.39 394.424 6932.54");
		obj.SetOrientation("-38 0 0");
		obj.SetPosition("6131.39 394.424 6932.54");
		obj.SetOrientation("-38 0 0");
		//---------------------------------------------
		obj = GetGame().CreateObject("Land_Power_Pole_Wood1_Amp", "6133.42 385.304 6939.3");
		obj.SetOrientation("-172 0 0");
		obj = GetGame().CreateObject("Land_Power_Pole_Wood1_Amp", "6123.6 385.154 6931.33");
		obj.SetOrientation("109 0 0");
		obj = GetGame().CreateObject("Land_Power_Pole_Conc4_Lamp_Amp", "6140.28 386.376 6932.4");
		obj.SetOrientation("-165 0 0");
		obj = GetGame().CreateObject("Land_Power_Pole_Conc4_Lamp_Amp", "6129.02 386.372 6923.28");
		obj.SetOrientation("-73 0 0");
		obj = GetGame().CreateObject("Land_Misc_Well_Pump_Blue", "6188.25 362.334 6861.72");
		obj.SetOrientation("0 0 0");
		obj = GetGame().CreateObject("Land_Castle_Wall1_20", "6142.58 365.087 6945.36");
		obj.SetOrientation("-41 0 0");
		obj = GetGame().CreateObject("Land_Castle_Wall1_20", "6116.8 364.876 6923.73");
		obj.SetOrientation("-41 0 0");
		obj = GetGame().CreateObject("Land_Castle_Wall1_20", "6104.64 364.907 6908.4");
		obj.SetOrientation("-62 0 0");
		obj = GetGame().CreateObject("Land_Castle_Bastion_nolc", "6199.81 364.729 6843.97");
		obj.SetOrientation("146 1 0");
		obj = GetGame().CreateObject("Land_Castle_Wall1_20", "6113.61 355.71 6855.04");
		obj.SetOrientation("-131 0 0");
		obj = GetGame().CreateObject("Land_Castle_Bastion_nolc", "6187.77 358.556 6862.24");
		obj.SetOrientation("-31 -1.19209e-07 0");
		obj = GetGame().CreateObject("Land_Castle_Wall2_End1", "6180.26 365.052 6948.69");
		obj.SetOrientation("11 0 0");
		obj = GetGame().CreateObject("Land_Castle_Gate", "6182.3 363.839 6833.77");
		obj.SetOrientation("-33 0 0");
		obj = GetGame().CreateObject("Land_Castle_Wall2_30", "6245.85 367.416 6918.13");
		obj.SetOrientation("52.0002 0 0");
		obj = GetGame().CreateObject("Land_Castle_Wall1_20", "6159.49 365.082 6948.43");
		obj.SetOrientation("18 0 0");
		obj = GetGame().CreateObject("Land_Castle_Wall1_End2", "6177.39 364.933 6943.36");
		obj.SetOrientation("13 0 0");
		obj = GetGame().CreateObject("Land_Village_HealthCare", "6136.72 365.485 6885.81");
		obj.SetOrientation("54 0 0");
		obj = GetGame().CreateObject("Land_Castle_Wall2_30", "6127.69 364.286 6837.7");
		obj.SetOrientation("-132 0 0");
		obj = GetGame().CreateObject("Land_Lunapark_Shooting_Gallery", "6182.04 363.737 6872.33");
		obj.SetOrientation("57 0 0");
		obj = GetGame().CreateObject("Land_Lunapark_Shooting_Gallery", "6169.94 363.992 6884.23");
		obj.SetOrientation("-126 0 0");
		obj = GetGame().CreateObject("Land_Tower_TC3_Red", "6165.48 362.39 6890.66");
		obj.SetOrientation("-36 0 0");
		obj = GetGame().CreateObject("Land_Misc_Toilet_Mobile", "6190.16 363.354 6872.59");
		obj.SetOrientation("-170 0 0");
		obj = GetGame().CreateObject("Land_Misc_Toilet_Mobile", "6177.84 362.95 6864.81");
		obj.SetOrientation("107 0 0");
		obj = GetGame().CreateObject("Land_Misc_Toilet_Mobile", "6178.64 363.058 6866.71");
		obj.SetOrientation("115 0 0");
		obj = GetGame().CreateObject("Land_Misc_Toilet_Mobile", "6188.15 363.342 6872.73");
		obj.SetOrientation("179 0 0");
		obj = GetGame().CreateObject("Land_Mil_Tent_Big4", "6155.32 362.509 6864.53");
		obj.SetOrientation("-87 0 0");
		obj = GetGame().CreateObject("Land_Mil_Fortified_Nest_Watchtower", "6247.12 364.031 6884.95");
		obj.SetOrientation("-127 0 0");
		obj = GetGame().CreateObject("Land_Castle_Wall2_30", "6101.78 366.022 6872.77");
		obj.SetOrientation("-113 0 0");
		obj = GetGame().CreateObject("Land_Castle_Wall2_Corner1", "6154.18 368.453 6824.15");
		obj.SetOrientation("126 0 0");
		obj = GetGame().CreateObject("Land_Sawmill_Illuminanttower", "6252.73 371.708 6888.57");
		obj.SetOrientation("-64 0 0");
		obj = GetGame().CreateObject("Land_Mil_Barracks_Round", "6157.05 361.488 6846.79");
		obj.SetOrientation("-178 0 0");
		obj = GetGame().CreateObject("Land_Sawmill_Illuminanttower", "6154.15 368.701 6825.22");
		obj.SetOrientation("0 0 0");
		obj = GetGame().CreateObject("Land_Mil_Barracks_Round", "6147.48 361.031 6846.47");
		obj.SetOrientation("-180 0 0");
		obj = GetGame().CreateObject("Land_Mil_Barracks_Round", "6211.56 363.268 6911.45");
		obj.SetOrientation("0 0 0");
		obj = GetGame().CreateObject("Land_Mil_Barracks_Round", "6219.29 363.201 6911.29");
		obj.SetOrientation("0 0 0");
		obj = GetGame().CreateObject("Land_Mil_Tent_Big4", "6211.91 363.475 6893.38");
		obj.SetOrientation("87 0 0");
		obj = GetGame().CreateObject("Land_Camp_House_red", "6116.4 363.949 6915.15");
		obj.SetOrientation("-41 0 0");
		obj = GetGame().CreateObject("Land_Camp_House_brown", "6150.48 363.729 6944.08");
		obj.SetOrientation("-40 0 0");
		obj = GetGame().CreateObject("Land_Camp_House_white", "6124.91 364.113 6922.44");
		obj.SetOrientation("-40 0 0");
		obj = GetGame().CreateObject("Land_Camp_House_brown", "6141.74 364.012 6936.53");
		obj.SetOrientation("-39 0 0");
		obj = GetGame().CreateObject("Land_House_1B01_Pub", "6174.7 365.112 6915");
		obj.SetOrientation("-37 0 0");
		obj = GetGame().CreateObject("Land_City_Stand_News2", "6169.6 363.983 6894.15");
		obj.SetOrientation("-125 0 0");
		obj = GetGame().CreateObject("Land_City_Stand_News1", "6160.55 364.186 6887.19");
		obj.SetOrientation("54 0 0");
		obj = GetGame().CreateObject("Land_Mil_Barracks_Round", "6203.65 363.315 6911.59");
		obj.SetOrientation("0 0 0");
		obj = GetGame().CreateObject("Land_Power_Pole_Conc1_Amp", "6183.65 369.938 6869");
		obj.SetOrientation("-28 0 0");
		obj = GetGame().CreateObject("Land_Power_Pole_Conc1_Amp", "6204.33 376.149 6837.51");
		obj.SetOrientation("149 0 0");
		obj = GetGame().CreateObject("Land_Power_Pole_Conc4_Lamp_Amp", "6141.79 366.065 6874.98");
		obj.SetOrientation("-126 0 0");
		obj = GetGame().CreateObject("Land_Power_Pole_Conc4_Lamp_Amp", "6221.61 366.348 6851.02");
		obj.SetOrientation("-33.9999 0 0");
		obj = GetGame().CreateObject("Land_Power_Pole_Conc4_Lamp_Amp", "6174.68 366.953 6889.27");
		obj.SetOrientation("-160 0 0");
		obj = GetGame().CreateObject("Land_Power_Pole_Conc4_Lamp_Amp", "6164.08 366.792 6881.49");
		obj.SetOrientation("-75 0 0");
		obj = GetGame().CreateObject("Land_Power_Pole_Conc4_Lamp_Amp", "6183.73 365.209 6827.11");
		obj.SetOrientation("147 0 0");
		obj = GetGame().CreateObject("Land_Power_Pole_Conc4_Lamp_Amp", "6208.39 366.692 6906.65");
		obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_Farm_WaterTower_Small", "6152.19 367.293 6910.47");
		obj.SetOrientation("-34 0 0");
		//---------------------------------------------
		obj = GetGame().CreateObject("Land_Container_1Moh", "6135.86 361.719 6862.81");
		obj.SetOrientation("0 0 0");
		obj.SetPosition("6135.86 361.719 6862.81");
		obj.SetOrientation("0 0 0");
		//---------------------------------------------
		obj = GetGame().CreateObject("Land_Container_1Moh", "6135.05 363.921 6857.89");
		obj.SetOrientation("-12 6 0");
		obj.SetPosition("6135.05 363.921 6857.89");
		obj.SetOrientation("-12 6 0");
		//---------------------------------------------
		obj = GetGame().CreateObject("Land_Container_1Moh", "6135.94 361.087 6854.73");
		obj.SetOrientation("0 0 0");
		obj.SetPosition("6135.94 361.087 6854.73");
		obj.SetOrientation("0 0 0");
		//---------------------------------------------
		obj = GetGame().CreateObject("Land_Container_1Moh", "6139.95 361.712 6858.42");
		obj.SetOrientation("0 0 0");
		obj.SetPosition("6139.95 361.712 6858.42");
		obj.SetOrientation("0 0 0");
		//---------------------------------------------
		obj = GetGame().CreateObject("Land_Container_1Bo", "6130.01 361.745 6866.53");
		obj.SetOrientation("-17 -43 0");
		obj.SetPosition("6130.01 361.745 6866.53");
		obj.SetOrientation("-17 -43 0");
		//---------------------------------------------
		obj = GetGame().CreateObject("Land_Container_1Bo", "6137.97 364.255 6861.23");
		obj.SetOrientation("-38 -1 0");
		obj.SetPosition("6137.97 364.255 6861.23");
		obj.SetOrientation("-38 -1 0");
		//---------------------------------------------
		obj = GetGame().CreateObject("Land_Container_1Aoh", "6133.77 364.614 6864.36");
		obj.SetOrientation("0 8 0");
		obj.SetPosition("6133.77 364.614 6864.36");
		obj.SetOrientation("0 8 0");
		//---------------------------------------------
		obj = GetGame().CreateObject("Land_Container_1Aoh", "6132.54 361.427 6860.88");
		obj.SetOrientation("-33 0 0");
		obj.SetPosition("6132.54 361.427 6860.88");
		obj.SetOrientation("-33 0 0");
		//---------------------------------------------
		obj = GetGame().CreateObject("Land_Container_1Mo", "6133.29 362.049 6867.58");
		obj.SetOrientation("2 0 0");
		obj.SetPosition("6133.29 362.049 6867.58");
		obj.SetOrientation("2 0 0");
		//---------------------------------------------
		obj = GetGame().CreateObject("Land_Mil_Tent_Big4", "6592.12 340.64 6989.2");
		obj.SetOrientation("145 0 0");
		obj = GetGame().CreateObject("Land_Castle_Wall1_20", "6235.98 358.446 6875.71");
		obj.SetOrientation("144 0 0");
		obj = GetGame().CreateObject("Land_Castle_Wall1_20", "6162.33 355.105 6828.36");
		obj.SetOrientation("149 0 0");
		obj = GetGame().CreateObject("Land_Tower_TC1", "6198.68 377.684 6896.37");
		obj.SetOrientation("0 0 0");
		obj = GetGame().CreateObject("Land_Castle_Wall1_20", "6229.58 358.66 6871.21");
		obj.SetOrientation("145 0 0");
		obj = GetGame().CreateObject("Land_Castle_Wall1_20", "6209.76 360.192 6937.44");
		obj.SetOrientation("11 0 0");
		obj = GetGame().CreateObject("Land_Castle_Wall1_20", "6253.44 358.64 6898.19");
		obj.SetOrientation("86 0 0");
		obj = GetGame().CreateObject("Land_Castle_Wall1_20", "6229.01 360.116 6931.03");
		obj.SetOrientation("26 0 0");
		obj = GetGame().CreateObject("Land_Castle_Gate", "6215.87 365.189 6855.57");
		obj.SetOrientation("-32 0 0");
		obj = GetGame().CreateObject("Land_Castle_WallS_10", "6197.15 362.262 6941");
		obj.SetOrientation("8 0 0");
		obj = GetGame().CreateObject("Land_Castle_Wall1_End2", "6098.8 363.1 6892.21");
		obj.SetOrientation("-82 0 0");
		obj = GetGame().CreateObject("Land_Castle_Wall2_Corner1", "6252.81 367.914 6888.65");
		obj.SetOrientation("74 1 0");
		obj = GetGame().CreateObject("Land_Castle_Wall1_20", "6145.06 361.612 6826.47");
		obj.SetOrientation("-158 0 0");
		//---------------------------------------------
		//Thunder Dome
		obj = GetGame().CreateObject("Land_Castle_Bastion_nolc", "6260.64 357.091 6838.33");
		obj.SetOrientation("-133 1 -1");
		obj.SetPosition("6260.64 357.091 6838.33");
		obj.SetOrientation("-133 1 -1");

		obj = GetGame().CreateObject("Land_Wall_Gate_FenG", "6261.17 362.653 6850.17");
		obj.SetOrientation("138 0 0");
		obj.SetPosition("6261.17 362.653 6850.17");
		obj.SetOrientation("138 0 0");

		obj = GetGame().CreateObject("Land_Wall_Gate_FenG", "6272.49 362.425 6838.02");
		obj.SetOrientation("-42 0 0");
		obj.SetPosition("6272.49 362.425 6838.02");
		obj.SetOrientation("-42 0 0");

		obj = GetGame().CreateObject("Land_Castle_Bastion", "6272.84 356.52 6849.84");
		obj.SetOrientation("47 2.38419e-07 0");
		obj.SetPosition("6272.84 356.52 6849.84");
		obj.SetOrientation("47 2.38419e-07 0");

		obj = GetGame().CreateObject("Land_Misc_DeerStand1", "6252.82 365.424 6830.94");
		obj.SetOrientation("-132 0 0");
		obj.SetPosition("6252.82 365.424 6830.94");
		obj.SetOrientation("-132 0 0");

		obj = GetGame().CreateObject("Land_Misc_Scaffolding", "6271.16 360.64 6832.66");
		obj.SetOrientation("-133 0 0");
		obj.SetPosition("6271.16 360.64 6832.66");
		obj.SetOrientation("-133 0 0");

		obj = GetGame().CreateObject("Land_Misc_Scaffolding", "6282.7 360.223 6843.36");
		obj.SetOrientation("-133 0 0");
		obj.SetPosition("6282.7 360.223 6843.36");
		obj.SetOrientation("-133 0 0");

		obj = GetGame().CreateObject("Land_Misc_Scaffolding", "6250.95 360.73 6844.76");
		obj.SetOrientation("47 0 0");
		obj.SetPosition("6250.95 360.73 6844.76");
		obj.SetOrientation("47 0 0");

		obj = GetGame().CreateObject("Land_Misc_Scaffolding", "6262.6 360.296 6855.69");
		obj.SetOrientation("49 0 0");
		obj.SetPosition("6262.6 360.296 6855.69");
		obj.SetOrientation("49 0 0");

		obj = GetGame().CreateObject("Land_Misc_Scaffolding", "6278.78 359.892 6859.2");
		obj.SetOrientation("140 0 0");
		obj.SetPosition("6278.78 359.892 6859.2");
		obj.SetOrientation("140 0 0");

		obj = GetGame().CreateObject("Land_Power_Pole_Conc1_Amp", "6250.89 365.452 6837.67");
		obj.SetOrientation("83 0 0");
		obj.SetPosition("6250.89 365.452 6837.67");
		obj.SetOrientation("83 0 0");
		//---------------------------------------------
		//------------------------------------------------------
		// Prison Island Bridge
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1955"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1935"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1915"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1895"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1895"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1875"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1855"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1835"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1815"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1795"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1775"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1755"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1735"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1715"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1695"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1675"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1655"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1635"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1615"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1595"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1575"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1555"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1535"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1515"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1495"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1475"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1455"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1435"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1415"); obj.SetOrientation("90 0 0");
		obj = GetGame().CreateObject("Dam_Concrete_20_Floodgate", "0 0 0"); obj.SetPosition("2658 -6.55 1395"); obj.SetOrientation("90 0 0");
		
		//------------------------------------------------------
		// Water Pumps
		obj = GetGame().CreateObject("Land_Misc_Well_Pump_Yellow", "0 0 0"); obj.SetPosition( "2788.34 26.6838 1224.95"); obj.SetOrientation("0 0 0");
		obj = GetGame().CreateObject("Land_Misc_Well_Pump_Yellow", "0 0 0"); obj.SetPosition( "2643.2 4.34487 1955.34"); obj.SetOrientation("0 0 -0");
		//------------------------------------------------------
		// Island Additions
		obj = GetGame().CreateObject("Land_Mil_Barracks_Round", "0 0 0"); obj.SetPosition( "2782.77 27.0999 1180.29"); obj.SetOrientation("-137 0 0");
		obj = GetGame().CreateObject("Land_Mil_Barracks_Round", "0 0 0"); obj.SetPosition( "2789.39 27.0889 1174.43"); obj.SetOrientation("-138 0 0");
		obj = GetGame().CreateObject("Land_Container_1Bo", "0 0 0"); obj.SetPosition( "2544.73 21.4275 1320.72"); obj.SetOrientation("14 0 0");
		obj = GetGame().CreateObject("Land_Lighthouse", "0 0 0"); obj.SetPosition( "2496.95 11.9459 1206.76"); obj.SetOrientation("-141 0 0");
		obj = GetGame().CreateObject("Land_Sawmill_Illuminanttower", "0 0 0"); obj.SetPosition( "2582.94 24.6698 1399.32"); obj.SetOrientation("-180 0 0");
		//------------------------------------------------------
		// Land-side Special
		obj = GetGame().CreateObject("Land_Smokestack_Metal", "0 0 0"); obj.SetPosition( "2690 23.2027 1994.78"); obj.SetOrientation("27 0 0");
		obj = GetGame().CreateObject("Land_Tank_Big", "0 0 0"); obj.SetPosition( "2680.02 10.8301 1995.89"); obj.SetOrientation("-45 0 0");
		obj = GetGame().CreateObject("Land_Mil_Tent_Big4", "0 0 0"); obj.SetPosition( "2624.34 5.95009 1958.76"); obj.SetOrientation("-87 1 -6");
		obj = GetGame().CreateObject("Land_Rail_Warehouse_Small", "0 0 0"); obj.SetPosition( "2703.9 9.14553 1988.83"); obj.SetOrientation("0 0 0");
		obj = GetGame().CreateObject("Land_Misc_Toilet_Mobile", "0 0 0"); obj.SetPosition( "2675.14 7.22083 1977.95"); obj.SetOrientation("-87 0 0");
		obj = GetGame().CreateObject("Land_Misc_Toilet_Mobile", "0 0 0"); obj.SetPosition( "2675.17 7.22083 1979.27"); obj.SetOrientation("-89 0 0");
		//------------------------------------------------------
		// Net Tents near bridge
		obj = GetGame().CreateObject("Land_Mil_CamoNet_Roof_east", "0 0 0"); obj.SetPosition("2678.37 5.34332 1966.04"); obj.SetOrientation("0 0 0");
		obj = GetGame().CreateObject("Land_Mil_CamoNet_Roof_east", "0 0 0"); obj.SetPosition("2641.33 4.8511 1957.22"); obj.SetOrientation("0 0 0");
		//------------------------------------------------------
		// Guardhouse
		obj = GetGame().CreateObject("Land_Sawmill_Illuminanttower", "0 0 0"); obj.SetPosition( "2653.55 12.0782 1947.52"); obj.SetOrientation("0 0 0");
		obj = GetGame().CreateObject("Land_Mil_Guardhouse2", "0 0 0"); obj.SetPosition("2665.25 3.68976 1953.45"); obj.SetOrientation("0 0 0");
		obj = GetGame().CreateObject("Land_Radio_PanelPAS", "0 0 0"); obj.SetPosition("2668.19 2.57883 1950.76"); obj.SetOrientation("180 0 0");
		obj = GetGame().CreateObject("Land_Mil_Tower_Small", "0 0 0"); obj.SetPosition("2668.24 9.78019 1952.16"); obj.SetOrientation("-180 0 0");
		obj = GetGame().CreateObject("Land_BusStation_building", "0 0 0"); obj.SetPosition("2671.62 2.80564 1951.65"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_Ladder", "0 0 0"); obj.SetPosition("2672.23 2.19335 1954.74"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_Wreck_V3S", "0 0 0"); obj.SetPosition("2668.4 4.40857 1960.24"); obj.SetOrientation("180 -11 0");
		obj = GetGame().CreateObject("Land_Guardhouse", "0 0 0"); obj.SetPosition("2656.39 3.44714 1949.95"); obj.SetOrientation("90 0 0");
		//------------------------------------------------------
		// End Prison Island Bridge
		// Prison Walkway
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 4.472 1875.55"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 4.472 1904.55"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 4.472 1846.55"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 4.472 1817.55"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 4.472 1788.55"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 4.472 1759.55"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 4.472 1730.55"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 4.472 1701.55"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 4.472 1672.55"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 4.472 1643.55"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 4.472 1614.55"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 4.472 1585.55"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 4.472 1556.55"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 4.472 1527.55"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 4.472 1498.55"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 4.472 1469.55"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 4.472 1440.55"); obj.SetOrientation("-90 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.45 2.972 1412"); obj.SetOrientation("-90 0 -6");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2676.4 0.272002 1384.64"); obj.SetOrientation("-69.0001 0 -5");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionC", "0 0 0"); obj.SetPosition("2659.11 10.7 1980.75"); obj.SetOrientation("-85 0 0");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2681.44 5.472 1933.39"); obj.SetOrientation("-90 0 -4");
		obj = GetGame().CreateObject("Land_CementWorks_ExpeditionB", "0 0 0"); obj.SetPosition("2678.51 9.04677 1961.67"); obj.SetOrientation("-102 0 -10");
		//------------------------------------------------------
		// End Prison Walkway
		// Start Prison Bridge Debris
		obj = GetGame().CreateObject("Land_Wreck_Uaz", "0 0 0"); obj.SetPosition("2665.67 3.27628 1942.72"); obj.SetOrientation("-49 0 0");
		obj = GetGame().CreateObject("Land_Wreck_Ikarus", "0 0 0"); obj.SetPosition("2665.66 3.62061 1925"); obj.SetOrientation("0 -0 -5");
		obj = GetGame().CreateObject("Land_Wreck_Lada_Green", "0 0 0"); obj.SetPosition("2666.57 3.09459 1932.48"); obj.SetOrientation("-35 0 -4");
		obj = GetGame().CreateObject("Land_Wreck_Lada_Red", "0 0 0"); obj.SetPosition("2660.04 3.09459 1912.42"); obj.SetOrientation("125 -2 0");
		obj = GetGame().CreateObject("Land_Wreck_S1023_Blue", "0 0 0"); obj.SetPosition("2659.66 3.48222 1916.19"); obj.SetOrientation("0 0 3");
		obj = GetGame().CreateObject("Land_Container_1Bo", "0 0 0"); obj.SetPosition("2664.85 3.69233 1899.84"); obj.SetOrientation("-37 -0.5 0");
		obj = GetGame().CreateObject("Land_Container_1Bo", "0 0 0"); obj.SetPosition("2659.07 4.59233 1885.52"); obj.SetOrientation("140 -19 -10");
		obj = GetGame().CreateObject("Land_Wreck_V3S", "0 0 0"); obj.SetPosition("2660.79 3.76648 1889.56"); obj.SetOrientation("13 0 0");
		obj = GetGame().CreateObject("Land_Wreck_Ikarus", "0 0 0"); obj.SetPosition("2661.53 3.82061 1873.69"); obj.SetOrientation("-175 0 -13");
		obj = GetGame().CreateObject("Land_Wreck_Lada_Green", "0 0 0"); obj.SetPosition("12566.2 150.834 6682.4"); obj.SetOrientation("0 0 -0");
		obj = GetGame().CreateObject("Land_Wreck_Lada_Green", "0 0 0"); obj.SetPosition("2661.74 3.09459 1866.62"); obj.SetOrientation("-169 0 0");
		obj = GetGame().CreateObject("Land_Wreck_Lada_Red", "0 0 0"); obj.SetPosition("2662.83 3.09459 1863.19"); obj.SetOrientation("167 0 0");
		obj = GetGame().CreateObject("Land_Wreck_S1023_Beige", "0 0 0"); obj.SetPosition("2660.28 3.43222 1859.45"); obj.SetOrientation("152 0 0");
		obj = GetGame().CreateObject("Land_Wreck_S1023_Blue", "0 0 0"); obj.SetPosition("2668.29 4.03222 1857.5"); obj.SetOrientation("-130 -34 0");
		obj = GetGame().CreateObject("Land_Wreck_Volha_Grey", "0 0 0"); obj.SetPosition("2666.66 3.22003 1853.67"); obj.SetOrientation("-157 0.999999 2");
		obj = GetGame().CreateObject("Land_Wreck_Volha_Blue", "0 0 0"); obj.SetPosition("2665.45 1.75653 1844.56"); obj.SetOrientation("0 0 -0");
		obj = GetGame().CreateObject("Land_Wreck_Volha_Blue", "0 0 0"); obj.SetPosition("2665.51 3.09164 1844.56"); obj.SetOrientation("0 0 -0");
		obj = GetGame().CreateObject("Land_Wreck_Volha_Grey", "0 0 0"); obj.SetPosition("2665.32 1.75658 1835.26"); obj.SetOrientation("0 0 -0");
		obj = GetGame().CreateObject("Land_Wreck_Volha_Grey", "0 0 0"); obj.SetPosition("2665.78 3.09171 1840.51"); obj.SetOrientation("26 0 -2.38419e-07");
		obj = GetGame().CreateObject("Land_Wreck_Volha_Police", "0 0 0"); obj.SetPosition("2659.95 3.16573 1843.63"); obj.SetOrientation("21 -7 7");
		obj = GetGame().CreateObject("Land_Wreck_S1023_Blue", "0 0 0"); obj.SetPosition("2666.44 3.48222 1834.7"); obj.SetOrientation("-37 -2 0");
		obj = GetGame().CreateObject("Land_Wreck_Lada_Red", "0 0 0"); obj.SetPosition("2657.49 3.54459 1823.98"); obj.SetOrientation("105 17 15");
		obj = GetGame().CreateObject("Land_Wreck_Volha_Blue", "0 0 0"); obj.SetPosition("2660.51 3.17003 1821.93"); obj.SetOrientation("139 -2 0");
		obj = GetGame().CreateObject("Land_Wreck_Lada_Green", "0 0 0"); obj.SetPosition("2661.56 3.09459 1818.11"); obj.SetOrientation("-170 0 0");
		obj = GetGame().CreateObject("Land_Wreck_S1023_Beige", "0 0 0"); obj.SetPosition("2659.43 3.43222 1826.35"); obj.SetOrientation("0 0 -0");
		obj = GetGame().CreateObject("Land_Wreck_Ikarus", "0 0 0"); obj.SetPosition("2666.53 3.72061 1812.69"); obj.SetOrientation("-159 -1 0");
		obj = GetGame().CreateObject("Land_Container_1Moh", "0 0 0"); obj.SetPosition("2665.77 3.64233 1798.53"); obj.SetOrientation("156 0 3");
		obj = GetGame().CreateObject("Land_Wreck_Uaz", "0 0 0"); obj.SetPosition("2660.16 3.37628 1782.42"); obj.SetOrientation("0 0 6");
		obj = GetGame().CreateObject("Land_Wreck_Lada_Green", "0 0 0"); obj.SetPosition("2660.75 3.09459 1769.54"); obj.SetOrientation("0 0 -0");
		obj = GetGame().CreateObject("Land_Wreck_S1023_Blue", "0 0 0"); obj.SetPosition("2660.8 3.43222 1762.97"); obj.SetOrientation("0 0 0");
		obj = GetGame().CreateObject("Land_Wreck_V3S", "0 0 0"); obj.SetPosition("2660.8 3.91648 1776.13"); obj.SetOrientation("0 0 0");
		obj = GetGame().CreateObject("Land_Wreck_Volha_Blue", "0 0 0"); obj.SetPosition("2666.95 3.47003 1745.13"); obj.SetOrientation("0 0 -34");
		obj = GetGame().CreateObject("Land_Wreck_Lada_Red", "0 0 0"); obj.SetPosition("2667.59 3.24459 1733.74"); obj.SetOrientation("-144 19 -179");
		obj = GetGame().CreateObject("Land_Wreck_Ikarus", "0 0 0"); obj.SetPosition("2665.7 3.67061 1726.52"); obj.SetOrientation("-167 0 0");
		obj = GetGame().CreateObject("Land_Wreck_Lada_Green", "0 0 0"); obj.SetPosition("2666.83 3.26947 1392.8"); obj.SetOrientation("-31 0 9");
		obj = GetGame().CreateObject("Land_Wreck_Lada_Red", "0 0 0"); obj.SetPosition("2665.7 3.09459 1448.63"); obj.SetOrientation("157 0 9");
		obj = GetGame().CreateObject("Land_Wreck_Lada_Green", "0 0 0"); obj.SetPosition("2664.75 3.39459 1451.72"); obj.SetOrientation("21 -7 -27");
		obj = GetGame().CreateObject("Land_Wreck_Ikarus", "0 0 0"); obj.SetPosition("2664.71 3.67061 1486.37"); obj.SetOrientation("0 0 0");
		obj = GetGame().CreateObject("Land_Wreck_Volha_Grey", "0 0 0"); obj.SetPosition("2667.33 3.42003 1479.27"); obj.SetOrientation("-27 -9 -30");
		obj = GetGame().CreateObject("Land_Wreck_S1023_Beige", "0 0 0"); obj.SetPosition("2666.16 3.43222 1476.22"); obj.SetOrientation("0 0 -6");
		obj = GetGame().CreateObject("Land_Wreck_Volha_Blue", "0 0 0"); obj.SetPosition("2663.62 3.17003 1474.32"); obj.SetOrientation("-139 0 0");
		obj = GetGame().CreateObject("Land_Wreck_S1023_Beige", "0 0 0"); obj.SetPosition("2660.9 3.43222 1520.17"); obj.SetOrientation("180 0 0");
		obj = GetGame().CreateObject("Land_Wreck_V3S", "0 0 0"); obj.SetPosition("2661.88 3.66648 1525.49"); obj.SetOrientation("-133 0 -79");
		obj = GetGame().CreateObject("Land_Wreck_Volha_Blue", "0 0 0"); obj.SetPosition("2661.43 3.17003 1562.42"); obj.SetOrientation("172 18 -180");
		obj = GetGame().CreateObject("Land_Wreck_S1023_Blue", "0 0 0"); obj.SetPosition("2661.3 3.43222 1558.64"); obj.SetOrientation("-180 0 0");
		obj = GetGame().CreateObject("Land_Container_1Bo", "0 0 0"); obj.SetPosition("2660.56 4.34233 1565.47"); obj.SetOrientation("14 -15 -1");
		obj = GetGame().CreateObject("Land_Container_1Bo", "0 0 0"); obj.SetPosition("2665.51 3.69233 1658.48"); obj.SetOrientation("-26 0 -2");
		obj = GetGame().CreateObject("Land_Wreck_Volha_Grey", "0 0 0"); obj.SetPosition("2668.08 4.02003 1592.53"); obj.SetOrientation("-41 -10 0");
		obj = GetGame().CreateObject("Land_Wreck_Lada_Green", "0 0 0"); obj.SetPosition("2665.43 3.14459 1595.14"); obj.SetOrientation("-24 -2 0");
		obj = GetGame().CreateObject("Land_Wreck_Ikarus", "0 0 0"); obj.SetPosition("2665.7 3.57061 1646.74"); obj.SetOrientation("0 0 0");
		//----------------------BLACK MARKET--------------------------------
		obj = GetGame().CreateObject("Land_Mil_CamoNet_Roof_east", "14919 96.9956 13761");
		obj.SetOrientation("140 0 -20");
		obj.SetPosition("14919 96.9956 13761");
		obj.SetOrientation("140 0 -20");

		obj = GetGame().CreateObject("Land_Mil_CamoNet_Roof_east", "14876.5 101.007 13757.5");
		obj.SetOrientation("23 0 -7");
		obj.SetPosition("14876.5 101.007 13757.5");
		obj.SetOrientation("23 0 -7");

		obj = GetGame().CreateObject("Land_Mil_CamoNet_Roof_east", "14919.4 100.079 13716.1");
		obj.SetOrientation("81 0 0");
		obj.SetPosition("14919.4 100.079 13716.1");
		obj.SetOrientation("81 0 0");

		obj = GetGame().CreateObject("Land_Container_1Aoh", "14909.8 99.4901 13709.7");
		obj.SetOrientation("38 0 0");
		obj.SetPosition("14909.8 99.4901 13709.7");
		obj.SetOrientation("38 0 0");

		obj = GetGame().CreateObject("Land_Container_1Mo", "14909.8 102.006 13709.5");
		obj.SetOrientation("21 0 0");
		obj.SetPosition("14909.8 102.006 13709.5");
		obj.SetOrientation("21 0 0");

		obj = GetGame().CreateObject("Land_Mil_GuardShed", "14926.2 98.0812 13706.9");
		obj.SetOrientation("0 0 0");
		obj.SetPosition("14926.2 98.0812 13706.9");
		obj.SetOrientation("0 0 0");

		obj = GetGame().CreateObject("Land_Container_1Moh", "14870.1 99.896 13751");
		obj.SetOrientation("-52 -28 -4.99999");
		obj.SetPosition("14870.1 99.896 13751");
		obj.SetOrientation("-52 -28 -4.99999");

		obj = GetGame().CreateObject("Land_Power_Pole_Conc4_Lamp_Amp", "14914.3 105.516 13740");
		obj.SetOrientation("0 0 0");
		obj.SetPosition("14914.3 105.516 13740");
		obj.SetOrientation("0 0 0");

		obj = GetGame().CreateObject("Land_Mil_Tower_Small", "14874.7 103.128 13766.2");
		obj.SetOrientation("-100 0 0");
		obj.SetPosition("14874.7 103.128 13766.2");
		obj.SetOrientation("-100 0 0");

		obj = GetGame().CreateObject("Land_Mil_Tent_Big4", "14902 100.361 13744.7");
		obj.SetOrientation("-45 0 0");
		obj.SetPosition("14902 100.361 13744.7");
		obj.SetOrientation("-45 0 0");

		obj = GetGame().CreateObject("Land_Misc_Toilet_Mobile", "14882.9 101.463 13743.4");
		obj.SetOrientation("-60 0 0");
		obj.SetPosition("14882.9 101.463 13743.4");
		obj.SetOrientation("-60 0 0");

		obj = GetGame().CreateObject("Land_Misc_Well_Pump_Blue", "14899.3 100.008 13731.5");
		obj.SetOrientation("-30 0 6.00001");
		obj.SetPosition("14899.3 100.008 13731.5");
		obj.SetOrientation("-30 0 6.00001");

		obj = GetGame().CreateObject("Land_Wreck_Uaz", "14917.3 100.892 13731.1");
		obj.SetOrientation("0 12 0");
		obj.SetPosition("14917.3 100.892 13731.1");
		obj.SetOrientation("0 12 0");

		obj = GetGame().CreateObject("Land_Wreck_Volha_Grey", "14920.5 100.653 13727.9");
		obj.SetOrientation("100 11 22");
		obj.SetPosition("14920.5 100.653 13727.9");
		obj.SetOrientation("100 11 22");

		obj = GetGame().CreateObject("Land_Wreck_S1023_Beige", "14885.2 101.404 13737.6");
		obj.SetOrientation("0 0 0");
		obj.SetPosition("14885.2 101.404 13737.6");
		obj.SetOrientation("0 0 0");

		obj = GetGame().CreateObject("Land_Container_1Bo", "14868.9 99.0356 13746.4");
		obj.SetOrientation("0 0 -0");
		obj.SetPosition("14868.9 99.0356 13746.4");
		obj.SetOrientation("0 0 -0");

		obj = GetGame().CreateObject("Land_Container_1Moh", "14870.7 102.199 13746.5");
		obj.SetOrientation("49 13 0");
		obj.SetPosition("14870.7 102.199 13746.5");
		obj.SetOrientation("49 13 0");

		obj = GetGame().CreateObject("Land_Wreck_V3S", "14909.6 100.268 13721.6");
		obj.SetOrientation("-160 0 -44");
		obj.SetPosition("14909.6 100.268 13721.6");
		obj.SetOrientation("-160 0 -44");
	}
};