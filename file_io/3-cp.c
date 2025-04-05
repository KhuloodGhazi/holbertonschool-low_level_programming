#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(97); // Example error code for incorrect usage
    }

    int source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        exit(98); // Example error code for open failure
    }

    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Error opening destination file");
        close(source_fd);
        exit(99); // Example error code for open failure
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written == -1) {
            perror("Error writing to destination file");
            close(source_fd);
            close(dest_fd);
            exit(100); // Example error code for write failure
        }
    }

    if (bytes_read == -1) {
        perror("Error reading from source file");
        close(source_fd);
        close(dest_fd);
        exit(98); // This is the likely error code you need to return
    }

    if (close(source_fd) == -1) {
        perror("Error closing source file");
        exit(101);
    }
    if (close(dest_fd) == -1) {
        perror("Error closing destination file");
        exit(102);
    }

    return 0;
}
