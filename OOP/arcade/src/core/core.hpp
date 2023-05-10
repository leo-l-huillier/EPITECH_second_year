/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** core.hpp
*/
#pragma once
#include "../interfaces/IDisplayModule.hpp"
#include "../interfaces/IGameModule.hpp"
#include "../interfaces/ICore.hpp"
#include "../errors/errors.hpp"

#include <iostream>
#include <vector>
#include <map>
#include <filesystem>
#include <tuple>
#include <dlfcn.h>
#include <cstring>

namespace arcade {
    enum gameLibs {
        Snake,
        Nibbler,
        Pacman,
        Centipede,
        Qix,
        Solarfox
    };

    enum displayLibs {
        Ncurses,
        SFML,
        SDL2,
        Aalib,
        Caca,
        OpenGL,
        Allegro,
        Gtk,
        Xlib,
        Irrlicht,
        Qt5,
        Vulkain,
        Ndk
    };

    enum class libChange {
        NextGame,
        PreviousGame,
        NextLibrary,
        PreviousLibrary,
        ReturnToSelectionMenu,
        Restart,
        Quit,
        None
    };
    class Core: public ICore {
        std::string _name;

    public:
        std::map<std::string, std::pair<enum gameLibs, void *>> _gameLibs;
        std::map<std::string, std::pair<enum displayLibs, void *>> _displayLibs;

        Core() {}
        ~Core() {};

        void setName(const std::string &name) {
            _name = name;
        }
        const std::string &getName() const {
            return _name;
        }
    };

    //chargeLib
    IDisplayModule *createDisplayModule(void *lib);
    IGameModule *createGameModule(void *lib);
    IGameModule *nextGame(Core *core, IGameModule *gameModule, std::vector<std::string> &gameLibs);
    IDisplayModule *nextDisplay(Core *core, IDisplayModule *displayModule, std::vector<std::string> &displayLibs);
    std::string previousIndex(std::vector<std::string> lib, std::string curent);
    std::string nextIndex(std::vector<std::string> lib, std::string curent);

    //initLib
    Core *chargeAllLibs(void);
    void *openLib(const char *libName);

    //closeLib
    void closeAllLibs(Core *core);
    void deleteAllModules(IDisplayModule *displayModule, IGameModule *gameModule);

    //findLib
    std::string findDisplayLib(Core *core, char *file);
    std::string findDisplay(Core *core, enum displayLibs libs);
    std::string findGame(Core *core, enum gameLibs libs);

    //menu
    int Menu(IDisplayModule *display, Core *core, std::string firstDisplay);
    std::string getGameLibName(enum gameLibs gameLib);
    std::string getDisplayLibName(enum displayLibs displayLib);

    //core
    int gameLoop(Core *core, IDisplayModule *displayModule, IGameModule *gameModule, std::vector<std::string> games, std::vector<std::string> displays, std::string gameName, std::string displayName);
}