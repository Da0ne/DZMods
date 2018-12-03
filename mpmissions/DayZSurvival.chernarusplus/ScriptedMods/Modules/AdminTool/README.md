
# Admin Tools
NOTE: Remember,the only thing that should seperate the command you using and your arguments should be space, that means no commas as well.
```
Correct Command Usage:
  /strip GravityWolf
Wrong Command Usage:
  /strip "Da0ne" "GravityWolf"
```

### Multiple Argument Commands
| Command  | Purpose | Arguments | Example | 
| ------------- | ------------- | ------------- |  ------------- |
|  /strip  |  Strip targeted players of all gear |  One Player Name | /strip DaOne
|  /tpm   |  Teleports caller to another player  |  One Player Name | /tpm Danny
|  /tpp   |  Teleports player to caller |  One Player name| /ttp BoobMan
|  /tpto  |  Teleports caller to preset location on the map |  One Location argument: see [Locations](https://github.com/D/DZMods/new/master/mpmissions/DayZSurvival.chernarusplus/ScriptedMods/Modules/AdminTool#locations) | /tpto 
|  /tpc   |  Teleports caller to point on the map | X coordinate, Z coordinate, Y coordinate  | Correct usage: 7500 0 7500 Wrong Usage: 7500,7500,0
|  /spi   |  Spawns item in callers inventory |  One name of item | /spi M4A1
|  /spg   |  Spawns item on the ground around caller |  One name of item | /spg AKM
|  /export|  Exports current inventory into Static Loadouts, can be used by players if staticloadouts is active in AdvancedLoadouts.c| Provide a unique name for your loadout| /export HazmatSuit
| /savePoint |  Saves a location point to be used by people who are spawning | Provide a unique spawn point name| /savePoint ChernoSouthSpawn

### No Argument Commands
| Command  | Purpose |
| ------------- | ------------- |
|  /ammo  |   Reloads and repairs callers current weapon |
|  /updateLoadouts |  Updates 'RandomlyGenerated loadouts |
|  /freecam |  Allows the caller to freely fly around the map while character remain, use command again to exit.  |
|  /nighttime |  Turns server time to night  |
|  /daytime |  Turns server time to day |
|  /heal |  Heals the caller |
|  /kill |  Kills the caller |
|  /tpalltome |  Teleports all players to caller |
|  /killall |  Kills every player on the server except the Admin |
|  /spawncar | Spawns a fully equipped Hackback with fluids |
|  /refuel |  Refules cars that are close to the caller |
|  /debug |  Turns on the Debug Monitor  |

### Locations:
| Names | Location Arguments|
| ------------- | ------------- |
| Serverograd | Severograd |
|Krasnostav|Krasnostav|
|Mogilevka|Mogilevka|
|Stary Sobor|Stary|
|Msta|Msta|
|Vybor|Vybor|
|Gorka|Gorka|
|Solni|Solni|
|North Weat Airfield South | NWAFS|
|North Weat Airfield Center | NWAFC|
|North Weat Airfield North|NWAFN|
|Balota Airfield | BAF|
|North East Airfield | NEAF|
|Chernogorsk Center | ChernoC|
|Chernogorsk West | ChernoW|
|Chernogorsk East | ChernoE|
|Elektro West | ElektroW|
|Elektro East | ElektroE|
|Berezino Center | BerezC|
|Berezino South |BerezS|
|Berezino North | BerezN|
|Svetlojarsk | Svet|
|Zelenogorsk South | ZelenoS|
|Zelenogorsk North | ZelenoN|
|Lopatino | Lopatino|
|Tisy|Tisy|
|Novaya|Novaya|
|Grishino|Grishino|
|Kabanino|Kabanino|
