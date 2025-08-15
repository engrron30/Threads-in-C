#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define STRING_ARG_IND      1
#define STRING_LIMIT        1024

static void *monitor_string( void *arg );

int main(int argc, char *argv[])
{
    pthread_t thread_monitor_string;
    char string_to_monitor[STRING_LIMIT];

    if (argc == 2) {
        strcpy(string_to_monitor, argv[STRING_ARG_IND]);
        printf("Found string: %s\n", string_to_monitor);
    }

    pthread_create(&thread_monitor_string, NULL, monitor_string, NULL);
    pthread_join(thread_monitor_string, NULL);

    return 0;
}

static void *monitor_string( void *arg )
{
    printf("Monitoring reboot...\n");

    return NULL;
}
