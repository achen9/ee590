### To compile hw2 prob3 code
Make sure you have navigated to the /hw2/prob3/ folder as the current directory.
* Type "make stack" to compile the "stack" program. Typing "make" will compile "stack.c" by default.
* Type "make clean" to delete all compiled code.

### To run hw2 prob3 code
Make sure the program you want to run has been compiled first. 
If an error message pops up, try the suggested fix if one is mentioned. 
All programs perform some basic input error checking and will recommend a fix if the input error is detected.
* Type "./stack \<filename.csv\> \<"pop", "print_top", or "swap_top"\>" to run the "stack" program.

###Test notes
* All code has been tested on a Raspberry Pi 3 Model B running Raspbian.
* gcc version 4.9.2 was used to compile the code.
* The Makefile compiles with all warnings enabled. A warning about the use of "typenam" may display when compiling. The code will still work even with that warning.
