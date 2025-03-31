#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <string>


class Xwindow {
    class XWindowImpl; // forward declaration
    XWindowImpl *pimpl;

 public:
    Xwindow(int width=500, int height=500);  // Displays the window.
    ~Xwindow();                              // Destroys the window.
    Xwindow(const Xwindow & ) = delete;      // Disallow copy and assignment.
    Xwindow &operator=( const Xwindow & ) = delete;

    static const int MAX_NUM_COLOURS; // Available colours.
    enum class Colour {White=0, Black, Red, Green, Blue}; 

    // Draws a rectangle
    void fillRectangle(int x, int y, int width, int height, Xwindow::Colour colour=Colour::Black);

    // Draws a string
    void drawString(int x, int y, std::string msg);
};

#endif
