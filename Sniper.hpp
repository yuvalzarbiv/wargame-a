#pragma once


using namespace std;
#include "Soldier.hpp"


class Sniper: public Soldier
{
private:


public:
    Sniper(int player):Soldier(player)
    {
        this->health = 100;
        this->affect_per_activity = 50;
    }
    ~Sniper();

    void attack(Soldier& s){}
    void heal(){}
};


