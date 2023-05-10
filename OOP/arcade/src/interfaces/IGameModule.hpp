/*
** EPITECH PROJECT, 2023
** InterfaceArcade
** File description:
** IGameModule
*/

#pragma once

#include "IDisplayModule.hpp"
#include "ICore.hpp"

namespace arcade {
    /**
     * A game module that handle how the game works
     */
    class IGameModule {
    public:
        /**
         * The destructor, which is responsible for cleaning up all resources
         */
        virtual ~IGameModule() = default;

        /**
         * handle all command provided by IDisplayModule
         */
        virtual void tick(IDisplayModule &displayModule, const std::list<Event> &events) = 0;

        /**
         * the function which return the name, Duuuhh~
         */
        virtual std::string getName() const = 0;

        /**
         * the function that start the game
         */
        virtual void start(ICore &core) = 0;
    };
}

extern "C"
{
    /**
     * The entry point of the library, which is responsible for creating the game module
     */
    arcade::IGameModule *createGameModule();
}