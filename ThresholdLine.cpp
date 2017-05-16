//
// Created by note on 11.05.17.
//

#include "ThresholdLine.h"

void ThresholdLine::tick(bool boost) {
    if(boost) {
        tempTime = boostTime->getRand();
    } else {
        tempTime = transTime->getRand();
    }
}

ThresholdLine::ThresholdLine(Randomizer* transTime, Randomizer* boostTime) : Line(transTime), boostTime(boostTime) {}
