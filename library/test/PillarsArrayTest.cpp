//
// Created by student on 12.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "Pillar/PillarsArray.h"
#include "typedefs.h"
#include <sstream>
#include <Pillar/RedPillar.h>
#include <Pillar/BluePillar.h>
#include <Pillar/GreenPillar.h>

BOOST_AUTO_TEST_SUITE(PillarsArrayTestSuite)

BOOST_AUTO_TEST_CASE(PillarsArrayParameterConstructorTest) {
        PillarsArray pillars_array;
        for(unsigned int i =0 ; i<5;i++)
        {
            BOOST_TEST_CHECK(pillars_array.getPillar(i)!= nullptr);
        }
}

BOOST_AUTO_TEST_CASE(PillarsArrayParameterConstructorTwoTest) {
        PillarPtr tab[5];
        tab[0] = std::make_shared<BluePillar>(0);
        tab[1] = std::make_shared<RedPillar>(1);
        tab[2] = std::make_shared<GreenPillar>(2);
        tab[3] = nullptr;
        tab[4] = std::make_shared<BluePillar>(4);
        PillarsArray pillarsArray(tab);
        BOOST_TEST_CHECK(pillarsArray.getPillar(0) == tab[0]);
        BOOST_TEST_CHECK(pillarsArray.getPillar(1) == tab[1]);
        BOOST_TEST_CHECK(pillarsArray.getPillar(2) == tab[2]);
        BOOST_TEST_CHECK(pillarsArray.getPillar(3) == tab[3]);
        BOOST_TEST_CHECK(pillarsArray.getPillar(4) == tab[4]);
}

BOOST_AUTO_TEST_CASE(PillarsArrayDeletePillarTest) {
        PillarPtr tab[5];
        tab[0] = std::make_shared<BluePillar>(0);
        tab[1] = std::make_shared<RedPillar>(1);
        tab[2] = std::make_shared<GreenPillar>(2);
        tab[3] = nullptr;
        tab[4] = std::make_shared<BluePillar>(4);
        PillarsArray pillarsArray(tab);
        pillarsArray.deletePillar(1);
        BOOST_TEST_CHECK(pillarsArray.getPillar(1) == nullptr);
}

BOOST_AUTO_TEST_CASE(PillarsArrayGetPillarInfo) {
        PillarsArray pillars_array;
        std::ostringstream sout;

        for(unsigned int i=0;i<5;i++) {
            if(pillars_array.getPillar(i)==nullptr) sout<<"Pillar destroyed"<<std::endl;
            else{
                sout<<"Position: "<<pillars_array.getPillar(i)->getPosition()+1<<" ";
                sout<<"HP: "<<pillars_array.getPillar(i)->getHealth()<<" ";
                sout<<"Ability: "<<pillars_array.getPillar(i)->getAbility()<<std::endl;
            }
        }
        BOOST_CHECK_EQUAL(pillars_array.getPillarsInfo(),sout.str());

}





BOOST_AUTO_TEST_SUITE_END()