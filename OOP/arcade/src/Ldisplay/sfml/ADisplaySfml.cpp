/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** ADisplaySfml.cpp
*/

#include "ADisplaySfml.hpp"

/**
 * @brief Construct a new arcade::A Display Sfml::A Display Sfml object
 * @author pier-alexandre
 */
arcade::ADisplaySfml::ADisplaySfml()
{
    _window.create(sf::VideoMode(1920, 1080), "Arcade");
    _font.loadFromFile("res/fonts/Minecraft.ttf");
    _CoinBuffer.loadFromFile("res/sounds/coin.wav");
    _hurtBuffer.loadFromFile("res/sounds/hurt.wav");
    _gameOverBuffer.loadFromFile("res/sounds/gameover.wav");
    _startBuffer.loadFromFile("res/sounds/start.wav");
    _superBuffer.loadFromFile("res/sounds/super.wav");
    _blockSize = 20;
}

/**
 * @brief Destroy the arcade::A Display Sfml::A Display Sfml object
 * @author pier-alexandre
 */
arcade::ADisplaySfml::~ADisplaySfml()
{
    _window.close();
}

/**
 * @brief display a block on the screen
 * @param blockType
 * @param pos
 * @author pier-alexandre
 */
void arcade::ADisplaySfml::displayBlock(BlockType blockType, Position pos)
{
    // créer une forme géométrique pour représenter le bloc
    ::sf::RectangleShape block(sf::Vector2f(_blockSize, _blockSize));
    block.setPosition((pos.x * _blockSize), (pos.y * _blockSize)); // positionner le bloc dans la fenêtre de rendu

    // définir la couleur du bloc en fonction de son type
    switch (blockType) {
        case BlockType::BrickWall:
            block.setFillColor(sf::Color(139, 69, 19)); // brun
            break;
        case BlockType::Grass:
            block.setFillColor(sf::Color::Green);
            block.setOutlineColor(sf::Color(0, 100, 0)); // Couleur de la bordure
            block.setOutlineThickness(1); // Epaisseur de la bordure
            break;
        case BlockType::Fruit:
            block.setFillColor(sf::Color::Red);
            break;
        case BlockType::Coin:
            block.setFillColor(sf::Color::Yellow);
            break;
        case BlockType::Character:
            block.setFillColor(sf::Color::White);
            break;
    }

    // dessiner le bloc dans la fenêtre de rendu
    _window.draw(block);
}

/**
 * @brief display a text on the screen
 * @param text
 * @param pos
 * @author pier-alexandre
 */
void arcade::ADisplaySfml::displayText(const std::string &text, Position pos)
{
    // créer un objet texte
    sf::Text textObject(text, _font, 20);
    textObject.setFillColor(sf::Color::White);
    textObject.setPosition(pos.x * _blockSize, pos.y * _blockSize); // positionner le texte dans la fenêtre de rendu

    // dessiner le texte dans la fenêtre de rendu
    _window.draw(textObject);
}

/**
 * @brief clear the screen
 * @author pier-alexandre
 */
void arcade::ADisplaySfml::clear()
{
    _window.clear(sf::Color::Black); // effacer la fenêtre de rendu
}

/**
 * @brief refresh the screen
 * @author pier-alexandre
 */
void arcade::ADisplaySfml::refresh()
{
    _window.display(); // afficher la fenêtre de rendu
}

/**
 * @brief get the input from the user
 * @param sound
 * @author pier-alexandre
 */
void arcade::ADisplaySfml::playSound(Sound sound)
{
    sf::Sound _soundEffect;
    switch (sound) {
        case Sound::Coin:
            _soundEffect.setBuffer(_CoinBuffer);
            break;
        case Sound::Hurt:
            _soundEffect.setBuffer(_hurtBuffer);
            break;
        case Sound::GameOver:
            _soundEffect.setBuffer(_gameOverBuffer);
            break;
        case Sound::Start:
            _soundEffect.setBuffer(_startBuffer);
            break;
        case Sound::Super:
            _soundEffect.setBuffer(_superBuffer);
            break;
    }
    _soundEffect.play();
}

