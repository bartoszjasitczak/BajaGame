//
// Created by student on 12.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "Hand.h"
#include "Unit/Unit.h"
#include <sstream>
#include <Unit/Archer.h>
#include <Unit/Medic.h>
#include <Unit/Warrior.h>
#include <Unit/Thief.h>

BOOST_AUTO_TEST_SUITE(HandTestSuite)

BOOST_AUTO_TEST_CASE(HandParameterConstructorTest) {
        Hand hand;
        for (unsigned int i = 0; i < 5; i++) {
            BOOST_TEST_CHECK(hand.getCard(i) != nullptr);
        }
}

BOOST_AUTO_TEST_CASE(HandParameterConstructorTwoTest) {
        UnitPtr tab[5];
        tab[0] = std::make_shared<Archer>(0);
        tab[1] = std::make_shared<Medic>(1);
        tab[2] = std::make_shared<Warrior>(2);
        tab[3] = nullptr;
        tab[4] = std::make_shared<Thief>(4);
        Hand hand(tab);
        BOOST_TEST_CHECK(hand.getCard(0) == tab[0]);
        BOOST_TEST_CHECK(hand.getCard(1) == tab[1]);
        BOOST_TEST_CHECK(hand.getCard(2) == tab[2]);
        BOOST_TEST_CHECK(hand.getCard(3) == tab[3]);
        BOOST_TEST_CHECK(hand.getCard(4) == tab[4]);

}

BOOST_AUTO_TEST_CASE(HandSetCardTest) {
        Hand hand;
        UnitPtr card = std::make_shared<Archer>(2);
        hand.setCard(3, card);
        BOOST_CHECK_EQUAL(hand.getCard(3), card);
        BOOST_CHECK_EQUAL(hand.getCard(3)->isOnBoard(), false);
        BOOST_CHECK_EQUAL(hand.getCard(3)->getPosition(), 3);
}

BOOST_AUTO_TEST_CASE(HandDeleteCardTest) {
        Hand hand;
        UnitPtr card = std::make_shared<Archer>(2);
        hand.setCard(3, card);
        BOOST_CHECK_EQUAL(hand.getCard(3), card);
        hand.deleteCard(3);
        BOOST_CHECK_EQUAL(hand.getCard(3), nullptr);
}

BOOST_AUTO_TEST_CASE(HandGetCardsInfo) {
        Hand hand;
        std::ostringstream sout;

        for(int i=0; i<5; i++)
        {
            if(hand.getCard(i)==nullptr) sout<<"Empty place"<<std::endl;
            else sout<<hand.getCard(i)->get_unit_info();
        }
        BOOST_CHECK_EQUAL(hand.getCardsInfo(), sout.str());


}


BOOST_AUTO_TEST_SUITE_END()