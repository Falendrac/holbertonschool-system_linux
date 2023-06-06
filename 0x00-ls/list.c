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
 * Return: 0 if is reach here
 */
int main(void)
{
	DIR *dir;

	dir = opendir(".");

	printList(dir);

	closedir(dir);

	return (0);
}
