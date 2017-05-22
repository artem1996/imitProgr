//
// Created by note on 11.05.17.
//

#include "Controller.h"

Controller::Controller(Randomizer* transTime) : Advance(transTime) {}

Advance *Controller::callBack() {
    inPut++;
    busy = false;
    if(prevBuffer->pop()) {
        return makeEvent();
    }
    return NULL;
}

Advance *Controller::sendResult() {
    return NULL;
}

void Controller::setPrevBuffer(Queue *prevBuffer) {
    Controller::prevBuffer = prevBuffer;
}