CXX=g++
CFLAGS=-c -g -Wall -arch x86_64
LDFLAGS=-lcurl -arch x86_64
SOURCES=main.cpp http.cpp
OBJECTS=${SOURCES:.cpp=.o}
EXECUTABLE=main

all: ${SOURCES} ${EXECUTABLE}
	clang -arch x86_64 -dynamiclib http.cpp -current_version 1.0 -compatibility_version 1.0 -fvisibility=hidden -o libHttp.0.dylib

${EXECUTABLE}: ${OBJECTS}
	${CXX} ${LDFLAGS} ${OBJECTS} -o $@

.cpp.o:
	${CXX} ${CFLAGS} $< -o $@ 

clean:
	rm -fr *.o ${EXECUTABLE}

run: ${EXECUTABLE}
	./${EXECUTABLE}

