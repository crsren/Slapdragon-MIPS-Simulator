simulator: simulator.cpp
	mkdir bin
	g++ simulator.cpp -o ./bin/mips_simulator

testbench: mips_testbench.sh
	mv testbench.sh /bin/mips_testbench.sh

run:
	./bin/mips_simulator

test:
	./bin/mips_testbench

clean:
	rm -rf ./bin
