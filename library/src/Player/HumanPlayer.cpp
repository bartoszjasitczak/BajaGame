//
// Created by student on 04.06.2020.
//

#include "Player/HumanPlayer.h"
#include <iostream>
#include "Strategy.h"
#include "Battlefield.h"
#include <memory>
#include "Play.h"

HumanPlayer::HumanPlayer(const std::string &nickname, Play *playerPlay) : Player(nickname, playerPlay) {
    human=true;
}

HumanPlayer::~HumanPlayer() {

}

void HumanPlayer::decision() {
    std::cout<<"\nPlayer's "<<getNickname()<<" Turn"<<std::endl;
    while(getPlayerActions()>0) {
        std::cout<<"----------------------------------------------------------------------------------------------------------------"<<std::endl;
        std::cout<<"\033[1;32m"<<getPlayerInfo()<<"\033[0m\n";
        std::cout<<"\033[1;31m"<<"--Enemy's Battlefield"<<"\033[0m\n";
        std::cout<<"\033[1;31m"<<getPlayerPlay()->getEnemyPlayer()->getPlayerBoard()->getCardsInfo()<<"\033[0m\n";
        std::cout<<"\033[1;31m"<<"--Enemy's Pillars"<<"\033[0m\n";
        std::cout<<"\033[1;31m"<<getPlayerPlay()->getEnemyPlayer()->getPlayerPillars()->getPillarsInfo()<<"\033[0m\n"<<std::endl;
        bool sucess=false;
        while(sucess!=true) {
            try {
                Action action = strategy->decision(shared_from_this());
                switch (action) {
                    case ATTACK:
                        strategy->attack(getPlayerBoard(), getPlayerPlay());
                        break;
                    case TRADECARDS:
                        strategy->trade_cards(getPlayerHand());
                        break;
                    case PUTCARD:
                        strategy->put_card(getPlayerHand(), getPlayerBoard());
                        break;
                    case DRAWCARD:
                        strategy->draw_card(getPlayerHand());
                        break;
                    case MOVEONBOARD:
                        strategy->move_onboard(getPlayerBoard());
                        break;
                    case SAVE:
                        strategy->save(getPlayerPlay());
                        break;
                    case ENDGAME:
                        delete getPlayerPlay();
                        exit(0);
                }
                sucess=true;
            } catch (HandException &e) {
                std::cout << e.what() << std::endl;
            }
            catch (BattlefieldException &e) {
                std::cout << e.what() << std::endl;
            } catch (StrategyException &e) {
                std::cout << e.what() << std::endl;
            }
        }

        setPlayerActions(getPlayerActions() - 1);
    }
    setPlayerActions(3);
}

HumanPlayer::HumanPlayer(bool human, std::basic_string<char> nickname, int player_actions, Hand *player_hand, Battlefield *player_board,
                         PillarsArray *player_pillars) : Player(human, nickname, player_actions, player_hand, player_board,
                                                                player_pillars) {

}

