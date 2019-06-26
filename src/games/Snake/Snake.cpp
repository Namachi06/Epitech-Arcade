/*
** EPITECH PROJECT, 2019
** Snake.cpp
** File description:
** Snake program
*/

#include "../../../include/games/Snake/Snake.hpp"
#include <cstdlib>
#include <ctime>

Snake::Snake()
{
}

Arcade::Command Snake::playGame(Arcade::ICore &core)
{
    Arcade::Command cmd;

    _core = &core;
    initGame();
    cmd = game();
    return cmd;
}

void Snake::initGame(void)
{
    int width = MAP_WIDTH
    int height = MAP_HEIGHT;
    std::srand(std::time(NULL));
    _mapSize = std::make_pair(width, height);
    _snakeSpeed = SPEED_SNAKE;
    _score = 0;
    for (int i = 0; i < _mapSize.first * _mapSize.second; ++i) {
        _map.push_back(Arcade::OBSTACLE);
    }
    for (int i = 0; i < 5; ++i) {
        _snakeCellsPos.push_back(std::make_pair(_mapSize.first / 2, _mapSize.second / 2 + i));
    }
}

void Snake::initTexture(void)
{
    _core->getLibrary()->assignTexture("./assets/img/empty.img", Arcade::EMPTY, Arcade::Color::DEFAULT);
    _core->getLibrary()->assignTexture("./assets/img/obstacle.img", Arcade::OBSTACLE, Arcade::Color::DEFAULT);
    _core->getLibrary()->assignTexture("./assets/img/apple.img", Arcade::APPLE, Arcade::Color::DEFAULT);
}

void Snake::gameOver(void)
{
}

void Snake::gameWin(void)
{
}

void Snake::move(void)
{
}

void Snake::spawnNewApple(void)
{
    bool checkApple = false;
    std::vector<std::pair<int, int>>::iterator it = _snakeCellsPos.begin();

    _applePos.first = (std::rand() % (_mapSize.first - 2)) + 2;
    _applePos.second = (std::rand() % (_mapSize.second - 2)) + 2;
    for (; it != _snakeCellsPos.end() && checkApple == false; ++it) {
        if (_applePos.first == it->first && _applePos.second == it->second) {
            _applePos.first = (std::rand() % (_mapSize.first - 2)) + 2;
            _applePos.second = (std::rand() % (_mapSize.second - 2)) + 2;
            checkApple = false;
            it = _snakeCellsPos.begin();
        } else
            checkApple = true;
    }
}

Arcade::IGameModel *createGame()
{
    return (new Snake());
}