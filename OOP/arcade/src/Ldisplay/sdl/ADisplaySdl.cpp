/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** ADisplaySdl.cpp
*/

#include "ADisplaySdl.hpp"

/**
 * @brief Construct a new arcade::A Display Sdl::A Display Sdl object
 * @author pier-alexandre
 */
arcade::ADisplaySdl::ADisplaySdl()
{
    TTF_Init();
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    _CoinBuffer = Mix_LoadWAV("res/sounds/coin.wav");
    _hurtBuffer = Mix_LoadWAV("res/sounds/hurt.wav");
    _gameOverBuffer = Mix_LoadWAV("res/sounds/game_over.wav");
    _startBuffer = Mix_LoadWAV("res/sounds/start.wav");
    _superBuffer = Mix_LoadWAV("res/sounds/super.wav");
    _spriteSheet = SDL_CreateTextureFromSurface(_renderer, IMG_Load("res/sprite/spritesheet.png"));
    const int SPRITE_SIZE = 806;
    for (int i = 0; i < 5; i++) {
        _spriteSheetRect[i].x = i * SPRITE_SIZE;
        _spriteSheetRect[i].y = 0;
        _spriteSheetRect[i].w = SPRITE_SIZE;
        _spriteSheetRect[i].h = SPRITE_SIZE;
    }
    _font = TTF_OpenFont("res/fonts/Minecraft.ttf", 32);
    _blockSize = 20;
}

/**
 * @brief Destroy the arcade::A Display Sdl::A Display Sdl object
 * @author pier-alexandre
 */
arcade::ADisplaySdl::~ADisplaySdl()
{
    Mix_FreeChunk(_CoinBuffer);
    Mix_FreeChunk(_hurtBuffer);
    Mix_FreeChunk(_gameOverBuffer);
    Mix_FreeChunk(_startBuffer);
    Mix_FreeChunk(_superBuffer);
    SDL_DestroyTexture(_spriteSheet);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

/**
 * @brief display a block of 32 pixel
 * @author pier-alexandre
 */
void arcade::ADisplaySdl::displayBlock(BlockType blockType, Position pos)
{
    SDL_Rect destRect = {(int)(pos.x * _blockSize), (int)(pos.y * _blockSize), _blockSize, _blockSize};  // les coordonnées et la taille du sprite

    switch (blockType) {
        case BlockType::BrickWall:
            SDL_RenderCopy(_renderer, _spriteSheet, &_spriteSheetRect[0], &destRect);
            break;
        case BlockType::Grass:
            SDL_RenderCopy(_renderer, _spriteSheet, &_spriteSheetRect[1], &destRect);
            break;
        case BlockType::Fruit:
            SDL_RenderCopy(_renderer, _spriteSheet, &_spriteSheetRect[2], &destRect);
            break;
        case BlockType::Coin:
            SDL_RenderCopy(_renderer, _spriteSheet, &_spriteSheetRect[3], &destRect);
            break;
        case BlockType::Character:
            SDL_RenderCopy(_renderer, _spriteSheet, &_spriteSheetRect[4], &destRect);
            break;
        default:
            break;
    }
}

/**
 * @brief display text
 * @param text
 * @param pos
 * @author pier-alexandre
 */
void arcade::ADisplaySdl::displayText(const std::string &text, Position pos) {
    SDL_Color color = {255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Solid(_font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect destRect = {(int)(pos.x * _blockSize), (int)(pos.y * _blockSize), (int)(text.size() * 20), 50};
    SDL_RenderCopy(_renderer, texture, NULL, &destRect);
}

/**
 * @brief clear the screen
 * @author pier-alexandre
 */
void arcade::ADisplaySdl::clear() {
    SDL_RenderClear(_renderer);
}

/**
 * @brief refresh the screen
 * @author pier-alexandre
 */
void arcade::ADisplaySdl::refresh() {
    SDL_RenderPresent(_renderer);
}

/**
 * @brief play a sound
 * @param sound
 * @author pier-alexandre
 */
void arcade::ADisplaySdl::playSound(Sound sound) {
    Mix_Chunk* effect = nullptr;

    switch (sound) {
        case Sound::Coin:
            effect = _CoinBuffer;
            break;
        case Sound::Hurt:
            effect = _hurtBuffer;
            break;
        case Sound::GameOver:
            effect = _gameOverBuffer;
            break;
        case Sound::Start:
            effect = _startBuffer;
            break;
        case Sound::Super:
            effect = _superBuffer;
            break;
        default:
            break;
    }

    if (effect) {
        Mix_PlayChannel(-1, effect, 0);
    }
}

/**
 * @brief poll the event from the keyboard
 * @return std::list<arcade::Event>
 * @author pier-alexandre
 */
std::list<arcade::Event> arcade::ADisplaySdl::pollEvent() {
    std::list<arcade::Event> events;

    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent)) {
        switch (sdlEvent.type) {
            case SDL_QUIT: {
                events.push_back({arcade::EventType::Quit});
                break;
            }
            case SDL_KEYDOWN: {
                switch (sdlEvent.key.keysym.sym) {
                    case SDLK_UP: {
                        events.push_back({arcade::EventType::Up});
                        break;
                    }
                    case SDLK_DOWN: {
                        events.push_back({arcade::EventType::Down});
                        break;
                    }
                    case SDLK_LEFT: {
                        events.push_back({arcade::EventType::Left});
                        break;
                    }
                    case SDLK_RIGHT: {
                        events.push_back({arcade::EventType::Right});
                        break;
                    }
                    case SDLK_SPACE: {
                        events.push_back({arcade::EventType::Action});
                        break;
                    }
                    case SDLK_ESCAPE: {
                        events.push_back({arcade::EventType::Pause});
                        break;
                    }
                    case SDLK_BACKSPACE: {
                        events.push_back({arcade::EventType::Quit});
                        break;
                    }
                    case SDLK_PLUS: {
                        events.push_back({arcade::EventType::SwitchToNextGame});
                        break;
                    }
                    case SDLK_MINUS: {
                        events.push_back({arcade::EventType::SwitchToPreviousGame});
                        break;
                    }
                    case SDLK_RETURN: {
                        events.push_back({arcade::EventType::ReturnToSelectionMenu});
                        break;
                    }
                    case SDLK_p: {
                        events.push_back({arcade::EventType::NextLibrary});
                        break;
                    }
                    case SDLK_o: {
                        events.push_back({arcade::EventType::PreviousLibrary});
                        break;
                    }
                    case SDLK_r: {
                        events.push_back({arcade::EventType::RestartGame});
                        break;
                    }
                    default: {
                        // Do nothing
                        break;
                    }
                }
                break;
            }
            default: {
                // Do nothing
                break;
            }
        }
    }

    return events;
}


/**
 * @brief close the window
 * @author pier-alexandre
 */
void arcade::ADisplaySdl::close() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

/**
 * @brief set the window size
 * @param size
 * @author pier-alexandre
 */
void arcade::ADisplaySdl::setWindowSize(Position size) {
    _windowSize = size;
}

/**
 * @brief get window size
 * @return arcade::Position
 * @author pier-alexandre
 */
arcade::Position arcade::ADisplaySdl::getWindowSize()
{
    return _windowSize;
}

/**
 * @brief set window title
 * @param std::string &title
 * @author pier-alexandre
 */
void arcade::ADisplaySdl::setWindowTitle(const std::string &title) {
    _windowTitle = title;
}

extern "C" {
    arcade::IDisplayModule *createDisplayModule()
    {
        return new arcade::ADisplaySdl();
    }
}