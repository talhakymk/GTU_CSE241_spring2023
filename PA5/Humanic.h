#ifndef HUMANIC_H
#define HUMANIC_H

#include "Robot.h"
#include <iostream>
using namespace std;

class Humanic : public Robot {
    public:
        int getDamage();
        Humanic();
        string getType()override = 0;
        Humanic(World * world , int x ,int y);
};

#endif
