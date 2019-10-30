simulator.o: simulator.cpp
	g++ -c simulator.cpp -o ../bin/simulator.o

decoder.o: decoder.cpp decoder.h
	g++ -c decoder.cpp -o ../bin/decoder.o

all: ../bin/simulator.o ../bin/decoder.o
	g++ ../bin/simulator.o ../bin/decoder.o -o ../bin/mips_simulator

testbench: mips_testbench.sh
	mv testbench.sh ../bin/mips_testbench.sh

clean:
	rm -f ../bin/*
