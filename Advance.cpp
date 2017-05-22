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

Advance *Advance::sendResult() {
    cout << "advanceend" << endl;
    return nullptr;
}

ostream &operator<<(ostream &out, Advance &line) {
    out << "done: " << line.inPut;
    return out;
}

Advance *Advance::callback() {
    return NULL;
}
