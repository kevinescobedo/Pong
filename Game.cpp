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

        const sf::Vector2u windowSize = window.getSize();
        float paddleMovement = windowSize.y / 20.f;

        float currentLeftY = leftPaddle.getPosition().y;
        float currentRightY = rightPaddle.getPosition().y;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if(currentLeftY - paddleMovement >= 0)
            {
                leftPaddle.move(0, -paddleMovement);
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if(currentLeftY + paddleMovement + leftPaddle.getSize().y <= windowSize.y)
            {
                leftPaddle.move(0, paddleMovement);
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if(currentRightY - paddleMovement >= 0)
            {
                rightPaddle.move(0, -paddleMovement);
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if(currentRightY + paddleMovement + rightPaddle.getSize().y <= windowSize.y)
            {
                rightPaddle.move(0, paddleMovement);
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
