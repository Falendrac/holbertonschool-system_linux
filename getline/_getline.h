#ifndef _GETLINE_H
#define _GETLINE_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define READ_SIZE 256

typedef struct lines_get
{
	char *line;
	struct lines_get *nextLine;
} lines_get;

char *_getline(const int fd);
char *allocateBuffer(char *buffer, size_t size);
int _searchLine(char *buffer, size_t bufferSize, size_t index);

#endif
