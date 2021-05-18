//
// Created by student on 13.06.2020.
//

#include <Player/HumanPlayer.h>
#include <Player/ComputerPlayer.h>
#include "Strategy.h"
#include <iostream>
#include <Unit/Archer.h>
#include <Unit/Medic.h>
#include <Unit/Thief.h>
#include <Unit/Warrior.h>
#include "Unit/Unit.h"
#include "Battlefield.h"
#include "Hand.h"
#include <fstream>
#include <limits>


Action Strategy::decision(HumanPlayerPtr) {
    int action;
    // Wyswietlenie stanu planszy
    std::cout << "What do you want to do?" << std::endl;
    std::cout
            << "1. Attack, 2. Draw card, 3. Move card on board, 4. Put card on battlefield, 5. Trade cards, 6. Save game, 7. End game"
            << std::endl;
    std::cin>>action;
    if(!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw StrategyException("Wrong option");
    } else{
        switch (action) {
            case 1:
                return ATTACK;
            case 2:
                return DRAWCARD;
            case 3:
                return MOVEONBOARD;
            case 4:
                return PUTCARD;
            case 5:
                return TRADECARDS;
            case 6:
                return SAVE;
            case 7:
                return ENDGAME;
            default:
                throw StrategyException("Wrong option");
        }
    }

}

void Strategy::move_onboard(Battlefield *player_board) {
    int card_number, position;
    std::cout << "What card do you want to move? (1-5) " << std::endl;
    std::cin >> card_number;
    if(!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw StrategyException("Wrong option");
    }
    if (player_board->getCard(card_number - 1) == nullptr) throw StrategyException("there is no card");
    std::cout << "Where? (1-5) " << std::endl;
    std::cin >> position;
    if(!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw StrategyException("Wrong option");
    }
    if (player_board->getCard(position - 1) != nullptr) throw StrategyException("There is a card on this position");
    player_board->putCard(position - 1, player_board->getCard(card_number - 1));
    player_board->deleteCard(card_number - 1);
}

void Strategy::put_card(Hand *player_hand, Battlefield *player_board) {
    int card_number, position;
    std::cout << "What card do you want to put? (1-5)" << std::endl;
    std::cin >> card_number;
    if(!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw StrategyException("Wrong option");
    }
    if (player_hand->getCard(card_number - 1) == nullptr) throw StrategyException("there is no card");
    std::cout << "Where? (1-5) " << std::endl;
    std::cin >> position;
    if(!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw StrategyException("Wrong option");
    }
    if (player_board->getCard(position - 1) != nullptr) throw StrategyException("There is a card on this position");
    player_board->putCard(position - 1, player_hand->getCard(card_number - 1));
    player_hand->deleteCard(card_number - 1);
}

void Strategy::draw_card(Hand *player_hand) {
    for (int i = 0; i < 5; i++) {
        if (player_hand->getCard(i) == nullptr) {
            UnitPtr newCard = RandomCard::random_card(i);
            player_hand->setCard(i, newCard);
            return;
        }
    }
    throw StrategyException("You already have 5 cards");
}

void Strategy::trade_cards(Hand *player_hand) {
    for (int i = 0; i < 5; i++) {
        if (player_hand->getCard(i) != nullptr) {
            UnitPtr newCard = RandomCard::random_card(i);
            player_hand->setCard(i, newCard);
        }
    }
}

void Strategy::attack(Battlefield *player_board, Play *player_play) {
    int choice;
    std::cout << "Using which card you want to attack? (1-5) " << std::endl;
    std::cin >> choice;
    if(!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw StrategyException("Wrong option");
    }
    if (player_board->getCard(choice - 1) == nullptr) throw StrategyException("There is no card");
    player_board->getCard(choice - 1)->attack(player_play);
}

