#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include "World.h"

using namespace std;

class World;

class Robot {
    private:
        string Name;
        int Strength;
        int Hitpoints;
    public:
        int code;
        World *world;
        Robot();
        Robot(World *wrld , int x , int y);
        Robot(int newStrength, int newHit, string name);
        virtual string getType() = 0;
        int getDamage();
        int getStrength();
        string getName();
        int getHitpoint();
        void setHitpoint(int hit);
        void setStrength(int strength);
        void setName(string name);
        Robot* move();
        int x , y;
        bool moved ;
};

#endif
