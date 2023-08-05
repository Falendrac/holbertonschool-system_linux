#include "main.h"

/**
 * main - Entry point
 *
 * @argc: The count of the arguments passes
 * @argv: Arguments passes to the program
 *
 * Return: 0 if the programm is executed correctly,
 * 1 if a minor problems is occur
 * 2 if a serious trouble is occur
 */
int main(int argc, char *argv[])
{
	arguments arguments;
	int index;
	char *separator = "";

	arguments = _getArguments(argc, argv);

	for (index = 0; index < arguments.fileNumber; index++)
	{
		if (index + 1 < arguments.fileNumber && arguments.options.oneline == 0)
			separator = STDSEPARATOR;
		else if (arguments.directoryNumber > 0 &&
					(arguments.options.oneline == 0 || index + 1 == arguments.fileNumber))
			separator = "\n\n";
		else
			separator = "\n";
		printf("%s%s", arguments.filelist[index], separator);
	}

	_openDirectories(argc, arguments);

	free(arguments.filelist);
	free(arguments.directorylist);

	return (arguments.errorCode);
}
