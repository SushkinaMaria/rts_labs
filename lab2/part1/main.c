#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define PARENT_MSG "Mariya\n"
#define CHILD_MSG "Sushkina I983\n"

int main(int argc, char const *argv[])
{
    pid_t pid;

    pid = fork();
    if (pid > 0) {
        printf(PARENT_MSG);
    } else if (!pid) {
        printf(CHILD_MSG);
    }
    else if (pid == -1) {
        perror("fork error");
    }

    return 0;
}
