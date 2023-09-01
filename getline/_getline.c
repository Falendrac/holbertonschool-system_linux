#include "_getline.h"
#include <stdio.h>

/**
 * allocateBuffer - Allocate memory for the buffer and set all memory
 * at the null character
 *
 * @size: The size the buffer that need to be alocate
 *
 * Return: Null if the allocation failed, otherwise, return the pointer of the
 * allocated buffer
*/
char *allocateBuffer(size_t size)
{
	char *buffer;

	buffer = malloc(size * sizeof(char));
	if (!buffer)
		return (NULL);
	memset(buffer, 0, size);

	return (buffer);
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
	char *buffer, *tmp;
	size_t charRead;
	static size_t sizeExposant = 1;

	buffer = allocateBuffer(READ_SIZE + 1);
	if (!buffer)
		return (NULL);

	charRead = read(fd, buffer, READ_SIZE);
	if (charRead <= 0)
	{
		free(buffer);
		return (NULL);
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
