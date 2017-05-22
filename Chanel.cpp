//
// Created by note on 22.05.17.
//

#include "Chanel.h"

template <class T>
int minim(T** a, int size) {
    int min = 0;
    for (int i = 1; i < size; ++i){
        if (*a[i] < *a[min])
            min = i;
    }
    return min;
}

Chanel::Chanel(Randomizer *randomizer, int numOfNextBuffs) : Advance(randomizer), numOfNextBuffs(numOfNextBuffs) {}

void Chanel::setNextBuffs(Queue **nextBuffs) {
    Chanel::nextBuffs = nextBuffs;
}

Advance *Chanel::sendResult() {
    int next = minim(nextBuffs, numOfNextBuffs);
    inPut++;
    return nextBuffs[next]->getResult();;
}

void Chanel::setPrevBuff(Queue *prevBuff) {
    Chanel::prevBuff = prevBuff;
}

Advance *Chanel::callBack() {
    busy = false;
    if(prevBuff->pop()) {
        return makeEvent();
    }
    return NULL;
}
