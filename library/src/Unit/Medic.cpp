//
// Created by student on 04.06.2020.
//

#include "Unit/Medic.h"

Medic::Medic( int position) : Unit(position) {
    health=7;
    attack_power=5;
    ability="Medic";
}



void Medic::attack(Play* play) {
    Unit::attack(play);
    for(int i=0; i<5; i++)
    {
        UnitPtr friendlyunit= play->getPlayer()->getPlayerBoard()->getCard(i);
        if(friendlyunit!= nullptr) friendlyunit->setHealth(friendlyunit->getHealth()+1);
    }
}

Medic::~Medic() {
}

Medic::Medic(int health, int attack_power, int position, bool on_board) : Unit(health, attack_power, position,
                                                                               on_board) {
    ability="Medic";

}