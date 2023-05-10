# Arcade
## How to launch
## The purpose of the project
## How the project works
## How to implement new graphic libraries or new games?
## People on the project
## Intergroup team leader

<br />
<br />
<br />
<br />
<br />
<br />

## How to launch
to launch the project you just have to execute make and then call the binary
```
./arcade ./lib/$(name of the lib) 
```
For example you can execute 
```
./arcade ./lib/arcade_sfml.so
```


## The purpose of the project
Arcade is a Project  where a core handle games libraries and display libraries. These libraries are dynamics libraries and must be created by the group. There is also for this project a group of groups. It must be possible to exchange libraries between groups, and the core must handle it and make it works.  


## How to implement new graphic libraries or new games?

To implement a new display library, you just have to code the function you can find in the IDisplayModule in a class that inherit from IDisplayModule.hpp with the graphic library you want to implement.  
To create a new game library, you also have to create a function tick that you can find in the IGameModule in a class that inherit from IGameModule.hpp. And in this function you have to call IDisplay functions that follow your game logic.

## People on the project
leo.l-huillier@epitech.eu <br />
pier-alexandre.rosa@epitech.eu <br />
evan.labourdette@epitech.eu <br />

## Intergroup team leader
romain.schneider@epitech.eu