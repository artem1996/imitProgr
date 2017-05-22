//
// Created by note on 02.05.17.
//

#include "Generator.h"

Generator::Generator(double min, double max, int count): Advance(new Randomizer(min, max)), transCount(count) {
}

Generator::Generator(bool type, double constant, int count) :Advance(new Randomizer(type, constant)), transCount(count) {
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
        return makeEvent();
    }
    return NULL;
}

void Generator::setNextBuf(Queue *nextBuf) {
    Generator::nextBuf = nextBuf;
}
