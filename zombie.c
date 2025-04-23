// zombie.c
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t p;
    p = fork();

    if (p == 0) {
        // Child process
        printf("Child having ID: %d\n", getpid());
    } else {
        // Parent process
        printf("Parent having ID: %d\n", getpid());
        sleep(15); // Run `ps` command during this time to observe zombie
    }

    return 0;
}
