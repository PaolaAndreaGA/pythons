#include "shell.h"
/**
 * execute - Executes binary or builtin
 * @args: Argument buffer
 * @line: Line buffer
 * @env: Environment
 * @flow: Helps decide what code to run
 * Return: 1 if success
 */

int execute(char **args, char *line, char **env, int flow)
{
	int status;

	if (args[0] == NULL)
		return (1);
	if (flow == 1)
	{
		if (check_for_builtins(args, line, env) == 1)
			return (1);
	}
	status = launch_prog(args);
	return (status);
}

/**
 * launch_prog - Forks and launches unix cmd
 * @args: Args for cmd
 * Return: 1 on success
 */
int launch_prog(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Failed to execute command\n");
			exit(0);
		}
	}
	else if (pid < 0)
	{
		perror("Error forking\n");
		exit(0);
	}
	else
	{
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && WIFSIGNALED(status));
	}
	(void)wpid;
	return (1);
}
