#include "shell.h"

/**
 * shell_cd - Bultin command change directory.
 * @args: List of args.  args[0] is "cd".  args[1] is the directory.
 * return: Always returns 1, to continue executing.
 */
int shell_cd(char **args)
{
	if (args[1] == NULL)
		fprintf(stderr, "shell: expected argument to \"cd\"\n");
	else
	{
		if (chdir(args[1]) != 0)
			perror("shell");
	}
	return (1);
}


/**
 * shell_help - Builtin command: print help.
 * @args: List of args.  Not examined.
 * return: Always returns 1, to continue executing.
 */
int shell_help(char **args)
{
	int i;
	printf("Simple Shell\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < shell_num_builtins(); i++)
		printf("  %s\n", builtin_str[i]);

	printf("Use the man command for information on other programs.\n");
	return (1);
}


  /**
   * shell_exit - Builtin command: .
   * @args: List of args.  Not examined.
   * return: Always returns 0, to terminate execution.
   */
int shell_exit(char **args)
{
	return (0);
}

/**
 * shell_num_builtins - Builtin command: .
 * @args: List of args.  Not examined.
 * return: Always returns 0, to terminate execution.
 */
int shell_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}
