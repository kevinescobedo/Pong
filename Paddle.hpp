#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <cstdint>
#include <random>

class Paddle: public sf::RectangleShape
{
public:
    Paddle(float x, float y, float width, float height);
    Paddle(const sf::Vector2f& position, const sf::Vector2f& dimensions);
    Paddle(const Paddle& paddle);
    Paddle& operator =(const Paddle& paddle);
    friend std::ostream& operator <<(std::ostream& os, const Paddle& paddle);

private:
    static sf::Color randomColor();
};

#endif /* PADDLE_HPP */
