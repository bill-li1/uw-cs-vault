#include <iostream>
#include <fstream>
#include <string>

void usage( char * pgmname ) {
    std::cerr << pgmname << " [ input-file-name [output-file-name] ]" << std::endl;
} // usage

int main( int argc, char * argv[] ) {
    std::istream * infile = &std::cin;
    std::ostream * outfile = &std::cout;

    if ( argc > 3 || argc < 1 ) {
        usage( argv[0] );
        return 1;           
    } // if

    switch( argc ) {
        case 3:
            outfile = new std::ofstream{ argv[2] };
            if ( outfile == nullptr || outfile->fail() ) {
                std::cerr << "ERROR: unable to open output file \""
                    << argv[2] << '"' << std::endl;
                delete outfile;
                return 1;
            } // if
            // fall through to open up the input file next
        case 2:
            infile = new std::ifstream{ argv[1] };
            if ( infile == nullptr || infile->fail() ) {
                std::cerr << "ERROR: unable to open input file \""
                    << argv[1] << '"' << std::endl;
                delete infile;
                if ( outfile != &std::cout ) delete outfile;
                return 1;
            } // if
            break;
        default:
            // do nothing
            break;
    } // switch

    // Echoes the input to output.
    std::string line;
    while ( std::getline( *infile, line ) ) {
        *outfile << line << std::endl;
    } // while

    // Closes the I/O files. Don't delete if standard input or output, though.
    if ( infile != &std::cin ) delete infile;
    if ( outfile != &std::cout ) delete outfile;
} // main