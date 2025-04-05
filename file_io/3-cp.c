#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - An helper function to handle errors print and exit
 *
 * @code: The exit code to return
 * @msg: The error message to be printed
 * @arg: A string of arguments for message
 *
 * Return: Nothing
 */

void error_exit(int code, char *msg, int arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * error_exit_str - An helper function to print a message with string and exit
 *
 * @code: The exit code to return
 * @msg: The error message to be printed
 * @arg: A string of arguments for message
 */

void error_exit_str(int code, char *msg, char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * copy - Helper function to copy file content
 *
 * @f_f: The source file descriptor
 * @f_t: The destination files descriptor
 * @sr: The source of the file
 * @des: The destination of the file
 * @f_buf: The first buffer read
 * @f_b: The number of bytes inside the first buffer
 *
 * Return: Noting
 */

void copy(int f_f, int f_t, char *sr, char *des, char *f_buf, ssize_t f_b)
{
	char buffer[BUFFER_SIZE];
	ssize_t b_read, b_wr;

	b_wr = write(f_t, f_buf, f_b);
	if (b_wr == -1)
	{
		close(f_f);
		close(f_t);
		error_exit_str(99, "Error: Can't write to %s\n", des);
	}

	while ((b_read = read(f_f, buffer, BUFFER_SIZE)) > 0)
	{
		b_wr = write(f_t, buffer, b_read);
		if (b_wr == -1)
		{
			close(f_f);
			close(f_t);
			error_exit_str(99, "Error: Can't write to %s\n", des);
		}
	}

	if (b_read == -1)
	{
		close(f_f);
		close(f_t);
		error_exit_str(98, "Error: Can't read from file %s\n", sr);
	}
}


/**
 * main - Entry point
 *
 * @argc: Argument counts
 * @argv: Values of arguments
 *
 * Return: 0 for success, various code for failures
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;

	if (argc != 3)
		error_exit_str(97, "Usage: cp file_from file_to\n", "");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit_str(98, "Error: Can't read from file %s\n", argv[1]);

	bytes_read = read(fd_from, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		close(fd_from);
		error_exit_str(98, "Error: Can't read from file %s\n", argv[1]);
	}

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit_str(99, "Error: Can't write to %s\n", argv[2]);
	}

	copy(fd_from, fd_to, argv[1], argv[2], buffer, bytes_read);

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd %d\n", fd_from);
	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd %d\n", fd_to);

return (0);
}
