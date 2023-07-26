#ifndef ROOMBA_H
#define ROOMBA_H

#include "Robot.h"
#include <iostream>
using namespace std;

class Roomba : public Robot {
    public:
        Roomba(World * world , int x , int y);
        int getDamage();
        Roomba();
        string getType()override;
        void setCount(int count);
        int getCount();
        void coutName();
    private:
        int count;
};

#endif
