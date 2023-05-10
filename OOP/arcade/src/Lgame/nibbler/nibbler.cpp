/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** nibleur.cpp
*/

#include "nibbler.hpp"

void arcade::Nibbler::setMap()
{
    std::list<std::string> mapStrings = {
        "####################",
        "#..................#",
        "#.#.##.######.##.#.#",
        "#.#....#....#....#.#",
        "#.##.###.##.###.##.#",
        "#..................#",
        "#.#.#..#.##.#.##.#.#",
        "#...#.#........#...#",
        "###.#.#.#.##.###.###",
        "#..................#",
        "#.#.#..######.##.#.#",
        "#.#.#..#....#....#.#",
        "#.#..###.##.###.##.#",
        "#..................#",
        "#.#.##.#.##.#.##.#.#",
        "#..................#",
        "#.#.###.#.##.###.#.#",
        "#..................#",
        "#.....#.......#....#",
        "####################"
    };
    int i = 0;
    for (auto str : mapStrings) {
        std::vector<BlockType> row;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == '#') {
                row.push_back(BlockType::BrickWall);
                _wall.push_back({(float)j, (float)i});
            } else {
                row.push_back(BlockType::Grass);
            }
        }
        _Map[i] = std::move(row);
        i++;
    }
}

/**
 * @brief set new position for the fruit
 * @author Pier-Alexendre
 */
void arcade::Nibbler::setAllFruits()
{
    srand(time(nullptr));
    Position pos = {0, 0};
    while (_fruit.size() < 10) {
        if (!placeFruits(pos))
            _fruit.push_back({pos.x, pos.y });
        pos.x = rand() % 18 + 1;
        pos.y = rand() % 18 + 1;
    }
}

arcade::Nibbler::Nibbler()
{
    setMap();
    setAllFruits();
    _snakeCara.push_back({10, 9});
    _snakeCara.push_back({9, 9});
    _snakeCara.push_back({8, 9});
    _snakeCara.push_back({7, 9});
    _speed = 1;
    _direction = EventType::Right;
    _waitDirection = EventType::Right;
    _name = "Nibbler";
}

arcade::Nibbler::~Nibbler()
{
    //std::cout << "Nibbler destructor" << std::endl;
}

/**
 * @brief print _Map
 * @author Pier-Alexendre
 */
void arcade::Nibbler::printMap()
{
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            _display->displayBlock(_Map[i][j], {(float)j, (float)i});
        }
    }
}


void addVector(std::vector<arcade::Position> &vec1, const std::vector<arcade::Position> &vec2)
{
    for (auto pos : vec2) {
        vec1.push_back(pos);
    }
}

bool arcade::Nibbler::placeFruits(const arcade::Position &block) {
    std::vector<Position> blocks;
    addVector(blocks, _wall);
    addVector(blocks, _snakeCara);
    addVector(blocks, _fruit);
    float xMin = block.x - 0.2;
    float xMax = block.x + 0.2;
    float yMin = block.y - 0.2;
    float yMax = block.y + 0.2;

    for (const auto pos : blocks) {
        float xCaraMin = pos.x - 0.5;
        float xCaraMax = pos.x + 0.5;
        float yCaraMin = pos.y - 0.5;
        float yCaraMax = pos.y + 0.5;


        if ((xMin < xCaraMax && yMin < yCaraMax && yMax > yCaraMin) &&
        (xMax > xCaraMin && yMin < yCaraMax && yMax > yCaraMin) ||
        (yMin < yCaraMax && xMin < xCaraMax && xMax > xCaraMin) &&
        (yMax > yCaraMin && xMin < xCaraMax && xMax > xCaraMin)) {
            return true;
        }
    }
    return false;
}

