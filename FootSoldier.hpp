#pragma once


using namespace std;
#include "Soldier.hpp"


class FootSoldier: public Soldier
{
private:


public:
    FootSoldier(int player):Soldier(player)
    {
        this->health = 100;
        this->affect_per_activity = 10;
    }
    ~FootSoldier();

    void attack(Soldier& s){}
    void heal(){}





};


