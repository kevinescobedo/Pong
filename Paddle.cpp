#include "Paddle.hpp"

Paddle::Paddle(float x, float y, float width, float height)
:sf::RectangleShape(sf::Vector2f(width, height))
{
    setPosition(x, y);
    setFillColor(randomColor());
}

Paddle::Paddle(const sf::Vector2f& position, const sf::Vector2f& dimensions)
:Paddle(position.x, position.y, dimensions.x, dimensions.y)
{

}

Paddle::Paddle(const Paddle& paddle)
:Paddle(paddle.getPosition(), paddle.getSize())
{
    setFillColor(paddle.getFillColor());
}

Paddle& Paddle::operator =(const Paddle& paddle)
{
    Paddle(paddle.getPosition(), paddle.getSize());
    setFillColor(paddle.getFillColor());

    return *this;
}

sf::Color Paddle::randomColor()
{
    std::uniform_int_distribution<uint8_t> range(0, 255);
    std::random_device rd;

    uint8_t redValue = range(rd);
    uint8_t greenValue = range(rd);
    uint8_t blueValue = range(rd);

    return sf::Color(redValue, greenValue, blueValue);
}
