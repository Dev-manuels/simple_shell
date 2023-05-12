#ifndef _MAIN_H
#define _MAIN_H

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
char *get_path(char *cmd);
int output(char *s);
int prompt(void);
int seperate_word(char *line, char *line_cpy,
char ***words, size_t line_size, char *delim);
int _strcmp(const char *s1, const char *s2);
char *_strdup(char *str);
int _strlen(char *s);
char *_strtok(char *str, const char *delim);


#endif