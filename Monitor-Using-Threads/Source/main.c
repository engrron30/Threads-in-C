#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define ARGS_COMMAND_STR_IND    0
#define ARGS_MONITOR_STR_IND    1
#define STRING_LIMIT            1024

static bool check_monitor_string_from_args(int argc, char *argv[], char *save_here);
static void *monitor_string( void *arg );

int main(int argc, char *argv[])
{
    pthread_t thread_monitor_string;
    char string_to_monitor[STRING_LIMIT];

    check_monitor_string_from_args(argc, argv, string_to_monitor);

    pthread_create(&thread_monitor_string, NULL, monitor_string, NULL);
    pthread_join(thread_monitor_string, NULL);

    return 0;
}

static bool check_monitor_string_from_args(int argc, char *argv[], char *save_here)
{
    bool rv = false;

    if (argc <= ARGS_MONITOR_STR_IND) {
        perror("Lack arguments: monitor_string <string-to-monitor>\n");
        goto exit;
    }

    printf("Monitor String: %s\n", argv[ARGS_MONITOR_STR_IND]);
    strcpy(save_here, argv[ARGS_MONITOR_STR_IND]);
    rv = true;

exit:
    return rv;
}

static void *monitor_string( void *arg )
{
    printf("Monitoring reboot...\n");

    return NULL;
}
