CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -MMD
EXEC = main
OBJECTS = main.o component.o decorator.o size.o coffee.o cup.o bucket.o soupbowl.o tinycup.o weecup.o cream.o sugar.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
