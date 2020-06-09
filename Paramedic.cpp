#pragma once
#include "Paramedic.hpp"
#include <iostream>


using namespace std;


void Paramedic::attack(vector<vector<Soldier*>> &board, pair<int,int> location)
{
    int pID = board[location.first][location.second]->get_playerID();
    int r = location.first;
    int c = location.second;

    for (int i = r-1; i < r+1 ; i++)
    {
        for (int j = c-1; j < c+1; j++)
        {
            if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size())
            {
                if (board[i][j] != nullptr && board[i][j]->get_playerID() == pID)
                {
                    if (i != r && j != c)
                    {
                        board[i][j]->set_health(board[i][j]->cure());
                    }
                }
            }
        }
    }

}
   