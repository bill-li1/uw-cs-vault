#include <string>
#ifndef SIZE_H
#define SIZE_H

enum class Size { Wee, Tiny, SoupBowl, Bucket };

std::string convert( Size s );
Size convert( std::string s );

#endif
