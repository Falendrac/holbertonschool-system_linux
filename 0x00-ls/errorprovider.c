#include "list.h"

/**
 * openError - called when the function
 * opendir cannot open a directory, and print the error
 * in the stderr
 *
 * @argv: value passed at the execution of the command
 *
 * Return: 2
*/
void openError(char **argv)
{
	fprintf(stderr,
			"%s: cannot access '%s': No such file or directory\n", argv[0], argv[1]);

	exit(2);
}
