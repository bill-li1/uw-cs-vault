CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -MMD -fno-elide-constructors
EXEC = node
OBJECTS = main.o node.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
