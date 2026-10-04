#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open the file
    int fd = open("lab10.txt", O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Get the actual file size automatically
    struct stat sb;

    if (fstat(fd, &sb) == -1) {
        perror("Error getting file size");
        close(fd);
        return 1;
    }

    size_t filesize = sb.st_size;

    // Map entire file to memory
    char *data = mmap(NULL, filesize, PROT_READ, MAP_SHARED, fd, 0);

    if (data == MAP_FAILED) {
        perror("mmap-error");
        close(fd);
        return 1;
    }

    // Access like a normal array!
    printf("First 20 bytes: %.20s\n", data);

    // To print all bytes
    fwrite(data, 1, filesize, stdout);

    // Cleanup
    munmap(data, filesize);
    close(fd);

    return 0;
}
