#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * create_file - Creates a file with the given filename and writes the given
 * text content to it.
 * @filename: Name of the file to create.
 * @text_content: A NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure (if the file cannot be created, written,
 *         or if any system call fails).
 */
int create_file(const char *filename, char *text_content)
{
	int fd, wr;
	size_t len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	/* If text_content is not NULL, write it; otherwise, create an empty file */
	if (text_content)
	{
		for (len = 0; text_content[len]; len++)
			;
		wr = write(fd, text_content, len);
		if (wr == -1 || (size_t)wr != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

