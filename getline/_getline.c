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
char *allocateBuffer(char *buffer, size_t size)
{
	char *tmp;

	if (!buffer)
	{
		tmp = malloc(sizeof(char) * (READ_SIZE + 1));
		if (!tmp)
			return (NULL);
		memset(tmp, '\0', READ_SIZE + 1);
		return (tmp);
	}

	buffer = realloc(buffer, (size + READ_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	memset(buffer + size, '\0', READ_SIZE + 1);

	return (buffer);
}

char *_readFile(const int fd, size_t *size, char **buffer)
{
	char *localBuffer;
	size_t charRead;

	localBuffer = allocateBuffer(NULL, 0);
	if (!localBuffer)
		return (NULL);
	charRead = read(fd, localBuffer, READ_SIZE);
	*size += charRead;
	strcat(*buffer, localBuffer);
	free(localBuffer);

	if (charRead == READ_SIZE)
	{
		*buffer = allocateBuffer(*buffer, *size);
		return (_readFile(fd, size, buffer));
	}

	return (*buffer);
}

lines_get *_addNodeLine(char *buffer, size_t indexStart, size_t indexEnd)
{
	lines_get *lines;
	size_t lineSize;

	lineSize = indexEnd - indexStart;
	lines = malloc(sizeof(lines_get));
	lines->line = malloc(sizeof(char) * (lineSize + 1));
	memcpy(lines->line, buffer + indexStart, lineSize);
	memset(lines->line + lineSize, '\0', 1);
	lines->nextLine = NULL;

	return (lines);
}

lines_get *_lineParsing(char *buffer, size_t size)
{
	lines_get *lines = NULL, *tmp;
	size_t indexStart = 0, indexEnd = 0;

	while (buffer[indexStart])
	{
		while(buffer[indexEnd] != '\n' && indexEnd < size)
			indexEnd++;

		if (!lines)
		{
			lines = _addNodeLine(buffer, indexStart, indexEnd);
			tmp = lines;
		}
		else
		{
			tmp->nextLine = _addNodeLine(buffer, indexStart, indexEnd);
			tmp = tmp->nextLine;
		}

		indexEnd++;
		indexStart = indexEnd;
	}

	return (lines);
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
	char *buffer;
	size_t charRead = 0;
	static lines_get *lines;
	lines_get *tmp;

	while (lines)
	{
		tmp = lines->nextLine;
		buffer = lines->line;
		free(lines);
		lines = tmp;
		return (buffer);
	}

	buffer = allocateBuffer(NULL, 0);
	if (!buffer)
		return (NULL);

	_readFile(fd, &charRead, &buffer);
	if (charRead <= 0)
	{
		free(buffer);
		return (NULL);
	}

	if (buffer[charRead - 1] == '\n')
	{
		buffer[charRead - 1] = '\0';
		charRead--;
	}

	lines = _lineParsing(buffer, charRead);
	free(buffer);

	return (_getline(fd));
}
