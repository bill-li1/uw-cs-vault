Note that you cannot push a file without read permissions to the git repository.
You will have to create your own if you want one. The simplest approach is to
enter the following commands:

	touch no_read.args; chmod u-r no_read.args
	touch test4.args; chmod u-r test4.args

Note that the versions of my_factorial for Q3 will attempt to convert each command-line argument
to an integer value, calculate the factorial value, and output it. If the value isn't a valid 
integer, the program terminates with a non-zero return value. If there were no command-line
arguments, the program returns a non-zero value. If it managed to successfully process each argument, 
a zero value is returned.