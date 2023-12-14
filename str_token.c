#include "shell.h"

/**
 * _strtok - Splits a string into tokens using specified delimiters.
 * @line: Pointer to the array received from getline,
 * containing the string to tokenize.
 * @delim: Characters used as delimiters to segment the string.
 *
 * This function separates the string pointed to by 'line' into tokens,
 * using characters in 'delim' as the delimiters to mark off each token.
 *
 * Return: A pointer to the created token, or NULL if no token is found.
 */
char *_strtok(char *line, char *delim)
{
	/* Function variables*/
	int j;
	static char *str;
	char *copystr;

	/* Check if the line is not NULL, set 'str' accordingly*/
	if (line != NULL)
		str = line;

	/* Loop through the string until a delimiter is found*/
	for (; *str != '\0'; str++)
	{
		/* Check each character against the delimiters*/
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
			break;
		}
		/* Break if the delimiter is found*/
		if (delim[j] == '\0')
			break;
	}
	/* Copy the starting address of the token*/
	copystr = str;
	if (*copystr == '\0')
		return (NULL);
	 /* Loop through the string to find the end of the token*/
	for (; *str != '\0'; str++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
			{
				*str = '\0';
				str++;
				return (copystr);
			}
		}
	}
	return (copystr);
}
