//
// Created by student on 04.06.2020.
//

#ifndef GAMEBAJA_REDPILLAR_H
#define GAMEBAJA_REDPILLAR_H
#include "Pillar.h"

class RedPillar : public Pillar{
public:
    RedPillar(int position);
    RedPillar(int position, int health);

    virtual ~RedPillar();
    virtual void defend(Play* play) override;


};


#endif //GAMEBAJA_REDPILLAR_H