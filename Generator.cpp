//
// Created by note on 02.05.17.
//

#include "Generator.h"

extern double Time;

Generator::Generator(double min, double max, bool type, bool difficult): Randomizer(type, max, min), difficult(difficult) {
}

Generator::Generator(double constant, bool difficult) : Randomizer(constant), difficult(difficult) {
}

ostream &operator<<(ostream &out, Generator &generator) {
    out << "generated: " << generator.outPut;
    return out;
}

Advance *Generator::sendResult() {
    outPut++;
    return Queue::getQueue(difficult);
}

Advance *Generator::callback() {
    if(Time < THRESHOLDTIME) {
        tempTime = getRand();
        return this;
    }
    return NULL;
}
