//
// Created by note on 11.05.17.
//

#include "Line.h"

Line::Line(Randomizer* transTime) : transTime(transTime) {}

void Line::inProgress() {
    tempTime = transTime->getRand();
}

bool Line::isAll() {
    tempTime--;
    if(!tempTime) {
        inPut++;
        return true;
    }
    return false;
}

bool Line::isBusy() {
    return tempTime > 0;
}

ostream &operator<<(ostream &out, Line &line) {
    out << "done: " << line.inPut;
    return out;
}
