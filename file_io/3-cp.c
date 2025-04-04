#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * open_source - Opens a file for reading.
 * @filename: The source filename.
 *
 * Return: File descriptor on success, exits on failure with code 98.
 */
int open_source(char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
			filename);
		exit(98);
	}
	return (fd);
}

/**
 * open_dest - Opens or creates a file for writing, truncates if it exists.
 * @filename: The destination filename.
 *
 * Return: File descriptor on success, exits on failure with code 99.
 */
int open_dest(char *filename)
{
	int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n",
			filename);
		exit(99);
	}
	return (fd);
}

/**
 * copy_content - Copies content from src fd to dest fd using a 1024-byte buffer.
 * @fd_from: Source file descriptor.
 * @fd_to: Destination file descriptor.
 * @src_name: Name of source file (for error messages).
 * @dest_name: Name of destination file (for error messages).
 *
 * Exits with:
 *   98 if read() fails,
 *   99 if write() fails or doesn't match bytes read.
 */
void copy_content(int fd_from, int fd_to, char *src_name, char *dest_name)
{
	char buffer[1024];
	ssize_t bytes_read, bytes_written;

	/* Keep reading until read returns 0 (EOF) or < 0 (error). */
	while ((bytes_read = read(fd_from, buffer, 1024)) != 0)
	{
		if (bytes_read < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
				src_name);
			close(fd_from);
			close(fd_to);
			exit(98);
		}
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written < 0 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n",
				dest_name);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}
}

/**
 * close_fd - Closes a file descriptor, exits on error with code 100.
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
 * main - Copies the content of one file to another.
 * @argc: Argument count (must be exactly 3).
 * @argv: Argument array: cp file_from file_to
 *
 * Return: 0 on success, or various exit codes on error:
 *    97: Incorrect argument count
 *    98: Cannot read from file_from
 *    99: Cannot create/write to file_to
 *   100: Cannot close file descriptor
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

