#pragma once
#include <vector>
#include <math.h>

using namespace std;

class Soldier
{
    protected:

    int health;
    int affect_per_activity;
    int playerID;
    int full_health;

    public:

    Soldier(): health(0), affect_per_activity(0){}
    Soldier(int P):playerID(P){}

    //////////////// METHODS /////////////////////////

    virtual void attack(vector<vector<Soldier*>> &board, pair<int,int> location){}
    //virtual void heal(){}

    /////////////////////////////////////////////////

    int get_playerID() const { return playerID;}
    int get_affect_per_activity() const { return affect_per_activity;}
    int get_health() const { return health;}
    int cure() const { return full_health;}
    void set_health(int life){this->health = life;}
  
};






