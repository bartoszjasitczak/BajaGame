//
// Created by student on 04.06.2020.
//

#include "Pillar/BluePillar.h"
#include "Play.h"
#include "Battlefield.h"
#include "Unit/Unit.h"

BluePillar::BluePillar(int position) : Pillar(position) {
    ability="Blue";

}

BluePillar::~BluePillar() {

}

void BluePillar::defend(Play* play) {

    for(int i=0; i<5; i++)
    {
        UnitPtr friendlyunit=play->getEnemyPlayer()->getPlayerBoard()->getCard(i);
        if(friendlyunit!= nullptr) friendlyunit->setHealth(friendlyunit->getHealth()+1);
    }
}

BluePillar::BluePillar(int position, int health) : Pillar(position, health) {
    ability="Blue";

}