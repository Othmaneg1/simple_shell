#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stddef.h>

extern char **environ;

/* exit_func.c */
void ext_func(char **argv, char *ptr_line, int ext);
void get_envi(char **env);

/* fork_func.c */
int fork_func(char *arg[], char *av[], char *envi[],
		char *ptr_line, int pidd, int checker);

/* get_path_func.c */
char *get_path(char **env);

/* get_token_func.c */
char **get_token(char *ptr_line);

/* get_cmd_func.c */
char *getline_cmd(void);

/* ptr_cmd.c */
void prt_cmd(void);

/* path_seperator.c */
int path_sepetator(char **arg, char **env);

/* prt_cmd.c */
void prt_cmd(void);

/* Helper functions */
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);

int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, const char *src);

char *_strtok(char *str, const char *delim);
size_t _strcspn(char *s1, char *s2);

unsigned int _strspn(char *s, char *accept);
char *_strchr(char *s, char c);
char *_strdup(const char *src);
#endif
