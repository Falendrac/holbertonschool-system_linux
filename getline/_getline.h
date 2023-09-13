#ifndef _GETLINE_H
#define _GETLINE_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define READ_SIZE 256

/**
 * struct lines_get - Node that store one line of a buffer
 *
 * @line: One line in the original buffer
 * @nextLine: The next node of line
*/
typedef struct lines_get
{
	char *line;
	struct lines_get *nextLine;
} lines_get;

char *_getline(const int fd);
char *allocateBuffer(char *buffer, size_t size);
char *_readFile(const int fd, size_t *size, char **buffer);
lines_get *_addNodeLine(char *buffer, size_t indexStart, size_t indexEnd);
lines_get *_lineParsing(char *buffer, size_t size);
lines_get *_browseLines(lines_get *lines);

#endif
