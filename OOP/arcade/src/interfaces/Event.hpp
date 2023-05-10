/*
** EPITECH PROJECT, 2023
** InterfaceArcade
** File description:
** Arcade Events
*/

#pragma once

namespace arcade {
    /**
     * The type of a keyboard or mouse event
     */
    enum class EventType {
        /// Go UP (arrow key)
        Up,
        /// Go DOWN (arrow key)
        Down,
        /// Go LEFT (arrow key)
        Left,
        /// Go RIGHT (arrow key)
        Right,
        /// Activate (space bar)
        Action,
        /// Toggle Pause (escape key)
        Pause,
        /// Exit program (backspace key or close the windoow)
        Quit,
        /// Quit current game and load the next one (+)
        SwitchToNextGame,
        /// Quit current game and load the previous one (-)
        SwitchToPreviousGame,
        /// Quit current game and return to the game selection menu (enter key)
        ReturnToSelectionMenu,
        /// Switch to the next graphical library (page up or p key)
        NextLibrary,
        /// Switch to the previous graphical library (page down or o key)
        PreviousLibrary,
        /// Restart the current game (r key)
        RestartGame,
    };

    /**
     * A structure which holds an event, passed from the graphical module
     * to the game module.
     */
    struct Event {
        /**
         * The type of the event which was received
         */
        EventType type;
    };
}