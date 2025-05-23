//
// Created by l on 23.05.25.
//

#include "CoordinateTranslator.hpp"

#include <utility>
#include "customEnums.hpp"
using namespace std;

CoordinateTranslator::CoordinateTranslator(enum coordinateType cT, float baseInWindowX, float baseInWindowY) {
    this->coordinateType = cT;
    this->posInWindow[0] = baseInWindowY;
    this->posInWindow[1] = baseInWindowX;
}

std::vector<float> CoordinateTranslator::translate(std::vector<float> newRealtivePosition) {
    this->posInWindow = std::move(newRealtivePosition);
    switch (coordinateType) {
        case coordinateType::polar: {



            break;
        }
        default:{ // coordinateType::cartesian: {



            break;
        }
    }
}

std::vector<float> CoordinateTranslator::translate(float newRelativeX, float newRelativeY) {
    std::vector<float> realtivePosition;
    realtivePosition.push_back(newRelativeY);
    realtivePosition.push_back(newRelativeX);
    return this->translate(realtivePosition);
}

void CoordinateTranslator::setNewBase(float baseInWindowX, float baseInWindowY) {
    this->posInWindow[0] = baseInWindowY;
    this->posInWindow[1] = baseInWindowX;
}
