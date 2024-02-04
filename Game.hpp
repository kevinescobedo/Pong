#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System/Vector2.hpp>
#include "Window.hpp"
#include <iostream>

class Game
{
private:
    Window window;

public:
    Game(unsigned int width, unsigned int height);
    Game(const sf::Vector2u& dimensions);
    Game(const Game& game);
    Game& operator =(const Game& game);
    ~Game();
    void play();
    friend std::ostream& operator <<(std::ostream& os, const Game& game);
};

#endif /* GAME_HPP */
