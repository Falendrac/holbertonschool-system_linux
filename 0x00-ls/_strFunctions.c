#include "main.h"

/**
 * _strcmp - Compares two strings
 *
 * @str1: The first string we compare
 * @str2: The second string we compare
 *
 * Return: compare
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*str1 == *str2);
}