void Strategy::save(Play *play) {
    std::ofstream plik;
    plik.open("save.txt");
    if (plik.good()) {
        plik << play->isTurnPlayer1();
        plik << "\n";
        plik<<play->getPlayer()->isHuman();
        plik<<"\n";
        plik << play->getPlayer()->getNickname();
        plik << "\n";
        plik << play->getPlayer()->getPlayerActions();
        plik << "\n";
        for (int i = 0; i < 5; i++) {
            if (play->getPlayer()->getPlayerHand()->getCard(i) != nullptr) {
                plik << play->getPlayer()->getPlayerHand()->getCard(i)->getPosition() << "\n";
                plik << play->getPlayer()->getPlayerHand()->getCard(i)->getHealth() << "\n";
                plik << play->getPlayer()->getPlayerHand()->getCard(i)->getAttackPower() << "\n";
                plik << play->getPlayer()->getPlayerHand()->getCard(i)->getAbility() << "\n";
            } else {
                plik << 100; //jezeli 100 tzn. pusty
                plik << "\n";
            }
        }


        for (int i = 0; i < 5; i++) {
            if (play->getPlayer()->getPlayerBoard()->getCard(i) != nullptr) {
                plik << play->getPlayer()->getPlayerBoard()->getCard(i)->getPosition() << "\n";
                plik << play->getPlayer()->getPlayerBoard()->getCard(i)->getHealth() << "\n";
                plik << play->getPlayer()->getPlayerBoard()->getCard(i)->getAttackPower() << "\n";
                plik << play->getPlayer()->getPlayerBoard()->getCard(i)->getAbility() << "\n";
            } else {
                plik << 100; //jezeli 100 tzn. pusty
                plik << "\n";
            }
        }

        for (int i = 0; i < 5; i++) {
            if (play->getPlayer()->getPlayerPillars()->getPillar(i) != nullptr) {
                plik << play->getPlayer()->getPlayerPillars()->getPillar(i)->getPosition() << "\n";
                plik << play->getPlayer()->getPlayerPillars()->getPillar(i)->getHealth() << "\n";
                plik << play->getPlayer()->getPlayerPillars()->getPillar(i)->getAbility() << "\n";

            } else {
                plik << 100<< "\n"; //jezeli 100 tzn. zniszczony
            }
        }

        plik<<play->getPlayer()->isHuman();
        plik<<"\n";
        plik << play->getEnemyPlayer()->getNickname();
        plik << "\n";
        plik << play->getPlayer()->getPlayerActions();
        plik << "\n";
        for (int i = 0; i < 5; i++) {
            if (play->getEnemyPlayer()->getPlayerHand()->getCard(i) != nullptr) {
                plik << play->getEnemyPlayer()->getPlayerHand()->getCard(i)->getPosition() << "\n";
                plik << play->getEnemyPlayer()->getPlayerHand()->getCard(i)->getHealth() << "\n";
                plik << play->getEnemyPlayer()->getPlayerHand()->getCard(i)->getAttackPower() << "\n";
                plik << play->getEnemyPlayer()->getPlayerHand()->getCard(i)->getAbility() << "\n";
            } else {
                plik << 100;
                plik << "\n";
            }


        }
        for (int i = 0; i < 5; i++) {
            if (play->getEnemyPlayer()->getPlayerBoard()->getCard(i) != nullptr) {
                plik << play->getEnemyPlayer()->getPlayerBoard()->getCard(i)->getPosition() << "\n";
                plik << play->getEnemyPlayer()->getPlayerBoard()->getCard(i)->getHealth() << "\n";
                plik << play->getEnemyPlayer()->getPlayerBoard()->getCard(i)->getAttackPower() << "\n";
                plik << play->getEnemyPlayer()->getPlayerBoard()->getCard(i)->getAbility() << "\n";
            } else {
                plik << 100;
                plik << "\n";
            }
        }

        for (int i = 0; i < 5; i++) {
            if (play->getEnemyPlayer()->getPlayerPillars()->getPillar(i) != nullptr) {
                plik << play->getEnemyPlayer()->getPlayerPillars()->getPillar(i)->getPosition() << "\n";
                plik << play->getEnemyPlayer()->getPlayerPillars()->getPillar(i)->getHealth() << "\n";
                plik << play->getEnemyPlayer()->getPlayerPillars()->getPillar(i)->getAbility() << "\n";
            } else {
                plik << 100 << "\n";
            }


        }


    }


    plik.close();
}


