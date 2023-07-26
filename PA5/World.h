#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include "Robot.h"
/*#include "Optimusprime.h"
#include "Roomba.h"
#include "Robocop.h"
#include "Bulldozer.h"*/

const int initial_count_of_each_robot_type = 5;
class Robot;
/*class Bulldozer;
class Roomba;
class Robocop;
class Optimusprime;*/
class World {
    public:
        World();
        //~World();
        Robot* getAt(int x , int y);
        void setAt(int x , int y , Robot * rbt);
        void Display();
        void SimulateOneStep();
        Robot* grid[10][10];
};

#endif
