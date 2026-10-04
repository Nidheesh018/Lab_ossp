#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_NAME "/tmp/my_fifo"

int main() {
    printf("[Process B] Opening FIFO to read...\n");
    int fd = open(FIFO_NAME, O_RDONLY); // Blocks until Process A opens for writing

    char buffer[100];
    read(fd, buffer, sizeof(buffer));
    printf("[Process B] Received: %s\n", buffer);

    close(fd);
    unlink(FIFO_NAME); // Delete the FIFO file from /tmp
    return 0;
}
