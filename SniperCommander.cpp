#include "SniperCommander.hpp"

void SniperCommander::attack(vector<vector<Soldier *>> &board, pair<int, int> location)
{
    int pID = board[location.first][location.second]->get_playerID();
    Sniper::attack(board, location);

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] != nullptr && board[i][j]->get_playerID() == pID)
            {
                if (dynamic_cast<Sniper*>(board[i][j]) != nullptr && dynamic_cast<SniperCommander*>(board[i][j]) == nullptr) 
                {
                    board[i][j]->attack(board, {i,j});
                }
            }
        }
    }
}
