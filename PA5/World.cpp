#include <iostream>
#include "World.h"

using namespace std;

void World::Display() {
    int i,j;
    cout<<endl<<endl;
    for(j=0;j<10;j++) {

        for(i=0;i<10;i++)
        {
            if(grid[i][j]==NULL)
                cout<<".";
            else if(grid[i][j]->getType().compare("optimusprime") == 0)
                cout<<"1";
            else if(grid[i][j]->getType().compare("robocop") == 0)
                cout<<"2";
            else if(grid[i][j]->getType().compare("roomba") == 0)
                cout<<"3";
            else if(grid[i][j]->getType().compare("bulldozer") == 0)
                cout<<"4";
        }
        cout<<endl;
    }
}


void World::SimulateOneStep(){
    int i,j;

    for(i=0;i<10;i++)
        for(j=0;j<10;j++){
            if(grid[i][j]!=NULL) grid[i][j]->moved=false;
        }

    for(i=0;i<10;i++)
        for(j=0;j<10;j++){
            if((grid[i][j]!=NULL)){
                
                if(grid[i][j]->moved==false){
                    grid[i][j]->moved=true;
                    Robot* rbt = grid[i][j]->move();
                    if(rbt != NULL){
                        while(true){
                            int damageOfAttacker = grid[i][j]->getDamage();
                            int health2 = rbt->getHitpoint();
                            cout << grid[i][j]->getName() << grid[i][j]->code << "(" << grid[i][j]->getHitpoint() << ") hits with " << damageOfAttacker
                             << " to "   << rbt->getName() << rbt->code << " (" <<rbt->getHitpoint() << ")" << endl;
                            rbt->setHitpoint(health2 - damageOfAttacker);
                            if(rbt->getHitpoint() <= 0){
                                cout << rbt->getName() << rbt->code << "DIED\n";
                                //delete rbt;
                                int oldX = grid[i][j]->x;
                                int oldY = grid[i][j]->y;
                                setAt(rbt->x , rbt->y , grid[i][j]);
                                setAt(oldX ,oldY , NULL );
                                //grid[i][j]->moved=true;
                                
                                return;
                            }
                            cout << " the new hitpoints of " << rbt->getName() << rbt->code << " is " <<rbt->getHitpoint() << endl;
                            int damageOfAttacker2 = rbt->getDamage();
                            int health1 = grid[i][j]->getHitpoint();
                            cout << rbt->getName() << rbt->code << "(" << rbt->getHitpoint() << ") hits with " << damageOfAttacker2
                              << " to "  << grid[i][j]->getName() << grid[i][j]->code << " (" << grid[i][j]->getHitpoint() << ")";
                            grid[i][j]->setHitpoint(health1 - damageOfAttacker2);
                            if(grid[i][j]->getHitpoint() <= 0){
                                cout << grid[i][j]->getName() << grid[i][j]->code << "DIED\n";
                                //delete grid[i][j];
                                int oldX = rbt->x;
                                int oldY = rbt->y;
                                setAt(grid[i][j]->x , grid[i][j]->y ,rbt);
                                setAt(oldX , oldY , NULL);
                                //rbt->moved=true;
                    
                                return;
                            }
                            cout << " the new hitpoints of " << grid[i][j]->getName() << grid[i][j]->code << " is " <<grid[i][j]->getHitpoint() << endl;
                        }
                    }           
                }
            }
        }
                
}

Robot * World::getAt(int x , int y){
    if((x >= 0)&&(x < 10)&&(y >= 0)&&(y < 10)){
        return grid[x][y];
    }
    return NULL;
}

void World::setAt(int x , int y , Robot *rbt){
    if((x >= 0)&&(x < 10)&&(y >= 0)&&(y < 10)){
        grid[x][y] = rbt;
    }
}

World::World(){
    int i,j;
    for(i = 0 ; i < 10 ; i++){
        for(j = 0 ; j < 10 ; j++){
            grid[i][j]=NULL;
            //grid[i][j]->moved = false;
        }
    }

    
}

/*World::~World(){
    int i,j;
    for(i = 0 ; i < 10 ; i++){
        for(j = 0 ; j < 10 ; j++){
            if(grid[i][j]!=NULL)
            delete (grid[i][j]);
        }
    }
}*/
