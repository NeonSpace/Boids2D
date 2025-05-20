//
// Created by l on 14.05.25.
//

#ifndef SIMULATION2D_HPP
#define SIMULATION2D_HPP

#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Boid.hpp"

enum class arrangementType {
    rand,
    quadratic,
    circular
};


class Simulation2D {
public:
    Simulation2D(int width, int height, sf::RenderWindow& window);

    int getWidth() const{return width;};
    int getHeight() const{return height;};
    int getAmount() const{return amount;};

    //void setAmount(const int amount){this->amount = amount;};

    sf::RenderWindow& getWindow() const{return window;};

    void init(arrangementType aT, int amount);


    void evolve();
    void draw();

private:
    int width, height, amount = 0;
    std::vector<Boid> boids;
    sf::RenderWindow& window;
};

#endif //SIMULATION2D_HPP
