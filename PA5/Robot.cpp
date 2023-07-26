#include "Robot.h"
#include <iostream>
using namespace std;

Robot::Robot() { }

Robot::Robot(int newStrength, int newHit, string name) {
    this->Name = name;
    this->Hitpoints = newHit;
    this->Strength = newStrength;
    moved = false;
}

int Robot::getDamage() {
    int damage;
    damage = (rand() % Strength) + 1;
    //cout << damage;
    return damage;
}

Robot::Robot(World *wrld, int x, int y) {
    this->world=wrld;
    moved = false;
    this->x=x;
    this->y=y;
    wrld->setAt(x,y,this);
}

int Robot::getStrength() { return Strength; }
string Robot::getName() { return Name; }
int Robot::getHitpoint() { return Hitpoints; }
void Robot::setHitpoint(int hit) { this->Hitpoints = hit; }
void Robot::setName(string name) { this->Name = name; }
void Robot::setStrength(int strength) { this->Strength = strength; }

Robot* Robot::move() {
    int dir = rand() %4; // we create random number from 0 to 3

    if (dir==0) // if number is 0 we move robot to up
    {
        if((y>0))
        {
            if(world->getAt(x,y-1)==NULL){
                world->setAt(x,y-1,world->getAt(x,y));
                world->setAt(x,y,NULL);
                y--;
                return NULL;
            }
            else{
                return world->getAt(x,y-1);
            }
            
        }
    }
    else if(dir==1) // if number is 1 we move robot to down
    {
        if((y<9))
        {
            if(world->getAt(x,y+1)==NULL){
                world->setAt(x,y+1,world->getAt(x,y));
                world->setAt(x,y,NULL);
                y++;
                return NULL;
            }
            else{
                return world->getAt(x,y+1);
            }
            
        }
    }
    else if(dir==2) // if number is 2 we move robot to left
    {
        if((x>0))
        {
            if(world->getAt(x-1,y)==NULL){
                world->setAt(x-1,y,world->getAt(x,y));
                world->setAt(x,y,NULL);
                x--;
                return NULL;
            }
            else{
                return world->getAt(x-1,y);
            }
    
        }
    }
    else  //  we move robot to right
    {
        if((x<9))
        {
            if((world->getAt(x-1,y)==NULL)){
                world->setAt(x+1,y,world->getAt(x,y));
                world->setAt(x,y,NULL);
                x++;
                return NULL;
            }
            else{
                return world->getAt(x+1,y);
            }
            
        }
    }
    return NULL;
}
