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


#ifndef MVC_TEXT_VIEW_H
#define MVC_TEXT_VIEW_H

#include "observer.h"

class Controller;
class Model;


class TextView : public Observer {
  public:
    TextView( Controller*, Model* );
    virtual ~TextView();
    virtual void update();	// Observer Pattern: concrete update() method

  private:
    // Observer Pattern: to access Model accessors without having to downcast subject
    Model *model_;
	
    // Strategy Pattern member (plus signal handlers)
    Controller *controller_;

    // User input:
    void nextCommand();
}; // View

#endif
