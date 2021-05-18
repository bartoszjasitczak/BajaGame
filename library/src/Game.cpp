//
// Created by student on 04.06.2020.
//

#include "../include/Game.h"
#include <iostream>
#include "Play.h"
#include <string>
#include <Battlefield.h>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <limits>
#include <Unit/Archer.h>
#include <Unit/Medic.h>
#include <Unit/Thief.h>
#include <Unit/Warrior.h>
#include <Pillar/BluePillar.h>
#include <Pillar/RedPillar.h>
#include <Pillar/GreenPillar.h>
#include <Player/ComputerPlayer.h>
#include "Unit/Unit.h"


Game::Game() {}

Game::~Game() {

}

Play *Game::load_game() {
    std::ifstream plik;
    int health, attack_power, position, action;
    std::string ability;
    std::string nickname;
    UnitPtr cards1[5], cards2[5];
    PillarPtr pillars1[5], pillars2[5];
    PlayerPtr player1, player2;
    int human, how_many_human_players = 0;
    bool whoseTurn;

    plik.open("save.txt");
    if (!plik.good()) {
        throw MenuException("Wrong file");
    } else {
        plik >> whoseTurn;
        plik >> human;
        plik >> nickname;
        plik >> action;
        for (int i = 0; i < 5; i++) {
            plik >> position;
            if (position == 100) {
                cards1[i] = nullptr;
                continue;
            }
            plik >> health;
            plik >> attack_power;
            plik >> ability;
            if (ability == "Archer") cards1[i] = std::make_shared<Archer>(health, attack_power, position, false);
            else if (ability == "Medic")
                cards1[i] = std::make_shared<Medic>(health, attack_power, position, false);
            else if (ability == "Thief")
                cards1[i] = std::make_shared<Thief>(health, attack_power, position, false);
            else cards1[i] = std::make_shared<Warrior>(health, attack_power, position, false);

        }
        Hand *player1_hand = new Hand(cards1);
        for (int i = 0; i < 5; i++) {
            plik >> position;
            if (position == 100) {
                cards1[i] = nullptr;
                continue;
            }
            plik >> health;
            plik >> attack_power;
            plik >> ability;
            if (ability == "Archer") cards1[i] = std::make_shared<Archer>(health, attack_power, position, true);
            else if (ability == "Medic") cards1[i] = std::make_shared<Medic>(health, attack_power, position, true);
            else if (ability == "Thief") cards1[i] = std::make_shared<Thief>(health, attack_power, position, true);
            else cards1[i] = std::make_shared<Warrior>(health, attack_power, position, true);
        }
        Battlefield *player1_battlefield = new Battlefield(cards1);
        for (int i = 0; i < 5; i++) {
            plik >> position;
            if (position == 100) {
                pillars1[i] = nullptr;
                continue;
            }
            plik >> health;
            plik >> ability;
            if (ability == "Blue") pillars1[i] = std::make_shared<BluePillar>(position, health);
            else if (ability == "Red") pillars1[i] = std::make_shared<RedPillar>(position, health);
            else pillars1[i] = std::make_shared<GreenPillar>(position, health);
        }
        PillarsArray *player1_pillars = new PillarsArray(pillars1);
        if (human == true)
            player1 = std::make_shared<HumanPlayer>(human, nickname, action, player1_hand, player1_battlefield,
                                                    player1_pillars);
        if (human == false)
            player1 = std::make_shared<ComputerPlayer>(human, nickname, action, player1_hand, player1_battlefield,
                                                    player1_pillars);




        plik >> human;
        plik >> nickname;
        plik >> action;
        for (int i = 0; i < 5; i++) {
            plik >> position;
            if (position == 100) {
                cards2[i] = nullptr;
                continue;
            }
            plik >> health;
            plik >> attack_power;
            plik >> ability;
            if (ability == "Archer") cards2[i] = std::make_shared<Archer>(health, attack_power, position, false);
            else if (ability == "Medic")
                cards2[i] = std::make_shared<Medic>(health, attack_power, position, false);
            else if (ability == "Thief")
                cards2[i] = std::make_shared<Thief>(health, attack_power, position, false);
            else cards2[i] = std::make_shared<Warrior>(health, attack_power, position, false);

        }
        Hand *player2_hand = new Hand(cards2);
        for (int i = 0; i < 5; i++) {
            plik >> position;
            if (position == 100) {
                cards2[i] = nullptr;
                continue;
            }
            plik >> health;
            plik >> attack_power;
            plik >> ability;
            if (ability == "Archer") cards2[i] = std::make_shared<Archer>(health, attack_power, position, true);
            else if (ability == "Medic") cards2[i] = std::make_shared<Medic>(health, attack_power, position, true);
            else if (ability == "Thief") cards2[i] = std::make_shared<Thief>(health, attack_power, position, true);
            else cards2[i] = std::make_shared<Warrior>(health, attack_power, position, true);
        }
        Battlefield *player2_battlefield = new Battlefield(cards2);
        for (int i = 0; i < 5; i++) {
            plik >> position;
            if (position == 100) {
                pillars2[i] = nullptr;
                continue;
            }
            plik >> health;
            plik >> ability;
            if (ability == "Blue") pillars2[i] = std::make_shared<BluePillar>(position, health);
            else if (ability == "Red") pillars2[i] = std::make_shared<RedPillar>(position, health);
            else pillars2[i] = std::make_shared<GreenPillar>(position, health);
        }
        PillarsArray *player2_pillars = new PillarsArray(pillars2);
        if (human == true)
            player2 = std::make_shared<HumanPlayer>(human, nickname, action, player2_hand, player2_battlefield,
                                                    player2_pillars);
        if (human == false)
            player2 = std::make_shared<ComputerPlayer>(human, nickname, action, player2_hand, player2_battlefield,
                                                    player2_pillars);
        // plik.close();
        Play *loadedplay;

        if (whoseTurn == 1) loadedplay = new Play(player1, player2, true);
        else loadedplay = new Play(player2, player1, false);

        return loadedplay;
    }

}

