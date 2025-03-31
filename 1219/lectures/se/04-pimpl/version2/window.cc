#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include "window.h"

const int Xwindow::MAX_NUM_COLOURS = 5; // Allocate the static constant space.

struct XWindowImpl {
    Display *d;
    Window w;
    int s;
    GC gc;
    unsigned long colours[10];
};

Xwindow::Xwindow(int width, int height) : pimpl{new XWindowImpl} {
    pimpl->d = XOpenDisplay( nullptr );
    if ( pimpl->d == nullptr ) {
        std::cerr << "Cannot open display" << std::endl;
        exit(1);
    }
    pimpl->s = DefaultScreen(pimpl->d);
    pimpl->w = XCreateSimpleWindow(pimpl->d, RootWindow(pimpl->d, pimpl->s), 10, 10, width, height, 1,
        BlackPixel(pimpl->d, pimpl->s), WhitePixel(pimpl->d, pimpl->s));
    XSelectInput(pimpl->d, pimpl->w, ExposureMask | KeyPressMask);
    XMapRaised(pimpl->d, pimpl->w);

    Pixmap pix = XCreatePixmap(pimpl->d, pimpl->w, width,height, 
        DefaultDepth(pimpl->d,DefaultScreen(pimpl->d)));
    pimpl->gc = XCreateGC(pimpl->d, pix, 0,(XGCValues *) nullptr);

    XFlush(pimpl->d);
    XFlush(pimpl->d);

    // Set up colours.
    XColor xcolour;
    Colormap cmap;
    char color_vals[7][10] = { "white", "black", "red", "green", "blue" };

    cmap = DefaultColormap( pimpl->d, DefaultScreen(pimpl->d) );
    for ( int i = 0; i < Xwindow::MAX_NUM_COLOURS; ++i) {
        XParseColor(pimpl->d, cmap, color_vals[i], &xcolour);
        XAllocColor(pimpl->d, cmap, &xcolour);
        pimpl->colours[i] = xcolour.pixel;
    }

    XSetForeground(pimpl->d, pimpl->gc, pimpl->colours[static_cast<int>(Colour::Black)]);

    // Make window non-resizeable.
    XSizeHints hints;
    hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
    hints.height = hints.base_height = hints.min_height = hints.max_height = height;
    hints.width = hints.base_width = hints.min_width = hints.max_width = width;
    XSetNormalHints(pimpl->d, pimpl->w, &hints);
    XSynchronize(pimpl->d,True);

    usleep(1000);
} // Xwindow::Xwindow

Xwindow::~Xwindow() {
    XFreeGC(pimpl->d, pimpl->gc);
    XCloseDisplay(pimpl->d);
    delete pimpl;
}

void Xwindow::fillRectangle(int x, int y, int width, int height, Xwindow::Colour colour) {
    XSetForeground(pimpl->d, pimpl->gc, pimpl->colours[static_cast<int>(colour)]);
    XFillRectangle(pimpl->d, pimpl->w, pimpl->gc, x, y, width, height);
    XSetForeground(pimpl->d, pimpl->gc, pimpl->colours[static_cast<int>(Colour::Black)]);
}

void Xwindow::drawString(int x, int y, std::string msg) {
    XDrawString(pimpl->d, pimpl->w, DefaultGC(pimpl->d, pimpl->s), x, y, msg.c_str(), msg.length());
}

