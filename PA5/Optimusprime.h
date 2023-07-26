#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H

#include "Humanic.h"
#include <iostream>
using namespace std;

class Optimusprime : public Humanic {
    public:
        Optimusprime(World * world , int x , int y);
        int getDamage();
        Optimusprime();
        string getType()override;
        void setCount(int count);
        void coutName();
        int getCount();
    private:
        int count;
};

#endif
