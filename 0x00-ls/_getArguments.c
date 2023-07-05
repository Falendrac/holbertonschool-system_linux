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
	int optionNumbers = 0;

	for (int index = 0; index < argc; index++)
		if (argv[index][0] == '-')
			optionNumbers++;

	arguments = _createArguments(argc - optionNumbers);
	arguments.options = _createOptions();

	if (argc == 1)
	{
		arguments.args[0] = ".";
		arguments.number = 1;
	}

	for (int index = 1; index < argc; index++)
		if (argv[index][0] != '-')
		{
			arguments.args[arguments.number] = argv[index];
			arguments.number++;
		}
		else
			switch (argv[index][1])
			{
				case 'a':
					arguments.options.hidden = 1;
					break;
				case '1':
					arguments.options.listing = 1;
					break;
			}

	return (arguments);
}
