//
// Created by note on 11.05.17.
//

#include "Barber.h"

extern double Time;

Barber::Barber(Randomizer* transTime, Randomizer* diffTransTime, double dinner, double during) :
        transTime(transTime), diffTransTime(diffTransTime), dinner(dinner), during(during), dinnerStart(dinner) {}

Advance *Barber::sendResult() {
    busy = false;
    if(!isDinnered && Time > dinner)
        dinnerStart = Time;
    return NULL;
}

Advance *Barber::makeEvent(bool difficult) {
    busy = true;
    inPut++;
    if(difficult) {
        tempTime = diffTransTime->getRand();
    } else {
        tempTime = transTime->getRand();
    }
    return this;
}

bool Barber::isBusy() {
    return (busy || (!isDinnered && Time > dinner && Time < dinnerStart + during));
}
