CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = main
EXEC_BAD = main_exceptions
OBJECTS = main.o main_exceptions.o book.o text.o comic.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} $(filter-out main_exceptions.o, ${OBJECTS}) -o ${EXEC}
	${CXX} ${CXXFLAGS} $(filter-out main.o, ${OBJECTS}) -o ${EXEC_BAD}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${EXEC_BAD} ${DEPENDS}
