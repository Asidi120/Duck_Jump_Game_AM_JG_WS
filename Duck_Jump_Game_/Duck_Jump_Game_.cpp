#include "SFML/Graphics.hpp" // w tym miejscu nawiasy ostre (youtube uniemożliwia umieszczenie ich w opisie filmu)

int main(void) {
    sf::RenderWindow window(sf::VideoMode(700, 900), "Duck_Jump");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) //:DD
    {
        sf::Event event;
        while (window.pollEvent(event)) //ko
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }//dkd

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}