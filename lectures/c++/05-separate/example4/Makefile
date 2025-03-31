CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g
EXEC = myprogram
OBJECTS = main.o linalg.o vec.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
