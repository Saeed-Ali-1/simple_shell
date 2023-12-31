#include "shell.h"

/**
 * _print - Write an array of characters to standard output.
 * @string: Pointer to the array of characters.
 * Return: The number of bytes written.
 * On error, -1 is returned, and errno is set appropriately.
 *
 * This function writes the given array of characters to the standard output.
 */
int _print(char *string)
{
	return (write(STDOUT_FILENO, string, str_length(string)));
}

/**
 * _printe - Write an array of characters to standard error.
 * @string: Pointer to the array of characters.
 * Return: The number of bytes written.
 * On error, -1 is returned, and errno is set appropriately.
 *
 * This function writes the given array of characters to the standard error.
 */
int _printe(char *string)
{
	return (write(STDERR_FILENO, string, str_length(string)));
}

/**
 * _print_error - Write an error message to standard error.
 * @errorcode: The error code to print.
 * @data: A pointer to the program's data.
 * Return: 0 on success.
 * On error, -1 is returned, and errno is set appropriately.
 *
 * This function prints an error message to the standard error (stderr)
 * based on the provided error code and program's data.
 */

int _print_error(int errorcode, data_of_program *data)
{
	char n_as_string[10] = {'\0'};

	long_to_string((long) data->exec_counter, n_as_string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->tokens[0]);
		if (errorcode == 2)
			_printe(": Illegal number: ");
		else
			_printe(": can't cd to ");
		_printe(data->tokens[1]);
		_printe("\n");
	}
	else if (errorcode == 127)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": not found\n");
	}
	else if (errorcode == 126)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": Permission denied\n");
	}
	return (0);
}
