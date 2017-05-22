//
// Created by note on 11.05.17.
//

#include "Queue.h"

Queue::Queue(bool difficult) : difficult(difficult) {}

void Queue::setTransfer(Transfer *trans) {
    transfer = trans;
}

Advance *Queue::getQueue(bool difficult) {
    inPut++;
    for(int i = 0; i < countBarbers; i++) {
        if(!barbers[i]->isBusy()) {
            outFirst++;
            return barbers[i]->makeEvent(difficult);
        }
    }
    if(!transfer->tick()) {
        aboveFirst++;
        return NULL;
    }
    return new Queue(difficult);
}

void Queue::setBurbers(Barber **pBarber, int pCountBarbers) {
    barbers = pBarber;
    countBarbers = pCountBarbers;
}

Advance *Queue::sendResult() {
    for(int i = 0; i < countBarbers; i++) {
        if(!barbers[i]->isBusy()) {
            outSecond++;
            return barbers[i]->makeEvent(difficult);
        }
    }
    aboveSecond++;
    return NULL;
}

void Queue::print() {
    cout << "Queue: inPut: " << inPut << "; firstOut: " << outFirst << "; secondOut: " << outSecond << "; firstAbove: " << aboveFirst << "; secondAbove: " << aboveSecond << endl;
}
