/*
 * MVC example - Text-based view
 *
 * View class.  Is responsible for for displaying the top card of the deck
 * in text format and asking for user input from stdin.
 *
 *  Created by Gustavo Tondello on 29/06/20 based on GTKmm version.
 *  Copyright 2009, 2017, 2020 UW. All rights reserved.
 *
 */


#include "observer.h"
#include "text_view.h"
#include "controller.h"
#include "model.h"
#include "subject.h"
#include <iostream>
#include <string>

const std::string face_names[] = { "NINE", "TEN", "JACK", "QUEEN", "KING", "ACE", "NOFACE" };
const std::string suit_names[] = { "DIAMONDS", "CLUBS", "HEARTS", "SPADES", "NOSUIT" };


// Creates buttons with labels. Sets butBox elements to have the same size, 
// with 10 pixels between widgets
TextView::TextView(Controller *c, Model *m) : model_{m}, controller_{c}
{
    std::cout << "CS246 MVC example" << std::endl;
	
    // Register view as observer of model.
    model_->subscribe(this);

    // Display initial view
    update();
} // View::View

TextView::~TextView() {}


void TextView::update() {
    Suits suit = model_->suit();
    Faces face = model_->face();
    std::cout << "Current card: ";
    if ( suit == NOSUIT ) 
		std::cout << "NO CARD";
    else
		std::cout << face_names[face] << " of " << suit_names[suit];
    std::cout << std::endl;
    nextCommand();
}

void TextView::nextCommand() {
    std::cout << "Command: [N]ext card, [R]eset, [Q]uit? ";
    char c;
    std::cin >> c;
    if (c == 'N' || c == 'n') {
        controller_->nextButtonClicked();
    } else if (c == 'R' || c == 'r') {
        controller_->resetButtonClicked();
    } else {
        // let program terminate
    }
} // View::nextCommand
