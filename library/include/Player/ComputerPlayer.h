//
// Created by student on 04.06.2020.
//

#ifndef GAMEBAJA_COMPUTERPLAYER_H
#define GAMEBAJA_COMPUTERPLAYER_H

#include "RandomCard.h"
#include "Player.h"


class ComputerPlayer : public Player, RandomCard{


public:
    ComputerPlayer(const std::string &nickname, Play *playerPlay);
    ComputerPlayer(bool human, std::string &nickname, int player_actions, Hand* player_hand, Battlefield* player_board, PillarsArray* player_pillars);

    virtual ~ComputerPlayer();

   virtual void decision() override;

};


#endif //GAMEBAJA_COMPUTERPLAYER_H