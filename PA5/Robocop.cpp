#include "Robocop.h"
#include <iostream>
using namespace std;

int Robocop::getDamage() {
    int damage = Humanic::getDamage();
    //cout << " robocop attacks for totally " << damage << " points" << endl;
    return damage;
}

Robocop::Robocop() {
    Humanic::setStrength(30);
    Humanic::setHitpoint(40);
}

string Robocop::getType() {
    return "robocop";
}

Robocop::Robocop(World* world , int x , int y) : Humanic(world,x,y) {
    Humanic::setStrength(30);
    Humanic::setHitpoint(40);
}

void Robocop::setCount(int count) {
    this->count = count;
}

int Robocop::getCount() {
    return this->count;
}

void Robocop::coutName() {
    cout << this->getName() << this->getCount() << endl;
}
