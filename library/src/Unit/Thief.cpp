//
// Created by student on 04.06.2020.
//

#include "../../include/Unit/Thief.h"



Thief::Thief( int position) : Unit(position) {
    health=6;
    attack_power=4;
    ability="Thief";
}

Thief::~Thief() {
}

void Thief::attack(Play* play) {
    Unit::attack(play);
    for(int i=0; i<5; i++)
    {
        if(play->getPlayer()->getPlayerHand()->getCard(i)==nullptr)
        {
            UnitPtr newCard= RandomCard::random_card(i);
            play->getPlayer()->getPlayerHand()->setCard(i, newCard);
            return;
        }
    }
}

Thief::Thief(int health, int attack_power, int position, bool on_board) : Unit(health, attack_power, position,
                                                                               on_board) {
    ability="Thief";

}