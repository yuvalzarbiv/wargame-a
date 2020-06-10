#include "FootCommander.hpp"
#include <iostream>

 void FootCommander::attack(vector<vector<Soldier *>> &board, pair<int, int> location)
    {   
        int pID = board[location.first][location.second]->get_playerID();
        FootSoldier::attack(board, location);

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != nullptr && board[i][j]->get_playerID() == pID)
                {
                    if (dynamic_cast<FootSoldier*>(board[i][j]) && !dynamic_cast<FootCommander*>(board[i][j])) 
                    {
                        board[i][j]->attack(board, {i,j});
                    }
                }
            }
        }
    }