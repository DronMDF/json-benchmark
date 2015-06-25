
CXXFLAGS += -std=c++11 -O2 -g0 -ICelero/include -Lbuild/celero -Ijson_spirit

run:
	LD_PRELOAD=./build/celero/libcelero.so ./json-benchmark -g Parsing
	LD_PRELOAD=./build/celero/libcelero.so ./json-benchmark -g Generating

json-benchmark: json-benchmark.cpp
	g++ ${CXXFLAGS} json-benchmark.cpp -o json-benchmark -lcelero -ljsoncpp

celero:
	mkdir -p build/celero
	cd build/celero; cmake ../../Celero
	make -C build/celero

all: celero json-benchmark

