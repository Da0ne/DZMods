# DayZ Vanilla++ Mission by DaOne v0.2
#### DO NOT sign the mod ModdedScripts, if you do then verifySignature would not work!!

#### Future Plans & updates:
 -Support for client side.
	-UI for trader system, admin tool interface/panel, Customizable map UI, Killfeed UI
 - Fully Customizable Randomized AI server events.
 - Support of 'event mode' ( switching the server from survival to PvP style with ability to customize playzones,match duration etc )
----------------------------------------------------------------------------------------------------------------------
### IMPORTANT : For those who own a server provide by [www.Vilayer.com](Vilayer.com), can auto install the mod via the `AddonManager` (special thanks goes to the Vilayer team)!
![Vilayer.com](https://ci5.googleusercontent.com/proxy/yE1RaRsPdehe3Y5lTBg3K2UmKkKYBPUl4HOLneY8hzalp34EayGB0c8qeUxsz4W_vaGETV57DzOYC1huj7bvJmDlyfIodhIE2p07uyLeVuvkyCvCOmKg=s0-d-e1-ft#https://www.vilayer.com/templates/ColoNode/html/img/logo_dark.png)
----------------------------------------------------------------------------------------------------------------------

## Installation:
#### NOTE: If you have previously edited your loot XMLs, make sure you replace the XMLs inside of DayZSurvival.chernarusplus'.
#### NOTE: The db folder contains NO MODDED features/changes, and is 100% vanilla; this is the same with other XML files.

## Step One:
##### 	1. Go to the server's main directory and create a new directory and name the folder anything you desire, but not NewFolder.
##### 	2. Open the 'mpmissions' which is located inside of your server directory.
##### 	3. Copy 'DayZSurvival.chernarusplus' into this location.

## Step Two:
##### 1. Back back to the servers main directory, and move the 'serverDZ.cfg' file into the folder you named in Step One.
##### 2. Open the config file, and change 'dayzOffline.chernarusplus' to 'DayZSurvival.chernarusplus', then save and exit.

## Step Three:
##### 1. Place the 'ModdedScripts' directory into your server's main directory.

## Step Four:
##### 1. Change your startup command line to:
```bash
-mod=ModdedScripts -config=FolderFromStepOne\serverDZ.cfg -profiles=FolderFromStepOne -name=myServerName -scrAllowFileWrite
```
#### NOTE: The -name tag will change the name which shows up in global chat for moments where a player joins, leaves, or is killed.
#### NOTE: If you forget -scrAllowFileWrite than the server save your custom loadouts.

# ----Features----

## -Enable/Disable player Join/leave messages. Check the file "Settings.C"

## Custom Spawn lodaouts.
### This feature allows the server to create loadouts for fresh spawns to spawn with.

## Enable/Disable Stamina
### Add -DisableStamina to your startup commandline to enable, and remove it from your startup commandline.

## Spawn Custom Buildings
### This feature allows the server owner to place CustomBuildings by minimalizing the amount of code needed to spawn in additional buildings.

## Chatbased Admin Tools
### This feature allows the server owner to add Steam 64 IDs into a text file, allowing those users to login using the password set inside of the server.cfg.
### An admin can login by typing the following into DayZ's chat system:
```
#login mypassword
```
## Player Score/Kill Activity Tracker
### This feature creates two files into the servers profile, and stores detailed kill information and player stats such as total deaths, and kills.
## Chatbased Kill Messages
### Sends chat messages showing who killed who, and who committed suicide.

### USEFUL THINGS:
#### How to generate new loot positions for your custom buildings: https://pastebin.com/FqunXuzc

## CREDITS:
### @Sen ( @zalexki zalexki ) from DayZModders Discord Server for the KillScore system https://github.com/zalexki
