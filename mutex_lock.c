#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void *fun1();
void *fun2();
int shared = 1;               // Shared variable
pthread_mutex_t l;           // Mutex lock
int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Final value of shared is: %d\n", shared);
    return 0;
}
void *fun1() {
    int x;
    printf("Thread1 trying to acquire lock\n");
    pthread_mutex_lock(&l);  // Thread acquires lock
    printf("Thread1 acquired lock\n");
    x = shared;
    printf("Thread1 reads the shared variable as: %d\n", x);
    x++;
    printf("Local updation by thread1: %d\n", x);
    sleep(1); // Thread1 is preempted by Thread2
    shared = x;  // Thread1 updates the value of shared
    printf("Value of shared variable updated by Thread1 is: %d\n", shared);
    pthread_mutex_unlock(&l);
    printf("Thread1 released the lock\n");
    return NULL;
}
void *fun2() {
    int y;
    printf("Thread2 trying to acquire lock\n");
    pthread_mutex_lock(&l);  // Thread acquires lock
    printf("Thread2 acquired lock\n");
    y = shared;
    printf("Thread2 reads the shared variable as: %d\n", y);
    y++;
    printf("Local updation by thread2: %d\n", y);
    sleep(1); // Thread2 is preempted by Thread1
    shared = y;  // Thread2 updates the value of shared
    printf("Value of shared variable updated by Thread2 is: %d\n", shared);
    pthread_mutex_unlock(&l);
    printf("Thread2 released the lock\n");
    return NULL;
}
