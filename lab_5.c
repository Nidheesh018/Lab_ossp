#include <stdio.h>          // For printf
#include <unistd.h>         // For pipe, fork, read, write, close, dup2, execlp
#include <sys/types.h>      // For pid_t
#include <sys/wait.h>       // For wait

int main()
{
    int fd[2];

    pipe(fd);

    if (fork() == 0)                  // Child 1: producer ("cat")
    {
        close(fd[0]);

        dup2(fd[1], 1);

        close(fd[1]);

        execlp("cat", "cat", "lab5.txt", NULL);
    }

    if (fork() == 0)                  // Child 2: consumer ("wc")
    {
        close(fd[1]);

        dup2(fd[0], 0);

        close(fd[0]);

        execlp("wc", "wc", "-l", NULL);
    }

    close(fd[0]);
    close(fd[1]);                     // Parent needs neither end

    wait(NULL);
    wait(NULL);

    return 0;
}
