//
// Created by student on 04.06.2020.
//

#include "Player/ComputerPlayer.h"
#include <iostream>
#include "Battlefield.h"
#include <cstdlib>
#include <ctime>
#include <sstream>

ComputerPlayer::ComputerPlayer(const std::string &nickname, Play *playerPlay) : Player(nickname, playerPlay) {
    human=false;
}

ComputerPlayer::~ComputerPlayer() {}

void ComputerPlayer::decision() {

    bool attack, cardsonbattlefield, cardsonhand, put, draw, wasaction;
    int choice;
    std::cout<<"\nPlayer's "<<getNickname()<<" Turn"<<std::endl;
    setPlayerActions(3);
    while(getPlayerActions()>0) {
        std::ostringstream sout;
        attack = false;
        cardsonbattlefield = false;
        cardsonhand = false;
        put = false;
        draw = false;
        wasaction = false;
        choice = rand() % 4 + 1;
        for (unsigned int i = 0; i < 5; i++) {
            if (getPlayerBoard()->getCard(i) != nullptr) {
                cardsonbattlefield = true;
                break;
            }
        }
        for (unsigned int i = 0; i < 5; i++) {
            if (getPlayerHand()->getCard(i) != nullptr) {
                cardsonhand = true;
                break;
            }
        }
        switch (choice) {
            case 1:
                if (cardsonbattlefield == true) {
                    while (attack == false) {
                        int x = rand() % 4;
                        if (getPlayerBoard()->getCard(x) != nullptr) {
                            getPlayerBoard()->getCard(x)->attack(getPlayerPlay());
                            attack = true;
                            std::cout << "Player " << getNickname() << " attacked\n";
                            wasaction = true;
                        }
                    }
                }
                break;
            case 2:
                if (cardsonhand == true) {
                    while (put == false) {
                        int x = rand() % 5;
                        if (getPlayerHand()->getCard(x) != nullptr) {
                            while (put == false) {
                                int y = rand() % 5;
                                if (getPlayerBoard()->getCard(y) == nullptr) {
                                    getPlayerBoard()->putCard(y, getPlayerHand()->getCard(x));
                                    getPlayerHand()->deleteCard(x);
                                    put = true;
                                    std::cout << "Player " << getNickname() << " put card on battlefield\n";
                                    wasaction = true;
                                }
                            }

                        }
                    }
                }
                break;
            case 3:
                for (int i = 0; i < 5; i++) {
                    if (getPlayerHand()->getCard(i) == nullptr) {
                        UnitPtr newCard = this->random_card(i);
                        getPlayerHand()->setCard(i, newCard);
                        draw = true;
                        std::cout << "Player " << getNickname() << " drew cards\n";
                        wasaction = true;
                    }
                    if (draw == true) break;
                }

                break;
            case 4:
                for (int i = 0; i < 5; i++) {
                    if (getPlayerHand()->getCard(i) != nullptr) {
                        UnitPtr newCard = this->random_card(i);
                        getPlayerHand()->setCard(i, newCard);
                    }
                }
                std::cout << "Player " << getNickname() << " traded cards\n";
                wasaction = true;
                break;
        }
        sout
                << "----------------------------------------------------------------------------------------------------------------"
                << std::endl;
        sout << "\033[1;32m" << getPlayerInfo() << "\033[0m\n";
        sout << "\033[1;31m" << "--Enemy's Battlefield" << "\033[0m\n" << std::endl;
        sout << "\033[1;31m" << getPlayerPlay()->getEnemyPlayer()->getPlayerBoard()->getCardsInfo() << "\033[0m\n";
        sout << "\033[1;31m" << "--Enemy's Pillars" << "\033[0m\n" << std::endl;
        sout << "\033[1;31m" << getPlayerPlay()->getEnemyPlayer()->getPlayerPillars()->getPillarsInfo() << "\033[0m\n"
             << std::endl;
        if (wasaction){
            std::cout << sout.str();
            setPlayerActions(getPlayerActions()-1);
        }
        if(!wasaction) std::cout<<"\nPlayer "<<getNickname()<<" did nothing\n";

    }


}

ComputerPlayer::ComputerPlayer(bool human, std::string &nickname, int player_actions, Hand *player_hand, Battlefield *player_board,
                               PillarsArray *player_pillars) : Player(human, nickname, player_actions, player_hand,
                                                                      player_board, player_pillars) {

}







