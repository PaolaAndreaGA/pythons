#include "shell.h"

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: Difference of first nonmatching character
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
		{
			i++;
			continue;
		}
		else
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}

/**
 * _strlen - a function that returns the length of a string
 * @s: char input
 * Return: length of the input string
 */
int _strlen(char *s)
{
	int i = 1, sum = 0;
	char pl = s[0];

	while (pl != '\0')
	{
		sum++;
		pl = s[i++];
	}
	return (sum);
}

/**
 * _getenv - gets env of input
 * @env: input
 * Return: env without =
 */
char *_getenv(char *env)
{
	int i = 0, n = 0;
	char *temp, *res;

	while (environ[i] != NULL)
	{
		if (_strcmp(environ[i], env) == 0)
			temp = environ[i];
		i++;
	}

	while (temp[n] != '\0')
	{
		if (_strcmp(temp, env) == 0)
			res = _strstr(temp, "/");
		n++;
	}
	return (res);
}

/**
 * _strstr - locates sub string
 * @haystack: input one
 * @needle: input two
 * Return: sub string
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *one = haystack;
		char *two = needle;

		while (*one == *two && *two != '\0')
		{
			one++;
			two++;
		}

		if (*two == '\0')
			return (haystack);
	}

	return (NULL);
}

/**
 * tokenization - Splits line into args
 * @line: Line of user input
 * Return: Array of args of user input
 */
char **tokenization(char *line)
{
	size_t buffer_size = TOKENS_BUFFER_SIZE;
	char **tokens = malloc(sizeof(char *) * buffer_size);
	char *token;
	int pos = 0;

	if (!tokens)
	{
		perror("Could not allocate space for tokens\n");
		exit(0);
	}
	token = strtok(line, TOKEN_DELIMITERS);
	while (token)
	{
		tokens[pos] = token;
		token = strtok(NULL, TOKEN_DELIMITERS);
		pos++;
	}
	tokens[pos] = NULL;
	return (tokens);
}
