/*
** EPITECH PROJECT, 2019
** SFML.cpp
** File description:
** SFML lib program
*/

#include "../../../include/libs/SFML/SFML.hpp"
#include <thread>
#include <iostream>

SFML::SFML()
{
    _core = nullptr;
}

void SFML::init(Arcade::ICore *core)
{
    (void)core;
    initKeyboard();
    initCommands();
    initColors();
    initTextures();
    _arcadeFont.loadFromFile("./assets/fonts/Arcade.ttf");
    _window.create(sf::VideoMode(WIDTH, HEIGHT), "Arcade");
    _window.setFramerateLimit(60);
    _window.setKeyRepeatEnabled(false);
    clear();
}

void SFML::close()
{
    _window.close();
}

void SFML::clear()
{
    _window.clear();
}

void SFML::refresh()
{
    _window.display();
}

sf::Sprite SFML::createSprite(const sf::Texture &texture)
{
    sf::Sprite sprite;

    sprite.setTexture(texture);
    return (sprite);
}

void SFML::drawSprite()
{
}

std::string SFML::getCharKeyboardEvent()
{
    _window.pollEvent(_event);
    if (_event.type == sf::Event::KeyPressed) {
        for (auto &&character : _chars) {
            if (character.second == _event.key.code)
                return character.first;
        }
    }
    return "";
}

Arcade::Command SFML::getCommand()
{
    _window.pollEvent(_event);
    if (_event.type == sf::Event::KeyPressed) {
        for (auto &&command : _commands) {
            if (command.second == _event.key.code)
                return command.first;
        }
    }
    return Arcade::UNDEFINED;
}

sf::Color SFML::getColor(Arcade::Color Selectedcolor)
{
    for (auto &&color : _colors) {
        if (color.first == Selectedcolor)
            return color.second;
    }
    return sf::Color::White;
}

void SFML::putText(const std::string text, Arcade::Color color,
    std::size_t x, std::size_t y, std::size_t size)
{
    sf::Text sfText;

    sfText.setFont(_arcadeFont);
    sfText.setString(text);
    sfText.setFillColor(getColor(color));
    sfText.setPosition(x - (size * (text.length() / 2)), y);
    sfText.setCharacterSize(size);
    _window.draw(sfText);
}

void SFML::loadTexture(const std::string path, sf::Texture texture)
{
    if (texture.loadFromFile(path))
        texture.setSmooth(true);
}

void SFML::assignTexture(const std::string path, Arcade::cellTileType type, Arcade::Color color)
{
    (void)color;
    for (auto &&texture : _textures) {
        if (texture.first == type)
            loadTexture(path, texture.second);
    }
}

void SFML::initTextures()
{
    _textures.emplace(Arcade::EMPTY, _empty);
    _textures.emplace(Arcade::OBSTACLE, _obstacle);
    _textures.emplace(Arcade::APPLE, _apple);
}

void SFML::initKeyboard()
{
    _chars.emplace("A", sf::Keyboard::A);
    _chars.emplace("B", sf::Keyboard::B);
    _chars.emplace("C", sf::Keyboard::C);
    _chars.emplace("D", sf::Keyboard::D);
    _chars.emplace("E", sf::Keyboard::E);
    _chars.emplace("F", sf::Keyboard::F);
    _chars.emplace("G", sf::Keyboard::G);
    _chars.emplace("H", sf::Keyboard::H);
    _chars.emplace("I", sf::Keyboard::I);
    _chars.emplace("J", sf::Keyboard::J);
    _chars.emplace("K", sf::Keyboard::K);
    _chars.emplace("L", sf::Keyboard::L);
    _chars.emplace("M", sf::Keyboard::M);
    _chars.emplace("N", sf::Keyboard::N);
    _chars.emplace("O", sf::Keyboard::O);
    _chars.emplace("P", sf::Keyboard::P);
    _chars.emplace("Q", sf::Keyboard::Q);
    _chars.emplace("R", sf::Keyboard::R);
    _chars.emplace("S", sf::Keyboard::S);
    _chars.emplace("T", sf::Keyboard::T);
    _chars.emplace("U", sf::Keyboard::U);
    _chars.emplace("V", sf::Keyboard::V);
    _chars.emplace("W", sf::Keyboard::W);
    _chars.emplace("X", sf::Keyboard::X);
    _chars.emplace("Y", sf::Keyboard::Y);
    _chars.emplace("Z", sf::Keyboard::Z);
    _chars.emplace("ENTER", sf::Keyboard::Return);
    _chars.emplace("BACKSPACE", sf::Keyboard::BackSpace);
    _chars.emplace("ESCAPE", sf::Keyboard::Escape);
}

void SFML::initCommands()
{
    _commands.emplace(Arcade::ESCAPE, sf::Keyboard::Escape);
    _commands.emplace(Arcade::MENU, sf::Keyboard::Num0);
    _commands.emplace(Arcade::NEXT_LIB, sf::Keyboard::Num1);
    _commands.emplace(Arcade::NEXT_LIB, sf::Keyboard::Num2);
    _commands.emplace(Arcade::PREV_LIB, sf::Keyboard::Num3);
    _commands.emplace(Arcade::NEXT_GAME, sf::Keyboard::Num4);
    _commands.emplace(Arcade::PREV_GAME, sf::Keyboard::Num5);
    _commands.emplace(Arcade::PLAY, sf::Keyboard::Return);
    _commands.emplace(Arcade::UP, sf::Keyboard::Up);
    _commands.emplace(Arcade::DOWN, sf::Keyboard::Down);
    _commands.emplace(Arcade::RIGHT, sf::Keyboard::Right);
    _commands.emplace(Arcade::LEFT, sf::Keyboard::Left);
}

void SFML::initColors()
{
    _colors.emplace(Arcade::WHITE, sf::Color::White);
    _colors.emplace(Arcade::BLACK, sf::Color::Black);
    _colors.emplace(Arcade::RED, sf::Color::Red);
    _colors.emplace(Arcade::GREEN, sf::Color::Green);
    _colors.emplace(Arcade::BLUE, sf::Color::Blue);
    _colors.emplace(Arcade::YELLOW, sf::Color::Yellow);
    _colors.emplace(Arcade::CYAN, sf::Color::Cyan);
}

Arcade::ILibraryView *createLibrary()
{
    return (new SFML());
}
