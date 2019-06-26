/*
** EPITECH PROJECT, 2019
** Pacman.hpp
** File description:
** Pacman game header
*/

#ifndef PACMAN_HPP_
    #define PACMAN_HPP_

#include "../IGameModel.hpp"

extern "C"
{
    Arcade::IGameModel *createGame();
}

class Pacman : public Arcade::IGameModel {
    public:
        Pacman();
        virtual ~Pacman();

        void initGame(void) override;
        void initTexture(void) override;

        void gameOver(void) override;
        void gameWin(void) override;
        void move(void) override;

        Arcade::Command playGame(Arcade::ICore &core) override;
        Arcade::Command game() override;
    private:
};

#endif /* !PACMAN_HPP_ */
