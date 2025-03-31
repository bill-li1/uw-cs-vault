#include <iostream>

int main() {
	for ( unsigned int i = 0; i < 10; i++ ) {
		if ( i % 2 == 0 ) 
			std::cout << i << ' ';
		else
			std::cerr << i << ' ';
	}
	std::cout << std::endl;
	std::cerr << std::endl;
}
