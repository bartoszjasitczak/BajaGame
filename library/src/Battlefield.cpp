//
// Created by student on 04.06.2020.
//

#include "../include/Battlefield.h"
#include <sstream>

Battlefield::Battlefield() {
    for(int i=0; i<5; i++)
    {
        cards[i]= nullptr;
    }
}

Battlefield::~Battlefield() {

}

UnitPtr Battlefield::getCard(int card_number) {
    if(card_number>4)
    {
        throw BattlefieldException ("This card doesn't exist");
    }
    return cards[card_number];
}

std::string Battlefield::getCardsInfo() {
    std::ostringstream sout;
    for(int i=0; i<5; i++)
    {
        if(cards[i]==nullptr) sout<<"Empty place"<<std::endl;
        else sout<<cards[i]->get_unit_info();
    }

    return sout.str();
}

void Battlefield::putCard(int position, UnitPtr unit) {
    if(position>4)
    {
        throw BattlefieldException("Position doesn't exist");
    }
    cards[position]=unit;
    cards[position]->setOnBoard();
    cards[position]->setPosition(position);
    //unit->Unit::~Unit();
    return;

}


void Battlefield::deleteCard(int i) {
    cards[i]=nullptr;
}

Battlefield::Battlefield(UnitPtr *tab) {
    for(int i=0; i<5; i++)
    {
        cards[i]=tab[i];
    }

}

