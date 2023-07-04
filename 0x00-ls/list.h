#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * struct argumentsPasses - Store all arguments and options
 *
 * @args: All arguments to print the content
 * @argsNumber: Number of arguments passes
 * @endLine: Handle the end of line when if they have
 * multiple arguments or one
 * @errorCode: Store the error code if an error is occur in the
 * program, by default set it at 0
 */
typedef struct argumentsPasses
{
	char **args;
	int argsNumber;
	char *endLine;
	int errorCode;
} argsPass;

void printList(DIR *dir, argsPass *dataArgs);
void openError(char *program, argsPass *dataArgs, int index);

#endif

