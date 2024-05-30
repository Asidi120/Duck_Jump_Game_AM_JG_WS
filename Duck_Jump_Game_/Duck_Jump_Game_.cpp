﻿#include "SFML/Graphics.hpp" // w tym miejscu nawiasy ostre (youtube uniemożliwia umieszczenie ich w opisie filmu)

int main(void) {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) 
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}