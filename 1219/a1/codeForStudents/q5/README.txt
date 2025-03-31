Note that you cannot push a file without read permissions to the git repository.
You will have to create your own if you want one. The simplest approach is to
enter the following commands:

	touch test1.in; chmod u-r test1.in

Note that the versions of my_factorial for Q5 will attempt to convert each command-line argument
to an integer value, calculate the factorial value, and output it. If the value isn't a valid 
integer, the program terminates with a non-zero return value. 

If there were no command-line arguments, the program attempts to read in an integer from stdin. If the read fails, the program returns a non-zero value. Otherwise, it calculates and outputs the 
factorial value.

If it managed to successfully process each command-line argument, or the value read from stdin,
a zero value is returned.