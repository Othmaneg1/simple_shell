#ifndef SHELL_H
#define SHELL_H

/*header files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

/*Global variables*/
extern char **environ;

/*Macros*/
#define BUFSIZE 256
#define TOKENSIZE 64
#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define PROMPT "$ "
#define SUCCESS (1)
#define FAIL (-1)
#define NEUTRAL (0)

/*Struct */
/**
 * struct sh_data - Global data structure
 * @line: the line input
 * @args: the arguments token
 * @error_msg: the global path
 * @cmd: the parsed command
 * @index: the command index
 * @oldpwd: the old path visited
 * @env: the environnment
 * Description: this structure has all t variables needed to deal with
 * the program and mmory also acces */
typedef struct sh_data
{
	char *line;
	char **args;
	char *cmd;
	char *error_msg;
	char *oldpwd;
	unsigned long int index;
	char *env;
} sh_t;
/**
 * struct builtin - Manage the builtin functions
 * @cmd: the command line in a string
 * @f: the associated function
 * Description: this strctre manage biltin commands
 */
typedef struct builtin
{
	char *cmd;
	int (*f)(sh_t *data);
} blt_t;
/*Process prototype*/
int read_line(sh_t *);
int split_line(sh_t *);
int parse_line(sh_t *);
int process_cmd(sh_t *);
/*Tools prototype*/
void *fill_array(void *a, int el, unsigned int len);
void signal_hlr(int signo);
char _chpath(char *path_name);
void cmd_of_index(sh_t *data);
void rev_array(char *arr, int len);

/*2.tools prototype*/
char *_ita(unsigned int n);
int lens(int num);
int _atoi(char *c);
int print_error(sh_t *data);
int write_his(sh_t *data);
int _alpha(int c);

/*Builtins*/
int abort_prg(sh_t *data);
int change_dir(sh_t *data);
int display_help(sh_t *data);
int handle_builtin(sh_t *data);
int check_builtin(sh_t *data);

/*Prc*/
int path_form(sh_t *data);
void short_form(sh_t *data);
int builtin(sh_t *data);


/*String prototype*/
char *_strdup(char *str);
char *_strcat(char *first, char *second);
int _strlen(char *str);
char *_strchr(char *str, char c);
int _strcmp(char *s1, char *s2);

/* 2.Strings prototype*/
char *__srgcoy(char *dest, char *source);

/*Memory prototype*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memset(char *s, char byt, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
int free_data(sh_t *);


#endif /* SHELL_H */
