#include "shell.h"

/**
 * main - this function start the shell
 * @argument_count: console writer argument numbers.
 * @argument_vector: is the array of arguments.
 * @environment: is the array of paths of the environment
 * Return: return 0
 */

int shell(int argument_count, char **argument_vector, char **environment)
{
	char **argument_array, *line_input, *file_name, *tmp_size = NULL;
	char *error = "Error";
	int route, status = 1;

	do {
		prompt();
		line_input = _getline();
		if (_strlen(line_input) > 1)
		{
			argument_array = tokenization(line_input);
			route = checker(argument_array[0], argument_array);
			if (route == 2)
			{
				file_name = argument_array[0];
				argument_array[0] = find_path(argument_array[0], tmp_size, error);
			if (argument_array[0] == error)
			{
				argument_array[0] = get_cwd(file_name, error);
				if (argument_array[0] == file_name)
					write(1, error, 5);
			}
			}
			if (argument_array[0] != error)
				status = execute(argument_array, line_input, environment, route);
			free(argument_array);
		}
		free(line_input);

	} while (status);
	if (!argument_count)
		(void)argument_count;
	if (!argument_vector)
		(void)argument_vector;
	if (!environment)
		(void)environment;
	return (0);
}
