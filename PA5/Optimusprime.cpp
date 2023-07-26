#include "Optimusprime.h"
#include <iostream>
using namespace std;

int Optimusprime::getDamage() {
    int damage = Humanic::getDamage();
    int persantage = (rand() % 100) + 1;
    if(persantage > 0 && persantage < 16) {
        //cout << "+" << damage;
        damage += damage;
    }
        //cout << " optimusprime attacks for totally " << damage << " points" << endl;
    return damage;
}

Optimusprime::Optimusprime() {
    Humanic::setStrength(100);
    Humanic::setHitpoint(100);
}

string Optimusprime::getType() {
    return "optimusprime";
}

void Optimusprime::setCount(int count) {
    this->count = count;
}

int Optimusprime::getCount() {
    return this->count;
}

void Optimusprime::coutName() {
    cout << this->getName() << this->getCount() << endl;
}

Optimusprime::Optimusprime(World* world , int x , int y) : Humanic(world,x,y) {
    Humanic::setStrength(100);
    Humanic::setHitpoint(100);
}
