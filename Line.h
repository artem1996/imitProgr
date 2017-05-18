//
// Created by note on 11.05.17.
//

#ifndef UNTITLED_LINE_H
#define UNTITLED_LINE_H


#include "Randomizer.h"
#include <iostream>

using namespace std;

class Line {
public:
    Line(Randomizer* transTime);
    void inProgress();
    bool isAll();
    bool isBusy();
    friend ostream& operator<<(ostream& out, Line& line);
protected:
    int tempTime = 0;
    Randomizer* transTime;
    int inPut = 0;
};


#endif //UNTITLED_LINE_H
