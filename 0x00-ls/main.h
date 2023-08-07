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
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define STDSEPARATOR "  "
#define LINESEPARATOR "\n"
#define SERIOUS_PROBLEM 2
#define MINOR_PROBLEM 1

/**
 * struct options - Struct for options
 *
 * @hidden: 1 if the option -a is passed, 0 otherwise
 * @oneline: 1 if the option -1 is passed, 0 otherwise
 * @implied: 1 if the option -A is passed, 0 otherwise
 * @detail: 1 if the option -l is passed, 0 otherwise
 */
typedef struct options
{
	int hidden;
	int oneline;
	int implied;
	int detail;
} options;

/**
 * struct arguments - Struct for arguments
 *
 * @programName: The name of the pogram
 * @directorylist: The list of directory name passes
 * @filelist: The list of files name passes
 * @options: The options struct
 * @optionsNumber: The number passes though
 * the program (only count args with '-' character)
 * @directoryNumber: The number of arguments that was a directory
 * @fileNumber: The number of arguments that was a file
 * @errorCode: The error code
 */
typedef struct arguments
{
	char *programName;
	char **directorylist;
	char **filelist;
	options options;
	int optionsNumber;
	int directoryNumber;
	int fileNumber;
	int errorCode;
} arguments;

arguments _createArguments(char *programName);
options _createOptions(void);
void _errorProvider(arguments *arguments, char *errorName);
arguments _getArguments(int argc, char *argv[]);
void _listFiles(DIR *directory, options options);
struct stat _checkFileOrDirectory(char *path, arguments *arguments);
void _createDirectoryList(arguments *arguments, char *path);
void _createFileList(arguments *arguments, char *path);
void _createErrorList(arguments *arguments, char *path);
void _setOptions(arguments *arguments, char *options);
int _strcmp(char *str1, char *str2);
void _openDirectories(int argc, arguments arguments);
void _print_file_details(char *filename);

#endif
