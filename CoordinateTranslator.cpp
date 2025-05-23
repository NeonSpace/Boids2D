//
// Created by l on 23.05.25.
//

#include "CoordinateTranslator.hpp"

#include <complex>
#include <utility>
#include "customEnums.hpp"
using namespace std;

CoordinateTranslator::CoordinateTranslator(enum coordinateType cT, float baseInWindowX, float baseInWindowY) {
    this->coordinateType = cT;
    this->posInWindow[0] = baseInWindowY;
    this->posInWindow[1] = baseInWindowX;
}

std::vector<float> CoordinateTranslator::translate(std::vector<float> newRealtivePosition) {
    //if polar:  newRealtivePosition[0] = radius , newRealtivePosition[1] = angle
    //if cartesian:  newRealtivePosition[0] = y , newRealtivePosition[1] = x
    //return is always cartesian to window base

    std::vector<float> newPosInWindow;
    switch (coordinateType) {
        case coordinateType::polar: {
            newPosInWindow[0] = newRealtivePosition[0] * cos(newRealtivePosition[1]) + posInWindow[0];
            newPosInWindow[1] = newRealtivePosition[0] * sin(newRealtivePosition[1]) + posInWindow[1];
            return newPosInWindow;
        }
        default:{ // coordinateType::cartesian: {
            newPosInWindow[0] = newRealtivePosition[0] + posInWindow[0];
            newPosInWindow[1] = newRealtivePosition[1] + posInWindow[1];
            return newPosInWindow;
        }
    }
}

std::vector<float> CoordinateTranslator::translate(float newRelativeX, float newRelativeY) {
    std::vector<float> relativePosition;
    relativePosition.push_back(newRelativeY);
    relativePosition.push_back(newRelativeX);
    return this->translate(relativePosition);
}

void CoordinateTranslator::setNewBase(float baseInWindowX, float baseInWindowY) {
    this->posInWindow[0] = baseInWindowY;
    this->posInWindow[1] = baseInWindowX;
}
