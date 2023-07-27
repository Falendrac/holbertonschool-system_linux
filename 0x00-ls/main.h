#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#define STDSEPARATOR "  "
#define LINESEPARATOR "\n"
#define SERIOUS_PROBLEM 2
#define MINOR_PROBLEM 1

/**
 * struct options - Struct for options
 *
 * @listing: 1 if the option -1 is passed, 0 otherwise
 * @hidden: 1 if the option -a is passed, 0 otherwise
 */
typedef struct options
{
	int listing;
	int hidden;
} options;

/**
 * struct arguments - Struct for arguments
 *
 * @args: The arguments
 * @options: The options struct
 * @number: The number of arguments
 * @errorCode: The error code
 */
typedef struct arguments
{
	char **directorylist;
	char **filelist;
	char **errorlist;
	options options;
	int number;
	int errorCode;
} arguments;

arguments _createArguments(int argc);
options _createOptions(void);
void _errorProvider(char *program, arguments *arguments, int index);
arguments _getArguments(int argc, char *argv[]);
void _listFiles(DIR *directory, options options);

#endif
