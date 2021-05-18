//
// Created by student on 12.06.2020.
//
#include <boost/test/unit_test.hpp>
#include <Play.h>
#include "Player/Player.h"
#include "Battlefield.h"
#include "Hand.h"
#include "Pillar/PillarsArray.h"


BOOST_AUTO_TEST_SUITE(PlayerTestSuite)

BOOST_AUTO_TEST_CASE(PlayerParametrConstructorTest) {
        Play *play = new Play(2, "Wojtus", "Macius");
        PlayerPtr player=std::make_shared<HumanPlayer>("Imie", play);
        BOOST_CHECK_EQUAL(player->getNickname(), "Imie");
        BOOST_CHECK_EQUAL(player->getPlayerPlay(), play);
        BOOST_TEST_CHECK(player->getPlayerBoard() != nullptr);
        BOOST_TEST_CHECK(player->getPlayerHand() != nullptr);
        BOOST_TEST_CHECK(player->getPlayerPillars() != nullptr);
        delete play;
}

BOOST_AUTO_TEST_CASE(PlayerParametrConstructorTwoTest) {
        Battlefield *battlefield=new Battlefield();
        Hand *hand=new Hand();
        PillarsArray *pillarArray=new PillarsArray();
        PlayerPtr player=std::make_shared<HumanPlayer>(true, "player", 3, hand, battlefield, pillarArray);
        BOOST_TEST_CHECK(player->getPlayerBoard() == battlefield);
        BOOST_TEST_CHECK(player->getPlayerHand() == hand);
        BOOST_TEST_CHECK(player->getPlayerPillars() == pillarArray);
//        delete battlefield;
//        delete hand;
//        delete pillarArray;
}

BOOST_AUTO_TEST_CASE(PlayerGetSetPlayerActionsTest) {
        Play *play = new Play(2, "Wojtus", "Macius");
        PlayerPtr player=std::make_shared<HumanPlayer>("Lolek", play);
        player->setPlayerActions(3);
        BOOST_CHECK_EQUAL(player->getPlayerActions(), 3);
        delete play;
}

BOOST_AUTO_TEST_CASE(PlayerGetPlayerInfoTest) {
        Play *play = new Play(2, "Wojtus", "Macius");
        PlayerPtr player=std::make_shared<HumanPlayer>("Lolek", play);
        std::ostringstream sout;
        sout << player->getNickname()<<std::endl;
        sout << "--Hand:\n"<<player->getPlayerHand()->getCardsInfo()<<std::endl;
        sout << "--Pillars:\n"<<player->getPlayerPillars()->getPillarsInfo()<<std::endl;
        sout <<"--Battlefield:\n"<< player->getPlayerBoard()->getCardsInfo()<<std::endl;
        BOOST_CHECK_EQUAL(player->getPlayerInfo(), sout.str());
        delete play;
}


BOOST_AUTO_TEST_SUITE_END()