//
// Created by note on 22.05.17.
//

#ifndef UNTITLED_ADVANCERBALANSER_H
#define UNTITLED_ADVANCERBALANSER_H


#include "Advance.h"
#include "Queue.h"

class Chanel: public Advance {
    int numOfNextBuffs;
    Queue *prevBuff;
    Queue **nextBuffs;
public:
    void setPrevBuff(Queue *prevBuff);
    void setNextBuffs(Queue **nextBuffs);
    Chanel(Randomizer *randomizer, int numOfNextBuffs);
    Advance* sendResult();
    Advance* callBack();
};


#endif //UNTITLED_ADVANCERBALANSER_H
