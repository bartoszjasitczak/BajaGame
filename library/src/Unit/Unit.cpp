//
// Created by student on 04.06.2020.
//

#include "../../include/Unit/Unit.h"
#include <sstream>

Unit::Unit( int position) :position(position){
    if(position>4)
    {
        throw UnitException("This position doesn't exist");
    }
    on_board=false;
}

Unit::~Unit() {
}

int Unit::getHealth() const {
    return health;
}

void Unit::setHealth(int health) {
    Unit::health = health;
}

int Unit::getPosition() const {
    return position;
}

void Unit::setPosition(unsigned int position) {
    if(position>4) {
        throw UnitException("This position doesn't exist");
    }
    Unit::position = position;
}

bool Unit::isOnBoard() const {
    return on_board;
}

void Unit::setOnBoard() {
    on_board = !on_board;
}

int Unit::getAttackPower() const {
    return attack_power;
}

const std::string &Unit::getAbility() const {
    return ability;
}

void Unit::attack(Play* play) {
    UnitPtr enemy=play->getEnemyPlayer()->getPlayerBoard()->getCard(getPosition());
    if(enemy!=nullptr)
    {
        int newHealth= enemy->getHealth()-getAttackPower();
        enemy->setHealth(newHealth);
        if(enemy->getHealth()<=0) play->getEnemyPlayer()->getPlayerBoard()->deleteCard(enemy->getPosition());
    } else{
        PillarPtr enemypillar=play->getEnemyPlayer()->getPlayerPillars()->getPillar(getPosition());
        if(enemypillar!=nullptr)
        {
            int newHealth= enemypillar->getHealth()-getAttackPower();
            enemypillar->setHealth(newHealth);
            enemypillar->defend(play);
            if(enemypillar->getHealth()<=0) play->getEnemyPlayer()->getPlayerPillars()->deletePillar(enemypillar->getPosition());
        }
    }


}

std::string Unit::get_unit_info() {
    std::ostringstream sout;
    sout<<"Position: "<<getPosition()+1<<" ";
    sout<<"HP: "<<getHealth()<<" ";
    sout<<"Attack: "<<getAttackPower()<<" ";
    sout<<"Ability: "<<getAbility()<<" ";
    sout<<std::endl;
    return sout.str();
}

Unit::Unit(int health, int attack_power, int position, bool on_board) : health(health), attack_power(attack_power), position(position), on_board(on_board){

}
