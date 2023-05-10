/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** closeLib.cpp
*/
#include "core.hpp"

namespace arcade {

    /**
     * @brief delete a display and a game module
     * @author leo
     * @param displayModule
     * @param gameModule
     */
    void deleteAllModules(IDisplayModule *displayModule, IGameModule *gameModule) {
        delete(displayModule);
        delete(gameModule);
    }

    /**
     * @brief Close a library
     * @authors leo
     * @param lib created by openLib
     * @throw cannotCloseLibrary
     * @return int
     */
    static int closeLib(void *lib) {
        if (dlclose(lib) != 0) throw cannotCloseLibrary();
        return 0;
    }

    /**
     * @brief Close all libraries
     * @author leo
     * @param core
     */
    void closeAllLibs(Core *core) {
        for (auto &displayLib : core->_displayLibs) {
            closeLib(displayLib.second.second);
        }
        for (auto &gameLib : core->_gameLibs) {
            closeLib(gameLib.second.second);
        }
        delete(core);
    }
} // namespace arcade