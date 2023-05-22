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


/* Enviroment Variable */
extern char **environ;


/* External Header Files */
#include <limits.h>
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
int _atoi(const char *s);
void chgdir(const char *path);
void clear_env(void);
int exe_bin(char **args);
int exe_cmd(char **argv);
void exit_status(const char *input);
void free_list(list_t *head);
int freeWords(char ***words, int wordCount);
char *get_path(char *cmd);
int _setenv(const char *name, const char *value, int overwrite);
int seperate_word(char *line,
char ***words, int line_size, char *delim);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);
char *_strdup(char *str);
int _strlen(const char *s);
char *_strtok(char *str, const char *delim);
int output(char *s);
int prompt(void);
int _unsetenv(const char *name);


#endif
