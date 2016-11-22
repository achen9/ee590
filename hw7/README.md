### To run hw7 code
Make sure you have navigated to the /hw7/ folder as the current directory.
* If an error message pops up, try the suggested fix if one is mentioned.
* All programs perform some basic input error checking and will recommend a fix if the input error is detected.  
* Type "node data_server.js" to start the server.
* Type "node save_cpu.js <IP address> <port>" to start the client and save cpu load data to the specified server.

### Test notes
* All code has been tested on a Raspberry Pi 3 Model B running Raspbian.
* nodejs version 6.9.1 LTS was used to run the code.

### Note: running on an instance of AWS in the background
* Use the "nohup" command: nohup node data_server.js &
* data_server.js will run in the background even if not connected to the server through SSH.
