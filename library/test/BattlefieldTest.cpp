//
// Created by student on 12.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "Battlefield.h"
#include <sstream>
#include <ctime>
#include <iostream>
#include <Unit/Unit.h>
#include <Unit/Archer.h>
#include <Unit/Medic.h>
#include <Unit/Thief.h>
#include <Unit/Warrior.h>

BOOST_AUTO_TEST_SUITE(BattlefieldTestSuite)

BOOST_AUTO_TEST_CASE(BattlefieldParameterConstructorTest) {
        Battlefield battlefield;
        for (unsigned int i = 0; i < 5; i++) {
            BOOST_TEST_CHECK(battlefield.getCard(i) == nullptr);
        }
}

BOOST_AUTO_TEST_CASE(BattlefieldParameterConstructorTwoTest) {
        UnitPtr tab[5];
        tab[0] = std::make_shared<Archer>(0);
        tab[1] = std::make_shared<Medic>(1);
        tab[2] = std::make_shared<Warrior>(2);
        tab[3] = nullptr;
        tab[4] = std::make_shared<Thief>(4);
        Battlefield battlefield(tab);
        BOOST_TEST_CHECK(battlefield.getCard(0) == tab[0]);
        BOOST_TEST_CHECK(battlefield.getCard(1) == tab[1]);
        BOOST_TEST_CHECK(battlefield.getCard(2) == tab[2]);
        BOOST_TEST_CHECK(battlefield.getCard(3) == tab[3]);
        BOOST_TEST_CHECK(battlefield.getCard(4) == tab[4]);

}

BOOST_AUTO_TEST_CASE(BattlefieldGetCardTest) {
        Battlefield battlefield;
        UnitPtr card = std::make_shared<Archer>(2);
        battlefield.putCard(2, card);
        BOOST_CHECK_EQUAL(battlefield.getCard(2), card);
}

BOOST_AUTO_TEST_CASE(BattlefieldPutCardTest) {
        Battlefield battlefield;
        UnitPtr card = std::make_shared<Archer>(2);
        battlefield.putCard(3, card);
        BOOST_CHECK_EQUAL(battlefield.getCard(3), card);
        BOOST_CHECK_EQUAL(battlefield.getCard(3)->isOnBoard(), true);
        BOOST_CHECK_EQUAL(battlefield.getCard(3)->getPosition(), 3);
}

BOOST_AUTO_TEST_CASE(BattlefieldDeleteCardTest) {
        Battlefield battlefield;
        UnitPtr card = std::make_shared<Archer>(2);
        battlefield.putCard(3, card);
        BOOST_CHECK_EQUAL(battlefield.getCard(3), card);
        battlefield.deleteCard(3);
        BOOST_CHECK_EQUAL(battlefield.getCard(3), nullptr);
}

BOOST_AUTO_TEST_CASE(BattlefieldGetCardsInfo) {
        Battlefield battlefield;
        std::ostringstream sout;
        UnitPtr card;
        srand(time(NULL));
        for (int i = 0; i < 5; i++) {
            int x = (std::rand() % 4) + 1;
            if (x == 1) card = std::make_shared<Archer>(i);
            else if (x == 2) card = std::make_shared<Medic>(i);
            else if (x == 3) card = std::make_shared<Thief>(i);
            else card = std::make_shared<Warrior>(i);
            battlefield.putCard(i, card);
        }

        for (int i = 0; i < 5; i++) {
            if (battlefield.getCard(i) == nullptr) sout << "Empty place" << std::endl;
            else sout << battlefield.getCard(i)->get_unit_info();
        }
        BOOST_CHECK_EQUAL(battlefield.getCardsInfo(), sout.str());


}


BOOST_AUTO_TEST_SUITE_END()