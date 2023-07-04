#include "list.h"

/**
 * printList - Print the content of dir
 *
 * @dir: Pointer that contain the content of a directory
 * @dataArgs: the struct of all args passes at the beggining
*/
void printList(DIR *dir, __attribute__((unused)) argsPass *dataArgs)
{
	struct dirent *read;
	char *separator = "";

	while ((read = readdir(dir)) != NULL)
	{
		if (*read->d_name != '.')
		{
			printf("%s%s", separator, read->d_name);

			separator = "  ";
		}
	}

	printf("\n");
}

/**
 * readArgs - Check all arguments passes to the program and
 * store it in a argsPass struct
 *
 * @argc: The count of the arguments passes
 * @argv: Arguments passes to the program
 *
 * Return: A argsPass struct
*/
argsPass *readArgs(int argc, char **argv)
{
	argsPass *dataArgs;

	dataArgs = malloc(sizeof(argsPass));
	dataArgs->args = malloc(argc * sizeof(char *));
	dataArgs->argsNumber = 0;
	dataArgs->endLine = "\n";
	dataArgs->errorCode = 0;

	if (argc == 1)
	{
		dataArgs->args[0] = ".";
		dataArgs->argsNumber = 1;
	}

	for (int row = 1; row < argc; row++)
	{
		dataArgs->args[row - 1] = argv[row];
		dataArgs->argsNumber++;
	}

	if (dataArgs->argsNumber > 1)
		dataArgs->endLine = "\n\n";

	return (dataArgs);
}

/**
 * main - main function of hls
 *
 * @argc: Number of arguments passed
 * @argv: All values passed
 *
 * Return: 0 if is reach here
 */
int main(int argc, char **argv)
{
	DIR *dir;
	argsPass *dataArgs;
	int errorTmp;

	dataArgs = readArgs(argc, argv);

	for (int row = 0; row < dataArgs->argsNumber; row++)
	{
		dir = opendir(dataArgs->args[row]);

		if (dir == NULL)
		{
			openError(argv[0], dataArgs, row);
			continue;
		}

		if (dataArgs->argsNumber > 1)
			printf("%s:\n", dataArgs->args[row]);

		printList(dir, dataArgs);
		if (dataArgs->argsNumber - row > 1)
			printf("\n");

		closedir(dir);
	}

	free(dataArgs->args);
	errorTmp = dataArgs->errorCode;
	free(dataArgs);

	if (errorTmp != 0)
		exit(dataArgs->errorCode);

	return (errorTmp);
}
