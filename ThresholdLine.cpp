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

ThresholdLine::ThresholdLine(bool label, Randomizer* transTime, Randomizer* boostTime) : label(label), transTime(transTime), boostTime(boostTime) {}

Advance *ThresholdLine::makeEvent(bool difficult) {
    tempTime = difficult ? transTime->getRand() : boostTime->getRand();
    return this;
}

Advance *ThresholdLine::callBack() {
    if(prevBuff->watch(label)) {
        if(prevBuff->isDifficult()) {
            tempTime = boostTime->getRand();
        } else {
            tempTime = transTime->getRand();
        }
        prevBuff->pop(label);
        return this;
    }
    return NULL;
}

Advance *ThresholdLine::sendResult() {
    tempTime = 0;
    inPut++;
    return NULL;
}

void ThresholdLine::setPrevBuff(ThresholdBuffer *prevBuff) {
    ThresholdLine::prevBuff = prevBuff;
}

ostream &operator<<(ostream &out, ThresholdLine &line) {
    out << "done: " << line.inPut;
    return out;
}