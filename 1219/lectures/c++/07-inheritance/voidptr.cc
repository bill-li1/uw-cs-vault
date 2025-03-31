#include <iostream>

struct Element {
    void * data;
    char dataType;
};

int main() {
    Element elems[3];
    int * iptr;
    char * cptr;
    float * fptr;

    elems[0].data = (void *) new int{-1};
    elems[0].dataType = 'i';
    elems[1].data = (void *) new char{'x'};
    elems[1].dataType = 'c';
    elems[2].data = (void *) new float{3.14159};
    elems[2].dataType = 'f';
    
    for ( int i = 0; i < 3; ++i ) {
        switch( elems[i].dataType ) {
            case 'i':
                iptr = (int*) elems[i].data;
                std::cout << *iptr << std::endl;
                break;
            case 'f' :
                fptr = (float*) elems[i].data;
                std::cout << *fptr << std::endl;
                break;
            case 'c':
                cptr = (char*) elems[i].data;
                std::cout << *cptr << std::endl;
                break;
        } // switch
    } // for
} // main