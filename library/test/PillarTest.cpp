//
// Created by student on 12.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "Pillar/Pillar.h"
#include "Pillar/GreenPillar.h"
#include <sstream>
#include <Pillar/BluePillar.h>
#include <Unit/Archer.h>
#include <Unit/Medic.h>
#include <Unit/Warrior.h>
#include <Unit/Thief.h>
#include <Pillar/RedPillar.h>

BOOST_AUTO_TEST_SUITE(PillarTestSuite)

BOOST_AUTO_TEST_CASE(PillarParameterConstructorTest) {
        GreenPillar pillar(1);
        BOOST_CHECK_EQUAL(pillar.getHealth(), 15);
        BOOST_CHECK_EQUAL(pillar.getAbility(), "Green");
        BOOST_CHECK_EQUAL(pillar.getPosition(), 1);
}

BOOST_AUTO_TEST_CASE(PillarParameterConstructorTwoTest) {
        PillarPtr pillar;
        pillar = std::make_shared<BluePillar>(1, 4);
        BOOST_TEST_CHECK(pillar->getPosition() == 1);
        BOOST_CHECK_EQUAL(pillar->getAbility(), "Blue");
        BOOST_TEST_CHECK(pillar->getHealth() == 4);
}

BOOST_AUTO_TEST_CASE(getPillarInfoTest) {
        GreenPillar pillar(1);
        std::ostringstream sout;
        sout << "Position: " << pillar.getPosition() + 1 << " ";
        sout << "HP: " << pillar.getHealth() << " ";
        sout << "Ability: " << pillar.getAbility();
        BOOST_CHECK_EQUAL(pillar.getPillarInfo(), sout.str());
}

BOOST_AUTO_TEST_CASE(setPillarHealthTest) {
        GreenPillar pillar(1);
        pillar.setHealth(12);
        BOOST_CHECK_EQUAL(pillar.getHealth(), 12);

}

BOOST_AUTO_TEST_CASE(PillarDefendTest) {
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
        Play *play = new Play(player, enemy, false);
        pillars[0]->defend(play);
        for (int i = 0; i < 3; i++) {
            BOOST_CHECK_EQUAL(battlefield->getCard(i)->getHealth(), 7);
        }
        pillars[1]->defend(play);
        BOOST_CHECK_EQUAL(enemybattlefield->getCard(1)->getHealth(), 3);
        pillars[2]->defend(play);
        BOOST_CHECK_EQUAL(enemybattlefield->getCard(0)->getHealth(), 5);
        BOOST_CHECK_EQUAL(enemybattlefield->getCard(1)->getHealth(), 2);
        BOOST_CHECK_EQUAL(enemybattlefield->getCard(2)->getHealth(), 5);
        delete battlefield;
        delete enemybattlefield;
        delete pillarsArray;
        delete enemypillarsArray;

}


BOOST_AUTO_TEST_SUITE_END()