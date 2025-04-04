#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * open_source - Opens a file for reading.
 * @filename: The source filename.
 * Return: File descriptor on success, exits on failure.
 */
int open_source(char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * open_dest - Opens or creates a file for writing.
 * @filename: The destination filename.
 * Return: File descriptor on success, exits on failure.
 */
int open_dest(char *filename)
{
	int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (fd);
}

/**
 * copy_content - Copies content from src fd to dest fd using a 1KB buffer.
 * @fd_from: Source file descriptor.
 * @fd_to: Destination file descriptor.
 * @src_name: Name of the source file (for error messages).
 * @dest_name: Name of the dest file (for error messages).
 */
void copy_content(int fd_from, int fd_to, char *src_name, char *dest_name)
{
	char buffer[1024];
	ssize_t bytes_read, bytes_write;

	while ((bytes_read = read(fd_from, buffer, 1024)) > 0)
	{
		bytes_write = write(fd_to, buffer, bytes_read);
		if (bytes_write < 0 || bytes_write != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest_name);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}
	if (bytes_read < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src_name);
		close(fd_from);
		close(fd_to);
		exit(98);
	}
}

/**
 * close_fd - Closes a file descriptor, exits on error.
 * @fd: File descriptor to close.
 */
void close_fd(int fd)
{
	if (close(fd) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Entry point. Copies the content of one file to another.
 * @argc: Argument count.
 * @argv: Argument array.
 * Return: 0 on success, various codes on error.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open_source(argv[1]);
	fd_to = open_dest(argv[2]);
	copy_content(fd_from, fd_to, argv[1], argv[2]);
	close_fd(fd_from);
	close_fd(fd_to);
	return (0);
}

