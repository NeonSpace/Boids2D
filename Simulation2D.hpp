//
// Created by l on 14.05.25.
//

#ifndef SIMULATION2D_HPP
#define SIMULATION2D_HPP

#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Boid.hpp"
#include "customEnums.hpp"


class Simulation2D {
public:
    Simulation2D(int width, int height, sf::RenderWindow& window);

    int getWidth() const{return width;};
    int getHeight() const{return height;};
    int getAmount() const{return amount;};

    //void setAmount(const int amount){this->amount = amount;};

    sf::RenderWindow& getWindow() const{return window;};

    void init(arrangementType aT, movementType mT, int amount);

    std::vector<float> keepInBounds(float x, float y) const;
    std::vector<float> keepInBounds(const std::vector<float> &yx) const;

    void evolve();
    void draw(float radius);

private:
    int width, height, amount = 0;
    std::vector<Boid> boids;
    sf::RenderWindow& window;
    arrangementType aT;
    movementType mT;
};

#endif //SIMULATION2D_HPP
