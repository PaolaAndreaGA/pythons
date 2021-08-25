#include "shell.h"

/**
 * prompt - function that prints the $
 * character in the terminal.
 * Description: this function shows
 * the $ character in the console to
 * indicate that it is inside the shell
 * terminal
 */
void prompt(void)
{
	char *prompt = "$: ";

	/**
	 * isatty(): Determines if a file descriptor, fildes,
	 * is associated with a terminal
	 * isatty() returns 1 if the given file descriptor
	 * is a terminal, or 0 otherwise.
	 */
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
	}
}

/**
 * _getline - Gets line of user input
 * Return: Pointer to buffer of user input
 */
char *_getline(void)
{
	int temp;
	char *line = NULL;
	size_t size = 0;

	temp = getline(&line, &size, stdin);
	if (temp == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
		exit(0);
	}
	return (line);
}

