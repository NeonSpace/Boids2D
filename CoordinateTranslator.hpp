//
// Created by l on 23.05.25.
//

#ifndef COORDINATETRANSLATOR_HPP
#define COORDINATETRANSLATOR_HPP

#include <vector>
#include "customEnums.hpp"


class CoordinateTranslator {
public:
    CoordinateTranslator() = default;
    ~CoordinateTranslator() = default;

    CoordinateTranslator(coordinateType cT, float baseInWindowX, float baseInWindowY);

    std::vector<float> translate (std::vector<float>);
    std::vector<float> translate (float newX, float newY);

    void setNewBase(float baseInWindowX, float baseInWindowY);

private:
    std::vector<float> posInWindow;
    coordinateType coordinateType = coordinateType::cartesian;
};

#endif //COORDINATETRANSLATOR_HPP
