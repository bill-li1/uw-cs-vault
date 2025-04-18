#ifndef STUDIO_H
#define STUDIO_H
#include <iostream>
class AsciiArt;

class Studio {
  int rows = 10, cols = 10, ticks = 0;
  std::ostream &out = std::cout;

  AsciiArt *thePicture;

 public:
  explicit Studio(AsciiArt *picture): thePicture{picture} {}

  AsciiArt *&picture() { return thePicture; }
  void reset();
  void render();
	void createBox(int top, int bottom, int left, int right, char what, char type, char dir);
  void animate(int numTicks);
  ~Studio();
};

#endif
