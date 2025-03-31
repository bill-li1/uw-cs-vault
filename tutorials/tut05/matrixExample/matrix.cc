#include <iostream>
#include <iomanip>
using namespace std;

struct Matrix {
   unsigned int rows, cols; // eventually these should be hidden/encapsulated
   float ** data;

   Matrix();
   Matrix( unsigned int rows, unsigned int cols );
   ~Matrix();
   unsigned int getRows() const;
   unsigned int getCols() const;
   void resize( unsigned int newRows, unsigned int newCols );
   void set( unsigned int row, unsigned int col, float value );
   float get( unsigned int row, unsigned int col ) const;
   Matrix operator+( const Matrix & other ) const;

   // helper methods--eventually, we'd like to hide/encapsulate these
   void init();
   void init( unsigned int newRows, unsigned int newCols );
   void destroy();
};


ostream & operator<<( ostream & out, const Matrix & m );
istream & operator>>( istream & in, Matrix & m );

int main() {
    Matrix m;
    cout << m;
    cin >> m;
    cout << m;
    Matrix m1{3, 4}, m2{2, 6};
    m2.resize( 3, 4 );
    cin >> m1 >> m2;
    cout << "m1 =\n" << m1 << "\nm2 =\n" << m2 << endl;
    cout << "m1 + m2 = \n" << m1 + m2 
        << "\nm + m1 =\n" << m + m1 << endl;
}

Matrix::Matrix() { init(); }
Matrix::Matrix( unsigned int newRows, unsigned int newCols ) { init( newRows, newCols ); }
Matrix::~Matrix() { destroy(); }
unsigned int Matrix::getRows() const { return rows; }
unsigned int Matrix::getCols() const { return cols; }

void Matrix::init() {
    rows = cols = 0;
    data = nullptr;
}

void Matrix::resize( unsigned int newRows, unsigned int newCols ) {
    destroy();
    init( newRows, newCols );
}

void Matrix::set( unsigned int row, unsigned int col, float value ) {
    data[row][col] = value;
}

float Matrix::get( unsigned int row, unsigned int col ) const {
    return data[row][col];
}

void Matrix::init( unsigned int newRows, unsigned int newCols ) {
    rows = newRows;
    cols = newCols;
    data = new float*[rows];
    for ( unsigned int i = 0; i < rows; i++ ) {
        data[i] = new float[cols];
        for ( unsigned int j = 0; j < cols; j++ ) {
            data[i][j] = 0.0;
        }
    }
}

void Matrix::destroy() {
    for ( unsigned int i = 0; i < rows; i++ ) {
        delete [] data[i];
    }
    delete [] data;
}

Matrix Matrix::operator+( const Matrix & other ) const {
    Matrix result;
    if ( rows != other.rows || cols != other.cols ) return result;
    result.resize( rows, cols );
    for ( unsigned int i = 0; i < rows; i++ ) {
        for ( unsigned int j = 0; j < cols; j++ ) {
            result.set(i, j, data[i][j] + other.data[i][j] );
        }
    }
    return result;
}

ostream & operator<<( ostream & out, const Matrix & m ) {
    ios::fmtflags oldSettings = out.flags(); //save previous format flags
    out.setf(ios::fixed, ios::floatfield);   // set fixed floating format 
    out.precision(4);                        // for fixed format, 4 decimal places  
    out << '[' << ( m.getRows() > 0 ? "\n" : "" );
    for ( unsigned int i = 0; i < m.getRows(); i++ ) {
        for ( unsigned int j = 0; j < m.getCols(); j++ ) {
            // for each number, set the width to 8 characters and use a space to "fill"
            out << ' ' << setw(8) << setfill( ' ' ) << m.get( i, j );
        }
        out << '\n';
    }
    out << "]\n";
    out.flags(oldSettings); // reset the format back to the default
    return out;
}

istream & operator>>( istream & in, Matrix & m ) {
    unsigned int rows, cols;
    float value;
    in >> rows >> cols;
    if ( rows != m.getRows() || cols != m.getCols() ) m.resize( rows, cols );
    for ( unsigned int i = 0; i < rows; i++ ) {
        for ( unsigned int j = 0; j < cols; j++ ) {
            in >> value;
            m.set(i, j, value );
        }
    }
    return in;
}
