#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * open_source - Open a file for reading.
 * @filename: The source file name.
 * Return: File descriptor, or exit(98) on error.
 */
int open_source(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * open_dest - Open or create a file for writing.
 * @filename: The destination file name.
 * Return: File descriptor, or exit(99) on error.
 */
int open_dest(char *filename)
{
	int fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (fd);
}

/**
 * copy_content - Copy data from fd_from to fd_to in 1024-byte chunks.
 * @fd_from: Source descriptor.
 * @fd_to: Destination descriptor.
 * @src: Source name (for errors).
 * @dest: Destination name (for errors).
 */
void copy_content(int fd_from, int fd_to, char *src, char *dest)
{
	char buffer[1024];
	ssize_t rd, wr;

	while ((rd = read(fd_from, buffer, 1024)) != 0)
	{
		if (rd < 0)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", src);
			close(fd_from);
			close(fd_to);
			exit(98);
		}
		wr = write(fd_to, buffer, rd);
		if (wr < 0 || wr != rd)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", dest);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}
}

/**
 * close_fd - Close a file descriptor, exit(100) on error.
 * @fd: File descriptor.
 */
void close_fd(int fd)
{
	int c;

	c = close(fd);
	if (c < 0)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copy the content of one file to another.
 * @ac: Argument count (must be 3).
 * @av: Arguments: cp file_from file_to
 * Return: 0 on success, or exit codes 97, 98, 99, 100 on error.
 */
int main(int ac, char *av[])
{
	int fd_from, fd_to;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO,
			"Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open_source(av[1]);
	fd_to = open_dest(av[2]);
	copy_content(fd_from, fd_to, av[1], av[2]);
	close_fd(fd_from);
	close_fd(fd_to);
	return (0);
}

