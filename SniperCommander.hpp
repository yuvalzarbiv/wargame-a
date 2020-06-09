using namespace std;
#include "Sniper.hpp"


class SniperCommander: public Sniper
{
private:


public:
    SniperCommander(int player):Sniper(player)
    {
        this->health = 120;
        this->affect_per_activity = 100;
        this->full_health = 120;
    }
    ~SniperCommander();

    void attack(vector<vector<Soldier*>> &board, pair<int,int> dest){}
   





};


