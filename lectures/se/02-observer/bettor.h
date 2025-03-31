#ifndef __BETTOR_H__
#define __BETTOR_H__
#include "observer.h"
#include "horserace.h"

class Bettor: public Observer {
  HorseRace *subject;
  const std::string name;
  const std::string myHorse;

 public:
  Bettor( HorseRace *hr, std::string name, std::string horse );
  void notify() override;
  ~Bettor();
};

#endif
