DIST_PATH=dist
PROJECT="4D Plugin.xcodeproj"
EXECUTABLE=main

all:
	cp -r src wrappers/4d_mac/testPlugin
	cd wrappers && make


	 

dist:
	@mkdir -p ${DIST_PATH}
	cd src && make
	@cp src/${EXECUTABLE} ${DIST_PATH}/${EXECUTABLE}

run:
	cd src && make run

clean:
	cd src && make clean
	cd wrapper && make clean
	@rm -fr ${DIST_PATH}

