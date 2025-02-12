#include "Game.hpp"

Game::Game(unsigned int width, unsigned int height)
:window("Pong", width, height), leftPaddle(0, 0, width / 35.f, height / 3.f), rightPaddle(width - (width / 35.f), 0, width / 35.f, height / 3.f)
{

}

Game::Game(const sf::Vector2u& dimensions)
:Game(dimensions.x, dimensions.y)
{

}

Game::Game(const Game& game)
:Game(game.window.getSize())
{

}

Game& Game::operator =(const Game& game)
{
    Game(game.window.getSize());

    return *this;
}

Game::~Game()
{
    if(window.isOpen())
    {
        window.close();
    }
}

void Game::play()
{
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                    break;
                }

                default:
                {
                    break;
                }
            }
        }

        window.clear();
        
        window.draw(leftPaddle);
        window.draw(rightPaddle);

        window.display();
    }
}

std::ostream& operator <<(std::ostream& os, const Game& game)
{
    os<<"Window Information\n";
    os<<game.window<<'\n';

    os<<"Left Paddle Information\n";
    os<<game.leftPaddle<<'\n';

    os<<"Right Paddle Information\n";
    os<<game.rightPaddle;

    return os;
}
