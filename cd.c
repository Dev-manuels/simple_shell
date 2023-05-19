#include "main.h"

void chgdir(const char *input,...)
{
	va_list args;
	va_start(args, input);
	char tmp[200];
	char *path = va_arg(args, char*);

	if (strcmp(input, "chdir") == 0)
	{
		if (access(path, F_OK) == 0)
		{
			getcwd(tmp,200);
			printf("tmp: %s\n", tmp);
			chdir(path);
			getcwd(tmp,200);
			printf("done: %s\n", tmp);
		}
	}
}
