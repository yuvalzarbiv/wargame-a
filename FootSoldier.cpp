//#pragma once
#include "FootSoldier.hpp"
#include <iostream>


using namespace std;

pair<int,int> FootSoldier::closest_enemy (vector<vector<Soldier*>> board,  pair<int,int> soldier_location) const
{
    int pID = board[soldier_location.first][soldier_location.second]->get_playerID();
    pair <int,int> enemy = {-1,-1};
    double mindist = sqrt(pow(soldier_location.first,2) + pow(soldier_location.second,2));
    double dist;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] != nullptr && board[i][j]->get_playerID() != pID)
            {
                dist = sqrt(pow(i - soldier_location.first,2) + pow(j - soldier_location.second,2));
                if(dist < mindist)
                {
                    mindist = dist;
                    enemy = {i,j};
                }
            }
        }
    }

    return enemy;
}



void FootSoldier::attack(vector<vector<Soldier*>> &board, pair<int,int> location)
{
    pair<int,int> enemy = closest_enemy(board,location);

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
   







