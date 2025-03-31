#include <iostream>
#include <iomanip>
using namespace std;

struct Matrix {
   unsigned int rows, cols;
   float ** data;
};

void initMatrix( Matrix & m ) {
	m.rows = m.cols = 0;
	m.data = nullptr;
}

void destroyMatrix( Matrix & m ) {
	for ( unsigned int i = 0; i < m.rows; i++ ) {
		delete [] m.data[i];
	}
	initMatrix( m );
}

ostream & operator<<( ostream & out, const Matrix & m ) {
	ios::fmtflags oldSettings = out.flags(); //save previous format flags
	out.setf(ios::fixed, ios::floatfield);   // set fixed floating format 
	out.precision(4);                        // for fixed format, 4 decimal places 	
	out << '[' << ( m.rows > 0 ? "\n" : "" );
	for ( unsigned int i = 0; i < m.rows; i++ ) {
		for ( unsigned int j = 0; j < m.cols; j++ ) {
			// for each number, set the width to 8 characters and use a space to "fill"
			out << ' ' << setw(8) << setfill( ' ' ) << m.data[i][j];
		}
		out << '\n';
	}
	out << "]\n";
	out.flags(oldSettings); // reset the format back to the default
	return out;
}

istream & operator>>( istream & in, Matrix & m ) {
	in >> m.rows >> m.cols;
	m.data = new float*[m.rows];
	for ( unsigned int i = 0; i < m.rows; i++ ) {
		m.data[i] = new float[m.cols];
		for ( unsigned int j = 0; j < m.cols; j++ ) {
			in >> m.data[i][j];
		}
	}
	return in;
}

int main() {
	Matrix m;
	initMatrix( m );
	cout << m;
	cin >> m;
	cout << m;
	destroyMatrix( m );
}
