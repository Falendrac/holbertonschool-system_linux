#include "main.h"

#define STDSEPARATOR "  "
#define LINESEPARATOR "\n"

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
		if (*file->d_name != '.' || options.hidden)
		{
			printf("%s%s", separator, file->d_name);
			if (options.listing)
				separator = LINESEPARATOR;
			else
				separator = STDSEPARATOR;
		}

	printf("\n");
}
