#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>
#include <sys/stat.h>

/* get the "environment" pointer */
extern char **environ;

/* User input handling functions */
char *read_user_input(int *gt_line);
/* Memory handling functions */
void free_arguments(char **arguments);
/* command execution functions */
char *_find_command(char *cmd);
void execute_command(char **command_and_arguments);
/* environment variables */
char *_getenv(const char *var);
void _print_env(void);
/* String manipulation functions */
char **strtow(char *str);
int _strlen(char *s);
char *_strchr(const char *str, int character);
void remove_newline(char *str);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *str1, const char *str2, size_t n);
size_t cs_strlen(const char *str);
char *_strpbrk(const char *str, const char *chars);
char *_strtok(char *str, const char *delim);

#endif
