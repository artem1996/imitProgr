#include <random>
#include "iostream"
#include "Generator.h"
#define NUMOFTRANS 1000

using namespace std;

int main() {
    srand((unsigned int) time(NULL));
    const int nrolls=10000;  // number of experiments
    const int nstars=100;    // maximum number of stars to distribute
    const int nintervals=10; // number of intervals

    std::default_random_engine generator;
    std::exponential_distribution<double> distribution(2.5);

    int p[nintervals]={};

    for (int i=0; i<nrolls; ++i) {
        double number = distribution(generator);
        cout << number << endl;
        if (number<1.0) ++p[int(nintervals*number)];
    }

    std::cout << "exponential_distribution (3.5):" << std::endl;
    std::cout << std::fixed; std::cout.precision(1);

    for (int i=0; i<nintervals; ++i) {
        std::cout << float(i)/nintervals << "-" << float(i+1)/nintervals << ": ";
        std::cout << std::string(p[i]*nstars/nrolls,'*') << std::endl;
    }

    return 0;
//    std::random_device rd;
//    std::mt19937 gene(rd());
//
//    // if particles decay once per second on average,
//    // how much time, in seconds, until the next one?
//    std::exponential_distribution<> d(0.1);
//
//    for(int n=0; n<100; ++n) {
//        double print = (int) d(gene) % 10;
//        print += 5;
//        print += d(gene) / 100.0;
//        cerr << print << endl;
//    }

    double Time = 0;
    double tempTime;
    Generator gen(5, 15, NUMOFTRANS, false);
    Buffer A(20);
    ThresholdBuffer B(25, 20);
    Line AB1(false, new Randomizer(20)), AB2(true, new Randomizer(false, 15, 25));
    ThresholdLine BC1(false, new Randomizer(false, 22, 28), new Randomizer(15)), BC2(true, new Randomizer(false, 23, 30), new Randomizer(16));
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