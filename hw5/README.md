### To compile hw5 code
Make sure you have navigated to the /hw5/ folder as the current directory.
* Type "make" to compile the all code.
* Type "make clean" to delete all compiled code.

### To run hw5 code
Make sure the program you want to run has been compiled first.  
* If an error message pops up, try the suggested fix if one is mentioned.
* All programs perform some basic input error checking and will recommend a fix if the input error is detected.  
* Make sure to change to the test folder directory.
* Type "./test.sh" or "sudo bash test.sh" to run the unit tests.

### Test notes
* All code has been tested on a Raspberry Pi 3 Model B running Raspbian.
* gcc version 4.9.2 was used to compile the code.

### HW5 Notes
* In c++, the sign of the answer for the '%' operator is implementation dependent. On my machine,
the following code: "int i = -5 % 2; std::cout << i;" results in i = -1 **instead of** 1.