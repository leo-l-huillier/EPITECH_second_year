/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** findLib.cpp
*/
#include "core.hpp"

namespace arcade {
    /**
     * @brief Find a display library
     * @author leo
     * @param core
     * @param file
     * @return int number of the library
     */
    std::string findDisplayLib(Core *core, char *file) {
        if (strstr(file, "ncurses") != 0)
            return "ncurses";
        if (strstr(file, "sdl2") != 0)
            return "sdl2";
        if (strstr(file, "ndk++.") != 0)
            return "ndk++";
        if (strstr(file, "aalib") != 0)
            return "aalib";
        if (strstr(file, "libcaca") != 0)
            return "libcaca";
        if (strstr(file, "allegro") != 0)
            return "allegro";
        if (strstr(file, "xlib") != 0)
            return "xlib";
        if (strstr(file, "gtk+") != 0)
            return "gtk";
        if (strstr(file, "sfml") != 0)
            return "sfml";
        if (strstr(file, "irrlicht") != 0)
            return "irrlicht";
        if (strstr(file, "opengl") != 0)
            return "opengl";
        if (strstr(file, "vulkan") != 0)
            return "vulkan";
        if (strstr(file, "qt5") != 0)
            return "qt5";
        return "";
    }

    /**
     * @brief Find a game library
     * @author leo
     * @param core
     * @param libs
     * @return int
     */
    std::string findGame(Core *core, enum gameLibs libs) {
        for (auto &game : core->_gameLibs) {
            if (game.second.first == libs)
                return game.first;
        }
        return "";
    }

    /**
     * @brief Find a display library
     * @author leo
     * @param core
     * @param libs
     * @return int
     */
    std::string findDisplay(Core *core, enum displayLibs libs) {
        for (auto &display : core->_displayLibs) {
            if (display.second.first == libs)
                return display.first;
        }
        return "";
    }
} // namespace arcade
