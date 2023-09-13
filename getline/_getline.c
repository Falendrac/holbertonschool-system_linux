#include "_getline.h"
#include <stdio.h>

/**
 * allocateBuffer - Allocate memory for the buffer if there is null
 * and set all memory at the null character or reallocate the size of the
 * buffer to new size
 *
 * @buffer: The buffer of the getline
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

/**
 * _readFile - Read the entirely file descriptor and add all characters
 * read in the buffer by called the allocateBuffer function using the
 * recursion to reach all characters in the file
 *
 * @fd: The file descriptor we want to read
 * @size: the adress of the size in the main function getline that change
 * in each read
 * @buffer: The adresse of the pointer buffer and fill it in each read
 *
 * Return: The final buffer that it read or NULL if the allocation failled
*/
char *_readFile(const int fd, size_t *size, char **buffer)
{
	char *localBuffer;
	size_t charRead;

	localBuffer = allocateBuffer(NULL, 0);
	if (!localBuffer)
		return (NULL);
	charRead = read(fd, localBuffer, READ_SIZE);
	if (charRead == (size_t)-1)
	{
		write(STDIN_FILENO, "Nothing to read\n", 17);
		free(localBuffer);
		return (NULL);
	}
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

/**
 * _addNodeLine - Create a node by allocating memory for it, and create
 * the line of the node by allocate memory and copy the memory adress
 * of the buffer between indexStart and indexEnd and set the null terminated
 * value at the end of the line
 *
 * @buffer: The complete buffer read before
 * @indexStart: The start of the string we want to copy
 * @indexEnd: The end of the string we want to copy
 *
 * Return: The new node with the line
*/
lines_get *_addNodeLine(char *buffer, size_t indexStart, size_t indexEnd)
{
	lines_get *lines;
	size_t lineSize;

	lineSize = indexEnd - indexStart;
	lines = malloc(sizeof(lines_get));
	if (!buffer)
		lines->line = NULL;
	else
	{
		lines->line = malloc(sizeof(char) * (lineSize + 1));
		memcpy(lines->line, buffer + indexStart, lineSize);
		memset(lines->line + lineSize, '\0', 1);
	}
	lines->nextLine = NULL;

	return (lines);
}

/**
 * _lineParsing - Parse the buffer to detect all lines in and create
 * a linked list of lines with each line. That one node correspond to one line
 *
 * @buffer: The complete buffer read before
 * @size: The size of the buffer
 *
 * Return: A linked list with all lines
*/
lines_get *_lineParsing(char *buffer, size_t size)
{
	lines_get *lines = NULL, *tmp;
	size_t indexStart = 0, indexEnd = 0;

	while (buffer[indexStart])
	{
		while (buffer[indexEnd] != '\n' && indexEnd < size)
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

	tmp->nextLine =  _addNodeLine(NULL, 0, 0);

	return (lines);
}

/**
 * _getline - reads an entire line from a file descriptor
 * store all lines contain in and return each line when the function
 * is call
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

	lines = _lineParsing(buffer, charRead);
	free(buffer);

	return (_getline(fd));
}
