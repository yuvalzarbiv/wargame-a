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
    }
    ~SniperCommander();

    void attack(Soldier& s){}
    void heal(){}





};


