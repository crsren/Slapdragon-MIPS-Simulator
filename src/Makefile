simulator: simulator.cpp
	g++ -std=c++11 -c simulator.cpp -o ../bin/simulator.o

decoder: decoder.cpp decoder.h
	g++ -std=c++11 -c decoder.cpp -o ../bin/decoder.o

helpers: helpers.cpp helpers.h
	g++ -std=c++11 -c helpers.cpp -o ../bin/helpers.o

memory: memory.cpp memory.h
	g++ -std=c++11 -c memory.cpp -o ../bin/memory.o

all: ../bin/simulator.o ../bin/decoder.o ../bin/helpers.o
	g++ ../bin/simulator.o ../bin/decoder.o ../bin/helpers.o ../bin/memory.o -o ../bin/mips_simulator

testbench: mips_testbench.sh
	mv testbench.sh ../bin/mips_testbench.sh

clean:
	rm -f ../bin/*
