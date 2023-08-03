#include "main.h"

/**
 * _createArguments - Initialize all value in an arguments struct
 * Allocate a suffisant space for arguments.directorylist
 *
 * Return: An argument struct
 */
arguments _createArguments(void)
{
	arguments arguments;

	arguments.directorylist = NULL;
	arguments.errorlist = NULL;
	arguments.filelist = NULL;
	arguments.directoryNumber = 0;
	arguments.fileNumber = 0;
	arguments.errorNumber = 0;

	arguments.errorCode = EXIT_SUCCESS;

	return (arguments);
}
