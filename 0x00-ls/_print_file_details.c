#include "main.h"

/**
 * _strlength - Calculate the length of the str
 *
 * @str: The string we want to calculate the length
 *
 * Return: The length of the str
*/
int _strlength(char *str)
{
	int length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

/**
 * _pathFormat - See if the last character of the path is '/'
 *
 * @path: The path we check if the '/' is here
 * @pathSize: The size of the path
 *
 * Return: '/' if there is not that character, otherwise void string
*/
char *_pathFormat(char *path, int *pathSize)
{
	char *separator;

	if (path[*pathSize - 1] != '/')
	{
		*pathSize += 1;
		separator = "/";
	}
	else
		separator = "";

	return (separator);
}

/**
 * _print_file_details - Print all details of a file
 *
 * @filename: The name of the file we want to print all details
 * @path: The path of the current file we want to print the detail
*/
void _print_file_details(char *filename, char *path)
{
	struct stat file_info;
	struct passwd *owner_info;
	struct group *group_info;
	char *time_str, permissions[11], *fullPath, *separator;
	int indx, fullPathSize, pathSize;

	pathSize = _strlength(path);
	separator = _pathFormat(path, &pathSize);
	fullPathSize = pathSize + _strlength(filename);
	fullPath = malloc(sizeof(char) * (fullPathSize + 1));
	fullPath[fullPathSize] = '\0';
	sprintf(fullPath, "%s%s%s", path, separator, filename);

	if (lstat(fullPath, &file_info) == -1)
	{
		free(fullPath);
		return;
	}

	owner_info = getpwuid(file_info.st_uid);
	group_info = getgrgid(file_info.st_gid);
	time_str = ctime(&(file_info.st_mtime));
	time_str = time_str + 4;
	time_str[12] = '\0';

	permissions[0] = (S_ISDIR(file_info.st_mode)) ? 'd' : '-';
	for (indx = 0; indx < 9; indx += 3)
	{
		permissions[indx + 1] = (file_info.st_mode & (S_IRUSR >> indx)) ? 'r' : '-';
		permissions[indx + 2] = (file_info.st_mode & (S_IWUSR >> indx)) ? 'w' : '-';
		permissions[indx + 3] = (file_info.st_mode & (S_IXUSR >> indx)) ? 'x' : '-';
	}
	permissions[10] = '\0';

	printf("%s %ld %s %s %ld %s %s\n",
		   permissions, file_info.st_nlink,
		   (owner_info != NULL) ? owner_info->pw_name : "unknown",
		   (group_info != NULL) ? group_info->gr_name : "unknown",
		   file_info.st_size, time_str, filename);
	free(fullPath);
}
