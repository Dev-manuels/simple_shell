#include "main.h"

void exit_status(const char *input, ...)
{
	va_list args;
	va_start(args, input);
	int status = va_arg(args, int);

	if (strcmp(input, "exit") == 0)
	{
		exit(status);
	}
}
