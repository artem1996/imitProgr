//
// Created by note on 11.05.17.
//

#include "Advancer.h"

Advancer::Advancer(Randomizer* transTime) : transTime(transTime) {}

void Advancer::tick() {
    tempTime = transTime->getRand();
}

bool Advancer::isAll() {
    tempTime--;
    if(tempTime == 0) {
        inPut++;
        return true;
    }
    return false;
}

bool Advancer::isBusy() {
    return tempTime > 0;
}

ostream &operator<<(ostream &out, Advancer &line) {
    out << "done: " << line.inPut;
    return out;
}
