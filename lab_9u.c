#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("lab9.txt", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    char buffer[256];
    ssize_t n;

    while ((n = read(fd, buffer, 256)) > 0) {
        write(1, buffer, n);  // Write to stdout (FD 1)
    }

    close(fd);  // Release file descriptor

    return 0;
}
