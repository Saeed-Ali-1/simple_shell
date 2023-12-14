#include "shell.h"

/**
 * execute - Executes a command with its full path variables.
 * @data: Pointer to the program's data.
 * Return: Returns 0 on success, -1 on failure.
 */
int execute(data_of_program *data)
{
	int retval = 0, status;
	pid_t pidd;
	/* Check if the program is a built-in */
	retval = builtins_list(data);
	if (retval != -1)
	{/* If program found in built-ins */
		return (retval);
	}
	/* Check for program in the file system */
	retval = find_program(data);
	if (retval)
	{/* if program not found */
		return (retval);
	}
	else
	{/* If program was found */
		pidd = fork(); /* create a child process */
		if (pidd == -1)
		{ /* If the fork call failed */
			perror(data->command_name), exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{
			/* Child process executes the program */
			retval = execve(data->tokens[0], data->tokens, data->env);
			if (retval == -1)
			{/* If there's an error with execve */
				perror(data->command_name), exit(EXIT_FAILURE);
			}
		}
		else
		{/* Parent process waits and checks the exit status of the child */
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
