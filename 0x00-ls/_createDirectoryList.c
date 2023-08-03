#include "main.h"

/**
 * _createDirectoryList - Create the list of directory passes in argument
 *
 * @arguments: Structure of all arguments passes in the program
 * @path: Path passes in arguments
*/
void _createDirectoryList(arguments *arguments, char *path)
{
	arguments->directoryNumber++;

	if (!arguments->directorylist)
		arguments->directorylist = malloc(
											arguments->directoryNumber * sizeof(char *));
	else
		arguments->directorylist = realloc(
											arguments->directorylist,
											arguments->directoryNumber * sizeof(char *));

	if (!arguments->directorylist)
		return;

	arguments->directorylist[arguments->directoryNumber - 1] = path;
}
