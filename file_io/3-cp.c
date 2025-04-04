#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * safe_close - Closes a file descriptor and exits with code 100 on error.
 * @fd: The file descriptor to close.
 */
static void safe_close(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_loop - Reads from fd_from and writes to fd_to.
 * @fd_from: File descriptor for the source file.
 * @fd_to: File descriptor for the destination file.
 * @file_from: Name of the source file.
 * @file_to: Name of the destination file.
 */
static void copy_loop(int fd_from, int fd_to, const char *file_from,
		      const char *file_to)
{
	ssize_t r, w;
	char buffer[1024];

	while (1)
	{
		r = read(fd_from, buffer, sizeof(buffer));
		if (r == -1)
		{
			safe_close(fd_from);
			safe_close(fd_to);
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", file_from);
			exit(98);
		}
		if (r == 0)
			break;
		w = write(fd_to, buffer, r);
		if (w == -1 || (size_t)w != (size_t)r)
		{
			safe_close(fd_from);
			safe_close(fd_to);
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file_to);
			exit(99);
		}
	}
}

/**
 * copy_file - Copies the content of file_from to file_to.
 * @file_from: Source file name.
 * @file_to: Destination file name.
 *
 * Return: 0 on success.
 */
int copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		safe_close(fd_from);
		exit(99);
	}
	copy_loop(fd_from, fd_to, file_from, file_to);
	safe_close(fd_from);
	safe_close(fd_to);
	return (0);
}

/**
 * main - Entry point; copies content from one file to another.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	copy_file(argv[1], argv[2]);
	return (0);
}
