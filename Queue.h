//
// Created by note on 11.05.17.
//

#ifndef UNTITLED_BUFFER_H
#define UNTITLED_BUFFER_H


#include <vector>
#include <iostream>
#include "Advance.h"
#include "Barber.h"
#include "Transfer.h"

using namespace std;

class Barber;

class Queue: Advance {
    static Transfer *transfer;
    static Barber **barbers;
    static int countBarbers;
    static int inPut;
    static int outFirst;
    static int outSecond;
    static int aboveFirst;
    static int aboveSecond;
    bool difficult;
    Queue(bool difficult);
public:
    static Advance* getQueue(bool difficult);
    static void setTransfer(Transfer*);
    static void setBurbers(Barber**, int);
    static void print();
    Advance* sendResult();
};


#endif //UNTITLED_BUFFER_H
