//
// Created by student on 04.06.2020.
//

#ifndef GAMEBAJA_THIEF_H
#define GAMEBAJA_THIEF_H


#include "Unit.h"
#include "RandomCard.h"

class Thief : public Unit, RandomCard{
public:
    Thief( int position);
    Thief (int health, int attack_power, int position, bool on_board);

    virtual ~Thief();

    virtual void attack(Play*) override ;

};


#endif //GAMEBAJA_THIEF_H