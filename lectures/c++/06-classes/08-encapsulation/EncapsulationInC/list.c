#include "list.h"
#include <stdlib.h>
#include <cassert>
#include <cstdio>

typedef struct node {
    int value;
    struct node * next;
} Node;

struct List {
    size_t size;
    Node * head, *tail;
} List;

Node * createNode( int value ) {
    Node * ptr = (Node*) malloc( sizeof( Node ) );
    assert( ptr != NULL );
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

void zeroList( struct List * list ) {
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

struct List * createList() {
    struct List * list = (struct List*) malloc( sizeof(struct List) );
    zeroList( list );
    return list;
}

void destroyList( struct List * list ) {    
    Node * next = NULL;
    for ( Node * ptr = list->head; ptr != NULL; ptr = next ) {
        next = ptr->next;
        free( ptr );
    }
    zeroList( list );
} /* destroyList */

size_t get_size( struct List * list ) { return list->size; }

void add( struct List * list, int element ) {
    Node * ptr = createNode( element );
    if ( list->size == 0 ) {
        list->head = ptr;
    } else {
        list->tail->next = ptr;
    }
    list->tail = ptr;
    list->size += 1;
} /* add */

void remove( struct List * list, int element ) {
    /* Empty list so return immediately. */
    if ( list->size == 0 ) return;

    /* Single-element list and removing only element. */
    if ( list->size == 1 && list->head->value == element ) {
        free( list->head );
        zeroList( list );
        return;
    }  /* if */

    /* At least one element, and it's at the head of the list. */
    if ( list->head->value == element ) {
        Node * tmp = list->head;
        list->head = tmp->next;
        free( tmp );
        list->size -= 1;
        return;
    } /* if */

    Node * prev = list->head;
    for ( Node * ptr = prev->next; ptr != NULL; prev = ptr, ptr = ptr->next ) {
        if ( ptr->value == element ) {
            Node * tmp = ptr;
            prev->next = ptr->next;
            free( tmp );
            list->size -= 1;
            if ( ptr == list->tail ) { /* Are we removing the last element? */
                list->tail = prev;
            }
            return;
        } /* if */
    } /* for */
} /* remove */

int get( struct List * list, size_t index ) {
    size_t i = 0;
    for ( Node * ptr = list->head; ptr != NULL && i < list->size; ptr = ptr->next ) {
        if ( i == index ) { return ptr-> value; }
        i += 1;
    }
    return 0; /* should never be reached if preconditions met */
}

void print( struct List * list ) {
    printf( "{" );
    for ( Node * ptr = list->head; ptr != NULL; ptr = ptr->next ) {
        if ( ptr == list->tail ) {
            printf( "%d", ptr->value );
        } else {
            printf( "%d, ", ptr->value );
        } /* if */
    } /* for */
    printf( "}\n" );
} /* print */
