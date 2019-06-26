/*
** EPITECH PROJECT, 2019
** ICore.hh
** File description:
** Core interface
*/

#ifndef ICORE_HH_
    #define ICORE_HH_

#include "../libs/ILibraryView.hpp"
#include "../games/IGameModel.hpp"
#include <string>

namespace Arcade
{
	class ICore {
		public:
			virtual ~ICore() = default;

			virtual void openLib(const std::string &libName) = 0;
			virtual void openGame(const std::string &gameName) = 0;

			virtual void gameOver() = 0;
			virtual void setScore(const std::string &score) = 0;

			virtual void switchGame(Arcade::Command cmd) = 0;
			virtual void switchLib(Arcade::Command cmd) = 0;

			virtual ILibraryView *getLibrary() const = 0;
	};
};


#endif /* !ICORE_HH_ */
