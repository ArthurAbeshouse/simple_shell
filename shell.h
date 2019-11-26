#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

extern char **environ;
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int loop(void);
char **token(char *buff, char *delim);
char *get_env(char **str);
int parse(char **args);
int lsh_launch(char **args);
int spec(char **argv);
int fork(void);
int _strlen(char *s);
int _putchar(char c);
int _env(void);
int main(int argc, char **argv, char **env);
void ctrl_c(int n);
void _puts(char *str);
char **checkPaths(char **cmd);
int commandChecker(char **cmd);
int _execute(char **argv);
int _strcount(char *buff);
int cy(char *toCheck);
int checkAccess(char *path);

#endif
