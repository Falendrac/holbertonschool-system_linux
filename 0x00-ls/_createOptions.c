#include "main.h"

/**
 * _createOptions - Initialize all value in an options struct
 *
 * Return: An options struct
 */
options _createOptions(void)
{
	options options;

	options.listing = 0;
	options.hidden = 0;

	return (options);
}
