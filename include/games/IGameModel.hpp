/*
** EPITECH PROJECT, 2019
** IGameModel.hpp
** File description:
** Interface for the games
*/

#ifndef IGAMEMODEL_HPP_
    #define IGAMEMODEL_HPP_

#include "../core/ICore.hpp"

namespace Arcade
{
	class ICore;
	class ILiraryView;

	class IGameModel {
		public:
			virtual ~IGameModel() = default;

			virtual void initGame(void) = 0;
			virtual void initTexture(void) = 0;

			virtual void gameOver(void) = 0;
			virtual void gameWin(void) = 0;
			virtual void move(void) = 0;

			virtual Arcade::Command playGame(ICore &core) = 0;
			virtual Arcade::Command game() = 0;
	};
};

#endif /* !IGAMEMODEL_HPP_ */
