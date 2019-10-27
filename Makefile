simulator: simulator.cpp
	# g++ -c -std=c++11 simulator.cpp
	g++ std=c++11 simulator.cpp -o /bin/mips_simulator
#
# all: simulator.o point.o
# 	g++ simulator.o point.o triangle.o -o prog

testbench: mips_testbench.sh
	mv testbench.sh /bin/mips_testbench.sh

run:
	./bin/mips_simulator

test:
	./bin/mips_testbench

clean:
	rm mips* /bin
