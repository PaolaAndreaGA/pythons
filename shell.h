#ifndef _SHELL_
#define _SHELL_
#include <dirent.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* global constants */
#define TOKENS_BUFFER_SIZE 64
#define LINE_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"

extern char **environ;

/**
 * struct builtins - Has builtins and associated funcs
 * @argument: Builtins name
 * @builtin: Mathcing builtin func
 */
typedef struct builtins
{
	char *argument;
	void (*builtin)(char **arguments, char *line_input, char **environment);

} builtins_t;

/* start function -> prompt.c */
void prompt(void);
char *_getline(void);
int shell(int argument_count, char **argument_vector, char **environment);

/* function of support -support.c */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_getenv(char *env);
char *_strstr(char *haystack, char *needle);
char **tokenization(char *line);

/* builtins -> checker.c */
int checker(char *check, char **args);
int check_for_builtins(char **args, char *line, char **env);
int builtins_checker(char **args);

/*exe.c  */
int execute(char **args, char *line, char **env, int flow);
int launch_prog(char **args);

/* PATH function -> path.c */
char *get_cwd(char *filename, char *er);
char *find_path(char *args, char *tmp, char *er);
char *save_path(char *tmp, char *path);
char *read_dir(char *er, struct dirent *s, char *fi, int l, char *p, char *t);

/* function of the shell -> mandatory.c  */
void exit_shell(char **args, char *line, char **env);
void env_shell(char **args, char *line, char **env);

#endif
