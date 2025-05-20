#include <iostream>
#include <SFML/Graphics.hpp>

#include "Simulation2D.hpp"

int main() {

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Boid Simulation");
    Simulation2D sim = Simulation2D(1000,1000,window);

    sim.init(arrangementType::quadratic, 10);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sim.evolve();
        window.clear(sf::Color::Black);
        sim.draw(100);

        window.display();
    }

    return 0;
}
