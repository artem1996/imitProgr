//
// Created by note on 18.05.17.
//

#include "Advance.h"

double Advance::getTime() {
    return tempTime;
}

double Advance::decrTime(double minus) {
    tempTime -= minus;
    return tempTime;
}

bool Advance::operator<(Advance &second) {
    return this->tempTime < second.tempTime;
}

bool Advance::isBusy() {
    return busy;
}

Advance *Advance::sendResult() {
    cout << "advanceend" << endl;
    return nullptr;
}

Advance *Advance::callBack() {
    cout << "advancecallback" << endl;
    return nullptr;
}

Advance* Advance::makeEvent() {
    busy = true;
    tempTime = randomizer->getRand();
    return this;
}

Advance::Advance(Randomizer *randomizer): randomizer(randomizer) {
}

ostream &operator<<(ostream &out, Advance &line) {
    out << "done: " << line.inPut;
    return out;
}
