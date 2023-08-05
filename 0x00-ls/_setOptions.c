#include "main.h"

/**
 * _setOptions - Set at true all the options that is
 * pass in the program
 *
 * @arguments: The arguments structure with the options struct and all
 * arguments passes though
 * @options: The string passes in argument with options
*/
void _setOptions(arguments *arguments, char *options)
{
	int index = 1;

	while (options[index])
	{
		switch (options[index])
		{
			case 'a':
				arguments->options.hidden = 1;
				break;
			case '1':
				arguments->options.oneline = 1;
				break;
			case 'A':
				arguments->options.implied = 1;
				break;
		}
		index++;
	}
}
