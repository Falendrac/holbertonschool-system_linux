#include "_getline.h"
#include <stdio.h>

/**
 * allocateBuffer - Allocate memory for the buffer and set all memory
 * at the null character
 *
 * @index: The index the buffer that need to be alocate
 *
 * Return: Null if the allocation failed, otherwise, return the pointer of the
 * allocated buffer
*/
char *allocateBuffer(size_t index)
{
	char *buffer;

	buffer = malloc(index * sizeof(char));
	if (!buffer)
		return (NULL);
	memset(buffer, 0, index);

	return (buffer);
}

/**
 * _searchLine - Search for the new line per line and return the
 * index of the newline
 *
 * @buffer: The buffer fill by read
 * @bufferSize: the number of char that have been read
 *
 * Return: The index of the newline or the end of the buffer
*/
int _searchLine(char *buffer, size_t bufferSize, size_t index)
{
	for (; index < bufferSize; index++)
		if (buffer[index] == '\n')
			return (index);

	return (index);
}

/**
 * _getline - reads an entire line from a file descriptor
 *
 * @fd: file descriptor to read from
 *
 * Return: a null-terminated string that does not include the newline character
*/
char *_getline(const int fd)
{
	static char *buffer;
	char *tmp;
	static size_t charRead, oldIndex;
	size_t indexLine;
	static size_t sizeExposant = 1;

	if (charRead <= 0)
	{
		buffer = allocateBuffer(READ_SIZE + 1);
		if (!buffer)
			return (NULL);

		charRead = read(fd, buffer, READ_SIZE);
		if (charRead <= 0)
		{
			free(buffer);
			return (NULL);
		}
	}

	indexLine = _searchLine(buffer, charRead, oldIndex);
	if (indexLine < charRead)
	{
		tmp = malloc(sizeof(char) * (indexLine + 1));
		strncpy(tmp, buffer + oldIndex, indexLine);
		tmp[indexLine] = '\0';
		oldIndex += indexLine + 1;
		return (tmp);
	}

	if (charRead == READ_SIZE)
	{
		sizeExposant++;
		tmp = _getline(fd);
		buffer = realloc(buffer, READ_SIZE * sizeExposant + 1);
		if (!buffer)
		{
			free(tmp);
			return (NULL);
		}
		strcat(buffer, tmp);
		free(tmp);
	}
	else
	{
		buffer[charRead - 1] = '\0';
	}

	return (buffer);
}
