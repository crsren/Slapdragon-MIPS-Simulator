#for testing, incomplete as formal makefile

CC := g++ -std=c++11
CPPFLAGS := -W -Wall

#mips linux gnu stuff !!!

PRG_SRC := $(wildcard ./src/*.cpp)

.PHONY: o $(PRG_SRC)

#create object file for all source files, then move them to build directory
o: $(PRG_SRC)
	mkdir -p build
	mv *.o ./build

$(PRG_SRC):
	$(CC) $(CPPFLAGS) -c $@


simulator: ./build/*.o
	mkdir -p bin
	$(CC) $(CPPFLAGS) ./build/*.o -o ./bin/mips_simulator

%.o: ./src/%.cpp
	mkdir -p build
	$(CC) $(CPPFLAGS) -c $< -o ./build/$@

clean:
	rm -rf ./bin/*
	rm -rf ./build/*


testbench: ./src/testbench.sh
	mkdir -p bin
	cp ./src/testbench.sh ./bin/mips_testbench
	chmod 755 ./bin/mips_testbench
