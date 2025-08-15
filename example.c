#include <pthread.h>
#include <stdio.h>

void* foo(void* arg) {
    printf("Created a new thread");
    fflush(stdout);

    return NULL;
 }
int main() {

    // Create a pthread_t variable to store
    // thread ID
    pthread_t thread1;

    // Creating a new thread. 
    pthread_create(&thread1, NULL, foo, NULL);

    // Create join to wait finish doing the thread before continuing or exiting the program.
    pthread_join(thread1, NULL);

    return 0;
}
