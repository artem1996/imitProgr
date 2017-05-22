//
// Created by note on 18.05.17.
//


#ifndef UNTITLED_ADVANCE_H
#define UNTITLED_ADVANCE_H

#include <iostream>

using namespace std;

class Advance {
protected:
    double tempTime = 0;
public:
    double getTime();
    double decrTime(double minus);
    virtual Advance* sendResult();
    virtual Advance* callBack();
    bool operator<(Advance& second);
    virtual bool isBusy();
};


#endif //UNTITLED_ADVANCE_H
