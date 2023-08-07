#include "main.h"

/**
 * _listFiles - List all files in a directory
 *
 * @directory: The directory to list
 * @options: The options struct
 */
void _listFiles(DIR *directory, options options)
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
				_print_file_details(file->d_name);
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
