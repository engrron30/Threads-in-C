#include <stdio.h>
#include <pthread.h>

#define STRING_LIMIT        1024

static void *monitor_string( void *arg );

int main()
{
    pthread_t thread_monitor_string;
    char string_to_monitor[STRING_LIMIT];

    pthread_create(&thread_monitor_string, NULL, monitor_string, NULL);
    pthread_join(thread_monitor_string, NULL);

    return 0;
}

static void *monitor_string( void *arg )
{
    printf("Monitoring reboot...\n");

    return NULL;
}
