//
// Created by l on 14.05.25.
//

#ifndef BOID_HPP
#define BOID_HPP
#include <SFML/System/Vector2.hpp>

class Boid {
public:
    Boid(int id, sf::Vector2f pos, sf::Vector2f vel = sf::Vector2f(0,0));

    ~Boid() = default;

    int getID();
    sf::Vector2f getPos() const;
    sf::Vector2f getVel() const;

    void setPos(sf::Vector2f pos);
    void setVel(sf::Vector2f vel);
    void setID(int id);

    void update();

private:
    sf::Vector2f pos;
    sf::Vector2f vel;
    int id;

};

#endif //BOID_HPP
