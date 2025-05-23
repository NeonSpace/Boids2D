#include <iostream>
#include <SFML/Graphics.hpp>

#include "Simulation2D.hpp"

int main() {
    constexpr float width = 1000;
    constexpr float height = 1000;
    int amount = 5;
    float radius = 10;
    arrangementType aT = arrangementType::rand;
    movementType mT = movementType::linear;

    sf::RenderWindow window(sf::VideoMode( width, height), "Boid Simulation");
    Simulation2D sim = Simulation2D( width, height, window);

    sim.init(aT, mT, amount);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sim.evolve();
        window.clear(sf::Color::Black);
        sim.draw(radius);

        window.display();
    }

    return 0;
}
