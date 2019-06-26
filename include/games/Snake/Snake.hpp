/*
** EPITECH PROJECT, 2019
** Snake.hpp
** File description:
** Snake game header
*/

#ifndef SNAKE_HPP_
    #define SNAKE_HPP_

#include "../IGameModel.hpp"
#include <vector>

extern "C"
{
    Arcade::IGameModel *createGame();
}

#define SPEED_SNAKE 5;
#define MAP_WIDTH 30;
#define MAP_HEIGHT 30;

class Snake : public Arcade::IGameModel {
    public:
        Snake();
        virtual ~Snake();

        void initGame(void) override;
        void initTexture(void) override;

        void gameOver(void) override;
        void gameWin(void) override;
        void move(void) override;
        void spawnNewApple();

        Arcade::Command playGame(Arcade::ICore &core) override;
        Arcade::Command game() override;

    private:
        Arcade::ICore *_core;
        Arcade::Command _cmd;
        std::vector<Arcade::cellTileType> _map;
        std::pair<int, int> _mapSize;
        std::vector<std::pair<int, int>> _snakeCellsPos;
        std::pair<int, int> _applePos;
        std::size_t _snakeSpeed;
        std::size_t _score;
};

#endif /* !SNAKE_HPP_ */
