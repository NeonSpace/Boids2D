//
// Created by l on 14.05.25.
//

#include "Simulation2D.hpp"
#include <SFML/Graphics.hpp>

Simulation2D::Simulation2D(int width, int height, sf::RenderWindow &window): window(window) {
    this->width = width;
    this->height = height;
}

void Simulation2D::init(arrangementType aT, int amount) {
    boids.resize(amount);

    switch (aT) {
        case arrangementType::rand: {
            for (int i = 0; i < amount; i++) {
                boids.at(i).setID(i);
                float fx = static_cast<float>(rand()) / RAND_MAX;
                float fy = static_cast<float>(rand()) / RAND_MAX;
                boids.at(i).setPos(sf::Vector2f(fx * width, fy * height));
                boids.at(i).setVel(sf::Vector2f(fx, fy));
            }
            break;
        }
        case arrangementType::quadratic: {
            for (int i = 0; i < amount; i++) {
                boids.at(i).setID(i);
                boids.at(i).setPos(sf::Vector2f( 10+i*4, 10+i*4));
                boids.at(i).setVel(sf::Vector2f(0, 0));
            }
            break;
        }
    }
}

void Simulation2D::evolve() {
    /*for (int i = 0; i < boids.size(); i++) {
        float newPosX = 0;
        float newPosY = 0;
        float posChange= 0.05;
        if (boids.at(i).getPos().x+posChange > width) {
            newPosX = width - boids.at(i).getPos().x+posChange;
        }else {
            newPosX = boids.at(i).getPos().x+posChange;
        }
        if (boids.at(i).getPos().y+posChange > height) {
            newPosY = height - boids.at(i).getPos().y+posChange;
        }else {
            newPosY = boids.at(i).getPos().y+posChange;
        }
        boids.at(i).setPos(sf::Vector2f(newPosX, newPosY));
    }*/

    for (int i = 0; i < boids.size(); i++) {
        float newPosX = 0;
        float newPosY = 0;
        float posChangeX= -0.5 + static_cast<float>(rand()) / RAND_MAX;
        float posChangeY= -0.5 + static_cast<float>(rand()) / RAND_MAX;

        if (boids.at(i).getPos().x+posChangeX > width) {
            newPosX = width - boids.at(i).getPos().x+posChangeX;
        }else {
            newPosX = boids.at(i).getPos().x+posChangeX;
        }
        if (boids.at(i).getPos().y+posChangeY > height) {
            newPosY = height - boids.at(i).getPos().y+posChangeY;
        }else {
            newPosY = boids.at(i).getPos().y+posChangeY;
        }
        boids.at(i).setPos(sf::Vector2f(newPosX, newPosY));
    }
}

void Simulation2D::draw() {
    for (int i = 0; i < boids.size(); i++) {
        sf::CircleShape boidShape(3);
        boidShape.setFillColor(sf::Color::Blue);
        boidShape.setPosition(boids.at(i).getPos());

        window.draw(boidShape);
    }
}
