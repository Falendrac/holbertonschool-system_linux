#include "main.h"

/**
 * _errorProvider - called when the function
 * opendir cannot open a directory, and print the error
 * in the stderr
 *
 * @program: name of the program
 * @arguments: the struct of all errorlist passes at the beggining
 * @index: index of the arguments that occur the error
 *
 * Return: 2
*/
void _errorProvider(char *program, arguments *arguments, int index)
{
	arguments->errorCode = MINOR_PROBLEM;

	switch (errno)
	{
		case EACCES:
			fprintf(stderr,
					"%s: %s: Permission denied\n",
					program,
					arguments->errorlist[index]
			);
		break;
		case ENOENT:
			fprintf(stderr,
					"%s: cannot access '%s': No such file or directory\n",
					program,
					arguments->errorlist[index]
			);
			arguments->errorCode = SERIOUS_PROBLEM;
		break;
	}
}
