/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** Main
*/

#include <iostream>
#include "../../include/core/Core.hpp"
#include "../../include/exception/ArcadeExceptions.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        std::cerr << "USAGE: ./arcade ./lib/lib_arcade_XXX.so" << std::endl;
        return (84);
    }
    try {
        Core core(argv[1]);
        core.start();
    } catch(ArcadeExceptions::ArcadeException const &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}
