#include "main.h"

/**
 * main - main program entry
 * Return: 0 on success, -1 on failure
*/
int main(int argc, char **argv)
{
	int status = 0;

	while (status == 0)
		status = prompt(argc, argv);

	return (0);
}
