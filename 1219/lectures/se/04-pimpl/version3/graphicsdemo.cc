#include <iostream>
#include "window.h"

int main() {
    Xwindow w;

    for (int i = 0 ; i < Xwindow::MAX_NUM_COLOURS; i++) {
        w.fillRectangle(50 * i, 200, 50, 250, static_cast<Xwindow::Colour>(i));
    }

    w.drawString(50, 50, "Hello!");
    w.drawString(50, 100, "ABCD");
    w.drawString(50, 150, "Hello!");

    Xwindow w2(199, 199);
    w2.drawString(50, 100, "ABCD");

    //w.showAvailableFonts();

    // Wait for a character to be read from stdin; otherwise, the windows will be
    // immediately destroyed.
    char c;
    std::cin >> c;
}
