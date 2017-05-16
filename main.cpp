#include "iostream"
#include "Generator.h"
#include "Buffer.h"
#include "ThresholdBuffer.h"
#include "Line.h"
#include "ThresholdLine.h"

using namespace std;

int main() {
    srand((unsigned int) time(NULL));
    int point = 1000;
    int temp = 0;
    int tempTime = 0;
    int allTime = 0;
    Generator gen(5, 15, false);
    Buffer A(20);
    ThresholdBuffer B(25, 20);
    Line AB1(new Randomizer(20)), AB2(new Randomizer(false, 15, 25));
    ThresholdLine BC1(new Randomizer(false, 22, 28), new Randomizer(15)), BC2(new Randomizer(false, 23, 30), new Randomizer(16));
    while (point > temp) {
        tempTime++;
        //------------------------------------------------
        if(gen.tick()) {
            A.push();
        }
        if(AB1.isAll()) {
            B.push(false);
        }
        if(AB2.isAll()) {
            B.push(true);
        }
        if(BC1.isAll())
            temp++;
        if(BC2.isAll())
            temp++;
        //-----------------------------------------------
        if(!AB1.isBusy()) {
            if(A.pop())
                AB1.tick();
        }
        if(!AB2.isBusy()) {
            if(A.pop())
                AB2.tick();
        }
        if(!BC1.isBusy()) {
            bool difficult = B.isDifficult();
            if(B.pop(false))
                BC1.tick(difficult);
        }
        if(!BC2.isBusy()) {
            bool difficult = B.isDifficult();
            if(B.pop(true))
                BC2.tick(difficult);
        }
        //------------------------------------------------
        temp += A.isAbove();
        temp += B.isAbove();
    }
    cout << "Total: " << temp << "; Time: " << tempTime << endl;
    cout << "Generator: " << gen << endl;
    cout << "A: " << A << endl;
    cout << "AB1: " << AB1 << endl;
    cout << "AB2: " << AB2 << endl;
    cout << "B: " << B << endl;
    cout << "BC1: " << BC1 << endl;
    cout << "BC2: " << BC2 << endl;
}