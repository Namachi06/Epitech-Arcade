/*
** EPITECH PROJECT, 2019
** SFML.hpp
** File description:
** SFML lib header
*/

#ifndef SFML_HPP_
    #define SFML_HPP_

#include "../../core/ICore.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <functional>

extern "C"
{
    Arcade::ILibraryView *createLibrary();
}

class SFML : public Arcade::ILibraryView {
    public:
        SFML();
        virtual ~SFML() = default;

        void init(Arcade::ICore *core) override;
        void close() override;
        void clear() override;
        void refresh() override;

        std::string getCharKeyboardEvent() override;
        Arcade::Command getCommand() override;
        sf::Color getColor(Arcade::Color color);

        void putText(const std::string text, Arcade::Color color,
            std::size_t x, std::size_t y, std::size_t size) override;
        void assignTexture(const std::string path, Arcade::cellTileType type, Arcade::Color color) override;
        void loadTexture(const std::string path, sf::Texture texture);

        void initKeyboard();
        void initCommands();
        void initColors();
        void initTextures();

        sf::Sprite createSprite(const sf::Texture &texture);
        void drawSprite();
    private:
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Font _arcadeFont;
        sf::Texture _empty;
        sf::Texture _obstacle;
        sf::Texture _apple;

        Arcade::ICore *_core;
        std::map<std::string, sf::Keyboard::Key> _chars;
        std::map<Arcade::Command, sf::Keyboard::Key> _commands;
        std::map<Arcade::Color, sf::Color> _colors;
        std::map<Arcade::cellTileType, sf::Texture &> _textures;
};

#endif /* !SFML_HPP_ */
