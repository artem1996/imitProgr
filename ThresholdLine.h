//
// Created by note on 11.05.17.
//

#ifndef UNTITLED_THRESHOLDLINE_H
#define UNTITLED_THRESHOLDLINE_H


#include "Line.h"

class ThresholdLine: public Line {
    Randomizer* boostTime;
public:
    ThresholdLine(Randomizer* transTime, Randomizer* boostTime);
    void tick(bool);
};


#endif //UNTITLED_THRESHOLDLINE_H
