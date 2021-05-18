//
// Created by student on 04.06.2020.
//

#ifndef GAMEBAJA_MEDIC_H
#define GAMEBAJA_MEDIC_H


#include "Unit.h"

class Medic : public Unit{
public:
    Medic( int position);
    Medic (int health, int attack_power, int position, bool on_board);

    virtual ~Medic();

    virtual void attack(Play*) override ;

};


#endif //GAMEBAJA_MEDIC_H