#include "main.h"

/**
 * _openDirectories - Open all the directories in arguments directory list
 * and call the listFiles function to print the content of all directories
 *
 * @argc: Number of arguments passes though the program
 * @arguments: The data structure with all arguments passes though the
 * program and classified correctly
*/
void _openDirectories(int argc, arguments arguments)
{
	DIR *directory;
	int index;

	for (index = 0; index < arguments.directoryNumber; index++)
	{
		directory = opendir(arguments.directorylist[index]);
		if (directory == NULL)
			_errorProvider(&arguments, arguments.directorylist[index]);
		else
		{
			if (argc - arguments.optionsNumber - 1 > 1)
				printf("%s:\n", arguments.directorylist[index]);
			_listFiles(directory, arguments.options);
			closedir(directory);
			if (arguments.directoryNumber > 1 && index != arguments.directoryNumber - 1)
				printf("\n");
		}
	}
}
