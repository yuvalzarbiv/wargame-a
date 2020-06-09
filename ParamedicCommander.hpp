using namespace std;
#include "Paramedic.hpp"


class ParamedicCommander: public Paramedic
{
private:


public:
    ParamedicCommander(int player):Paramedic(player)
    {
        this->health = 120;
        this->affect_per_activity = __INT_MAX__;
        this->full_health = 120;
    }
    ~ParamedicCommander();

    void attack(vector<vector<Soldier*>> &board, pair<int,int> dest){}
    





};

