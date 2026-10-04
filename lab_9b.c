#include <stdio.h>

int main()
{
    // buffered io
    FILE* fp = fopen("lab9.txt", "r");

    if (!fp) {
        perror("fopen");
        return 1;
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);  // Each line
    }

    fclose(fp);  // Closes FD and flushes buffer

    return 0;
}
