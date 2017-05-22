//
// Created by note on 22.05.17.
//

#ifndef UNTITLED_TRANSFER_H
#define UNTITLED_TRANSFER_H


class Transfer {
private:
    double probability;
    double temp = 0;
public:
    Transfer(double probability);
    bool tick();
};


#endif //UNTITLED_TRANSFER_H
