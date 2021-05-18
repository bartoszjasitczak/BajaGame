//
// Created by student on 04.06.2020.
//

#ifndef TRUNK_HAND_H
#define TRUNK_HAND_H


#include "typedefs.h"
#include <exception>
#include "RandomCard.h"

class HandException : public std::logic_error
{
public:
    explicit HandException(const std::string& what_arg) : std::logic_error(what_arg) {}
};


class Hand : public RandomCard{
public:
    Hand();

    Hand(UnitPtr tab[]);

    virtual ~Hand();

    UnitPtr getCard(unsigned int);

    void setCard(int, UnitPtr);

    std::string getCardsInfo();

    void deleteCard(int);


private:
    UnitPtr cards[5];

};


#endif //TRUNK_HAND_H