#include "shell.h"
/**
 * checker - Will check to see whether we are dealing with a builtin or not
 * @check: Figures out what to execute
 * @args: Arguments passed from cmdline broken up
 * Return: 1 if user entered a path/builtin, 2 if user entered a binary
 */

/* ls -> args[0] = ls, args=[ls] */
int checker(char *check, char **args)
{
	int i = 0;

	/* args=[ls]  = 0*/
	if (builtins_checker(args) == 1)
		return (1);
	while (check[i] != '\0')
	{
		if (check[i] == '/')
			return (1);
		i++;
	}
	return (2);
}

/**
 * check_for_builtins - Checks for builtins
 * @args: Arguments passed from prompt
 * @line: Buffer with line of input from user
 * @env: Environment
 * Return: 1 if builtins exist, 0 if they don't
 */
int check_for_builtins(char **args, char *line, char **env)
{
	builtins_t list[] = {
		{"exit", exit_shell},
		{"env", env_shell},
		{NULL, NULL}
	};
	int i;

	for (i = 0; list[i].argument != NULL; i++)
	{
		if (_strcmp(list[i].argument, args[0]) == 0)
		{
			list[i].builtin(args, line, env);
			return (1);
		}
	}
	return (0);
}

/**
 * builtins_checker - Checks for builtins
 * @args: Arguments passed from prompt
 * Return: 1 if builtins exist, 0 if they don't
 */

/* args=[ls] */
int builtins_checker(char **args)
{
	int i;
	builtins_t list[] = {
		{"exit", exit_shell},
		{"env", env_shell},
		{NULL, NULL}};

	for (i = 0; list[i].argument != NULL; i++)
	{
		if (_strcmp(list[i].argument, args[0]) == 0)
			return (1);
	}
	return (0);
}
