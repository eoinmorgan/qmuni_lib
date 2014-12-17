CXX=g++
CFLAGS=-c -g -Wall
LDFLAGS=-lPocoUtil -lPocoNet -lPocoFoundation
SOURCES=main.cpp
OBJECTS=${SOURCES:.cpp=.o}
EXECUTABLE=main

all: ${SOURCES} ${EXECUTABLE}

${EXECUTABLE}: ${OBJECTS}
	${CXX} ${LDFLAGS} ${OBJECTS} -o $@

.cpp.o:
	${CXX} ${CFLAGS} $< -o $@

clean:
	rm -f *.o ${EXECUTABLE}

run: ${EXECUTABLE}
	./${EXECUTABLE}

