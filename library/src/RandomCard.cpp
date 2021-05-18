//
// Created by student on 14.06.2020.
//

#include "RandomCard.h"
#include <Unit/Archer.h>
#include <Unit/Medic.h>
#include <Unit/Thief.h>
#include <Unit/Warrior.h>
#include "typedefs.h"

boost::random::mt19937 gen;
boost::random::uniform_int_distribution<> rng(1,4);

UnitPtr RandomCard::random_card(int position) {

    int x=rng(gen);
    UnitPtr newCard;
    if(x==1) newCard=std::make_shared<Archer>(position);
    else if (x==2) newCard=std::make_shared<Medic>(position);
    else if(x==3) newCard=std::make_shared<Thief>(position);
    else newCard=std::make_shared<Warrior>(position);
    return newCard;
}