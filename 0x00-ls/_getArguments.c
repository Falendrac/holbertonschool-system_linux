#include "main.h"

/**
 * _getArguments - Get all arguments and store in a struct
 *
 * @argc: The count of the arguments passes
 * @argv: Arguments passes to the program
 *
 * Return: A arguments struct
*/
arguments _getArguments(int argc, char *argv[])
{
	arguments arguments;
	int optionNumbers = 0, index;

	for (index = 0; index < argc; index++)
		if (argv[index][0] == '-')
			optionNumbers++;

	arguments = _createArguments(argv[0]);
	arguments.optionsNumber = optionNumbers;
	arguments.options = _createOptions();

	if (argc == 1 || argc - optionNumbers == 1)
	{
		arguments.directorylist = malloc(sizeof(char *) * argc - optionNumbers);
		arguments.directorylist[0] = ".";
		arguments.directoryNumber = 1;
	}

	for (index = 1; index < argc; index++)
		if (argv[index][0] != '-')
			_checkFileOrDirectory(argv[index], &arguments);
		else
			_setOptions(&arguments, argv[index]);

	return (arguments);
}
