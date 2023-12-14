#include "shell.h"

/**
 * tokenize - Breaks down a string into tokens using specified delimiters.
 * @data: Pointer to the program's data,
 * containing the input string to tokenize.
 *
 * This function segments the string stored in 'data->input_line' into separate
 * tokens based on the specified delimiters,
 * primarily spaces and tabs (' ' and '\t').
 * It then allocates memory to store these tokens in 'data->tokens'
 * as an array of strings.
 * The 'data->command_name' is set to the first token found.
 */
void tokenize(data_of_program *data)
{
	char *delimiter = " \t";
	int i, j, counter = 2, length;

	length = str_length(data->input_line);
	if (length)
	{
		if (data->input_line[length - 1] == '\n')
			data->input_line[length - 1] = '\0';
	}

	for (i = 0; data->input_line[i]; i++)
	{
		for (j = 0; delimiter[j]; j++)
		{
			if (data->input_line[i] == delimiter[j])
				counter++;
		}
	}

	data->tokens = malloc(counter * sizeof(char *));
	if (data->tokens == NULL)
	{
		perror(data->program_name);
		exit(errno);
	}
	i = 0;
	data->tokens[i] = str_duplicate(_strtok(data->input_line, delimiter));
	data->command_name = str_duplicate(data->tokens[0]);
	while (data->tokens[i++])
	{
		data->tokens[i] = str_duplicate(_strtok(NULL, delimiter));
	}
}
