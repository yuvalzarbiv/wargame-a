#pragma once

using namespace std;
#include "Soldier.hpp"


class Paramedic: public Soldier
{
private:


public:
    Paramedic(int player):Soldier(player)
    {
        this->health = 100;
        this->affect_per_activity = __INT_MAX__;
    }
    ~Paramedic();

    void attack(Soldier& s){}
    void heal(){}





};


