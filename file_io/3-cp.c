#include "main.h"

/**
 * _errexit - Prints error message and exits.
 * @str: Error message as a string.
 * @file: File name as a string.
 * @code: Exit code.
 */
void _errexit(char *str, char *file, int code)
{
	dprintf(STDERR_FILENO, str, file);
	exit(code);
}

/**
 * _cp - Copies source file to destination file.
 * @file_from: Source file.
 * @file_to: Destination file.
 */
void _cp(char *file_from, char *file_to)
{
	int fd1, fd2, numread, numwrote;
	char buffer[1024];

	fd1 = open(file_from, O_RDONLY);
	if (fd1 == -1)
		_errexit("Error: Can't read from file %s\n", file_from, 98);

	fd2 = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd2 == -1)
		_errexit("Error: Can't write to %s\n", file_to, 99);

	numread = 1024;
	while (numread == 1024)
	{
		numread = read(fd1, buffer, 1024);
		if (numread == -1)
			_errexit("Error: Can't read from file %s\n", file_from, 98);

		numwrote = write(fd2, buffer, numread);
		if (numwrote == -1)
			_errexit("Error: Can't write to %s\n", file_to, 99);
	}

	if (close(fd2) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd2);
		exit(100);
	}
	if (close(fd1) == -1)
	{
		/* Fixed: print fd1, not fd2 */
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd1);
		exit(100);
	}
}

/**
 * main - Copies a file to another file.
 * @argc: Number of arguments.
 * @argv: Array containing arguments.
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
	_cp(argv[1], argv[2]);
	return (0);
}

