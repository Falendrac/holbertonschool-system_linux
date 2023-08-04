#include "main.h"

/**
 * _createArguments - Initialize all value in an arguments struct
 * Allocate a suffisant space for arguments.directorylist
 *
 * @programName: The name of the program
 *
 * Return: An argument struct
 */
arguments _createArguments(char *programName)
{
	arguments arguments;

	arguments.programName = programName;
	arguments.directorylist = NULL;
	arguments.filelist = NULL;
	arguments.directoryNumber = 0;
	arguments.fileNumber = 0;

	arguments.errorCode = EXIT_SUCCESS;

	return (arguments);
}
