#include "size.h"
#include <iostream>
#include <stdexcept>

std::string convert( Size s ) {
    switch( s ) {
        case Size::Wee:
            return std::string{ "Wee" };
            break;
        case Size::Tiny:
            return std::string{ "Tiny" };
            break;
        case Size::SoupBowl:
            return std::string{ "SoupBowl" };
            break;
        case Size::Bucket:
            return std::string{ "Bucket" };
            break;
        default:
            std::cerr << "should never see this" << std::endl;
            break;
    }
    return std::string{ "invalid size" };
}

Size convert( std::string s ) {
    if ( s == "Wee" ) return Size::Wee;
    if ( s == "Tiny" ) return Size::Tiny;
    if ( s == "SoupBowl" ) return Size::SoupBowl;
    if ( s == "Bucket" ) return Size::Bucket;
    return Size::Bucket; // throw std::range_error{ s };
}
