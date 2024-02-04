#include "Window.hpp"

Window::Window(const char* name, unsigned int width, unsigned int height)
:sf::RenderWindow(sf::VideoMode(width, height), name), title(name)
{
    setFramerateLimit(FRAMERATE);
}

Window::Window(const char* name, const sf::Vector2u& dimensions)
:Window(name, dimensions.x, dimensions.y)
{

}

Window::Window(const Window& window)
:Window(window.title, window.getSize())
{

}

Window& Window::operator =(const Window& window)
{
    Window(window.title, window.getSize());

    return *this;
}

std::ostream& operator <<(std::ostream& os, const Window& window)
{
    os<<"Title: "<<window.title<<'\n';
    sf::Vector2u dimensions = window.getSize();
    os<<"Dimensions: ("<<dimensions.x<<" x "<<dimensions.y<<')';

    return os;
}
