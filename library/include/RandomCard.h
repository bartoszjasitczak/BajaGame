//
// Created by student on 14.06.2020.
//

#ifndef GAMEBAJA_RANDOMCARD_H
#define GAMEBAJA_RANDOMCARD_H

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include "typedefs.h"


class RandomCard {
public:
    UnitPtr random_card(int position);
};


#endif //GAMEBAJA_RANDOMCARD_H