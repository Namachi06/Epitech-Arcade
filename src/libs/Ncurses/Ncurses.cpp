/*
** EPITECH PROJECT, 2019
** Ncurses.cpp
** File description:
** Ncurses lib program
*/

#include "../../../include/libs/Ncurses/Ncurses.hpp"
#include "../../../include/libs/Ncurses/NcursesFunc.hpp"
#include <iostream>

Ncurses::Ncurses()
{
    _window = NULL;
}

void Ncurses::init(Arcade::ICore *core)
{
    (void)core;
    initKeyboard();
    initCommands();
    NcursesFunc::newTerm(NULL, stderr, stdin);
    NcursesFunc::noEcho();
    NcursesFunc::cBreak();
    NcursesFunc::cursSet(0);
    NcursesFunc::keyPad(stdscr, TRUE);
    initColors();
}

void Ncurses::close()
{
    NcursesFunc::endWin();
}

void Ncurses::clear()
{
    NcursesFunc::Clear();
}

void Ncurses::refresh()
{
    NcursesFunc::Refresh();
}

std::string Ncurses::getCharKeyboardEvent()
{
    int c;

    c = NcursesFunc::getCh();
    for (auto &&character : _chars) {
        if (character.second == c) {
            return character.first;
        }
    }
    return "";
}

Arcade::Command Ncurses::getCommand()
{
    int c;

    c = NcursesFunc::getCh();
    for (auto &&command : _commands) {
        if (command.second == c) {
            return command.first;
        }
    }
    return Arcade::UNDEFINED;
}

void Ncurses::putText(const std::string text, Arcade::Color color,
                      std::size_t x, std::size_t y, std::size_t size)
{
    (void)size;
    NcursesFunc::Attron(COLOR_PAIR(color));
    mvprintw(y / 20, (x / 9) - (text.length() / 2), text.c_str());
    NcursesFunc::Attroff(COLOR_PAIR(color));
}

void Ncurses::assignTexture(const std::string path, Arcade::cellTileType type, Arcade::Color color)
{
    (void)path;
    (void)type;
    (void)color;
}

void Ncurses::initKeyboard()
{
    _chars.emplace("A", 'a');
    _chars.emplace("B", 'b');
    _chars.emplace("C", 'c');
    _chars.emplace("D", 'd');
    _chars.emplace("E", 'e');
    _chars.emplace("F", 'f');
    _chars.emplace("G", 'g');
    _chars.emplace("H", 'h');
    _chars.emplace("I", 'i');
    _chars.emplace("J", 'j');
    _chars.emplace("K", 'k');
    _chars.emplace("L", 'l');
    _chars.emplace("M", 'm');
    _chars.emplace("N", 'n');
    _chars.emplace("O", 'o');
    _chars.emplace("P", 'p');
    _chars.emplace("Q", 'q');
    _chars.emplace("R", 'r');
    _chars.emplace("S", 's');
    _chars.emplace("T", 't');
    _chars.emplace("U", 'u');
    _chars.emplace("V", 'v');
    _chars.emplace("W", 'w');
    _chars.emplace("X", 'x');
    _chars.emplace("Y", 'y');
    _chars.emplace("Z", 'z');
    _chars.emplace("ENTER", 10);
    _chars.emplace("BACKSPACE", 263);
    _chars.emplace("ESCAPE", 27);
}

void Ncurses::initCommands()
{
    _commands.emplace(Arcade::ESCAPE, 27);
    _commands.emplace(Arcade::MENU, 48);
    _commands.emplace(Arcade::RESTART, 49);
    _commands.emplace(Arcade::NEXT_LIB, 50);
    _commands.emplace(Arcade::PREV_LIB, 51);
    _commands.emplace(Arcade::NEXT_GAME, 52);
    _commands.emplace(Arcade::PREV_GAME, 53);
    _commands.emplace(Arcade::PLAY, 10);
    _commands.emplace(Arcade::UP, KEY_UP);
    _commands.emplace(Arcade::DOWN, KEY_DOWN);
    _commands.emplace(Arcade::RIGHT, KEY_RIGHT);
    _commands.emplace(Arcade::LEFT, KEY_LEFT);
}

void Ncurses::initColors()
{
    NcursesFunc::startColor();
    NcursesFunc::initPair(Arcade::WHITE, COLOR_WHITE, COLOR_BLACK);
    NcursesFunc::initPair(Arcade::BLACK, COLOR_BLACK, COLOR_WHITE);
    NcursesFunc::initPair(Arcade::RED, COLOR_RED, COLOR_BLACK);
    NcursesFunc::initPair(Arcade::GREEN, COLOR_GREEN, COLOR_BLACK);
    NcursesFunc::initPair(Arcade::BLUE, COLOR_BLUE, COLOR_BLACK);
    NcursesFunc::initPair(Arcade::YELLOW, COLOR_YELLOW, COLOR_BLACK);
    NcursesFunc::initPair(Arcade::CYAN, COLOR_CYAN, COLOR_BLACK);
}

Arcade::ILibraryView *createLibrary()
{
    return (new Ncurses());
}
