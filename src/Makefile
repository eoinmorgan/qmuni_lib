CXX=g++
CFLAGS=-c -g -Wall
LDFLAGS=-lPocoUtil -lPocoNet -lPocoFoundation
SOURCES=qmuni.cpp session_handler.cpp
OBJECTS=${SOURCES:.cpp=.o}
EXECUTABLE=qmuni

all: ${SOURCES} ${EXECUTABLE}

${EXECUTABLE}: ${OBJECTS}
	${CXX} ${LDFLAGS} ${OBJECTS} -o $@

.cpp.o:
	${CXX} ${CFLAGS} $< -o $@

clean:
	rm -f *.o ${EXECUTABLE}

run: ${EXECUTABLE}
	./${EXECUTABLE}
