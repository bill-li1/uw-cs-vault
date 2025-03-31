#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include "window.h"

const int Xwindow::MAX_NUM_COLOURS = 5; // Allocate the static constant space.

Xwindow::Xwindow(int width, int height) {
    d = XOpenDisplay( nullptr );
    if ( d == nullptr ) {
        std::cerr << "Cannot open display" << std::endl;
        exit(1);
    }
    s = DefaultScreen(d);
    w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1,
        BlackPixel(d, s), WhitePixel(d, s));
    XSelectInput(d, w, ExposureMask | KeyPressMask);
    XMapRaised(d, w);

    Pixmap pix = XCreatePixmap(d,w,width,height, DefaultDepth(d,DefaultScreen(d)));
    gc = XCreateGC(d, pix, 0,(XGCValues *) nullptr);

    XFlush(d);
    XFlush(d);

    // Set up colours.
    XColor xcolour;
    Colormap cmap;
    char color_vals[7][10] = { "white", "black", "red", "green", "blue" };

    cmap = DefaultColormap( d,DefaultScreen(d) );
    for ( int i = 0; i < Xwindow::MAX_NUM_COLOURS; ++i) {
        XParseColor(d, cmap, color_vals[i], &xcolour);
        XAllocColor(d, cmap, &xcolour);
        colours[i] = xcolour.pixel;
    }

    XSetForeground(d, gc, colours[static_cast<int>(Colour::Black)]);

    // Make window non-resizeable.
    XSizeHints hints;
    hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
    hints.height = hints.base_height = hints.min_height = hints.max_height = height;
    hints.width = hints.base_width = hints.min_width = hints.max_width = width;
    XSetNormalHints(d, w, &hints);
    XSynchronize(d,True);

    usleep(1000);
} // Xwindow::Xwindow

Xwindow::~Xwindow() {
    XFreeGC(d, gc);
    XCloseDisplay(d);
}

void Xwindow::fillRectangle(int x, int y, int width, int height, Xwindow::Colour colour) {
    XSetForeground(d, gc, colours[static_cast<int>(colour)]);
    XFillRectangle(d, w, gc, x, y, width, height);
    XSetForeground(d, gc, colours[static_cast<int>(Colour::Black)]);
}

void Xwindow::drawString(int x, int y, std::string msg) {
    XDrawString(d, w, DefaultGC(d, s), x, y, msg.c_str(), msg.length());
}

