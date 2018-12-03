
# DayZ Vanilla++ Mod v0.4

**Update: December 1st 2018**

**Version 0.4 is FINALLY HERE! Client SUPPORT! yeeet..Eskidddit...ok enough of that.**

**WORKSHOP SUPPORT FINALLY!** 

**This GitHub post will include Client + Server Files however you won't be able to edit the client side of things...due to it being a signed PBO, thus all players on your server need to subscribe to the mod on steam via this** [Vanilla++ Client Files](https://steamcommunity.com/sharedfiles/filedetails/?id=1578593068) 

**NOTE: PLEASE GO THRU THE SETUP STEPS BEFORE YOU OPEN AN ISSUE!**

### IMPORTANT :
- For those who own a server provide by [Vilayer.com](https://www.Vilayer.com), can auto install the mod via the `AddonManager` (special thanks goes to the Vilayer team)!

![https://www.vilayer.com](https://ci5.googleusercontent.com/proxy/yE1RaRsPdehe3Y5lTBg3K2UmKkKYBPUl4HOLneY8hzalp34EayGB0c8qeUxsz4W_vaGETV57DzOYC1huj7bvJmDlyfIodhIE2p07uyLeVuvkyCvCOmKg=s0-d-e1-ft#https://www.vilayer.com/templates/ColoNode/html/img/logo_dark.png)
-
## Installation: 

**Very IMPORTANT! This mod now has a dependency on using Jacob_Mango's @RPCFramework mod! Get it from [HERE](https://steamcommunity.com/sharedfiles/filedetails/?id=1559212036)**

### Step One:
1. Download Zip from: [Here](https://github.com/Da0ne/DZMods/archive/master.zip)
2. Go to the server's main directory and create a new directory and name the folder anything you desire, but not NewFolder.
3. Open the 'mpmissions' which is located inside of your server directory.
4. Copy 'DayZSurvival.chernarusplus' into this location.

### Step Two:
1. Move your server config file ```serverDZ.cfg``` file into the folder you named in Step One.
2. Open the config file, and change 'dayzOffline.chernarusplus' to 'DayZSurvival.chernarusplus', then save and exit.
3. Place the folder ```@VanillaPlusPlus``` into your server's main directory.

### Step Three:
1. Go to the !workshop folder inside of your DayZ client.
2. Copy the @RPCFramework and it's key to the proper location of your server. 
    - Key Location:
      - server root:/keys 
    - Add-on location:
      - server root:/
3. Change your startup following start-up commandlines to include:

Server:
```bash
-mod=@VanillaPlusPlus;@RPCFramework -config=FolderFromStepOne\serverDZ.cfg -profiles=FolderFromStepOne -name=myServerName -scrAllowFileWrite
```

Client:
```
-mod=@VanillaPlusPlus;@RPCFramework
```

**NOTE: Client can just enable mods through DayZ Launcher**

**NOTE: Make sure you add the keys to the server. Check 'Key' folder.**

**NOTE: The -name command will change the name which shows up in global chat for moments where a player joins, leaves, or is killed.**

**NOTE: If you forget -scrAllowFileWrite then many of stuff would not work, eg load-out system**
---

# Configuration:
- In order to turn on, or off different functionality, check the top of ``'/mpmission/DayZSurvival.chernarusplus/ScriptedMods/Tunables.c'``

# Features:

## In-game Map:
- Just as the header suggests, we created a in-game map for players to use.

![Map Interface](https://steamuserimages-a.akamaihd.net/ugc/963104528643221326/D74C7BB2CA2891C951869C679F3F4D13DE177E69/?interpolation=lanczos-none&output-format=jpeg&output-quality=95&fit=inside%7C637%3A358&composite-to=*,*%7C637%3A358&background-color=black)

## Custom Spawn lodaouts with Spawn Menu.
- This feature allows the server to create loadouts for fresh spawns to spawn with.
- The server owner can also set spawn points around the map.

![SpawnMenu1](https://steamuserimages-a.akamaihd.net/ugc/963104528643225571/1E0C1137F9E62FBD7DC52D8F23E5FA104F733EF3/?interpolation=lanczos-none&output-format=jpeg&output-quality=95&fit=inside%7C637%3A358&composite-to=*,*%7C637%3A358&background-color=black)

![SpawnMenu2](https://steamuserimages-a.akamaihd.net/ugc/963104528643226368/2133CEF77A50687271E10F26C591B865226EAD53/?interpolation=lanczos-none&output-format=jpeg&output-quality=95&fit=inside%7C637%3A358&composite-to=*,*%7C637%3A358&background-color=black)

## Ability to make customized loadouts using the AdminTool .
- This feature allows the server owner to create loadouts for fresh spawns to spawn with. 
- By adding your desired items to \ScriptedMods\LoadOuts\RandomlyGenerated OR Enable Static Loadouts via the Tuneables.c.
- Use the /export loadoutname command via the AdminTools to added a preset players can choose to spawn with. (Only used with Static Loadouts)

## Enable/Disable Stamina
- Add -DisableStamina to your startup commandline to enable, and remove it from your startup commandline to disable.

## Spawn Custom Buildings
- This feature allows the server owner to place CustomBuildings by minimalizing the amount of code needed to spawn in additional buildings.

## Chatbased Admin Tools
- This feature allows the server owner to add Steam 64 IDs into a text file, allowing those users to login using the password set inside of the server.cfg.

**An admin can login by typing the following into DayZ's chat system:**
```
#login mypassword
```

## Player Score/Kill Activity Tracker
- This feature creates two files into the servers profile, and stores detailed kill information and player stats such as total deaths, and kills.

## Chatbased Kill Messages
- Sends chat messages showing who killed who, and who committed suicide.
- UI Coming soon...

### USEFUL THINGS:
- How to generate new loot positions for your custom buildings: https://pastebin.com/FqunXuzc

## CREDITS:
- @Sen ( @zalexki zalexki ) from DayZModders Discord Server for the KillScore system https://github.com/zalexki
