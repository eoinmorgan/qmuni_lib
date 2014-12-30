DIST_PATH=dist
PROJECT="4D Plugin.xcodeproj"
EXECUTABLE=main

all:
	cd src && make clean run
	cp -r src wrapper/plugin_4d_mac/qmuni/src
	cd wrapper && make


	 

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

