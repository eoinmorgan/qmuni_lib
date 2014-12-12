DIST_PATH=dist
PROJECT="4D Plugin.xcodeproj"
EXECUTABLE=main

all:
	cd Wrappers && make


	 

dist:
	@mkdir -p ${DIST_PATH}
	cd src && make
	@cp src/${EXECUTABLE} ${DIST_PATH}/${EXECUTABLE}

run:
	cd src && make run

clean:
	cd src && make clean
	cd Wrappers && make clean
	@rm -fr ${DIST_PATH}

