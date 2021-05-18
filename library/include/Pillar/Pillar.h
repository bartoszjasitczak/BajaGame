//
// Created by student on 04.06.2020.
//

#ifndef GAMEBAJA_PILLAR_H
#define GAMEBAJA_PILLAR_H
#include <string>
#include <memory>
#include "typedefs.h"

class PillarException : public std::logic_error
{
public:
explicit PillarException(const std::string& what_arg) : std::logic_error(what_arg) {}
};

class Pillar {
protected:
    unsigned int health;
    std::string ability;
    int position;
public:
    int getHealth();
    void setHealth(unsigned int new_health);
    std::string getAbility();
    std::string getPillarInfo();
    Pillar(int position);
    Pillar(int position, int health);
    ~Pillar();
    int getPosition();
    virtual void defend(Play* play)=0;

};


#endif //GAMEBAJA_PILLAR_H