void arcade::Nibbler::verifDown(float x, float y)
{
    Position pos = {x, y};
    if (headSnakeOnWall(pos)) {
        if (!headSnakeOnWall({x + 1, y - 1}) && !headSnakeOnWall({x - 1, y - 1})) {
            if (_waitDirection != EventType::Down && _waitDirection != EventType::Up)
                _direction = _waitDirection;
            return;
        }
        else if (headSnakeOnWall({x + 1, y - 1}) && headSnakeOnWall({x - 1, y - 1}))
            exit(0);
        else if (!headSnakeOnWall({x + 1, y - 1}) && headSnakeOnWall({x - 1, y - 1})){
            _direction = EventType::Right;
            _waitDirection = EventType::Right;
        }
        else{
            _direction = EventType::Left;
            _waitDirection = EventType::Left;
        }
    } else {
        moveCorps();
        _snakeCara[0].y = y;
    }
}

void arcade::Nibbler::verifUp(float x, float y)
{
    Position pos = {x, y};
    if (headSnakeOnWall(pos)) {
        if (!headSnakeOnWall({x + 1, y + 1}) && !headSnakeOnWall({x - 1, y + 1})){
            if (_waitDirection != EventType::Down && _waitDirection != EventType::Up)
                _direction = _waitDirection;
            return;}
        else if (headSnakeOnWall({x + 1, y + 1}) && headSnakeOnWall({x - 1, y + 1}))
            exit(0);
        else if (!headSnakeOnWall({x + 1, y + 1}) && headSnakeOnWall({x - 1, y + 1})) {
            _direction = EventType::Right;
            _waitDirection = EventType::Right;
        }
        else {
            _direction = EventType::Left;
            _waitDirection = EventType::Left;
        }
    } else {
        moveCorps();
        _snakeCara[0].y = y;
    }
}

void arcade::Nibbler::gamePause()
{
    while (1) {
        std::list<Event> eventList = _display->pollEvent();
        for (const auto &it : eventList) {
            if (it.type == EventType::Pause)
                return;
        }
    }
}

void arcade::Nibbler::verifRight(float x, float y)
{
    Position pos = {x, y};
    if (headSnakeOnWall(pos)) {
        if (!headSnakeOnWall({x - 1, y - 1}) && !headSnakeOnWall({x - 1, y + 1})){
            if (_waitDirection != EventType::Left && _waitDirection != EventType::Right)
                _direction = _waitDirection;
            return;}
        else if (headSnakeOnWall({x - 1, y - 1}) && headSnakeOnWall({x - 1, y + 1}))
            exit(0);
        else if (!headSnakeOnWall({x - 1, y - 1}) && headSnakeOnWall({x - 1, y + 1})) {
            _waitDirection = EventType::Up;
            _direction = EventType::Up;
        }
        else {
            _waitDirection = EventType::Down;
            _direction = EventType::Down;
        }
    } else {
        moveCorps();
        _snakeCara[0].x = x;
    }
}

void arcade::Nibbler::verifLeft(float x, float y)
{
    Position pos = {x, y};
    if (headSnakeOnWall(pos)) {
        if (!headSnakeOnWall({x + 1, y - 1}) && !headSnakeOnWall({x + 1, y + 1})){
            if (_waitDirection != EventType::Left && _waitDirection != EventType::Right)
                _direction = _waitDirection;
            return;}
        else if (headSnakeOnWall({x + 1, y - 1}) && headSnakeOnWall({x + 1, y + 1}))
            exit(0);
        else if (!headSnakeOnWall({x + 1, y - 1}) && headSnakeOnWall({x + 1, y + 1})) {
            _waitDirection = EventType::Up;
            _direction = EventType::Up;
        } else {
            _waitDirection = EventType::Down;
            _direction = EventType::Down;
        }
    } else {
        moveCorps();
        _snakeCara[0].x = x;
    }
}

/**
 * @brief change snake direction and move it
 * @author Pier-Alexendre
 */
