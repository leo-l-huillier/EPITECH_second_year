/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** nibleur.hpp
*/

#ifndef ARCADE_NIBLEUR_HPP
#define ARCADE_NIBLEUR_HPP

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

#include "../../interfaces/IGameModule.hpp"

namespace arcade {
    class Nibbler : public IGameModule {
        IDisplayModule *_display;
        std::list<Event> _events;
        std::map<int, std::vector<BlockType>> _Map;
        std::vector<Position> _wall;
        int _score = 0;
        int _highScore = 0;
        float _speed = 1;
        EventType _waitDirection;
        EventType _direction;
        std::vector<std::pair<Event, Position>> _changeDirectionList;
        std::vector<Position> _fruit;
        std::vector<Position> _snakeCara;
        std::string _name;
        public:
            Nibbler();
            ~Nibbler();
            void tick(IDisplayModule &displayModule, const std::list<Event> &events) override;
            void start(ICore &core) override;
            std::string getName() const override { return "Nibbler"; };
            void setMap();
            bool placeFruits(const arcade::Position &block);
            bool headSnakeOnWall(const arcade::Position &block);
            bool isFruitOnSnake(const arcade::Position &block);
            void verifLeft(float x, float y);
            void verifRight(float x, float y);
            void verifUp(float x, float y);
            void verifDown(float x, float y);
            bool headSnakeOnSnake(const arcade::Position &block);
            void setAllFruits();
            void printMap();
            void printSnake();
            void printFruit();
            void setNewFruit();
            void snakeEatFruit();
            void printScoreAndName();
            void printHighScore() {};
            void gamePause();
            void applyEvent();
            void changeDirection();
            void deathCondition();
            void end();
            void moveCorps();
            void moveSnake();
    };
}

#endif //ARCADE_NIBLEUR_HPP