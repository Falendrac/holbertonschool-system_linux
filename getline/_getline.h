#ifndef _GETLINE_H
#define _GETLINE_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define READ_SIZE 256

char *_getline(const int fd);
char *allocateBuffer(size_t size);
int _searchLine(char *buffer, size_t bufferSize, size_t index);

#endif