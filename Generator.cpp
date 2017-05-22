//
// Created by note on 02.05.17.
//

#include "Generator.h"

Generator::Generator(double min, double max, int count): Randomizer(min, max), transCount(count) {
}

Generator::Generator(double constant, int count, bool type) : Randomizer(constant, type), transCount(count) {
}

ostream &operator<<(ostream &out, Generator &generator) {
    out << "generated: " << generator.outPut;
    return out;
}

Advance *Generator::sendResult() {
    transCount--;
    outPut++;
    return nextBuf->getResult();
}

Advance *Generator::callBack() {
    if(transCount > 0) {
        tempTime = getRand();
        return this;
    }
    return NULL;
}

void Generator::setNextBuf(Buffer *nextBuf) {
    Generator::nextBuf = nextBuf;
}
