cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        include/Battlefield.h src/Battlefield.cpp include/Hand.h src/Hand.cpp include/Player/Player.h src/Player/Player.cpp include/Unit/Unit.h src/Unit/Unit.cpp
        include/Play.h src/Play.cpp include/Pillar/Pillar.h src/Pillar/Pillar.cpp include/Game.h src/Game.cpp include/Unit/Warrior.h src/Unit/Warrior.cpp
        include/Unit/Thief.h src/Unit/Thief.cpp include/Unit/Archer.h src/Unit/Archer.cpp src/Unit/Medic.cpp include/Unit/Medic.h src/Player/HumanPlayer.cpp include/Player/HumanPlayer.h src/Player/ComputerPlayer.cpp include/Player/ComputerPlayer.h src/Pillar/RedPillar.cpp include/Pillar/RedPillar.h src/Pillar/GreenPillar.cpp include/Pillar/GreenPillar.h src/Pillar/BluePillar.cpp include/Pillar/BluePillar.h src/Pillar/PillarsArray.cpp include/Pillar/PillarsArray.h test/PlayTest.cpp test/HandTest.cpp test/BattlefieldTest.cpp test/UnitTest.cpp test/PillarsArrayTest.cpp src/Strategy.cpp include/Strategy.h include/typedefs.h src/RandomCard.cpp include/RandomCard.h)
#utwĂłrz bibliotekÄ typu STATIC, SHARED albo MODULE ze wskazanych ĹşrĂłdeĹ
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
        test/master.cpp
        test/PlayTest.cpp test/HandTest.cpp test/BattlefieldTest.cpp test/PillarTest.cpp test/PlayerTest.cpp test/UnitTest.cpp test/PillarsArrayTest.cpp)

add_executable (LibraryTest ${SOURCE_TEST_FILES})

#doĹÄcz bibliotekÄ z testowanymi klasami oraz bibliotekÄ boost.test do programu testĂłw
target_link_libraries (LibraryTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestBiblioteki1. Instrukcji cmake add_test moĹźe byÄ wiele.
#Dodatkowe parametry wpĹywajÄ na szczegĂłĹowoĹÄ generowanego raportu. Standardowo znajduje siÄ on w Testing/Temporary.
add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})