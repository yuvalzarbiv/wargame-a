//#pragma once


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
        this->full_health = 100;
    }
    ~Sniper();

    void attack(vector<vector<Soldier*>> &board, pair<int,int> dest){}
    pair<int,int> strongest_enemy (vector<vector<Soldier*>> board,  pair<int,int> soldier_location) const{}
    
};


