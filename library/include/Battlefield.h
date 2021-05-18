//
// Created by student on 04.06.2020.
//

#ifndef TRUNK_BATLLEFIELD_H
#define TRUNK_BATLLEFIELD_H

#include "Unit/Unit.h"
#include <exception>

class BattlefieldException : public std::logic_error
{
public:
    explicit BattlefieldException(const std::string& what_arg) : std::logic_error(what_arg) {}
};

class Battlefield {
public:
    Battlefield();

    Battlefield(UnitPtr tab[]);

    virtual ~Battlefield();

    UnitPtr getCard(int);
    std::string getCardsInfo();
    void putCard(int,UnitPtr);

    void deleteCard(int);


private:
    UnitPtr cards[5];

};


#endif //TRUNK_BATLLEFIELD_H
