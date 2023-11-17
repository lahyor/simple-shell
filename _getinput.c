#include "shell.h"

/**
 * _getline - Read Input
 *
 * Return: Always 0 (success)
 */
char *_getinput()
{
	int i = 0;
	size_t nread;
	char c = 0;
	char *buffer = malloc(sizeof(char) * 1);

	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	while (c != EOF && c != '\n')
	{
		fflush(stdin);
		nread = read(STDIN_FILENO, &c, 1);
		if (nread == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		if (nread == -1)
		{
			free(buffer);
			perror("Error: ");
		}
		buffer[i] = c;
		if (buffer[0] == '\n')
		{
			free(buffer);
			return ("\0");
		}
		if (i + 1 >= BUFFER_SIZE)
		{
			buffer = _realloc(buffer,  i + 1);
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	buffer[i] = '\0';
	return (buffer);
}