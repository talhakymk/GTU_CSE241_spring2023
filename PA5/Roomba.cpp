#include "Roomba.h"
#include <iostream>

using namespace std;

int Roomba::getDamage() {
    int damage = Robot::getDamage();
    damage += damage;
    //cout << " roomba attacks for totally " << damage << " points" << endl;
    return damage;
}

Roomba::Roomba() {
    Robot::setStrength(3);
    Robot::setHitpoint(10);
}

string Roomba::getType() {
    return "roomba";
}

Roomba::Roomba(World* world , int x , int y) : Robot(world,x,y) {
    Robot::setStrength(3);
    Robot::setHitpoint(10);
}

void Roomba::setCount(int count) {
    this->count = count;
}

int Roomba::getCount() {
    return  this->count;
}

void Roomba::coutName() {
    cout << this->getName() << this->getCount() << endl;
}
