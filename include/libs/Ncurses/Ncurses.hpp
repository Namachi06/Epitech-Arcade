/*
** EPITECH PROJECT, 2019
** Ncurses.hpp
** File description:
** Ncurses lib header
*/

#ifndef NCURSES_HPP_
    #define NCURSES_HPP_

#include "../../core/ICore.hpp"
#include <ncurses.h>
#include <curses.h>
#include <iostream>
#include <map>

extern "C"
{
    Arcade::ILibraryView *createLibrary();
}

class Ncurses : public Arcade::ILibraryView {
    public:
        Ncurses();
        virtual ~Ncurses() = default;

        void init(Arcade::ICore *core) override;
        void close() override;
        void clear() override;
        void refresh() override;

        std::string getCharKeyboardEvent() override;
        Arcade::Command getCommand() override;

        void putText(const std::string text, Arcade::Color color,
            std::size_t x, std::size_t y, std::size_t size) override;
        void assignTexture(const std::string path, Arcade::cellTileType type, Arcade::Color color) override;

        void initColors();
        void initKeyboard();
        void initCommands();
    private:
        WINDOW *_window;
    	std::map<std::string, int> _chars;
		std::map<Arcade::Command, int> _commands;
        std::map<Arcade::Color, int> _colors;
};

#endif /* !NCURSES_HPP_ */
