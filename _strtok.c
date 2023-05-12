#include <stdio.h>
#include <string.h>

char *_strtok(char *str, const char *delim)
{
	int index;
	char *new_str;

	if (str == NULL)
	{
		str = new_str;
	}

	for (index = 0; str[index] != '\0'; index++)
	{
		if (str[index] == *delim)
		{
			str[index] = '\0';
			new_str = &str[index + 1];
			break;
		}
	}

	if (str[index + 1] == '\0' && index == strlen(str) + 1)
	{
		new_str = NULL;
		return NULL;
	}

	return str;
}

int main()
{
	char *str = "MY NAME IS FRANK";
	char *delim = " ";

	char *new_str = strtok(str, delim);

	while (new_str != NULL)
	{
		printf("%s\n", new_str);
		new_str = strtok(NULL, delim);
	}

	/* 	printf(" new_str: %s\n", new_str);
		printf("new_str2: %s\n", new_str2);
		printf("new_str3: %s\n", new_str3); */

	return (0);
}
