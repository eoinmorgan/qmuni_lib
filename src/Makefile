CXX=g++
CFLAGS=-c -g -Wall
LDFLAGS=-lPocoUtil -lPocoNet -lPocoFoundation 
SOURCES=qmuni.cpp net.cpp session_handler.cpp session_model.cpp net_cookie_jar.cpp conversation_model.cpp model.cpp conversation_collection.cpp
INC=../vendor/rapidjson/include
INC_PARAMS=$(INC:%=-I%)
OBJECTS=${SOURCES:.cpp=.o}
EXECUTABLE=qmuni

all: ${SOURCES} ${EXECUTABLE}

${EXECUTABLE}: ${OBJECTS}
	${CXX} ${LDFLAGS} ${OBJECTS} -o $@

.cpp.o:
	${CXX} ${INC_PARAMS} ${CFLAGS} $< -o $@

clean:
	rm -f *.o ${EXECUTABLE}

run: ${EXECUTABLE}
	./${EXECUTABLE}
