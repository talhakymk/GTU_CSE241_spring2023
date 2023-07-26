#ifndef BULLDOZER_H
#define BULLDOZER_H

#include "Robot.h"
#include <iostream>
using namespace std;

class Bulldozer : public Robot {
    public:
        Bulldozer();
        Bulldozer(World * world , int x , int y);
        int getDamage();
        string getType()override;
        void setCount(int count);
        int getCount();
        void coutName();
    private:
        int count;
};

#endif
