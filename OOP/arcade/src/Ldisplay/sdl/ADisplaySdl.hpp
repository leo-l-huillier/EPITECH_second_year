/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** ADisplaySdl.hpp
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "../../interfaces/IDisplayModule.hpp"

namespace arcade {
    class ADisplaySdl : public IDisplayModule {
        SDL_Renderer* _renderer;
        SDL_Window* _window;
        Mix_Chunk* _CoinBuffer;
        Mix_Chunk* _hurtBuffer;
        Mix_Chunk* _gameOverBuffer;
        Mix_Chunk* _startBuffer;
        Mix_Chunk* _superBuffer;
        SDL_Texture* _spriteSheet;
        SDL_Rect _spriteSheetRect[5];
        int _blockSize;
        Position _windowSize;
        std::string _windowTitle;
        TTF_Font* _font;
    public:
        ADisplaySdl();
        ~ADisplaySdl() override;

        void displayBlock(BlockType blockType, Position pos) override;
        void displayText(const std::string &text, Position pos) override;
        void clear() override;
        void refresh() override;
        void close();
        void playSound(Sound sound) override;
        std::list<Event> pollEvent() override;
        void setWindowSize(Position size) override;
        Position getWindowSize() override;
        void setWindowTitle(const std::string &title) override;
        int getBlockSize() { return _blockSize;};
    };
}
