#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv[] ) {
	fprintf( stderr, "goes to stderr\n" ); 
	fprintf( stdout, "goes to stdout\n" ); 
	int num;
	if ( argc > 1 )  {
		FILE * fptr;
		fptr = fopen( argv[1], "r" );
		if ( fptr == NULL ) {
			fprintf( stderr, "Failed to open file \"%s\"\n", argv[1] );
			return 1;
		}
		fscanf( fptr, "%d", &num );
		fclose( fptr );
	} else {
		printf( "Enter an integer: " );
		scanf( "%d", &num );
	}
	printf( "Read in %d\n", num );
	return 0;
}
