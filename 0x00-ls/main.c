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
	DIR *directory;
	arguments arguments;
	int index;
	char *separator = "";

	arguments = _getArguments(argc, argv);

	for (index = 0; index < arguments.errorNumber; index++)
		_errorProvider(argv[0], &arguments, arguments.errorlist[index]);

	for (index = 0; index < arguments.fileNumber; index++)
	{
		if (index + 1 < arguments.fileNumber)
			separator = STDSEPARATOR;
		else
			separator = "\n";
		printf("%s%s", arguments.filelist[index], separator);
	}

	for (index = 0; index < arguments.directoryNumber; index++)
	{
		directory = opendir(arguments.directorylist[index]);
		if (directory == NULL)
			_errorProvider(argv[0], &arguments, arguments.directorylist[index]);
		else
		{
			if (arguments.directoryNumber > 1)
				printf("%s:\n", arguments.directorylist[index]);
			_listFiles(directory, arguments.options);
			closedir(directory);
			if (arguments.directoryNumber > 1 && index != arguments.directoryNumber - 1)
				printf("\n");
		}
	}

	free(arguments.filelist);
	free(arguments.errorlist);
	free(arguments.directorylist);

	return (arguments.errorCode);
}
