# CompArch-Slapdragon
This project started as a coursework for our Y2 Computer Architecture module @ImperialCollegeLondon.
It involved:
1. Developing MIPS CPU simulator, which can accurately execute MIPS-1 big-endian binaries
2. Creating a thorough testbench

## 1: CPU Simulator
### Build
The compiler can be built using the command:
```
make simulator
```
in the root of the repository, producing the `bin/mips_simulator` file.

### Execution
A Binary can then be simulated using:
```
bin/mips_simulator <file_name>.bin
```
On startup all MIPS registers will be zero, any uninitialised
memory will be zero, and the program counter will point at the
first instruction in memory.

------------------------------

## 2: Testbench
### Build
The Testbench can be built using the command:
```
make testbench
```
in the root of the repository, producing the `bin/mips_testbench` file.

### Execution
An example of running the testbench on some simulator would be:
```
bin/mips_testbench  ~/path/to/simulator
```
The testbench outputs useful tests and log files in a folder called `test/output`.
It also prints a CSV file to stdout, giving an overview of test results and possible errors.

### Testcases
We wrote all our testcases in MIPS Assembly. To get the corresponding Binaries, we used Olly Larkin's  "MIPS Binary Instruction File Generator" which is MIT licensed and can be found here:
https://github.com/olly-larkin/mips-parser
To write testcases more efficiently, we added a bash script to bach compile all assembly files and filter out important information from the comments in each file (Name, Description, References)
The binary files for the Jump instruction had do be converted by hand. To do so we used the following MIPS converter and Hex editor:
https://www.eg.bucknell.edu/~csci320/mips_web/
https://hexed.it
