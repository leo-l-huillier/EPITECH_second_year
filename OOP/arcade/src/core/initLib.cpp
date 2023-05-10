/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** initLib.cpp
*/
#include "core.hpp"

namespace arcade {

        /**
     * @brief Open a library
     * @authors leo
     * @param libName name of the library .so
     * @throw cannotOpenLibrary
     * @return void*
     */
    void *openLib(const char *libName) {
        void *lib = dlopen(libName, RTLD_LAZY);
        if (!lib) throw cannotOpenLibrary();
        return lib;
    }

    /**
     * @brief Get the All Display Modules object
     * @author leo
     * @param core
     * @param file
     */
    static Core *getAllDisplayModules(Core *core, const char *file) {
        if (strstr(file, "ncurses") != 0) {
        core->_displayLibs["ncurses"] = std::make_pair(Ncurses, openLib(file));
         return core;
        } else if (strstr(file, "sdl2") != 0) {
             core->_displayLibs["sdl2"] = std::make_pair(SDL2 , openLib(file));
             return core;
        } else if (strstr(file, "ndk++.") != 0) {
            core->_displayLibs["ndk"] = std::make_pair(Ndk, openLib(file));
            return core;
        } else if (strstr(file, "aalib") != 0) {
            core->_displayLibs["aalib"] = std::make_pair(Aalib, openLib(file));
             return core;
        } else if (strstr(file, "libcaca") != 0) {
            core->_displayLibs["libcaca"] = std::make_pair(Caca, openLib(file));
            return core;
        } else if (strstr(file, "allegro") != 0) {
             core->_displayLibs["allegro"] = std::make_pair(Allegro, openLib(file));
             return core;
        } else if (strstr(file, "xlib") != 0) {
            core->_displayLibs["xlib"] = std::make_pair(Xlib, openLib(file));
            return core;
        } else if (strstr(file, "gtk+") != 0) {
            core->_displayLibs["gtk"] = std::make_pair(Gtk, openLib(file));
            return core;
        } else if (strstr(file, "sfml") != 0) {
            core->_displayLibs["sfml"] = std::make_pair(SFML, openLib(file));
             return core;
        } else if (strstr(file, "irrlicht") != 0) {
            core->_displayLibs["irrlicht"] = std::make_pair(Irrlicht, openLib(file));
             return core;
        } else if (strstr(file, "opengl") != 0) {
            core->_displayLibs["opengl"] = std::make_pair(OpenGL, openLib(file));
            return core;
        } else if (strstr(file, "vulkan") != 0) {
             core->_displayLibs["vulkain"] = std::make_pair(Vulkain, openLib(file));
             return core;
        } else if (strstr(file, "qt5") != 0)
            core->_displayLibs["qt5"] = std::make_pair(Qt5, openLib(file));
            return core;
    }

    /**
     * @brief Get the All Game Modules object
     * @author leo
     * @param core
     * @param file
     */
    static Core *getAllGameModules(Core *core, const char *file) {
        if (strstr(file, "snake") != 0) {
            core->_gameLibs["snake"] = std::make_pair(Snake , openLib(file));
            return core;
        } else if (strstr(file, "nibbler") != 0) {
            core->_gameLibs["nibbler"] = std::make_pair(Nibbler, openLib(file));
            return core;
        } else if (strstr(file, "qix") != 0) {
            core->_gameLibs["qix"] = std::make_pair(Qix, openLib(file));
            return core;
        } else if (strstr(file, "centipede") != 0) {
            core->_gameLibs["centipede"] = std::make_pair(Centipede, openLib(file));
         return core;
        } else if (strstr(file, "solarfox.") != 0) {
            core->_gameLibs["solarfox"] = std::make_pair(Solarfox, openLib(file));
            return core;
        } else if (strstr(file, "pacman") != 0)
            core->_gameLibs["pacman"] = std::make_pair(Pacman, openLib(file));
            return core;
    }

    /**
     * @brief Get the All Libs object and fill core->_displayLibs and core->_gameLibs
     * @author leo
     * @param core
     * @param firstDisplay
     */
    Core *chargeAllLibs(void) {
        Core *core = new Core();

        std::string path = "./lib/";
        for (const auto & entry : std::filesystem::directory_iterator(path)) {
            std::string path = entry.path();
            core = getAllDisplayModules(core, path.c_str());
            core = getAllGameModules(core, path.c_str());
        }
        return core;
    }

} // namespace arcade