void arcade::Nibbler::changeDirection()
{
    Position oldPos = {_snakeCara[0].x, _snakeCara[0].y};
    switch (_direction)
    {
        case arcade::EventType::Left:
            verifLeft(_snakeCara[0].x - _speed, _snakeCara[0].y);
            break;
        case arcade::EventType::Right:
            verifRight(_snakeCara[0].x + _speed, _snakeCara[0].y);
            break;
        case arcade::EventType::Up:
            verifUp(_snakeCara[0].x, _snakeCara[0].y - _speed);
            break;
        case arcade::EventType::Down:
            verifDown(_snakeCara[0].x, _snakeCara[0].y + _speed);
            break;
        default:
            break;
    }
    if (_waitDirection != _direction) {
        if ((std::trunc(_snakeCara[0].x) != std::trunc(oldPos.x)) || (std::trunc(_snakeCara[0].y) != std::trunc(oldPos.y))){
            _snakeCara[0].x = std::round(arcade::Nibbler::_snakeCara[0].x);
            _direction = _waitDirection;
        }
    }
}

bool arcade::Nibbler::headSnakeOnSnake(const arcade::Position &block)
{
    float xMin = block.x - 0.2;
    float xMax = block.x + 0.2;
    float yMin = block.y - 0.2;
    float yMax = block.y + 0.2;

    for (int i = 1; i <= _snakeCara.size(); i++) {
        float xCaraMin = _snakeCara[i].x - 0.5;
        float xCaraMax = _snakeCara[i].x + 0.5;
        float yCaraMin = _snakeCara[i].y - 0.5;
        float yCaraMax = _snakeCara[i].y + 0.5;


        if ((xMin < xCaraMax && yMin < yCaraMax && yMax > yCaraMin) &&
        (xMax > xCaraMin && yMin < yCaraMax && yMax > yCaraMin) ||
        (yMin < yCaraMax && xMin < xCaraMax && xMax > xCaraMin) &&
        (yMax > yCaraMin && xMin < xCaraMax && xMax > xCaraMin)) {
            return true;
        }
    }
    return false;
}

bool arcade::Nibbler::headSnakeOnWall(const arcade::Position &block)
{
    float xMin = block.x - 0.2;
    float xMax = block.x + 0.2;
    float yMin = block.y - 0.2;
    float yMax = block.y + 0.2;

    for (const auto pos : _wall) {
        float xCaraMin = pos.x - 0.5;
        float xCaraMax = pos.x + 0.5;
        float yCaraMin = pos.y - 0.5;
        float yCaraMax = pos.y + 0.5;


        if ((xMin < xCaraMax && yMin < yCaraMax && yMax > yCaraMin) &&
        (xMax > xCaraMin && yMin < yCaraMax && yMax > yCaraMin) ||
        (yMin < yCaraMax && xMin < xCaraMax && xMax > xCaraMin) &&
        (yMax > yCaraMin && xMin < xCaraMax && xMax > xCaraMin)) {
            return true;
        }
    }
    return false;
}

bool arcade::Nibbler::isFruitOnSnake(const arcade::Position &block) {
    float xMin = block.x - 0.2;
    float xMax = block.x + 0.2;
    float yMin = block.y - 0.2;
    float yMax = block.y + 0.2;

    for (auto it = _fruit.begin(); it != _fruit.end(); ++it) {
        float xCaraMin = it->x - 0.5;
        float xCaraMax = it->x + 0.5;
        float yCaraMin = it->y - 0.5;
        float yCaraMax = it->y + 0.5;

        if ((xMin < xCaraMax && yMin < yCaraMax && yMax > yCaraMin) &&
            (xMax > xCaraMin && yMin < yCaraMax && yMax > yCaraMin) ||
            (yMin < yCaraMax && xMin < xCaraMax && xMax > xCaraMin) &&
            (yMax > yCaraMin && xMin < xCaraMax && xMax > xCaraMin)) {
            _fruit.erase(it); // supprime l'élément du vecteur _fruit
            return true;
        }
    }
    return false;
}

