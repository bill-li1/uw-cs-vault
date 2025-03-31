#ifndef LIST_H
#define LIST_H

#include <cstddef>

struct List; /* forward declaration of type */

/*
 * Returns a pointer to an empty list of integers.
 */
struct List * createList();

/*
 * Destroys the contents of the list.
 */
void destroyList( struct List * list );

/*
 * Returns the number of elements in the list.
 */
size_t get_size( struct List * list );

/*
 * Adds the element to the end of the list.
 */
void add( struct List * list, int element );

/*
 * Removes the first occurrence of element from the list.
 */
void remove( struct List * list, int element );

/*
 * Returns the element at the specified index from the list.
 * Precondition: list must not be empty and 0 <= index < get_size( list )
 */
int get( struct List * list, size_t index );

/*
 * Outputs the contents of list to stdout.
 */
void print( struct List * list );

#endif
