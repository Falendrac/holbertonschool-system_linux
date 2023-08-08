#include "main.h"

/**
 * _listFiles - List all files in a directory
 *
 * @directory: The directory to list
 * @options: The options struct
 * @path: The path of the directory and the file
 */
void _listFiles(DIR *directory, options options, char *path)
{
	struct dirent *file;
	char *separator = "";

	while ((file = readdir(directory)))
		if (*file->d_name != '.' || options.hidden || options.implied)
		{
			if (options.implied == 1 && *file->d_name == '.' &&
				(_strcmp(".", file->d_name) || _strcmp("..", file->d_name)))
				continue;

			if (options.detail)
				_print_file_details(file->d_name, path);
			else
				printf("%s%s", separator, file->d_name);

			if (options.oneline)
				separator = LINESEPARATOR;
			else
				separator = STDSEPARATOR;
		}

	if (!options.detail)
		printf("\n");
}
