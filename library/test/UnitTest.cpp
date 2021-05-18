//
// Created by student on 12.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "Unit/Unit.h"
#include "Unit/Warrior.h"
#include <sstream>
#include <Unit/Archer.h>
#include <Pillar/BluePillar.h>
#include <Pillar/RedPillar.h>
#include <Pillar/GreenPillar.h>
#include <Unit/Thief.h>
#include <Unit/Medic.h>

BOOST_AUTO_TEST_SUITE(UnitTestSuite)

BOOST_AUTO_TEST_CASE(UnitParameterConstructorTest) {
        Warrior unit(2);
        BOOST_CHECK_EQUAL(unit.getHealth(), 7);
        BOOST_CHECK_EQUAL(unit.getAttackPower(), 3);
        BOOST_CHECK_EQUAL(unit.getAbility(), "Warrior");
        BOOST_CHECK_EQUAL(unit.getPosition(), 2);
        BOOST_CHECK_EQUAL(unit.isOnBoard(), false);

}

BOOST_AUTO_TEST_CASE(UnitParameterConstructorTwoTest) {
        Warrior unit(3, 6, 2, true);
        BOOST_CHECK_EQUAL(unit.getHealth(), 3);
        BOOST_CHECK_EQUAL(unit.getAttackPower(), 6);
        BOOST_CHECK_EQUAL(unit.getAbility(), "Warrior");
        BOOST_CHECK_EQUAL(unit.getPosition(), 2);
        BOOST_CHECK_EQUAL(unit.isOnBoard(), true);

}

BOOST_AUTO_TEST_CASE(UnitSettersTest) {
        Unit unit(4);
        unit.setHealth(12);
        unit.setPosition(2);
        unit.setOnBoard();
        BOOST_CHECK_EQUAL(unit.getHealth(),12);
        BOOST_CHECK_EQUAL(unit.getPosition(), 2);
        BOOST_CHECK_EQUAL(unit.isOnBoard(), true);

}

BOOST_AUTO_TEST_CASE(UnitGetInfoTest) {
        Archer unit(4);
        std::ostringstream sout;
        sout<<"Position: "<<5<<" ";
        sout<<"HP: "<<6<<" ";
        sout<<"Attack: "<<3<<" ";
        sout<<"Ability: "<<"Archer"<<" ";
        sout<<std::endl;
        BOOST_CHECK_EQUAL(unit.get_unit_info(),sout.str());
}

BOOST_AUTO_TEST_CASE(UnitAttackTest){
        UnitPtr handcards[5];
        for(int i=0; i<5; i++)
        {
            handcards[i]=nullptr;
        }
        Hand *hand=new Hand(handcards);
        UnitPtr cards[5];
        cards[0] = std::make_shared<Archer>(0);
        cards[1] = std::make_shared<Thief>(1);
        cards[2] = std::make_shared<Archer>(2);
        cards[3] =std::make_shared<Warrior>(3);
        cards[4] = std::make_shared<Medic>(4);
        Battlefield *battlefield = new Battlefield(cards);
        PillarPtr pillars[5];
        pillars[0] = std::make_shared<BluePillar>(0);
        pillars[1] = std::make_shared<RedPillar>(1);
        pillars[2] = std::make_shared<GreenPillar>(2);
        pillars[3] = std::make_shared<RedPillar>(3);
        pillars[4] = std::make_shared<GreenPillar>(4);
        PillarsArray *pillarsArray = new PillarsArray(pillars);
        UnitPtr enemycards[5];
        enemycards[0] = std::make_shared<Archer>(0);
        enemycards[1] = std::make_shared<Medic>(1);
        enemycards[2] = std::make_shared<Warrior>(2);
        enemycards[3] = std::make_shared<Archer>(3);
        enemycards[4] = std::make_shared<Thief>(4);
        Battlefield *enemybattlefield = new Battlefield(enemycards);
        PillarPtr enemypillars[5];
        enemypillars[0] = std::make_shared<BluePillar>(0);
        enemypillars[1] = std::make_shared<RedPillar>(1);
        enemypillars[2] = std::make_shared<BluePillar>(2);
        enemypillars[3] = std::make_shared<GreenPillar>(3);
        enemypillars[4] = std::make_shared<GreenPillar>(4);
        PillarsArray *enemypillarsArray = new PillarsArray(enemypillars);
        PlayerPtr player = std::make_shared<HumanPlayer>(true, "player", 3, hand, battlefield, pillarsArray);
        PlayerPtr enemy = std::make_shared<HumanPlayer>(true, "enemy", 3, nullptr, enemybattlefield, enemypillarsArray);
        Play *play = new Play(player, enemy, true);
        //Warrior
        play->getPlayer()->getPlayerBoard()->getCard(3)->attack(play);
        BOOST_CHECK_EQUAL(play->getEnemyPlayer()->getPlayerBoard()->getCard(2)->getHealth(),4);
        BOOST_CHECK_EQUAL(play->getEnemyPlayer()->getPlayerBoard()->getCard(3)->getHealth(),3);
        BOOST_CHECK_EQUAL(play->getEnemyPlayer()->getPlayerBoard()->getCard(4)->getHealth(),3);
        //Archer
        play->getPlayer()->getPlayerBoard()->getCard(2)->attack(play);
        BOOST_CHECK_EQUAL(play->getEnemyPlayer()->getPlayerPillars()->getPillar(2)->getHealth(),12);
        //Medic
        play->getPlayer()->getPlayerBoard()->getCard(4)->attack(play);
        BOOST_CHECK_EQUAL(play->getEnemyPlayer()->getPlayerBoard()->getCard(4),nullptr);
        BOOST_CHECK_EQUAL(play->getPlayer()->getPlayerBoard()->getCard(0)->getHealth(),7);
        BOOST_CHECK_EQUAL(play->getPlayer()->getPlayerBoard()->getCard(1)->getHealth(),7);
        BOOST_CHECK_EQUAL(play->getPlayer()->getPlayerBoard()->getCard(2)->getHealth(),7);
        BOOST_CHECK_EQUAL(play->getPlayer()->getPlayerBoard()->getCard(3)->getHealth(),8);
        BOOST_CHECK_EQUAL(play->getPlayer()->getPlayerBoard()->getCard(4)->getHealth(),8);
        //Thief
        play->getPlayer()->getPlayerBoard()->getCard(1)->attack(play);
        BOOST_CHECK_EQUAL(play->getEnemyPlayer()->getPlayerBoard()->getCard(1)->getHealth(),4);
        BOOST_TEST_CHECK(play->getPlayer()->getPlayerHand()->getCard(0) != nullptr);
}

BOOST_AUTO_TEST_SUITE_END()