/*
** EPITECH PROJECT, 2019
** Core.hpp
** File description:
** Core game
*/

#ifndef COREGAME_HPP_
    #define COREGAME_HPP_

#include "ICore.hpp"
#include "../libs/ILibraryView.hpp"
#include "../games/IGameModel.hpp"
#include "../exception/ArcadeExceptions.hpp"
#include "File.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <dlfcn.h>

class Core : public Arcade::ICore {
    public:
        Core();
        Core(std::string const &libName);
        virtual ~Core();

        static void *dlOpen(const char *file, int mode);
        static void *dlSym(void *handle, const char *function);
        static int dlClose(void *handle);

        void openLib(const std::string &libName) override;
        void openGame(const std::string &gameName) override;
        void getLibs(const std::string directory);
        void getGames(const std::string directory);
        Arcade::ILibraryView *getLibrary() const override;

        void setScore(const std::string &score) override;
        void gameOver() override;

        void switchGame(Arcade::Command cmd) override;
        void switchLib(Arcade::Command cmd) override;

        void getPlayerName();
        void displayGames(std::size_t index);
        void displayLibs();
        void displayControls();
        void startMenu();
        void start();
        void game();

        void getBackToMenu();
        void restartGame();
    private:
        void *_handleGame;
        void *_handleLib;
        bool _exit;
        std::vector<std::string> _libsPath;
        std::vector<std::string> _gamesPath;
        std::vector<std::string> _libsName;
        std::vector<std::string> _gamesName;
        Arcade::ILibraryView *_graphic;
        Arcade::IGameModel *_game;
        std::string _currentGraph;
        std::string _currentGame;
        std::string _playerName;
        std::string _bestScore;
        std::string _libName;
        File _file;
};

#endif /* !COREGAME_HPP_ */
