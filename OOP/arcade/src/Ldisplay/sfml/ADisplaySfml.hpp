/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** ADisplaySfml.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "../../interfaces/IDisplayModule.hpp"

namespace arcade {
    class ADisplaySfml : public IDisplayModule {
        sf::RenderWindow _window;
        sf::Font _font;
        sf::SoundBuffer _CoinBuffer;
        sf::SoundBuffer _hurtBuffer;
        sf::SoundBuffer _gameOverBuffer;
        sf::SoundBuffer _startBuffer;
        sf::SoundBuffer _superBuffer;
        Position _windowSize;
        int _blockSize;
    public:
        ADisplaySfml();
        ~ADisplaySfml() override;

        void displayBlock(BlockType blockType, Position pos) override;
        void displayText(const std::string &text, Position pos) override;
        void clear() override;
        void refresh() override;
        void playSound(Sound sound) override;
        std::list<Event> pollEvent() override;
        void setWindowSize(Position size) override;
        Position getWindowSize() override;
        void setWindowTitle(const std::string &title) override;
        int getBlockSize() { return _blockSize;};
    };
}
