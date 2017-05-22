#include <random>
#include "iostream"
#include "Generator.h"
#define NUMOFTRANS 1000

using namespace std;

int main() {
    double Time = 0;
    double tempTime;
    Generator gen(5., 15., NUMOFTRANS);
    Buffer A(20);
    ThresholdBuffer B(25, 20);
    Line AB1(false, new Randomizer(false, 20)),
            AB2(true, new Randomizer(15., 25.));
    ThresholdLine BC1(false, new Randomizer(22., 28.), new Randomizer(false, 15)),
            BC2(true, new Randomizer(23., 30.), new Randomizer(false, 16));
    gen.setNextBuf(&A);
    static Line* lines[] = {&AB1, &AB2};
    A.setNext(lines);
    AB1.setPrevBuffer(&A);
    AB1.setNextBuffer(&B);
    AB2.setPrevBuffer(&A);
    AB2.setNextBuffer(&B);
    B.setLine1(&BC1);
    B.setLine2(&BC2);
    BC1.setPrevBuff(&B);
    BC2.setPrevBuff(&B);
    std::vector<Advance*> FEC;
    FEC.push_back(&gen);
    while (FEC.size()) {
        Advance* iteration = FEC[0];
        FEC.erase(FEC.begin());
        for(int i = 0; i < FEC.size(); i++) {
            FEC[i]->decrTime(iteration->getTime());
        }
        B.setSquare(iteration->getTime());
        Time += iteration->getTime();
        Advance* event = iteration->sendResult();
        if(event != NULL) {
            int i = 0;
            for(; i < FEC.size(); i++) {
                if(*event < *FEC[i]) {
                    FEC.insert(FEC.begin() + i, event);
                    break;
                }
            }
            if(i == FEC.size()) {
                FEC.push_back(event);
            }
        }
        event = iteration->callBack();
        if(event != NULL) {
            int i = 0;
            for(i = 0; i < FEC.size(); i++) {
                if(FEC[i]->getTime() > event->getTime()) {
                    FEC.insert(FEC.begin() + i, event);
                    break;
                }
            }
            if(i == FEC.size()) {
                FEC.push_back(event);
            }
        }
    }
    double AvgC = B.getSquare()/Time;
    cout << "Total: " << NUMOFTRANS << "; Time: " << Time << endl;
    cout << "Generator: " << gen << endl;
    cout << "A: " << A << endl;
    cout << "AB1: " << AB1 << endl;
    cout << "AB2: " << AB2 << endl;
    cout << "B: " << B << "; AVG.C: " << AvgC << "; MAX: " << B.getMAX() << endl;
    cout << "BC1: " << BC1 << endl;
    cout << "BC2: " << BC2 << endl;
}