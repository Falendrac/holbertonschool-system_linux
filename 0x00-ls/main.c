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

	arguments = _getArguments(argc, argv);
	for (index = 0; index < arguments.number; index++)
	{
		directory = opendir(arguments.args[index]);
		if (directory == NULL)
			_errorProvider(argv[0], &arguments, index);
		else
		{
			if (arguments.number > 1)
				printf("%s:\n", arguments.args[index]);
			_listFiles(directory, arguments.options);
			closedir(directory);
			if (arguments.number > 1 && index != arguments.number - 1)
				printf("\n");
		}
	}

	free(arguments.args);

	return (arguments.errorCode);
}
