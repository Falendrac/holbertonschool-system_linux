#include "list.h"

/**
 * printList - Print the content of dir
 *
 * @dir: Pointer that contain the content of a directory
*/
void printList(DIR *dir)
{
	struct dirent *read;
	int firstPrint = 0;

	while ((read = readdir(dir)) != NULL)
	{
		if (*read->d_name != '.')
		{
			if (firstPrint)
				printf("  ");

			printf("%s", read->d_name);

			firstPrint = 1;
		}
	}
	printf("\n");
}

/**
 * main - main function of hls
 *
 * @argc: Number of arguments passed
 * @argv: All values passed
 *
 * Return: 0 if is reach here
 */
int main(int argc, char **argv)
{
	DIR *dir;

	if (argc == 1)
		dir = opendir(".");
	else
		dir = opendir(argv[1]);

	if (dir == NULL)
		openError(argv);

	printList(dir);

	closedir(dir);

	return (0);
}
