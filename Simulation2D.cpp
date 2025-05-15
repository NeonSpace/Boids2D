//
// Created by l on 14.05.25.
//

#include "Simulation2D.hpp"
#include <SFML/Graphics.hpp>

Simulation2D::Simulation2D(int width, int height, sf::RenderWindow &window): window(window) {
}

void Simulation2D::init(arrangementType aT, int amount) {
    boids.resize(amount);

    switch (aT) {
        case arrangementType::rand: {
            for (int i = 0; i < amount; i++) {
                boids.at(i).setID(i);
                boids.at(i).setPos(sf::Vector2f(rand() % width, rand() % height));
                boids.at(i).setVel(sf::Vector2f(0, 0));
            }
        }

    }
}

void Simulation2D::evolve() {
    for (int i = 0; i < boids.size(); i++) {

    }
}
