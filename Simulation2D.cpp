//
// Created by l on 14.05.25.
//
#include <iostream>
#include <cmath>
#include "Simulation2D.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

Simulation2D::Simulation2D(int width, int height, sf::RenderWindow &window): window(window) {
    this->width = width;
    this->height = height;
}

void Simulation2D::init(arrangementType aT, movementType mT, int amount) {
    this->mT = mT;
    this->aT = aT;
    this->amount = amount;
    boids.resize(amount);

    switch (aT) {
        case arrangementType::rand: {
            for (int i = 0; i < amount; i++) {
                boids.at(i).setID(i);
                float fx = static_cast<float>(random()) / RAND_MAX;
                float fy = static_cast<float>(random()) / RAND_MAX;
                boids.at(i).setPos(sf::Vector2f(fx * width, fy * height));
                boids.at(i).setVel(sf::Vector2f(0, 0));
            }
            break;
        }
        case arrangementType::quadratic: {
            double amountPerLine = std::round(std::sqrt(amount));

            std::cout << amountPerLine << std::endl;
            double distance = width / amountPerLine;
            std::cout << distance << std::endl;
            int currentID = 0;

            for (int i = 0; i < amountPerLine; i++) {
                for (int j = 0; j < amountPerLine; j++) {
                    boids.at(currentID).setID(currentID);
                    boids.at(currentID).setPos(sf::Vector2f( i*distance, j*distance));
                    boids.at(currentID).setVel(sf::Vector2f(0, 0));
                    currentID++;
                }
            }
            break;
        }
        case arrangementType::circular: {
/*

            for (int i = 0; i < amount; i++) {
                boids.at(i).setID(i);
            }

            auto calcV1 = [](int x) -> int {
                //return round(sqrt(2));
                x++;
                return x*3;
            };

            //Calculate Nr of boids per Ring:
            vector<int> rings;
            rings.resize(amount);
            int leftoverAmount = amount;
            for (int ringNr = 0; ringNr < amount; ringNr++) {
                int numberOfBoidsOnThisRing = calcV1(ringNr);
                rings.push_back(numberOfBoidsOnThisRing);
                leftoverAmount -= numberOfBoidsOnThisRing;
                if (leftoverAmount <= 0) {
                    break;
                }
            }
            //Position Boids:
            float midX = width / 2;
            float midY = height / 2;
            leftoverAmount = amount;
            for (int ringNr = 0; ringNr < rings.size(); ringNr++) {
                float angleBetweenBoids = 360 / rings.at(ringNr);


            }

*/

            break;
        }
    }
}

void Simulation2D::evolve() {
    switch (mT) {
        case movementType::rand: {
            for (int i = 0; i < boids.size(); i++) {
                float newPosX = 0;
                float newPosY = 0;
                float posChangeX= -1 + 2*static_cast<float>(rand()) / RAND_MAX;
                float posChangeY= -1 + 2*static_cast<float>(rand()) / RAND_MAX;

                newPosX = boids.at(i).getPos().x+posChangeX;
                newPosY = boids.at(i).getPos().y+posChangeY;
                vector<float> flow = keepInBounds(newPosY, newPosX);
                boids.at(i).setPos(sf::Vector2f(flow.at(0), flow.at(1)));
            }
            break;
        }
        default: { //lin movement
            for (int i = 0; i < boids.size(); i++) {
                float newPosX = 0;
                float newPosY = 0;
                float posChange= 0.05;

                newPosX = boids.at(i).getPos().x+posChange;
                newPosY = boids.at(i).getPos().y;
                vector<float> flow = keepInBounds(newPosY, newPosX);
                boids.at(i).setPos(sf::Vector2f(flow.at(0), flow.at(1)));
            }

        }
    }
}

void Simulation2D::draw(float radius) {
    for (int i = 0; i < boids.size(); i++) {
        sf::CircleShape boidShape(radius);
        boidShape.setFillColor(sf::Color::Blue);
        float shapePosX = boids.at(i).getPos().x - radius;
        float shapePosY = boids.at(i).getPos().y - radius;
        boidShape.setPosition(shapePosX, shapePosY);

        window.draw(boidShape);
    }
}

std::vector<float> Simulation2D::keepInBounds(float x, float y) const {
    if (y > height || y < 0) {
        y= fmod(y, height);
        if (y < 0) {
            y = fabs(y);
        }
    }
    if (x > width || x < 0) {
        x = fmod(x, width);
        if (x < 0) {
            x = fabs(x);
        }
    }
    return std::vector<float>{y, x};
}

std::vector<float> Simulation2D::keepInBounds(const std::vector<float> &yx) const {
    return this->keepInBounds(yx.at(1), yx.at(0));

}
