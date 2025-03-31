#include <iostream>
#include "window.h"

using namespace std;

int main() {
    Xwindow w;

    w.fillRectangle(100, 200, 50, 250, Xwindow::Blue);
    w.drawString(50, 50, "Hello!");

    bool done = false;
    while ( ! done ) {
        XEvent event;
        XNextEvent( w.getDisplay(), &event);

        switch (event.type) {
            case KeyPress: {
                char c;
                cin >> c;
                if ( c == 'q' ) done = true;
                cout << "read in: " << c << endl;     
            }
            break;

            case ClientMessage:
                done = true;
                break;

            case Expose: 
                // window was moved/maximized, so redraw
                w.fillRectangle(100, 200, 50, 250, Xwindow::Blue);
                w.drawString(50, 50, "Hello!");

            // NO DEFAULT
        } // switch
    } // while
}

