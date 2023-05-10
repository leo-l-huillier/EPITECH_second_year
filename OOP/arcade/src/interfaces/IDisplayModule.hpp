

/*
** EPITECH PROJECT, 2023
** InterfaceArcade
** File description:
** IDisplayModule
*/

#pragma once

#include <string>
#include <list>

#include "Event.hpp"

namespace arcade {
    /**
     * A type of block to be rendered
     */
    enum class BlockType {
        BrickWall,
        Grass,
        Fruit,
        Coin,
        Character,
        Enemy,
        EnemyVulnerable,
        EnemyDead,
    };

    /**
     * A type of sound effect to be played
     */
    enum class Sound {
        Coin,
        Hurt,
        GameOver,
        Start,
        Super,
    };

    /**
     * A 2D position, in block units
     */
    struct Position {
        float x;
        float y;
    };

    /**
     * A graphical module, which handles displaying the arcade games
     */
    class IDisplayModule {
    public:
        /**
         * The destructor, which is responsible for cleaning up all resources
         */
        virtual ~IDisplayModule() = default;

        /**
         * Display a block on screen at the specified position
         */
        virtual void displayBlock(BlockType blockType, Position pos) = 0;

        /**
         * Display a string on screen at the specified position
         */
        virtual void displayText(const std::string &text, Position pos) = 0;

        /**
         * Reset the shown screen
         */
        virtual void clear() = 0;

        /**
         * Refresh the screen, so that the view is updated
         */
        virtual void refresh() = 0;

        /**
         * Play a sound
         */
        virtual void playSound(Sound sound) = 0;

        /**
         * Pop an event.
         * The event will be removed from the list of pending events.
         */
        virtual std::list<Event> pollEvent() = 0;

        /**
         * Try setting window size in blocks.
         */
        virtual void setWindowSize(Position size) = 0;

        /**
         * Get window size in blocks.
         */
        virtual Position getWindowSize() = 0;

        /**
         * Set the title of the window
         */
        virtual void setWindowTitle(const std::string &title) = 0;
    };
}

extern "C"
{
    /**
     * The entry point of the library, which is responsible for creating the display module
     */
    arcade::IDisplayModule *createDisplayModule();
}