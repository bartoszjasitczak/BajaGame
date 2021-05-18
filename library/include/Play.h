//
// Created by student on 04.06.2020.
//

#ifndef GAMEBAJA_PLAY_H
#define GAMEBAJA_PLAY_H

#include <string>
#include "Player/Player.h"
#include <exception>

class PlayException : public std::logic_error {
public:
    explicit PlayException(const std::string &what_arg) : std::logic_error(what_arg) {}
};

class Play {

private:
    PlayerPtr player1;
    PlayerPtr player2;
    bool whose_turn;
    bool check_win;
    int how_many_human_players;
public:
    int getHowManyHumanPlayers() const;

public:
    virtual ~Play();

    std::string getPlayInfo();

    bool isTurnPlayer1() const;

    void setWhoseTurn();

    PlayerPtr getPlayer() const;
    PlayerPtr getEnemyPlayer() const;

    void play();

    Play(unsigned int how_many_human_players,std::string nickname1,std::string nickname2);
    Play(PlayerPtr, PlayerPtr, bool);



};


#endif //GAMEBAJA_PLAY_H