#include "shell.h"

/**
 * free_recurrent_data - Free the fields needed for each loop.
 * @data: Pointer to the program's data.
 * Return: Nothing.
 *
 * This function frees specific fields in the program's data structure
 * that are used repeatedly within each loop of the shell.
 */

void free_recurrent_data(data_of_program *data)
{
	if (data->tokens)
		free_array_of_pointers(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}

/**
 * free_all_data - Free all fields of the data structure.
 * @data: Pointer to the program's data.
 * Return: Nothing.
 *
 * This function frees all fields within the program's data structure,
 * releasing memory allocated during program execution.
 */
void free_all_data(data_of_program *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	free_recurrent_data(data);
	free_array_of_pointers(data->env);
	free_array_of_pointers(data->alias_list);
}

/**
 * free_array_of_pointers - Frees each pointer in an array of pointers
 * and the array itself.
 * @array: Array of pointers.
 * Return: Nothing.
 *
 * This function releases memory allocated for each pointer in the array
 * and then frees the memory occupied by the array itself.
 */
void free_array_of_pointers(char **array)
{
	int i;

	if (array != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);

		free(array);
		array = NULL;
	}
}
