//
// Created by student on 04.06.2020.
//

#include "Pillar/Pillar.h"
#include <string>
#include <sstream>


Pillar::Pillar(int position):position(position)  {
    if(position>4)
    {
        throw PillarException("This position doesn't exist");
    }

    health=15;


}
int Pillar::getHealth()
{
    return health;
}
void Pillar::setHealth(unsigned int new_health)
{
   // if(new_health==0) this->~Pillar();
    health=new_health;
}
std::string Pillar::getAbility()
{
    return ability;
}

std::string Pillar::getPillarInfo(){
    std::ostringstream sout;
    sout<<"Position: "<<getPosition()+1<<" ";
    sout<<"HP: "<<getHealth()<<" ";
    sout<<"Ability: "<<getAbility();
    return sout.str();
}

Pillar::~Pillar() {

}


int Pillar::getPosition() {
    return position;
}

Pillar::Pillar(int position, int health) : position(position), health(health){

}
