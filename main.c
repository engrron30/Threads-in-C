#include <stdio.h>
#include <pthread.h>

static void *monitor_string( void *arg );

int main()
{
    pthread_t thread_monitor_string;
    pthread_create(&thread_monitor_string, NULL, monitor_string, NULL);
    pthread_join(thread_monitor_string, NULL);

    return 0;
}

static void *monitor_string( void *arg )
{
    printf("Monitoring reboot...\n");

    return NULL;
}