Play *Game::new_play() {
    int how_many_human_players;
    std::string nickname1;
    std::string nickname2;
    std::cout << "Welcome to Baja's Game" << std::endl;
    std::cout << "How many human Players do you want (0-2) " << std::endl;
    std::cin >> how_many_human_players;
    std::cout << "Please write first player nickname: " << std::endl;
    std::cin >> nickname1;
    std::cout << "Please write second player nickname: " << std::endl;
    std::cin >> nickname2;
    Play *play = new Play(how_many_human_players, nickname1, nickname2);
    return play;
}

Option Menu::choice_from_menu(GamePtr) {
    int choice;

    bool success = false;
    while (success == false) {
        try {
            std::cout << "\033[1;32m" << "MENU" << "\033[0m\n" << std::endl << std::endl;
            std::cout << "Choose option:\n";
            std::cout << "1.New play\n2.Load play\n3.Exit\n";
            std::cin >> choice;
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw MenuException("Wrong option");
            } else {
                switch (choice) {
                    case 1:
                        success = true;
                        return NEW;
                    case 2:
                        success = true;
                        return LOAD;
                    case 3:
                        success = true;
                        return EXIT;
                    default:
                        throw MenuException("Wrong option");

                }
            }
        }
        catch (MenuException &e) {
            std::cout << e.what() << std::endl << std::endl;
        }
    }


}

void Game::choice_from_menu() {
    try {
        Option option = menu->choice_from_menu(shared_from_this());
        switch (option) {

            case NEW: {
                Play *playtest = this->new_play();
                playtest->play();
            }
                break;
            case LOAD: {
                Play *playtest = this->load_game();
                std::cout<<playtest->getPlayer()->getPlayerInfo();
                std::cout<<playtest->getEnemyPlayer()->getPlayerInfo();
                playtest->play();
            }
                break;
            case EXIT:
                exit(0);
        }
    }
    catch (HandException &e) {
        std::cout << e.what() << std::endl << std::endl;
    }
    catch (BattlefieldException &e) {
        std::cout << e.what() << std::endl << std::endl;
    }
    catch (PlayException &e) {
        std::cout << "Player exception: " << e.what() << std::endl;
    }
}
