//
// Created by student on 12.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "Play.h"
#include <sstream>
#include <Player/ComputerPlayer.h>
#include <Player/HumanPlayer.h>
#include <cstddef>
#include <Pillar/GreenPillar.h>
#include <Pillar/RedPillar.h>
#include <Pillar/BluePillar.h>
#include <Unit/Archer.h>

using namespace std;

BOOST_AUTO_TEST_SUITE(PlayTestSuite)

BOOST_AUTO_TEST_CASE(PlayParameterConstructorTest) {
        Play play(0, "Wojtus", "Macius");
        Play play2(1, "Wojtus", "Macius");
        Play play3(2, "Wojtus", "Macius");
        for (unsigned int i = 0; i < 2; i++) {
            BOOST_TEST_REQUIRE(play.getPlayer() != nullptr);
            PlayerPtr player = play.getPlayer();
            BOOST_TEST_CHECK(dynamic_pointer_cast<ComputerPlayer>(player) != nullptr);
            play.setWhoseTurn();
        }

        PlayerPtr player = play2.getPlayer();
        BOOST_TEST_CHECK(dynamic_pointer_cast<HumanPlayer>(player) != nullptr);
        player = play2.getEnemyPlayer();
        BOOST_TEST_CHECK(dynamic_pointer_cast<ComputerPlayer>(player) != nullptr);


        for (unsigned int i = 0; i < 2; i++) {
            player = play3.getPlayer();
            BOOST_TEST_CHECK(dynamic_pointer_cast<HumanPlayer>(player) != nullptr);
            play3.setWhoseTurn();
        }
}

BOOST_AUTO_TEST_CASE(PlayParameterConstructorTwoTest) {
        UnitPtr cards[5];
        cards[0] = std::make_shared<Archer>(0);
        cards[1] = std::make_shared<Archer>(1);
        cards[2] = std::make_shared<Archer>(2);
        cards[3] = nullptr;
        cards[4] = nullptr;
        Battlefield *battlefield = new Battlefield(cards);
        PillarPtr pillars[5];
        pillars[0] = std::make_shared<BluePillar>(0);
        pillars[1] = std::make_shared<RedPillar>(1);
        pillars[2] = std::make_shared<GreenPillar>(2);
        pillars[3] = nullptr;
        pillars[4] = nullptr;
        PillarsArray *pillarsArray = new PillarsArray(pillars);
        UnitPtr enemycards[5];
        enemycards[0] = std::make_shared<Archer>(0);
        enemycards[1] = std::make_shared<Archer>(1);
        enemycards[2] = std::make_shared<Archer>(2);
        enemycards[3] = nullptr;
        enemycards[4] = nullptr;
        Battlefield *enemybattlefield = new Battlefield(enemycards);
        PillarPtr enemypillars[5];
        enemypillars[0] = std::make_shared<BluePillar>(0);
        enemypillars[1] = std::make_shared<RedPillar>(1);
        enemypillars[2] = std::make_shared<GreenPillar>(2);
        enemypillars[3] = nullptr;
        enemypillars[4] = nullptr;
        PillarsArray *enemypillarsArray = new PillarsArray(enemypillars);
        PlayerPtr player = std::make_shared<HumanPlayer>(true, "player", 3, nullptr, battlefield, pillarsArray);
        PlayerPtr enemy = std::make_shared<HumanPlayer>(true, "enemy", 3, nullptr, enemybattlefield, enemypillarsArray);
        Play *play = new Play(player, enemy, true);
        BOOST_TEST_REQUIRE(play->getPlayer() == player);
        BOOST_TEST_REQUIRE(play->getEnemyPlayer() == enemy);
        PlayerPtr playertest = play->getPlayer();
        BOOST_TEST_CHECK(dynamic_pointer_cast<HumanPlayer>(player) != nullptr);
        playertest = play->getEnemyPlayer();
        BOOST_TEST_CHECK(dynamic_pointer_cast<HumanPlayer>(player) != nullptr);
        play->setWhoseTurn();
}

BOOST_AUTO_TEST_CASE(PlayWhoseTurnTest) {
        Play play(0, "Wojtus", "Macius");
        BOOST_TEST_CHECK(play.isTurnPlayer1() == true);
        play.setWhoseTurn();
        BOOST_TEST_CHECK(play.isTurnPlayer1() == false);
}


BOOST_AUTO_TEST_SUITE_END()