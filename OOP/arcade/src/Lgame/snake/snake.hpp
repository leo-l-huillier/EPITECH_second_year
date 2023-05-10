/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** snake.hpp
*/

#ifndef ARCADE_SNAKE_HPP
#define ARCADE_SNAKE_HPP

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

#include "../../interfaces/IGameModule.hpp"

namespace arcade {
    class Snake : public IGameModule {
            IDisplayModule *_display;
            std::list<Event> _events;
            std::map<int, std::vector<BlockType>> _Map;
            int _score;
            int _highScore = 0;
            float _speed = 1;
            EventType _waitDirection;
            EventType _direction;
            std::vector<std::pair<Event, Position>> _changeDirectionList;
            Position _fruit;
            std::vector<Position> _snakeCara;
            std::string _name;
        public:
            Snake();
            ~Snake();
            void tick(IDisplayModule &displayModule, const std::list<Event> &events) override;
            void start(ICore &core) override;
            std::string getName() const override { return "Snake"; };
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
            void moveCorps();
            void moveSnake();
            void end();
    };
}

#endif //ARCADE_SNAKE_HPP