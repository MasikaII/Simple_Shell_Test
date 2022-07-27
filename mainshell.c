#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * main - Shell Main Function
 *
 * Return: Integer Value
 */

int main(void)
{
	int val;
	int i;
	char *argv[] = {" ", "-1", NULL};
	size_t n = 10;
	char *buff = NULL;

	while (1)
	{
		printf("#Ace-;)$ ");
		getline(&buff, &n, stdin);
		i = strlen(buff);
		buff[i - 1] = '\0';
		argv[0] = buff;
		val = execve(argv[0], argv, NULL);
		if (val == -1)
			perror("./shell");
	}
	printf("Done with execve\n");
	free(buff);

	return (0);
}

