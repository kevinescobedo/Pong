#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

class Window: public sf::RenderWindow
{
private:
    const char* title;
    static constexpr unsigned int FRAMERATE = 60;

public:
    Window(const char* name, unsigned int width, unsigned int height);
    Window(const char* name, const sf::Vector2u& dimensions);
    Window(const Window& window);
    Window& operator =(const Window& window);
    friend std::ostream& operator <<(std::ostream& os, const Window& window);
};

#endif /* WINDOW_HPP */
