#include <iostream>
#include <SFML/Graphics.hpp>

#include "Simulation2D.hpp"

int main() {

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Boid Simulation");
    Simulation2D sim = Simulation2D(1000,1000,window);

    sim.init(arrangementType::rand, 500);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sim.evolve();
        window.clear(sf::Color::White);
        sim.draw();

        window.display();
    }

    return 0;
}
