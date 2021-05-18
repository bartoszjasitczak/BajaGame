//
// Created by student on 04.06.2020.
//

#include "Pillar/RedPillar.h"
#include "Play.h"
#include "Battlefield.h"
#include "Unit/Unit.h"

RedPillar::RedPillar(int position) : Pillar(position) {
    ability="Red";
}

RedPillar::~RedPillar() {

}

void RedPillar::defend(Play* play) {
    int position=getPosition();
    UnitPtr enemy=play->getPlayer()->getPlayerBoard()->getCard(position);
    enemy->setHealth(enemy->getHealth()-enemy->getAttackPower());
    if(enemy->getHealth()<=0) play->getPlayer()->getPlayerBoard()->deleteCard(enemy->getPosition());

}

RedPillar::RedPillar(int position, int health) : Pillar(position, health) {
    ability="Red";

}
