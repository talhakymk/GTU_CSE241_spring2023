#include "Bulldozer.h"
#include "World.h"
#include <iostream>

using namespace std;

int Bulldozer::getDamage() {
    int damage = Robot::getDamage();
    //cout << " bulldozer attacks for totally " << damage << " points" << endl;
    return damage;
}

Bulldozer::Bulldozer() {
    Robot::setStrength(50);
    Robot::setHitpoint(200);
}

void Bulldozer::setCount(int count) {
    this->count = count;
}

int Bulldozer::getCount() {
    return this->count;
}

Bulldozer::Bulldozer(World* world , int x , int y) : Robot(world,x,y) {
    Robot::setStrength(50);
    Robot::setHitpoint(200);
}

string Bulldozer::getType() {
    return "bulldozer";
}

void Bulldozer::coutName() {
    cout << this->getName() << this->count << endl;
}
