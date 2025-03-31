#include <iostream>

int main(int argc, char **argv) {
  for (int argi = 0; argi < argc; argi++) {
    std::cout << argv[argi] << std::endl;
  }
}
