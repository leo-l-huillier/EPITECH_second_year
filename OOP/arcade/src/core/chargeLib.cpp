/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** chargeLib.cpp
*/
#include "core.hpp"

namespace arcade {

    /**
     * @brief Create a Display Module object
     * @authors leo
     * @param lib created by openLib
     * @throw cannotCreateModule
     * @return IDisplayModule*
     */
    IDisplayModule *createDisplayModule(void *lib) {
        IDisplayModule *(*createDisplayModule)();
        createDisplayModule = (IDisplayModule * (*)()) dlsym(lib, "createDisplayModule");
        if (!createDisplayModule) throw cannotCreateModule();
        return createDisplayModule();
    }

    /**
     * @brief Create a Game Module object
     * @authors leo
     * @param lib created by openLib
     * @throw cannotCreateModule
     * @return IGameModule*
     */
    IGameModule *createGameModule(void *lib) {
        IGameModule *(*createGameModule)();
        createGameModule = (IGameModule * (*)()) dlsym(lib, "createGameModule");
        if (!createGameModule) throw cannotCreateModule();
        return createGameModule();
    }

    /**
     * @brief delete a display module
     * @author leo
     * @param lib created by openLib
     * @param displayModule
     * @throw cannotCloseModule
     * @return int
     */
    static void deleteDisplayModule(IDisplayModule *displayModule) {
        delete(displayModule);
    }

    /**
     * @brief return the next index of a vector and the first one if it's the last
     * @author leo
     * @param lib list of libs
     * @return std::string next index
     */
    std::string nextIndex(std::vector<std::string> lib, std::string curent) {
        for (int i = 0; i < lib.size(); i++) {
            if (lib[i] == curent) {
                if (i + 1 == lib.size()) return lib[0];
                return lib[i + 1];
            }
        }
        return lib[0];
    }

    /**
     * @brief return the previous index of a vector and the last one if it's the first
     * @author leo
     * @param lib list of libs
     * @return std::string previous index
     */
    std::string previousIndex(std::vector<std::string> lib, std::string curent) {
        for (int i = 0; i < lib.size(); i++) {
            if (lib[i] == curent) {
                if (i - 1 < 0) return lib[lib.size() - 1];
                return lib[i - 1];
            }
        }
        return lib[0];
    }

} // namespace arcade