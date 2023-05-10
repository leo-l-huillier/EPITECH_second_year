/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** snake.cpp
*/

#include "snake.hpp"

/**
 * @brief Construct a new arcade::Snake::Snake object
 * @author Pier-Alexendre
 */
arcade::Snake::Snake()
{
    _Map[0] = std::vector<BlockType>(20, BlockType::BrickWall);
    for (int i = 1; i < 19; i++) {
        _Map[i] = std::vector<BlockType>(20, BlockType::Grass);
        _Map[i][0] = BlockType::BrickWall;
        _Map[i][19] = BlockType::BrickWall;
    }
    _Map[19] = std::vector<BlockType>(20, BlockType::BrickWall);
    _snakeCara.push_back({10, 10});
    _snakeCara.push_back({9, 10});
    _snakeCara.push_back({8, 10});
    _fruit.x = 9.0;
    _fruit.y = 10.0;
    _speed = 1;
    _direction = EventType::Right;
    _waitDirection = EventType::Right;
    _score = -10;
}

/**
 * @brief Destroy the arcade::Snake::Snake object
 * @author Pier-Alexendre
 */
arcade::Snake::~Snake()
{
}

/**
 * @brief print _Map
 * @author Pier-Alexendre
 */
void arcade::Snake::printMap()
{
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            _display->displayBlock(_Map[i][j], {(float)j, (float)i});
        }
    }
}

/**
 * @brief print _snakeCara
 * @author Pier-Alexendre
 */
void arcade::Snake::printSnake()
{
    Position pos;
    for (int i = 0; i < _snakeCara.size(); i++) {
        pos.x = _snakeCara[i].x;
        pos.y = _snakeCara[i].y;
        i == 0 ? _display->displayBlock(BlockType::Coin, pos) : _display->displayBlock(BlockType::Character, pos);
    }
}

/**
 * @brief pause the game and wait for a pause event to resume the game
 * @author Pier-Alexendre
 */
void arcade::Snake::gamePause()
{
    while (1) {
        std::list<Event> eventList = _display->pollEvent();
        for (const auto &it : eventList) {
            if (it.type == EventType::Pause)
                return;
        }
    }
}

/**
 * @brief parse and aplly _events to the game
 * @author Pier-Alexendre
 */
void arcade::Snake::applyEvent()
{
    for (auto event : _events) {
        if (event.type == arcade::EventType::Left && _direction != arcade::EventType::Right) {
            _waitDirection = arcade::EventType::Left; return; }
        else if (event.type == arcade::EventType::Right && _direction != arcade::EventType::Left){
            _waitDirection = arcade::EventType::Right; return; }
        else if (event.type == arcade::EventType::Up && _direction != arcade::EventType::Down){
            _waitDirection = arcade::EventType::Up; return; }
        else if (event.type == arcade::EventType::Down && _direction != arcade::EventType::Up){
            _waitDirection = arcade::EventType::Down; return; }
        else if (event.type == arcade::EventType::Quit) {
            exit(0); }
        else if (event.type == arcade::EventType::Pause){
            gamePause(); }
    }
}

bool headOnKillBloc(const arcade::Position &snakeHead, const arcade::Position &bloc) {
    float xMin = bloc.x - 0.2;
    float xMax = bloc.x + 0.2;
    float yMin = bloc.y - 0.2;
    float yMax = bloc.y + 0.2;

    float xCaraMin = snakeHead.x - 0.5;
    float xCaraMax = snakeHead.x + 0.5;
    float yCaraMin = snakeHead.y - 0.5;
    float yCaraMax = snakeHead.y + 0.5;


    if ((xMin < xCaraMax && yMin < yCaraMax && yMax > yCaraMin) &&
    (xMax > xCaraMin && yMin < yCaraMax && yMax > yCaraMin) ||
    (yMin < yCaraMax && xMin < xCaraMax && xMax > xCaraMin) &&
    (yMax > yCaraMin && xMin < xCaraMax && xMax > xCaraMin)) {
        return true;
    }
    return false;
}

/**
 * @brief change snake direction and move it
 * @author Pier-Alexendre
 */
