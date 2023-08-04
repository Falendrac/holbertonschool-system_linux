#include "main.h"

/**
 * _checkFileOrDirectory - Open the stat of an arguments passes though the
 * program and watch if the arguments is a file, directory or an error
 *
 * @path: Path of the arguments passes
 * @arguments: Structure of all arguments passes though the program
 *
 * Return: The stat structure of the path
*/
struct stat _checkFileOrDirectory(char *path, arguments *arguments)
{
	struct stat statInfos;

	if (lstat(path, &statInfos) == -1)
	{
		_errorProvider(arguments, path);
		return (statInfos);
	}

	if (S_ISREG(statInfos.st_mode))
		_createFileList(arguments, path);
	else if (S_ISDIR(statInfos.st_mode))
		_createDirectoryList(arguments, path);
	else
		_errorProvider(arguments, path);

	return (statInfos);
}
