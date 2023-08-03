#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define STDSEPARATOR "  "
#define LINESEPARATOR "\n"
#define SERIOUS_PROBLEM 2
#define MINOR_PROBLEM 1

/**
 * struct options - Struct for options
 *
 * @listing: 1 if the option -1 is passed, 0 otherwise
 * @hidden: 1 if the option -a is passed, 0 otherwise
 * @oneline: 1 if the option -l is passed, 0 otherwise
 */
typedef struct options
{
	int listing;
	int hidden;
	int oneline;
} options;

/**
 * struct arguments - Struct for arguments
 *
 * @directorylist: The list of directory name passes
 * @filelist: The list of files name passes
 * @errorlist: The list of name that occur errors
 * @options: The options struct
 * @directoryNumber: The number of arguments that was a directory
 * @fileNumber: The number of arguments that was a file
 * @errorNumber: The number of arguments that occur an error
 * @errorCode: The error code
 */
typedef struct arguments
{
	char **directorylist;
	char **filelist;
	char **errorlist;
	options options;
	int directoryNumber;
	int fileNumber;
	int errorNumber;
	int errorCode;
} arguments;

arguments _createArguments(void);
options _createOptions(void);
void _errorProvider(char *program, arguments *arguments, char *errorName);
arguments _getArguments(int argc, char *argv[]);
void _listFiles(DIR *directory, options options);
struct stat _checkFileOrDirectory(char *path, arguments *arguments);
void _createDirectoryList(arguments *arguments, char *path);
void _createFileList(arguments *arguments, char *path);
void _createErrorList(arguments *arguments, char *path);
void _setOptions(arguments *arguments, char *options);

#endif
