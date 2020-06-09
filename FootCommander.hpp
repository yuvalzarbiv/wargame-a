using namespace std;
#include "FootSoldier.hpp"


class FootCommander: public FootSoldier
{
private:


public:
    FootCommander(int player):FootSoldier(player)
    {
        this->health = 150;
        this->affect_per_activity = 20;
        this->full_health =150;
    }
    ~FootCommander();

    void attack(vector<vector<Soldier*>> &board, pair<int,int> dest){}
    





};


