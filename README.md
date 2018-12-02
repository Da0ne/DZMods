
# DayZ Vanilla++ Mod v0.4

**Update: December 1st 2018**

**Version 0.4 is FINALLY HERE! Client SUPPORT! yeeet..Eskidddit...ok enough of that.**

**WORKSHOP SUPPORT FINALLY!** 

**This GitHub post will include Client + Server Files however you won't be able to edit the client side of things...due to it being a signed PBO, thus all players on your server need to subscribe to the mod on steam via this** [Vanilla++ Client Files](https://steamcommunity.com/sharedfiles/filedetails/?id=1578593068) 

**NOTE: PLEASE GO THRU THE SETUP STEPS BEFORE YOU OPEN AN ISSUE!**

- New Features: 
  - Added: Spawn Selection Menu
    - Usage: Players are able to select where to spawn with startup gear of their choosing!Spawn points are editable by server admins via the AdminTool and Tunables. Individual Cooldown intervals are included for each spawn point.
  - Added: Map UI
    - Usage:
      - Toggled by any player who presses the Insert key on their keyboards.
    - Features: 
      - Marker placement, and saving.
      - Color chooser.
      - Remove from list.
      - Ability to zoom in and out.
- Added:
  - Commands:
    - Added:
      - savepoint: Saves current admin location and adds it as a spawn point for players to use during the spawn scene.
        - Usage: Login as admin, type the command /savePoint followed by a name you wish to give the spawn point.
        - Note: Make sure you don't include a duplicate name or else the point will not be added! eg. /savePoint Berezino-South
      - refuel: Refules vehicles that are close to the Admin.
        - Usage: Login as admin, type the command /refuel while close to a car, and boom. Done.
    - Changed:
      - updateLoadouts:
        - Change: only works with RandomlyGenerated loadout group. Static loadouts are auto updated upon exporting.
      - heal:
        - Change: Stops bleeding
- Bug Fixes:
  - Fixed:
    - Fixing different casting problems, and identifying how to avoid them in our day to day development.
    - Mutiple null points, and logical errors.
    - So many things, it's hard to keep a log of them.

### IMPORTANT :
- For those who own a server provide by [Vilayer.com](https://www.Vilayer.com), can auto install the mod via the `AddonManager` (special thanks goes to the Vilayer team)!

![https://www.vilayer.com](https://ci5.googleusercontent.com/proxy/yE1RaRsPdehe3Y5lTBg3K2UmKkKYBPUl4HOLneY8hzalp34EayGB0c8qeUxsz4W_vaGETV57DzOYC1huj7bvJmDlyfIodhIE2p07uyLeVuvkyCvCOmKg=s0-d-e1-ft#https://www.vilayer.com/templates/ColoNode/html/img/logo_dark.png)
-
## Installation: 

### Step One:
1. Go to the server's main directory and create a new directory and name the folder anything you desire, but not NewFolder.
2. Open the 'mpmissions' which is located inside of your server directory.
3. Copy 'DayZSurvival.chernarusplus' into this location.

### Step Two:
1. Move your server config file ```serverDZ.cfg``` file into the folder you named in Step One.
2. Open the config file, and change 'dayzOffline.chernarusplus' to 'DayZSurvival.chernarusplus', then save and exit.
3. Place the folder ```@VanillaPlusPlus``` into your server's main directory. 
4. ### Very IMPORTANT! This mod now has a dependency on using Jacob_Mango's @RPCFramework mod! Get it from [HERE](https://steamcommunity.com/sharedfiles/filedetails/?id=1559212036)

### Step Three:
1. Change your startup command line to include:

```bash
-mod=@VanillaPlusPlus;@RPCFramework -config=FolderFromStepOne\serverDZ.cfg -profiles=FolderFromStepOne -name=myServerName -scrAllowFileWrite
```
NOTE: Make sure you add the keys to the server. Check 'Key' folder.
NOTE: The -name command will change the name which shows up in global chat for moments where a player joins, leaves, or is killed.
NOTE: If you forget -scrAllowFileWrite then many of stuff would not work, eg load-out system

# Configuration:
- In order to turn on, or off different functionality, check the top of ``'/mpmission/DayZSurvival.chernarusplus/ScriptedMods/Tunables.c'``

## Features:
### Ability to make customized loadouts using the AdminTool .
- This feature allows the server owner to create loadouts for fresh spawns to spawn with. By adding your desired items to ```\ScriptedMods\LoadOuts\RandomlyGenerated``` OR Enable Static Loadouts via the ```Tuneables.c``` and use the ```/export loadoutname``` command via the AdminTools to added a preset so players can have the ability to choose it on spawn!

### Enable/Disable Stamina
### Spawn Custom Buildings

### Chatbased Admin Tools ( UI SUPPORT COMING SOON! )
- This feature allows the server owner to add Steam 64 IDs into a text file, allowing those users to login using the password set inside of the server.cfg.

#### An admin can login by typing the following into DayZ's chat system:
```
#login mypassword
```

### Player Score/Kill Activity Tracker
- This feature creates two files into the servers profile, and stores detailed kill information and player stats such as total deaths, and kills.

### Chatbased Kill Messages ( UI COMING SOON! )
- Sends chat messages showing who killed who, and who committed suicide.

### USEFUL LINKS:
- How to generate new loot positions for your custom buildings: https://pastebin.com/FqunXuzc
- Full List of Admin Commands: [Here](https://github.com/Da0ne/DZMods/blob/master/mpmissions/DayZSurvival.chernarusplus/ScriptedMods/Modules/AdminTool/README.md)

## CREDITS:
- GravityWolf #6981 || Code Snippets, BuildingSpawner script, overall contribution to the mod! github.com/GravityWolfNotAmused
- @Sen ( @zalexki zalexki ) from DayZModders Discord Server for the KillScore system https://github.com/zalexki
