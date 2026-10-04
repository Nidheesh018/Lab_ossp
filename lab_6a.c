#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/my_fifo"

int main() {
    mkfifo(FIFO_NAME, 0666); // Create FIFO file

    printf("[Process A] Opening FIFO to write...\n");
    int fd = open(FIFO_NAME, O_WRONLY); // Blocks until Process B opens for reading

    char message[] = "Hello from Process A!";
    write(fd, message, sizeof(message));

    printf("[Process A] Message sent.\n");

    close(fd);

    return 0;
}

