#include "main.h"

/**
 * _print_file_details - Print all details of a file
 *
 * @filename: The name of the file we want to print all details
*/
void _print_file_details(char *filename)
{
	struct stat file_info;
	struct passwd *owner_info;
	struct group *group_info;
	struct tm *tm_info;
	char time_str[20], permissions[11];
	int indx;

	if (lstat(filename, &file_info) == -1)
	{
		perror("lstat");
		exit(EXIT_FAILURE);
	}

	owner_info = getpwuid(file_info.st_uid);
	group_info = getgrgid(file_info.st_gid);
	tm_info = localtime(&(file_info.st_mtime));
	strftime(time_str, sizeof(time_str), "%b %d %H:%M", tm_info);

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
}
