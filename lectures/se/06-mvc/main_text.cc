/*
 * MVC example - Text-based view
 *
 * Displays top card of sorted deck of cards. When the [N]ext command is given,
 * the next card is displayed as a text.  When the [R]eset command is
 * given, the top card of a full sorted deck is displayed
 *
 *  Created by Gustavo Tondello on 29/06/20 based on GTKmm version.
 *  Copyright 2009, 2017, 2020 UW. All rights reserved.
 *
 */


#include "model.h"
#include "controller.h"
#include "text_view.h"

int main( int argc, char * argv[] ) {
    Model      model;		                // Create model
    Controller controller( &model );        // Create controller
    TextView   view( &controller, &model ); // Create the view -- is passed handle to controller and model.
                                            // The view's constructor will start the UI
} // main
