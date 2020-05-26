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
    }
    ~ParamedicCommander();

    void attack(Soldier& s){}
    void heal(){}





};

