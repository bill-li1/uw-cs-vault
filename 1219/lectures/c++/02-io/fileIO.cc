#include <fstream>

int main() {
    std::ifstream infile{ "input.txt" };
    std::ofstream outfile{ "output.txt" };
    int i;
    while ( true ) {
        infile >> i;
        if ( infile.fail() ) break;
        outfile << i << std::endl;
    }
}
