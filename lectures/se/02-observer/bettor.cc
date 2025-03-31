#include <iostream>
#include "bettor.h"

Bettor::Bettor( HorseRace *hr, std::string name, std::string horse )
    : subject{hr}, name{name}, myHorse{horse} 
{
  subject->attach( this );
}

Bettor::~Bettor() {
  subject->detach( this );
}

void Bettor::notify() {
  std::cout << name 
    << (subject->getState() == myHorse ? " wins! Off to collect." : " loses.") 
    << std::endl;
}

