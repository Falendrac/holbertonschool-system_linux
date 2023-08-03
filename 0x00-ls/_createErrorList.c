#include "main.h"

/**
 * _createErrorList - Create the list of arguments that occur an error
 *
 * @arguments: Structure of all arguments passes in the program
 * @path: Path passes in arguments
*/
void _createErrorList(arguments *arguments, char *path)
{
	arguments->errorNumber++;

	if (!arguments->errorlist)
		arguments->errorlist = malloc(arguments->errorNumber * sizeof(char *));
	else
		arguments->errorlist = realloc(
										arguments->errorlist,
										arguments->errorNumber * sizeof(char *));

	if (!arguments->errorlist)
		return;

	arguments->errorlist[arguments->errorNumber - 1] = path;
}
