//
// Created by student on 04.06.2020.
//

#ifndef GAMEBAJA_ARCHER_H
#define GAMEBAJA_ARCHER_H


#include "Unit.h"

class Archer : public Unit{
public:
    Archer( int position);
    Archer (int health, int attack_power, int position, bool on_board);

    virtual ~Archer();

    virtual void attack(Play*) override ;

};


#endif //GAMEBAJA_ARCHER_H