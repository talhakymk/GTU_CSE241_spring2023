#include "Humanic.h"
#include <iostream>
using namespace std;

int Humanic::getDamage() {
    int damage = Robot::getDamage();
    int persantage = (rand() % 100) + 1;
    if(persantage > 0 && persantage < 11) {
        damage += 50;
       // cout << "+50";
    }
    return damage;
}

Humanic::Humanic(World * world , int x , int y) : Robot(world,x,y) { }

Humanic::Humanic() {}
