#pragma once
#include "Sniper.hpp"
#include <iostream>


using namespace std;

pair<int,int> Sniper::strongest_enemy (vector<vector<Soldier*>> board,  pair<int,int> soldier_location) const
{
    int pID = board[soldier_location.first][soldier_location.second]->get_playerID();
    pair <int,int> enemy = {-1,-1};
    double strongest = -1;
    double strong;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] != nullptr && board[i][j]->get_playerID() != pID)
            {
                strong = board[i][j]->get_health();
                if(strong > strongest)
                {
                    strongest = strong;
                    enemy = {i,j};
                   
                }
            }
        }
    }

    return enemy;
}



void Sniper::attack(vector<vector<Soldier*>> &board, pair<int,int> location)
{
        pair<int,int> enemy = strongest_enemy(board,location);

        if (enemy.first >= 0 && enemy.second >= 0)
        {
            int soldierdemage = board[location.first][location.second]->get_affect_per_activity();
            int enemyNewH = board[enemy.first][enemy.second]->get_health()-soldierdemage;
            if (enemyNewH <= 0)
            {
                board[enemy.first][enemy.second] = nullptr;
            }
            else board[enemy.first][enemy.second]->set_health(enemyNewH);
            
        }

}
   







