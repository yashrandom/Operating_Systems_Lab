#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* thread_function(void* arg) {
    int i;
    printf("Inside thread\n");
    for (i = 0; i < 5; i++) {
        printf("i: %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t a_thread; // Thread declaration
    int j;

    pthread_create(&a_thread, NULL, thread_function, NULL);
    pthread_join(a_thread, NULL); // Process waits for thread to finish

    printf("Inside main program\n");
    for (j = 20; j < 25; j++) {
        printf("j: %d\n", j);
        sleep(1);
    }

    return 0;
}
