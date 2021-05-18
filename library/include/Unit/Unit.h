//
// Created by student on 04.06.2020.
//

#ifndef TRUNK_UNIT_H
#define TRUNK_UNIT_H
#include <string>
#include <memory>
#include<exception>
#include "Play.h"
#include "Battlefield.h"
#include "Pillar/PillarsArray.h"
#include "Hand.h"
#include "Strategy.h"
#include "typedefs.h"

class UnitException : public std::logic_error
{
public:
    explicit UnitException(const std::string& what_arg) : std::logic_error(what_arg) {}
};

class Unit {
protected:
    int health;
    int attack_power;
    std::string ability;
    unsigned int position;
    bool on_board;
public:
    Unit( int position);

    Unit (int health, int attack_power, int position, bool on_board);

    virtual ~Unit();

    int getHealth() const;

    void setHealth(int health);

    int getPosition() const;

    void setPosition(unsigned int position);

    bool isOnBoard() const;

    void setOnBoard();

    int getAttackPower() const;

    const std::string &getAbility() const;

    virtual void attack(Play*);

    std::string get_unit_info();


};


#endif //TRUNK_UNIT_H