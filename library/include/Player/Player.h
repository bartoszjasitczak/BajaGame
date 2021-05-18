//
// Created by student on 04.06.2020.
//

#ifndef TRUNK_PLAYER_H
#define TRUNK_PLAYER_H

#include <string>
#include <memory>
#include <exception>
#include "typedefs.h"


class PlayerException : public std::logic_error
{
public:
    explicit PlayerException(const std::string& what_arg) : std::logic_error(what_arg) {}
};


class Player {
private:
    Hand* player_hand;
    Battlefield* player_board;
    PillarsArray* player_pillars;
    std::string nickname;
    int player_actions;
public:
    void setPlayerPlay(Play *playerPlay);

private:
    Play* player_play;
protected:
    bool human;
public:
    bool isHuman() const;

public:
    Hand *getPlayerHand() const;

    Battlefield *getPlayerBoard() const;

    PillarsArray *getPlayerPillars() const;

    const std::string &getNickname() const;

    Play *getPlayerPlay() const;

    int getPlayerActions() const;

    void setPlayerActions(unsigned int playerActions);

    std::string getPlayerInfo();

    virtual ~Player();

    Player( const std::string &nickname, Play *playerPlay);

    Player(bool human, std::string &nickname, int player_actions, Hand* player_hand, Battlefield* player_board, PillarsArray* player_pillars);

    virtual void decision()=0;

};


#endif //TRUNK_PLAYER_H