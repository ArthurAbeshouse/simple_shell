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

typedef struct list_s
{
	char *var;
	unsigned int len;
	struct list_s *next;
} list_t;

char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
size_t print_list(list_t *h);
list_t *add_node_end(list_t **head, char *str);
int delete_nodeint_at_index(list_t **head, int index);
void free_linked_list(list_t *head);
int loop(void);
char **token(char *buff);
char *get_env(char **str);
int parse(char **args);
int lsh_launch(char **args);
int spec(char *argv);
int fork(void);
int _strlen(char *s);
void _puts_recursion(char *s);
int _putchar(char c);
int _env(void);
int main(int argc, char **argv, char **env);
void ctrl_c();
int _execve();

#endif