/**
 * @brief get the input from the user
 * @return std::list<arcade::Event> list of events
 * @author pier-alexandre
 */
std::list<arcade::Event> arcade::ADisplaySfml::pollEvent()
{
    std::list<arcade::Event> events;
    arcade::Event event;

    sf::Event sfEvent;
    if (_window.pollEvent(sfEvent)) {
        switch (sfEvent.type) {
            case sf::Event::KeyPressed:
                if (sfEvent.key.code == sf::Keyboard::Up) {
                    event.type = arcade::EventType::Up;
                    events.push_back(event);
                } else if (sfEvent.key.code == sf::Keyboard::Down) {
                    event.type = arcade::EventType::Down;
                    events.push_back(event);
                } else if (sfEvent.key.code == sf::Keyboard::Left) {
                    event.type = arcade::EventType::Left;
                    events.push_back(event);
                } else if (sfEvent.key.code == sf::Keyboard::Right) {
                    event.type = arcade::EventType::Right;
                    events.push_back(event);
                } else if (sfEvent.key.code == sf::Keyboard::Space) {
                    event.type = arcade::EventType::Action;
                    events.push_back(event);
                } else if (sfEvent.key.code == sf::Keyboard::Escape) {
                    event.type = arcade::EventType::Pause;
                    events.push_back(event);
                } else if (sfEvent.key.code == sf::Keyboard::Backspace || sfEvent.type == sf::Event::Closed) {
                    event.type = arcade::EventType::Quit;
                    events.push_back(event);
                } else if (sfEvent.key.code == sf::Keyboard::Add) {
                    event.type = arcade::EventType::SwitchToNextGame;
                    events.push_back(event);
                } else if (sfEvent.key.code == sf::Keyboard::Subtract) {
                    event.type = arcade::EventType::SwitchToPreviousGame;
                    events.push_back(event);
                } else if (sfEvent.key.code == sf::Keyboard::Return) {
                    event.type = arcade::EventType::ReturnToSelectionMenu;
                    events.push_back(event);
                } else if (sfEvent.key.code == sf::Keyboard::P) {
                    event.type = arcade::EventType::NextLibrary;
                    events.push_back(event);
                } else if (sfEvent.key.code == sf::Keyboard::O) {
                    event.type = arcade::EventType::PreviousLibrary;
                    events.push_back(event);
                } else if (sfEvent.key.code == sf::Keyboard::R) {
                    event.type = arcade::EventType::RestartGame;
                    events.push_back(event);
                }
                break;
            case sf::Event::Closed:
                _window.close();
                break;
            default:
                break;
        }
    }
    return events;
}

/**
 * @brief set the size of the window
 * @return std::list<arcade::Event> list of events
 * @author pier-alexandre
 */
void arcade::ADisplaySfml::setWindowSize(Position size)
{
    sf::Vector2u SFsize;
    size.x = size.x;
    size.y = size.y;
    _window.setSize(SFsize);
}

/**
 * @brief get the size of the window
 * @return std::list<arcade::Event> list of events
 * @author pier-alexandre
 */
arcade::Position arcade::ADisplaySfml::getWindowSize()
{
    Position size;
    sf::Vector2u SFsize = _window.getSize();
    size.x = SFsize.x;
    size.y = SFsize.y;
    return size;
}

/**
 * @brief set the title of the window
 * @return std::list<arcade::Event> list of events
 * @author pier-alexandre
 */
void arcade::ADisplaySfml::setWindowTitle(const std::string &title)
{
    _window.setTitle(title);
}

extern "C" {
    arcade::IDisplayModule *createDisplayModule()
    {
        return new arcade::ADisplaySfml();
    }
}