/**
 * @brief move the snake's body to the head position
 * @author Pier-Alexendre
 */
void arcade::Nibbler::moveCorps()
{
    if (_speed == 1) {
        for (int i = _snakeCara.size() - 1; i > 0; i--) {
            _snakeCara[i].x = _snakeCara[i - 1].x;
            _snakeCara[i].y = _snakeCara[i - 1].y;
        }
    }
}

void arcade::Nibbler::end()
{
    _speed = 0;
    _display->displayText("press 'r' to restart or 'enter' to return to the menu", {30, 10});
    for (const auto &it : _events) {
        if (it.type == EventType::Pause)
            return;
    }
}

void arcade::Nibbler::deathCondition()
{
    if (headSnakeOnSnake(_snakeCara[0])) {
        //std::cout << _snakeCara.size() << std::endl;
        end();
    }
}

/**
 * @brief parse and aplly _events to the game
 * @author Pier-Alexendre
 */
void arcade::Nibbler::applyEvent()
{
    for (auto event : _events) {
        if (event.type == arcade::EventType::Left && _direction != arcade::EventType::Right) {
            _waitDirection = arcade::EventType::Left; return; }
        else if (event.type == arcade::EventType::Right && _direction != arcade::EventType::Left) {
            _waitDirection = arcade::EventType::Right; return; }
        else if (event.type == arcade::EventType::Up && _direction != arcade::EventType::Down) {
            _waitDirection = arcade::EventType::Up; return; }
        else if (event.type == arcade::EventType::Down && _direction != arcade::EventType::Up) {
            _waitDirection = arcade::EventType::Down; return; }
        else if (event.type == arcade::EventType::Quit) {
            exit(0); }
        else if (event.type == arcade::EventType::Pause){
            gamePause(); }
    }
}


/**
 * @brief call all move function to move the snake and check if the snake is dead or not
 * @author Pier-Alexendre
 */
void arcade::Nibbler::moveSnake()
{
    applyEvent();
    changeDirection();
    deathCondition();
}

void arcade::Nibbler::snakeEatFruit()
{
    if (isFruitOnSnake(_snakeCara[0])) {
        _snakeCara.push_back({_snakeCara[_snakeCara.size() - 1].x, _snakeCara[_snakeCara.size() - 1].y});
        _display->playSound(arcade::Sound::Hurt);
        _score += 10;
    }
}

/**
 * @brief print _snakeCara
 * @author Pier-Alexendre
 */
void arcade::Nibbler::printFruit()
{
    for (int i = 0; i < _fruit.size(); i++) {
        _display->displayBlock(BlockType::Fruit, _fruit[i]);
    }
}

/**
 * @brief print _snakeCara
 * @author Pier-Alexendre
 */
void arcade::Nibbler::printSnake()
{
    Position pos;
    for (int i = 0; i < _snakeCara.size(); i++) {
        pos.x = _snakeCara[i].x;
        pos.y = _snakeCara[i].y;
        i == 0 ? _display->displayBlock(BlockType::Coin, pos) : _display->displayBlock(BlockType::Character, pos);
    }
}

void arcade::Nibbler::printScoreAndName()
{
    _display->displayText(_name, {22, 3});
    _display->displayText("Score : " + std::to_string(_score), {22, 5});
}

void arcade::Nibbler::start(ICore &core)
{
    _name = core.getName();
}

/**
 * @brief fonction called by the core to start the game
 * @param _display the display module
 * @param list of events
 * @author Pier-Alexendre
 */
void arcade::Nibbler::tick(IDisplayModule &displayModule, const std::list<Event> &events)
{
    _display = &displayModule;
    _events = events;
    _display->clear();
    moveSnake();
    snakeEatFruit();
    printMap();
    printFruit();
    printSnake();
    printScoreAndName();
    _display->refresh();
}

extern "C" {
    arcade::IGameModule *createGameModule()
    {
        return new arcade::Nibbler();
    }
}