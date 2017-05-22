#include <random>
#include "iostream"
#include "Generator.h"

double Time = 0;

using namespace std;

Transfer* Queue::transfer;
Barber** Queue::barbers;
int Queue::countBarbers;
int Queue::inPut;
int Queue::outFirst;
int Queue::outSecond;
int Queue::aboveFirst;
int Queue::aboveSecond;

int main() {
    srand((unsigned int) time(NULL));
    Generator gen(15, 35, false, false), addGen(25, 65, false, true);
    Queue::setTransfer(new Transfer(0.4));
    Barber **barbers = new Barber*[3];
    barbers[0] = new Barber(new Randomizer(30), new Randomizer(55), 210, 30);
    barbers[1] = new Barber(new Randomizer(30), new Randomizer(55), 240, 30);
    barbers[2] = new Barber(new Randomizer(30), new Randomizer(55), 270, 30);
    Queue::setBurbers(barbers, 3);
    std::vector<Advance*> FEC;
    FEC.push_back(&gen);
    FEC.push_back(&addGen);
    while (FEC.size()) {
        Advance* iteration = FEC[0];
        FEC.erase(FEC.begin());
        for(int i = 0; i < FEC.size(); i++) {
            FEC[i]->decrTime(iteration->getTime());
        }
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
        event = iteration->callback();
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
    }
    cout << "Time: " << Time << endl;
    cout << "Easy Generator: " << gen << endl;
    cout << "Difficult Generator: " << addGen << endl;
    Queue::print();
    cout << "Barber0: " << *barbers[0] << endl;
    cout << "Barber1: " << *barbers[1] << endl;
    cout << "Barber2: " << *barbers[2] << endl;
}