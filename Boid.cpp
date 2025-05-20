//
// Created by l on 14.05.25.
//

#include "Boid.hpp"

#include <algorithm>

Boid::Boid(int id, sf::Vector2f pos, sf::Vector2f vel) {
    this->id = id;
    this->pos = pos;
    this->vel = vel;
}


int Boid::getID() const {
    return id;
}

void Boid::setID(int id) {
    this->id = id;
}

sf::Vector2f Boid::getPos() const {
    return pos;
}

sf::Vector2f Boid::getVel() const {
    return vel;
}

void Boid::setPos(sf::Vector2f pos) {
    this->pos = pos;
}

void Boid::setVel(sf::Vector2f vel) {
    this->vel = vel;
}

void Boid::update() {

}
