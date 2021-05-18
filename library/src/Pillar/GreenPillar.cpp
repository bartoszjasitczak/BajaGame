//
// Created by student on 04.06.2020.
//

#include "Pillar/GreenPillar.h"
#include "Play.h"
#include "Battlefield.h"
#include "Unit/Unit.h"

GreenPillar::GreenPillar(int position) : Pillar(position) {
    ability="Green";
}

GreenPillar::~GreenPillar() {

}

void GreenPillar::defend(Play* play) {
    for(unsigned int i = 0; i<5; i++)
    {
        UnitPtr enemy=play->getPlayer()->getPlayerBoard()->getCard(i);
        if(enemy!= nullptr) {
            enemy->setHealth(enemy->getHealth() - 1);
            if(enemy->getHealth()<=0) play->getPlayer()->getPlayerBoard()->deleteCard(enemy->getPosition());
        }
    }

}

GreenPillar::GreenPillar(int position, int health) : Pillar(position, health) {
    ability="Green";

}

