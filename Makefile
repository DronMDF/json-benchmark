
CXXFLAGS += -std=c++11 -O2 -g0 -ICelero/include -Lbuild/celero

run:
	LD_PRELOAD=./build/celero/libcelero.so ./json-benchmark

json-benchmark:
	g++ ${CXXFLAGS} json-benchmark.cpp -o json-benchmark -lcelero

celero:
	mkdir -p build/celero
	cd build/celero; cmake ../../Celero
	make -C build/celero

all: celero json-benchmark

