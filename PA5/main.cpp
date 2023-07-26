#include "Optimusprime.h"
#include "Robocop.h"
#include "Roomba.h"
#include "Bulldozer.h"
#include "World.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(0));
    string s;
    World w;
    Robocop *temp_robo = new Robocop[5]; 
    Bulldozer *temp_bull = new Bulldozer[5];
    Optimusprime *temp_opt = new Optimusprime[5];
    Roomba *temp_roo = new Roomba[5];
    int bulldozer_count = 0 , optimusprime_count = 0 , robocop_count = 0 , roomba_count = 0;
    while(bulldozer_count < 5) {
        int x = rand() % 10; // we create random place to spawn
        int y = rand() % 10; // we create random place to spawn

        if (w.getAt(x,y)==NULL)
        {
            Bulldozer *bull = new Bulldozer(&w,x,y); // we create that type robot and include it into world
            bull->setName("bulldozer_");
            bull->setCount(bulldozer_count);
            bull->code = bulldozer_count;
            temp_bull[bulldozer_count] = *bull;
            bulldozer_count++;
        }
    }

    while(optimusprime_count < 5) {
        int x = rand() % 10; // we create random place to spawn
        int y = rand() % 10; // we create random place to spawn

        if (w.getAt(x,y)==NULL)
        {
            Optimusprime *optimus = new Optimusprime(&w,x,y);
            optimus->setName("optimusprime_"); // we create that type robot and include it into world
            optimus->setCount(optimusprime_count);
            optimus->code = optimusprime_count;
            temp_opt[optimusprime_count] = *optimus;
            optimusprime_count++;
            
        }
    }

    while(robocop_count < 5) {
        int x = rand() % 10; // we create random place to spawn
        int y = rand() % 10; // we create random place to spawn

        if (w.getAt(x,y)==NULL)
        {
            Robocop *roboco = new Robocop(&w,x,y); // we create that type robot and include it into world
            roboco->setName("robocop_");
            roboco->setCount(robocop_count);
            roboco->code = robocop_count;
            temp_robo[robocop_count] = *roboco;
            robocop_count++;
        }
    }

    while(roomba_count < 5) {
        int x = rand() % 10; // we create random place to spawn
        int y = rand() % 10; // we create random place to spawn

        if (w.getAt(x,y)==NULL)
        {
            Roomba *room = new Roomba(&w,x,y); // we create that type robot and include it into world
            room->setName("roomba_");
            room->setCount(roomba_count);
            room->code = roomba_count;
            temp_roo[roomba_count] = *room;
            roomba_count++;
        }
    }

    while(true)
    {
        //w.Display();
        w.SimulateOneStep();
        cout<<endl<<"Press enter for next step"<<endl;
        getline(cin,s);
    }
    return 0;
}
