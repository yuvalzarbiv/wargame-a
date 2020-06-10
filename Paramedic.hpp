#pragma once

//using namespace std;
#include "Soldier.hpp"


class Paramedic: public Soldier
{


    public:
    Paramedic(int player):Soldier(player)
    {
        this->health = 100;
        this->affect_per_activity = __INT_MAX__;
        this->full_health = 100;
    }
    ~Paramedic();

    void attack(vector<vector<Soldier*>> &board, pair<int,int> dest);
        


};


