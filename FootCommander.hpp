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
    }
    ~FootCommander();

    void attack(Soldier& s){}
    void heal(){}





};


