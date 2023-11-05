#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>
#include <sys/stat.h>

/* User input handling functions */
char *read_user_input(int *gt_line);
/* Memory handling functions */
void free_arguments(char **arguments);
/* command execution functions */
void execute_command(char **command_and_arguments, char **env);
/* String manipulation functions */
char **strtow(char *str);
int _strlen(char *s);
char *_strchr(const char *str, int character);
void remove_newline(char *str);


#endif