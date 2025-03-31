CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g
EXEC = tictac
OBJECTS = main.o tictac.o undo_manager.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
