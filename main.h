#ifndef _MAIN_H
#define _MAIN_H

/* Structs */

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;


/* Global Variables */
extern char **environ; /* Enviroment Variable */


/* Headers */
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


/* Function prototypes */
void *add_node(const char *str);
void free_list(list_t *head);
void clear_env(void);
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);

int exe_cmd(char **argv);
int freeWords(char ***words, int wordCount);
char *get_path(char *cmd, int *rt);
int seperate_word(char *line,
char ***words, int line_size, char *delim);
int _strcmp(const char *s1, const char *s2);
char *_strdup(char *str);
int _strlen(const char *s);
char *_strtok(char *str, const char *delim);
int output(char *s);
int prompt(void);

#endif
