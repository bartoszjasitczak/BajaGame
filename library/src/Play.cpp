//
// Created by student on 04.06.2020.
//

#include "../include/Play.h"
#include "Player/Player.h"
#include "Player/HumanPlayer.h"
#include "Player/ComputerPlayer.h"
#include "Battlefield.h"
#include <sstream>
#include <iostream>
#include <ctime>


Play::Play(unsigned int how_many_human_players,std::string nickname1,std::string nickname2) : how_many_human_players(how_many_human_players) {

    srand( time( NULL ) );
    if(how_many_human_players>2)
    {
        throw PlayException("Too many human players");
    }
    if (how_many_human_players == 2) {
        player1 = std::make_shared<HumanPlayer>(nickname1, this);
        player2 = std::make_shared<HumanPlayer>( nickname2, this);
    }
    if (how_many_human_players == 1) {
        player1 = std::make_shared<HumanPlayer>( nickname1, this);
        player2 = std::make_shared<ComputerPlayer>( nickname2, this);
    }
    if (how_many_human_players == 0) {
        player1 = std::make_shared<ComputerPlayer>( nickname1, this);
        player2 = std::make_shared<ComputerPlayer>( nickname2, this);
    }
    whose_turn=true;
    check_win=false;
}

Play::~Play() {
}

bool Play::isTurnPlayer1() const {
    return whose_turn;
}

void Play::setWhoseTurn() {
    whose_turn = !whose_turn;
}

PlayerPtr Play::getPlayer() const {
    if (isTurnPlayer1()) return player1;
    return player2;
}

PlayerPtr Play::getEnemyPlayer() const {
    if (isTurnPlayer1()) return player2;
    return player1;
}

std::string Play::getPlayInfo() {
    std::ostringstream sout;
    sout << player1->getPlayerInfo();
    sout << player2->getPlayerInfo();
    return sout.str();
}

void Play::play() {
    while(!check_win)
    {
        getPlayer()->decision();
        setWhoseTurn();
        check_win=true;
        for(int i=0; i<5; i++)
        {
            if (getPlayer()->getPlayerPillars()->getPillar(i)!=nullptr) check_win=false;
        }
    }
    setWhoseTurn();
    std::cout<<"\n\nThe winner is: "<<getPlayer()->getNickname();
    delete this;

}

int Play::getHowManyHumanPlayers() const {
    return how_many_human_players;
}

Play::Play(PlayerPtr player1, PlayerPtr player2, bool whose_turn) : player1(player1), player2(player2), whose_turn(whose_turn){
    player1->setPlayerPlay(this);
    player2->setPlayerPlay(this);
}



