#include "main.h"

/**
 * _errorProvider - called when the function
 * opendir cannot open a directory, and print the error
 * in the stderr
 *
 * @arguments: the struct of all errorlist passes at the beggining
 * @errorName: Name of the argument that occur an error
*/
void _errorProvider(arguments *arguments, char *errorName)
{
	arguments->errorCode = MINOR_PROBLEM;

	switch (errno)
	{
		case EACCES:
			fprintf(stderr,
					"%s: cannot open directory %s: Permission denied\n",
					arguments->programName,
					errorName
			);
		break;
		case ENOENT:
			fprintf(stderr,
					"%s: cannot access %s: No such file or directory\n",
					arguments->programName,
					errorName
			);
			arguments->errorCode = SERIOUS_PROBLEM;
		break;
	}
}
