#include "main.h"

/**
 * _createOptions - Initialize all value in an options struct
 *
 * Return: An options struct
 */
options _createOptions(void)
{
	options options;

	options.hidden = 0;
	options.oneline = 0;
	options.implied = 0;
	options.detail = 0;

	return (options);
}
