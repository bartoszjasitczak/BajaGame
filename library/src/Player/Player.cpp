//
// Created by student on 04.06.2020.
//

#include "../../include/Player/Player.h"
#include "Hand.h"
#include "Battlefield.h"
#include "Pillar/PillarsArray.h"
#include <sstream>

Player::Player(const std::string &nickname, Play *playerPlay) : nickname(nickname), player_play(playerPlay) {

    if (playerPlay== nullptr) {
        throw PlayerException("Cannot create Player without play");
    }
    player_board = new Battlefield();
    player_hand = new Hand();
    player_pillars = new PillarsArray();
    player_actions=3;

}

Player::~Player() {
    delete player_board;
    delete player_hand;
    delete player_pillars;
}

int Player::getPlayerActions() const {
    return player_actions;
}

void Player::setPlayerActions(unsigned int playerActions) {
    if(playerActions>3)
    {
        throw PlayerException("Too many actions");
    }
    player_actions = playerActions;
}

Hand *Player::getPlayerHand() const {
    return player_hand;
}

Battlefield *Player::getPlayerBoard() const {
    return player_board;
}

PillarsArray *Player::getPlayerPillars() const {
    return player_pillars;
}

const std::string &Player::getNickname() const {
    return nickname;
}

Play *Player::getPlayerPlay() const {
    return player_play;
}

std::string Player::getPlayerInfo() {
    std::ostringstream sout;
    sout << getNickname()<<std::endl;
    sout << "--Hand:\n"<<player_hand->getCardsInfo()<<std::endl;
    sout << "--Pillars:\n"<<player_pillars->getPillarsInfo()<<std::endl;
    sout <<"--Battlefield:\n"<< player_board->getCardsInfo()<<std::endl;
    return sout.str();


}

bool Player::isHuman() const {
    return human;
}

Player::Player(bool human, std::string &nickname, int player_actions, Hand *player_hand, Battlefield *player_board,
               PillarsArray *player_pillars) : human(human), nickname(nickname), player_actions(player_actions), player_hand(player_hand), player_board(player_board), player_pillars(player_pillars){

}

void Player::setPlayerPlay(Play *playerPlay) {
    player_play = playerPlay;
}