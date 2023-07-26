#ifndef ROBOCOP_H
#define ROBOCOP_H

#include "Humanic.h"
#include <iostream>
using namespace std;

class Robocop : public Humanic {
    public:
        Robocop(World * world , int x , int y);
        int getDamage();
        Robocop();
        string getType()override;
        void setCount(int count);
        void coutName();
        int getCount();
    private:
        int count;
};

#endif
