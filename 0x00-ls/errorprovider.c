#include "list.h"

/**
 * openError - called when the function
 * opendir cannot open a directory, and print the error
 * in the stderr
 *
 * @program: name of the program
 * @dataArgs: the struct of all args passes at the beggining
 * @index: index of the arguments that occur the error
 *
 * Return: 2
*/
void openError(char *program, argsPass *dataArgs, int index)
{
	fprintf(stderr,
			"%s: cannot access '%s': No such file or directory\n",
			program,
			dataArgs->args[index]);

	dataArgs->errorCode = 2;
}
