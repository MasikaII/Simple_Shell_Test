#include "shell.h"

/**
 * main - main shell function
 * return: Exit Success
 */
int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("$ ");
		line = shell_read_line();
		args = shell_split_line(line);
		status = shell_execute(args);

		free(line);
		free(args);
	} while (status);

	return (EXIT_SUCCESS);
}
