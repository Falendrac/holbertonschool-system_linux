#include "main.h"

/**
 * _createArguments - Initialize all value in an arguments struct
 * Allocate a suffisant space for arguments.args
 *
 * @argc: The count of the arguments passes to the program
 *
 * Return: An argument struct
 */
arguments _createArguments(int argc)
{
	arguments arguments;

	arguments.args = malloc((argc - 1) * sizeof(char *));
	arguments.number = 0;
	arguments.errorCode = EXIT_SUCCESS;

	return (arguments);
}
