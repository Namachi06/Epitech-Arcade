/*
** EPITECH PROJECT, 2019
** ILibraryView.hpp
** File description:
** Interface for the view
*/

#ifndef ILIBRARYVIEW_HPP_
    #define ILIBRARYVIEW_HPP_

#include "../core/ICore.hpp"
#include <string>

#define WIDTH	1920
#define HEIGHT	1080

namespace Arcade
{
    class ICore;

    enum Command
    {
        UNDEFINED,
        ESCAPE,
        MENU,
        RESTART,
        NEXT_LIB,
        PREV_LIB,
        NEXT_GAME,
        PREV_GAME,
        PLAY,
        UP,
        DOWN,
        RIGHT,
        LEFT
    };

    enum Color
    {
        DEFAULT,
        WHITE,
        BLACK,
        RED,
        GREEN,
        BLUE,
        YELLOW,
        CYAN
    };

    enum cellTileType
	{
		EMPTY,
		OBSTACLE,
		APPLE
	};

    class ILibraryView {
        public:
            virtual ~ILibraryView() = default;

            virtual void init(Arcade::ICore *core) = 0;
            virtual void close() = 0;

            virtual void clear() = 0;
            virtual void refresh() = 0;

            virtual std::string getCharKeyboardEvent() = 0;
            virtual Arcade::Command getCommand() = 0;
            virtual void putText(const std::string text, Color color,
                std::size_t x, std::size_t y, std::size_t size) = 0;
            virtual void assignTexture(const std::string path, cellTileType type, Color color) = 0;
    };
};

#endif /* !ILIBRARYVIEW_HPP_ */
