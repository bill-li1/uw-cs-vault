#include "component.h"
#include "decorator.h"
#include "bucket.h"
#include "coffee.h"
#include "cream.h"
#include "cup.h"
#include "size.h"
#include "soupbowl.h"
#include "sugar.h"
#include "tinycup.h"
#include "weecup.h"
#include <iostream>

Cup * getCupSize();
void getSugar( Component *& c );
void getCream( Component *& c );
void getCoffee( Component *& c );

int main() {
    while (true) {
        char c;
        std::cout << "Do you wish to order some coffee? (y/n)" << std::endl;
        std::cin >> c;
        if ( std::cin.eof() || c == 'n' ) break;
        if ( c != 'y' ) continue;

        Component * order = getCupSize();
        getSugar( order );
        getCream( order );
        getCoffee( order );
        std::cout << "You have ordered: " << order->description() << "\n"
            << "The cost will be $" << order->price() << std::endl;
        delete order;
    } // while

} // main

Cup * getCupSize() {
    std::string size;
    std::cout << "Which cup size would you like? (w/wee/t/tiny/s/soupbowl/b/bucket)" << std::endl;
    while ( true ) {
        std::cin >> size;
        if ( size == "w" || size == "wee" ) return new WeeCup;
        if ( size == "t" || size == "tiny" ) return new TinyCup;
        if ( size == "s" || size == "soupbowl" ) return new SoupBowlCup;
        if ( size == "b" || size == "bucket" ) return new BucketCup;
    }
}

void getSugar( Component *& c ) {
    unsigned int sugars;
    std::cout << "How many sugars would you like? (0..N)" << std::endl;
    std::cin >> sugars;
    if ( sugars > 0 ) {
        c = new Sugar( sugars, c );
    }
}

void getCream( Component *& c ) {
    unsigned int cream;
    std::cout << "How many cream would you like? (0..N)" << std::endl;
    std::cin >> cream;
    if ( cream > 0 ) {
        c = new Cream( cream, c );
    }
}

void getCoffee( Component *& c ) {
    char ch;
    std::cout << "Would you like your coffee decaf? (y/n)" << std::endl;
    while (true) {
        std::cin >> ch;
        if ( ch == 'n' || ch == 'y' ) break;
    }
    if ( ch == 'y' ) c = new Coffee{ c, true };
    else c = new Coffee{ c };
}
