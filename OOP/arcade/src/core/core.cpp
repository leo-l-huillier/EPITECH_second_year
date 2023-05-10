/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** core
*/
#include "core.hpp"
#include "../errors/errors.hpp"

#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>

namespace arcade {
    /**
     * @brief check if the lib has to change
     * @author leo
     * @param events list of events
     * @return enum libChange
     */
    enum libChange checkLibChange(const std::list<Event> &events) {
        for (auto event : events) {
            switch (event.type) {
            case EventType::SwitchToNextGame:
                return libChange::NextGame;
            case EventType::SwitchToPreviousGame:
                return libChange::PreviousGame;
            case EventType::ReturnToSelectionMenu:
                return libChange::ReturnToSelectionMenu;
            case EventType::NextLibrary:
                return libChange::NextLibrary;
            case EventType::PreviousLibrary:
                return libChange::PreviousLibrary;
            case EventType::RestartGame:
                return libChange::Restart;
            case EventType::Quit:
                return libChange::Quit;
            default:
                return libChange::None;
            }
        }
        return libChange::None;
    }

    /**
     * @brief game loop
     * @author leo
     * @param core
     * @param displayModule
     * @param gameModule
     * @return int TODO cahge that to return nothing or throw an error
     */
    int gameLoop(Core *core, IDisplayModule *displayModule, IGameModule *gameModule, std::vector<std::string> games, std::vector<std::string> displays, std::string gameName, std::string displayName) {
        std::string stringDisplay = displayName;
        std::string stringGame = gameName;

        gameModule->start(*core);
        while (1) {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            std::list<Event> events = displayModule->pollEvent();
            if (checkLibChange(events) == libChange::None)                  gameModule->tick(*displayModule, events);
            if (checkLibChange(events) == libChange::NextGame) {            delete(gameModule);         stringGame = nextIndex(games, stringGame);              gameModule = createGameModule(core->_gameLibs[stringGame].second);              continue; }
            if (checkLibChange(events) == libChange::PreviousGame) {        delete(gameModule);         stringGame = previousIndex(games, stringGame);          gameModule = createGameModule(core->_gameLibs[stringGame].second);              continue; }
            if (checkLibChange(events) == libChange::NextLibrary) {         delete(displayModule);      stringDisplay = nextIndex(displays, stringDisplay);     displayModule = createDisplayModule(core->_displayLibs[stringDisplay].second);  continue; }
            if (checkLibChange(events) == libChange::PreviousLibrary) {     delete(displayModule);      stringDisplay = previousIndex(displays, stringDisplay); displayModule = createDisplayModule(core->_displayLibs[stringDisplay].second);  continue; }
            if (checkLibChange(events) == libChange::ReturnToSelectionMenu) {                           return Menu(displayModule, core, stringDisplay); }
            if (checkLibChange(events) == libChange::Restart) {             delete(gameModule);                                                                 gameModule = createGameModule(core->_gameLibs[stringGame].second);              continue; }
            if (checkLibChange(events) == libChange::Quit) { break; }
        }
        deleteAllModules(displayModule, gameModule);
        closeAllLibs(core);
        std::cout << "thank you for playing our game" << std::endl;
        return 0;
    }

    /**
     * @brief Core of the program were display and game modules are created,linked and deleted
     * @author leo
     * @param argc
     * @param argv
     * @return int
     */
    int core(char *displayModule) {
        try {
            Core *core = chargeAllLibs();
            std::string firstDisplay = findDisplayLib(core, displayModule);
            IDisplayModule *displayModule = createDisplayModule(core->_displayLibs[firstDisplay].second);
            return Menu(displayModule, core, firstDisplay);
        }
        catch (std::exception &e) {
            std::cerr << e.what() << dlerror() << std::endl;
            return 84;
        }
        return 0;
    }
} // namespace arcade

/**
 * @brief display help information
 * @author leo
 */
void help() {
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./arcade ./lib/[LIBRARY]" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tLIBRARY\t\tlibrary in which the menu will open." << std::endl;
    std::cout << "\tYou can find it in the lib directory." << std::endl;
    std::cout << "MENU" << std::endl;
    std::cout << "\tOn the menu you can select another library to display the menu or the game in pressing enter key." << std::endl;
    std::cout << "\tYou can also choose a game to play or enter your GAM3R name in pressing 'r' key ." << std::endl;
    std::cout << "GAME" << std::endl;
    std::cout << "\tIn game, you can move using ←, ↑, → or ↓ key." << std::endl;
    std::cout << "\tyou can change game using + or - key." << std::endl;
    std::cout << "\tyou can change restart the game using 'r' key" << std::endl;
    std::cout << "\tyou can change pause the game using escape key." << std::endl;
    std::cout << "\tyou can quit pause the game using backspace key." << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << "\tfor more information you can execute 'make docs'." << std::endl;
}

/**
 * @brief Error handling for the program
 * @author leo
 * @param argc
 * @return int
 */
static int errorHandling(char **argv, int argc) {
    if (argc != 2 || std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help") {
        help();
        return 84;
    }
    return 0;
}

/**
 * @brief Main function of the program
 * @author Evan
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char **argv) {
    if (errorHandling(argv, argc) == 84) return 84;
    return arcade::core(argv[1]);
}
