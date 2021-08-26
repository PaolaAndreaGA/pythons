#include "shell.h"

/**
 * main - Entry point for shell, handles args to shell
 * @argument_count: Arg count
 * @argument_vector: args vector
 * @environment: Environment
 * Return: 0;
 */
int main(int argument_count, char **argument_vector, char **environment)
{
	if (!argument_count)
		(void)argument_count;
	if (!argument_vector)
		(void)argument_vector;
	if (!environment)
		(void)environment;
	shell(argument_count, argument_vector, environment);
	return (0);
}
