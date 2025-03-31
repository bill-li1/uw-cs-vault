a3q2: a3q2.o polynomial.o
		g++-11 a3q2.o polynomial.o rational.o -o myProgram

a3q2.o: a3q2.cc
		g++-11 -c a3q2.cc

polynomial.o: polynomial.cc polynomial.h rational.h
		g++-11 -c polynomial.cc
