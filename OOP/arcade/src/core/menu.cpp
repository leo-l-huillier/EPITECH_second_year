/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** menu
*/
#include "core.hpp"
#include <vector>

namespace arcade {
    enum changes {
        Left,
        Right,
        Up,
        Down,
        None
    };

    /**
     * @brief Get the Game Lib Name object
     * @author leo
     * @param gameLib
     * @return std::string
     */
    std::string getGameLibName(enum gameLibs gameLib) {
        switch (gameLib) {
        case Snake:
            return "snake";
        case Nibbler:
            return "nibbler";
        case Pacman:
            return "pacman";
        case Centipede:
            return "centipede";
        case Qix:
            return "qix";
        case Solarfox:
            return "solarfox";
        }
        return "";
    }

    /**
     * @brief Get the Display Lib Name object
     * @author leo
     * @param displayLib
     * @return std::string
     */
    std::string getDisplayLibName(enum displayLibs displayLib) {
        switch (displayLib) {
        case Allegro:
            return "allegro";
        case Aalib:
            return "aalib";
        case Caca:
            return "caca";
        case Gtk:
            return "gtk";
        case Irrlicht:
            return "irrlicht";
        case Ncurses:
            return "ncurses";
        case Ndk:
            return "ndk";
        case OpenGL:
            return "opengl";
        case Qt5:
            return "qt5";
        case SDL2:
            return "sdl2";
        case SFML:
            return "sfml";
        case Vulkain:
            return "vulkain";
        case Xlib:
            return "xlib";
        }
        return "";
    }

    /**
     * @brief highlight the selected game or library
     * @author leo
     * @param events
     * @param pos
     * @param games only use to get the size of the list TODO: change that
     * @param displays only use to get the size of the list TODO: change that
     * @return std::pair<int, int>
     */
    std::pair<int, int> changePos(const std::list<Event> &events, std::pair<int, int> pos, std::vector<std::string> games, std::vector<std::string> displays) {
        for (auto event : events) {
            switch (event.type) {
                case EventType::Right:
                    if (pos.second > -1)
                        return {pos.first, pos.second};
                    return {pos.second, pos.first};
                case EventType::Left:
                    if (pos.first > -1)
                        return {pos.first, pos.second};
                    return {pos.second, pos.first};
                case EventType::Up:
                    if (pos.first > -1 && pos.first > 0)
                        return {pos.first - 1, pos.second};
                    else if (pos.second > -1 && pos.second > 0)
                        return {pos.first, pos.second - 1};
                    return {pos.first, pos.second};
                case EventType::Down:
                    if (pos.first > -1 && pos.first < displays.size() - 1)
                        return {pos.first + 1, pos.second};
                    else if (pos.second > -1 && pos.second < games.size() - 1)
                        return {pos.first, pos.second + 1};
                    return {pos.first, pos.second};
            }
        }
        return {pos.first, pos.second};
    }

    /**
     * @brief display the menu and highlight the selected game or library
     * @author leo
     * @param pos
     * @param events
     * @param displayModule
     * @param games
     * @param displays
     * @param name
     * @return std::pair<int, int> pos
     */
    std::pair<int, int> displayMenu(std::pair<int, int> pos, std::list<Event> events, IDisplayModule *displayModule, std::vector<std::string> games, std::vector<std::string> displays, std::string name) {
        float j = 6;
        pos = changePos(events, pos, games, displays);
        displayModule->displayText("Display", { 2, 1 });
        for (int i = 0; i < displays.size(); i++) {
            if (i == pos.first) displayModule->displayText(displays[i], { 3, j });
            else displayModule->displayText(displays[i], { 2, j });
            j+=5;
        }
        j = 6;
        displayModule->displayText("Games", { 25, 1 });
        for (int i = 0; i < games.size(); i++) {
            if (i == pos.second) displayModule->displayText(games[i], { 27, j });
            else displayModule->displayText(games[i], { 25, j });
            j+=5;
        }
        displayModule->displayText("Presse 'r' and go", { 45, 1 });
        displayModule->displayText("back to the", { 45, 6 });
        displayModule->displayText("terminal to enter", { 45, 11 });
        displayModule->displayText("your name", { 45, 16 });

        if (name.size() == 0) displayModule->displayText("Name : not set yet" , { 45, 21 });
        else displayModule->displayText("Name : " + name, { 45, 26 });
        displayModule->refresh();
        displayModule->clear();
        return pos;
    }

    /**
     * @brief fill the vector with the games names
     * @author leo
     * @param core
     * @return std::vector<std::string> games
     */
    std::vector<std::string> fillGames(Core *core) {
        std::vector<std::string> games;
        for (auto lib : core->_gameLibs) {
            std::string temp = lib.first;
            games.push_back(temp);
        }
        return games;
    }

    /**
     * @brief fill the vector with the displays names
     * @author leo
     * @param core
     * @return std::vector<std::string> displays
     */
    std::vector<std::string> fillDisplays(Core *core) {
        std::vector<std::string> displays;
        for (auto lib : core->_displayLibs) {
            std::string temp = lib.first;
            displays.push_back(temp);
        }
        return displays;
    }

    /**
     * @brief Print the menu and handle the events. THIS FUNCTION CALL THE GAME LOOP
     * @author leo
     * @param display
     * @param core
     * @return int
     */
    int Menu(IDisplayModule *display, Core *core, std::string firstDisplay) {
        IDisplayModule *displayModule = display;

        std::vector<std::string> games = fillGames(core);
        std::vector<std::string> displays = fillDisplays(core);
        std::pair<int, int> pos = { 0, -1 };
        std::string name;
        std::string tempDisplay = firstDisplay;
        std::string tempGame;

        while (1) {
            std::list<Event> events = displayModule->pollEvent();
            for (auto event : events) {
                if (event.type == EventType::ReturnToSelectionMenu) {
                    if (pos.first > -1) {
                        std::cout << "new display lib selected" << std::endl;
                        tempDisplay = displays[pos.first];
                        delete(displayModule);
                        displayModule = createDisplayModule(core->_displayLibs[tempDisplay].second);
                    }
                    if (pos.second > -1) {
                        std::cout << "game selected" << std::endl;
                        tempGame = games[pos.second];
                        return gameLoop(core, displayModule, createGameModule(core->_gameLibs[tempGame].second), games, displays, tempGame, tempDisplay);
                    }
                }
                if (event.type == EventType::RestartGame) {
                    std::cout << "you can write your name here and press enter :" << std::endl;
                    std::cin >> name;
                    core->setName(name);
                    if (core->getName() == name)
                        std::cout << "your name has been set, have a great time '" << name << "' !" << std::endl;
                    else std::cout << "your name has not been set" << std::endl;
                }
                if (event.type == EventType::Quit) {
                    delete(displayModule);
                    closeAllLibs(core);
                    std::cout << "thank you for playing our game" << std::endl;
                    return 0;
                }
            }
            pos = displayMenu(pos, events, displayModule, games, displays, name);
        }
    }
} // namespace arcade