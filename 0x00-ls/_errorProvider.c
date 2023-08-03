#include "main.h"

/**
 * _errorProvider - called when the function
 * opendir cannot open a directory, and print the error
 * in the stderr
 *
 * @program: name of the program
 * @arguments: the struct of all errorlist passes at the beggining
 * @errorName: Name of the argument that occur an error
*/
void _errorProvider(char *program, arguments *arguments, char *errorName)
{
	arguments->errorCode = MINOR_PROBLEM;

	switch (errno)
	{
		case EACCES:
			fprintf(stderr,
					"%s: %s: Permission denied\n",
					program,
					errorName
			);
		break;
		case ENOENT:
			fprintf(stderr,
					"%s: cannot access '%s': No such file or directory\n",
					program,
					errorName
			);
			arguments->errorCode = SERIOUS_PROBLEM;
		break;
	}
}
