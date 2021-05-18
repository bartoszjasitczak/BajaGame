//
// Created by student on 04.06.2020.
//

#ifndef GAMEBAJA_PILLARSARRAY_H
#define GAMEBAJA_PILLARSARRAY_H

#include "Pillar.h"
#include <string>

class PillarsArrayException : public std::logic_error
{
public:
    explicit PillarsArrayException(const std::string& what_arg) : std::logic_error(what_arg) {}
};

class PillarsArray {
private:
    PillarPtr wall_of_pillars[5];
public:
    std::string getPillarsInfo();
    PillarPtr getPillar(int);
    PillarsArray();
    PillarsArray(PillarPtr pillars[]);
    ~PillarsArray();
    void deletePillar(int i);

};


#endif //GAMEBAJA_PILLARSARRAY_H