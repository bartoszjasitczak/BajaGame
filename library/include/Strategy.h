//
// Created by student on 13.06.2020.
//

#ifndef GAMEBAJA_STRATEGY_H
#define GAMEBAJA_STRATEGY_H
#include "Player/HumanPlayer.h"
#include "typedefs.h"
#include "RandomCard.h"

class Strategy: public RandomCard
{
public:

     Action decision(HumanPlayerPtr);
     void move_onboard(Battlefield*);
     void put_card(Hand*, Battlefield*);
     void draw_card(Hand*);
     void trade_cards(Hand*);
     void attack(Battlefield*, Play*);
     void save(Play*);

};


#endif //GAMEBAJA_STRATEGY_H