#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

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
 * copy_loop - Reads from fd_from and writes to fd_to, all errors => exit(98).
 * @fd_from: File descriptor for the source file.
 * @fd_to: File descriptor for the destination file.
 * @file_from: Name of the source file (used in error messages).
 */
static void copy_loop(int fd_from, int fd_to, const char *file_from)
{
	ssize_t r, w;
	char buffer[1024];

	while ((r = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
		{
			safe_close(fd_from);
			safe_close(fd_to);
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
				file_from);
			exit(98);
		}
	}
	if (r == -1)
	{
		safe_close(fd_from);
		safe_close(fd_to);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
			file_from);
		exit(98);
	}
}

/**
 * main - copies the content of a file to another file.
 * @argc: Number of arguments
 * @argv: Argument vector
 *
 * Return: 0 on success, or exits with specific codes on errors.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
			argv[1]);
		exit(98);
	}
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		safe_close(fd_from);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
			argv[1]);
		exit(98);
	}
	copy_loop(fd_from, fd_to, argv[1]);
	safe_close(fd_from);
	safe_close(fd_to);
	return (0);
}

