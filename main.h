#ifndef _MAIN_H
#define _MAIN_H

extern char **environ; /* Environment variables */
/* Required headers */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* Function prototypes */

int exe_cmd(char **argv);
int freeWords(char ***words, int wordCount);
char *get_path(char *cmd, int *rt);
int output(char *s);
int prompt(int argc, char **argv);
int seperate_word(char *line,
char ***words, int line_size, char *delim);
int _strcmp(const char *s1, const char *s2);
char *_strdup(char *str);
int _strlen(char *s);
char *_strtok(char *str, const char *delim);


#endif
