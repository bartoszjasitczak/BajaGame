//
// Created by student on 04.06.2020.
//

#include "../../include/Unit/Archer.h"
#include "Player/Player.h"

Archer::Archer( int position) : Unit(position) {
    health=6;
    attack_power=3;
    ability="Archer";
}

Archer::~Archer() {
}

void Archer::attack(Play* play) {
    PillarPtr enemypillar=play->getEnemyPlayer()->getPlayerPillars()->getPillar(getPosition());
    if(enemypillar!=nullptr)
    {
        int newHealth= enemypillar->getHealth()-getAttackPower();
        enemypillar->setHealth(newHealth);
        enemypillar->defend(play);
        if(enemypillar->getHealth()<=0) play->getEnemyPlayer()->getPlayerPillars()->deletePillar(enemypillar->getPosition());
    } else{
        UnitPtr enemy=play->getEnemyPlayer()->getPlayerBoard()->getCard(getPosition());
        if(enemy!=nullptr)
        {
            int newHealth= enemy->getHealth()-getAttackPower();
            enemy->setHealth(newHealth);
            if(enemy->getHealth()<=0) play->getEnemyPlayer()->getPlayerBoard()->deleteCard(enemy->getPosition());
        }
    }
}

Archer::Archer(int health, int attack_power, int position, bool on_board) : Unit(health, attack_power, position,
                                                                                 on_board) {
    ability="Archer";

}