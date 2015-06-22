
all json-benchmark:
	g++ -std=c++11 -O2 -g0 json-benchmark.cpp -o json-benchmark

celero:
	mkdir -p build/celero
	cd build/celero; cmake ../../Celero
	make -C build/celero
