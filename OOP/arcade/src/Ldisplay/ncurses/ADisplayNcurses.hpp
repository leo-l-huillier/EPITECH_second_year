/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** ADisplayNcurses.hpp
*/

#pragma once

#include <ncurses.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "../../interfaces/IDisplayModule.hpp"

namespace arcade {
    class ADisplayNcurses : public IDisplayModule {
        Position _windowSize;
        std::string _windowTitle;
        int _blockSize = 1;
    public:
        ADisplayNcurses();
        ~ADisplayNcurses() override;

        void displayBlock(BlockType blockType, Position pos) override; //check
        void displayText(const std::string &text, Position pos) override; // check
        void clear() override; // ckeck
        void refresh() override; // check
        void playSound(Sound sound) override; // check
        std::list<Event> pollEvent() override; // check
        void setWindowSize(Position size) override; // check
        Position getWindowSize() override; // check
        void setWindowTitle(const std::string &title) override; // check
        int getBlockSize() { return _blockSize;}; // check
    };
}
