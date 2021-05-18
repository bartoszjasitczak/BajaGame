#include <iostream>
#include "Game.h"
#include "Play.h"
#include "Hand.h"
#include "Battlefield.h"
#include "Player/Player.h"
#include "Player/ComputerPlayer.h"
#include "Player/HumanPlayer.h"
#include "Unit/Unit.h"
#include "Unit/Warrior.h"
#include "Unit/Archer.h"
#include "Unit/Thief.h"
#include "Unit/Medic.h"
#include "Pillar/PillarsArray.h"
#include "Pillar/Pillar.h"
#include "Pillar/RedPillar.h"
#include "Pillar/BluePillar.h"
#include "Pillar/GreenPillar.h"
#include <ctime>
#include <typeinfo>

int main() {

    srand(time(NULL));

    GamePtr game= std::make_shared<Game>();
    game->choice_from_menu();


    return 0;


}