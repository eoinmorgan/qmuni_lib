CXX=g++
CFLAGS=-c -g -Wall
LDFLAGS=-lPocoUtil -lPocoNet -lPocoFoundation 
SOURCES=qmuni.cpp net.cpp session_handler.cpp session_model.cpp json_parser.cpp
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