void arcade::Snake::changeDirection()
{
    Position oldPos = {_snakeCara[0].x, _snakeCara[0].y};
    switch (_direction)
    {
        case arcade::EventType::Left:
            _snakeCara[0].x -= _speed;
            break;
        case arcade::EventType::Right:
            _snakeCara[0].x += _speed;
            break;
        case arcade::EventType::Up:
            _snakeCara[0].y -= _speed;
            break;
        case arcade::EventType::Down:
            _snakeCara[0].y += _speed;
            break;
        default:
            break;
    }
    if (_waitDirection != _direction) {
        if ((std::trunc(_snakeCara[0].x) != std::trunc(oldPos.x)) || (std::trunc(_snakeCara[0].y) != std::trunc(oldPos.y))){
            _snakeCara[0].x = std::round(arcade::Snake::_snakeCara[0].x);
            _direction = _waitDirection;
        }
    }
}

/**
 * @brief move the snake's body to the head position
 * @author Pier-Alexendre
 */
void arcade::Snake::moveCorps()
{
    if (_speed == 1) {
        for (int i = _snakeCara.size() - 1; i > 0; i--) {
            _snakeCara[i].x = _snakeCara[i - 1].x;
            _snakeCara[i].y = _snakeCara[i - 1].y;
        }
    }
}

void arcade::Snake::end()
{
    _speed = 0;
    _display->displayText("press 'r' to restart or 'enter' to return to the menu", {30, 10});
    for (const auto &it : _events) {
        if (it.type == EventType::Pause)
            return;
    }
}

void arcade::Snake::deathCondition()
{
    std::vector<Position> snakeHead = {_snakeCara[0]};
    for (int i = 1; i < _snakeCara.size(); i++) {
        if (headOnKillBloc(_snakeCara[0], _snakeCara[i])) {
            end();
        }
    }
    if (snakeHead[0].x <= 0 || snakeHead[0].x >= 19 || snakeHead[0].y <= 0 || snakeHead[0].y >= 19)
        end();
}

/**
 * @brief call all move function to move the snake and check if the snake is dead or not
 * @author Pier-Alexendre
 */
void arcade::Snake::moveSnake()
{
    moveCorps();
    applyEvent();
    changeDirection();
    deathCondition();
}

/**
 * @brief check if the snake is dead or not
 * @param _snakeCara the snake's body
 * @param position of block
 * @return true if the snake is on block
 * @return false if the snake is not on block
 * @author Pier-Alexendre
 */
bool isFruitOnSnake(const std::vector<arcade::Position>& snakeCara, const arcade::Position& fruit) {
    float xMin = fruit.x - 0.5;
    float xMax = fruit.x + 0.5;
    float yMin = fruit.y - 0.49;
    float yMax = fruit.y + 0.49;

    for (const auto pos : snakeCara) {
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

/**
 * @brief set new position for the fruit
 * @author Pier-Alexendre
 */
void arcade::Snake::setNewFruit()
{
    srand(time(nullptr)); // Initialisation du générateur de nombres aléatoires
    while (isFruitOnSnake(_snakeCara, _fruit)) {
        _fruit.x = rand() % 18 + 1; // Génération d'un nombre aléatoire entre 1 et 18
        _fruit.y = rand() % 18 + 1;
    }
}

/**
 * @brief print the fruit on the map
 * @author Pier-Alexendre
 */
void arcade::Snake::printFruit()
{
    _display->displayBlock(BlockType::Fruit, _fruit);
}

/**
 * @brief check if the snake eat the fruit and if yes, add a new block to the snake's body and set a new fruit position
 * @author Pier-Alexendre
 */
void arcade::Snake::snakeEatFruit()
{
    if (isFruitOnSnake(_snakeCara, _fruit)) {
        _snakeCara.push_back({_snakeCara[_snakeCara.size() - 1].x, _snakeCara[_snakeCara.size() - 1].y});
        setNewFruit();
        _score += 10;
        _display->playSound(arcade::Sound::Hurt);
    }
}

void arcade::Snake::printScoreAndName()
{
    _display->displayText(_name, {22, 3});
    _display->displayText("Score : " + std::to_string(_score), {22, 5});
}

void arcade::Snake::start(ICore &core)
{
    _name = core.getName();
}

/**
 * @brief fonction called by the core to start the game
 * @param _display the display module
 * @param list of events
 * @author Pier-Alexendre
 */
void arcade::Snake::tick(IDisplayModule &displayModule, const std::list<Event> &events)
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
        return new arcade::Snake();
    }
}