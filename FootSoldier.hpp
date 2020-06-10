//#pragma once


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
        this->full_health = 100;
    }
    ~FootSoldier();

    void attack(vector<vector<Soldier*>> &board, pair<int,int> location){}

    pair<int,int> closest_enemy (vector<vector<Soldier*>> board,  pair<int,int> soldier_location) const{}





};


