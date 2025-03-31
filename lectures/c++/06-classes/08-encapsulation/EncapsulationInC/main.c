#include "list.h"
#include <cstddef>
#include <cstdio>

int main() {
    struct List * list1 = createList();
    print( list1 );
    for ( size_t i = 1; i < 6; i++ ) add( list1, 1 );
    print( list1 );
    printf( "size of list1 = %lu\n", get_size( list1 ) );
    printf( "list1[3] = %d\n", get( list1, 3 ) );
    remove( list1, 6 );
    for ( size_t i = 1; i < 6; i++ ) {
        remove( list1, 1 );
        print( list1 );
    }

    struct List * list2 = createList();
    for ( int i = -3; i < 4; i++ ) add( list2, i );
    print( list2 );
    printf( "size of list2 = %lu\n", get_size( list2 ) );
    printf( "list2[3] = %d\n", get( list2, 3 ) );
    remove( list2, -3 );
    remove( list2, 3 );
    remove( list2, 0 );
    print( list2 );

    struct List * list3 = createList();
    print( list3 );

    destroyList( list1 );
    destroyList( list2 );
    destroyList( list3 );
}
