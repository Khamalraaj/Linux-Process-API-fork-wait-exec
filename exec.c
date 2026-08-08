#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        exit(1);
    }
    else if (pid == 0) {
        printf("Child process executing 'ls -l'\n");

        execlp("ls", "ls", "-l", NULL);

        printf("exec failed\n");
        exit(1);
    }
    else {
        wait(NULL);

        printf("Parent process: Child execution completed\n");
    }

    return 0;
}
