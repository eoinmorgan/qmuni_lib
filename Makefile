DIST_PATH=dist
EXECUTABLE=main

all:
	cd src && make

dist:
	@mkdir -p ${DIST_PATH}
	cd src && make
	@cp src/${EXECUTABLE} ${DIST_PATH}/${EXECUTABLE}

run:
	cd src && make run

clean:
	cd src && make clean
	@rm -fr ${DIST_PATH}

