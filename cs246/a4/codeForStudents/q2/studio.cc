#include "studio.h"
#include "asciiart.h"

void Studio::reset() { ticks = 0; }

void Studio::render() {
  out << '+';
  for (int j = 0; j < cols; ++j) out << '-';
  out << '+' << std::endl;
  for (int i = 0; i < rows; ++i) {
    out << '|';
    for (int j = 0; j < cols; ++j) {
      out << picture()->charAt(i, j, ticks);
    }
    out << '|' << std::endl;
  }
  out << '+';
  for (int j = 0; j < cols; ++j) out << '-';
  out << '+' << std::endl;
  ++ticks;
}

void Studio::animate(int numTicks) {
  for (int i = 0; i < numTicks; ++i) render();
}

void Studio::createBox(int top, int bottom, int left, int right, char what, char type, char dir) {
	thePicture = new Box();
}

Studio::~Studio() { delete thePicture; }
