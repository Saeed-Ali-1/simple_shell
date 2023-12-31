#ifndef HELPERS_H
#define HELPERS_H

/* Prompt to be printed */
#define PROMPT_MSG "$" /* Needed to work with signals */

/* Resume from the unused attribute */
#define UNUSED __attribute__((unused))

/* Buffer size for each read call in _getline */
#define BUFFER_SIZE 1024

/************* FORMATTED STRING FOR HELP BUILT-IN **************/

#define HELP_CD_MSG "cd=\n" \
"cd:\tcd [dir]\n\n" \
"	Change the shell working directory.\n\n" \
"	If no argument is given to cd, the command will be interpreted\n" \
"	as cd $HOME.\n" \
"	If the argument is '-', the command will be interpreted\n" \
"	as cd $OLDPWD.\n\n"

#define HELP_EXIT_MSG "exit=\n" \
"exit:\texit [STATUS]\n\n" \
"	Exit of the simple-shell.\n\n" \
"	Exits the shell with a status of N. If N is omitted, the exit status\n" \
"	is that of the last command executed.\n\n"

#define HELP_ENV_MSG "env=\n" \
"env:\tenv \n\n" \
"	Print environment.\n\n" \
"	The env command will print a complete list of environment variables.\n\n"

#define HELP_SETENV_MSG "setenv=\n" \
"setenv:\tsetenv VARIABLE VALUE\n\n" \
"	Change or add an environment variable.\n\n" \
"	Initializes a new environment variable or modifies an existing one.\n" \
"	When an incorrect number of arguments is provided, it prints an error message.\n\n"

#define HELP_UNSETENV_MSG "unsetenv=\n" \
"unsetenv:\tunsetenv VARIABLE\n\n" \
"	Delete one variable from the environment.\n\n" \
"	When an incorrect number of arguments is provided, it prints an error message.\n\n"

#define HELP_MSG "help=\n" \
"help:\thelp [BUILTIN_NAME]\n\n" \
"	Display information about built-in commands.\n\n" \
"	Displays brief summaries of built-in commands. If BUILTIN_NAME is\n" \
"	specified, gives detailed help on all commands matching BUILTIN_NAME,\n" \
"	otherwise, the list of help topics is printed for BUILTIN_NAME list.\n" \
"	Arguments:\n\n" \
"	BUILTIN_NAME specifying a help topic.\n\n" \
"	cd\t[dir]\n" \
"	exit\t[status]\n" \
"	env\n" \
"	setenv\t[variable value]\n" \
"	unset\t[variable]\n" \
"	help\t[built_name]\n\n"

#endif

