#pragma once


using namespace std;


class Soldier
{
    protected:

    int health;
    int affect_per_activity;
    int playerID;

    public:

    Soldier(): health(0), affect_per_activity(0){}
    Soldier(int P):playerID(P){}

    //////////////// METHODS /////////////////////////

    virtual void attack(Soldier& s){}
    virtual void heal(){}

    /////////////////////////////////////////////////

    int get_playerID() const { return playerID;}
    int get_affect_per_activity() const { return affect_per_activity;}
    int get_health() const { return health;}
  
};






