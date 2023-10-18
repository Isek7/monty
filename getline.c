#include "monty.h"
/**
 * getline - Read a line from a file stream
 * @lineptr: A pointer to a buffer where the line will be stored
 * @n: A pointer to the size of the buffer
 * @stream: The file stream to read from
 *
 * Return: The number of bytes read, or -1 on failure
 */
ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufsize = 128, count = 0;
	int c, flag = 0;
	char *buffer, *temp;

	if (!lineptr || !n || !stream)
		return (errno = EINVAL, -1);

	if (count == bufsize)
		return (errno = ENOMEM, -1);

	while (1)
	{
		c = fgetc(stream);
		if (count == bufsize)
		{
			temp = realloc(buffer, bufsize *= 2);
			if (!temp)
				return (free(buffer), errno = ENOMEM, -1);
			buffer = temp;
		}
		buffer[count++] = c;
		if (c == EOF || c == '\n')
		{
			flag = 1;
			break;
		}
	}

	if (!count && !flag)
		return (free(buffer), -1);

	temp = realloc(buffer, count);
	if (!temp)
		return (free(buffer), errno = ENOMEM, -1);
	buffer = temp;

	*lineptr = buffer;
	*n = count;

	return (count);
}
