#include "main.h"

/**
 * _createFileList - Create the list of file passes in argument
 *
 * @arguments: Structure of all arguments passes in the program
 * @path: Path passes in arguments
*/
void _createFileList(arguments *arguments, char *path)
{
	arguments->fileNumber++;

	if (!arguments->filelist)
		arguments->filelist = malloc(arguments->fileNumber * sizeof(char *));
	else
		arguments->filelist = realloc(
										arguments->filelist,
										arguments->fileNumber * sizeof(char *));

	if (!arguments->filelist)
		return;

	arguments->filelist[arguments->fileNumber - 1] = path;
}
