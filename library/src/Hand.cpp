//
// Created by student on 04.06.2020.
//

#include "../include/Hand.h"
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <Unit/Archer.h>
#include <Unit/Medic.h>
#include <Unit/Thief.h>
#include <Unit/Warrior.h>
#include <Unit/Unit.h>
#include <iostream>
#include "../include/RandomCard.h"



Hand::Hand() {
    for(int i=0; i<5; i++)
    {
        cards[i]=this->random_card(i);
    }
}

Hand::~Hand() {

}

UnitPtr Hand::getCard(unsigned int card_number) {
    if(card_number>4)
    {
        throw HandException("This card doesn't exist");
    }
    return cards[card_number];
}

std::string Hand::getCardsInfo() {
    std::ostringstream sout;
    for(int i=0; i<5; i++)
    {
        if(cards[i]==nullptr) sout<<"Empty place"<<std::endl;
        else sout<<cards[i]->get_unit_info();
    }

    return sout.str();
}

void Hand::setCard(int i, UnitPtr newCard) {
    cards[i]=newCard;
    getCard(i)->setPosition(i);
}
void Hand::deleteCard(int i) {
    cards[i]=nullptr;
}

Hand::Hand(UnitPtr *tab) {
    for(int i=0; i<5; i++)
    {
        cards[i]=tab[i];
    }

}