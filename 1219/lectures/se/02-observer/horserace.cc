#include <iostream>
#include "horserace.h"

HorseRace::HorseRace(std::string source): in{source} {}

HorseRace::~HorseRace() {}

bool HorseRace::runRace() {
  bool result {in >> lastWinner};

  if (result) std::cout << "Winner: " << lastWinner << std::endl;

  return result;
}

std::string HorseRace::getState() {
  return lastWinner;
}

