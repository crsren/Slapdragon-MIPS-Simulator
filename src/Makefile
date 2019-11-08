all:
	g++ $(VERSION) -c simulator.cpp -o ../bin/simulator.o
	g++ $(VERSION) -c decoder.cpp -o ../bin/decoder.o
	g++ $(VERSION) -c helpers.cpp -o ../bin/helpers.o
	g++ $(VERSION) -c memory.cpp -o ../bin/memory.o
	g++ ../bin/simulator.o ../bin/decoder.o ../bin/helpers.o ../bin/memory.o -o ../bin/mips_simulator

VERSION := -std=c++11

%.o: %.cpp %.h
	g++ $(VERSION) -c %.cpp -o ../bin/%.o

link: ../bin/simulator.o ../bin/decoder.o ../bin/helpers.o
	g++ ../bin/simulator.o ../bin/decoder.o ../bin/helpers.o ../bin/memory.o -o ../bin/mips_simulator




testbench: mips_testbench.sh
	mv testbench.sh ../bin/mips_testbench.sh

clean:
	rm -f ../bin/*
