# CompArch-Slapdragon
MIPS Simulator and Testbench

## Testbench
### Testcases
We wrote all our testcases in MIPS Assembly. To get the corresponding Binaries, we used Olly Larkin's  "MIPS Binary Instruction File Generator" which is MIT licensed and can be found here:
https://github.com/olly-larkin/mips-parser
To write testcases more efficiently, we added a bash script to bach compile all assembly files and filter out important information from the comments in each file (Name, Description, References)
The binary files for the Jump instruction had do be converted by hand. To do so we used the following MIPS converter and Hex editor:
https://www.eg.bucknell.edu/~csci320/mips_web/
https://hexed.it
