simulator: simulator.cpp
	g++ -c simulator.cpp -o ../bin/simulator.o

decoder: decoder.cpp decoder.h
	g++ -c decoder.cpp -o ../bin/decoder.o

helpers: helpers.cpp helpers.h
	g++ -c helpers.cpp -o ../bin/helpers.o

all: ../bin/simulator.o ../bin/decoder.o ../bin/helpers.o
	g++ ../bin/simulator.o ../bin/decoder.o ../bin/helpers.o -o ../bin/mips_simulator

testbench: mips_testbench.sh
	mv testbench.sh ../bin/mips_testbench.sh

clean:
	rm -f ../bin/*
