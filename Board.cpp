#include "Board.hpp"
#include <iostream>

using namespace std;
using namespace WarGame;


// operator for putting soldiers on the game-board during initialization.
Soldier*& Board::operator[](std::pair<int,int> location)
{ 
    return board[location.first][location.second];

}

    
 // operator for reading which soldiers are on the game-board.
Soldier* Board::operator[](std::pair<int,int> location) const
 { 
     return board[location.first][location.second];

 }
    
    // The function "move" tries to move the soldier of player "player"
    //     from the "source" location to the "target" location,
    //     and activates the special ability of the soldier.
    // If the move is illegal, it throws "std::invalid_argument". 
    // Illegal moves include:
    //  * There is no soldier in the source location (i.e., the soldier pointer is null);
    //  * The soldier in the source location belongs to the other player.
    //  * There is already another soldier (of this or the other player) in the target location.
    // IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!
    // Your code should be generic. All handling of different types of soldiers 
    //      must be handled by polymorphism.
void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction)
 {
        int r = source.first;
        int c = source.second;
        if(r >= board.size() || r < 0 || c >= board[0].size() || c < 0) throw invalid_argument("ERROR:Out of the board");
        Soldier* player = board[r][c];
        if(player == nullptr || player->get_playerID() != player_number) throw("ERROR: illegal move"); 
        
        switch (direction)
        {
        case Up:
            r++;
            break;
        
        case Down:
            r--;
            break;

        case Left:
            c--;
            break;

        case Right:
            c++;
            break;  

        default:
            throw("Error");
            break;
        }
        
        if (r >= board.size() || r < 0 || c >= board[0].size() || c < 0) throw invalid_argument("ERROR:Out of the board");
        if(board[r][c] != nullptr)  throw invalid_argument("ERROR: another soldier stand here");
        board[source.first][source.second] = nullptr;
        board[r][c] = player;
        player->attack(board,{r,c});

 }

    // returns true iff the board contains one or more soldiers of the given player.
bool Board::has_soldiers(uint player_number) const
 {
     for (int i = 0; i < board.size(); i++)
     {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] != nullptr && board[i][j]-> get_playerID() == player_number) 
            {
                // cout << "on pair: " << i << "," << j << endl;
                // cout << "this is: " << board[i][j]->get_affect_per_activity() << endl;
                // cout << "his health: " << board[i][j]->get_health() << endl;
                return true;
            }
        }
     }
     return false;
 }


