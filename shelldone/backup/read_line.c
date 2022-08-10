#include "shell.h"
/**
 * shell_read_line - Read a line of input from stdin.
 * @return: The line from stdin.
 */
char *shell_read_line(void)
{
#define SHELL_RL_BUFSIZE 1024
	int bufsize = SHELL_RL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		fprintf(stderr, "shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
	// Read a character
	c = getchar();
	if (c == EOF)
		exit(EXIT_SUCCESS);
	else if (c == '\n')
	{
		buffer[position] = '\0';
		return (buffer);
	}
	else
		buffer[position] = c;
	position++;

	// If we have exceeded the buffer, reallocate.
	if (position >= bufsize)
	{
		bufsize += SHELL_RL_BUFSIZE;
		buffer = realloc(buffer, bufsize);
		if (!buffer)
		{
			fprintf(stderr, "shell: allocation error\n");
			exit(EXIT_FAILURE);
		}
	}
	}
/* #endif */
}
