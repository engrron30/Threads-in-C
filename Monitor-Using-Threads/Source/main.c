#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define ARGS_COMMAND_STR_IND    0
#define ARGS_MONITOR_STR_IND    1
#define RETURN_SUCCESS          true
#define RETURN_FAILURE          false
#define STRING_LIMIT            1024

static bool check_monitor_string_from_args(int argc, char *argv[], char *save_here);
static void *monitor_string( void *arg );

int main(int argc, char *argv[])
{
    bool rv = EXIT_FAILURE;
    pthread_t thread_monitor_string;
    char string_to_monitor[STRING_LIMIT];

    /* Simply check if there is a string argument when this is executed.
     * Save the string to string_to_monitor if existing.
     * Exit if not defined.
     */
    if (check_monitor_string_from_args(argc, argv, string_to_monitor) != RETURN_SUCCESS) {
        fprintf(stderr, "Lack arguments: monitor_string <string-to-monitor>\n");
        goto exit;
    }

    /* Create a thread called thread_monitor_string.
     * This thread accepts a string called string_to_monitor with typecast of void*.
     * This thread also accepts function called monitor_string and the string we 
     * added previously will be accepted as parameter to monitor_string.
     */
    if (pthread_create(&thread_monitor_string, NULL, monitor_string, (void*) string_to_monitor) != 0) {
        perror("Failed to create pthread");
        goto exit;
    }

    if (pthread_join(thread_monitor_string, NULL) != 0) {
        perror("Failed to join pthread");
        goto exit;
    }

    rv = EXIT_SUCCESS;

exit:
    return rv;
}

static bool check_monitor_string_from_args(int argc, char *argv[], char *save_here)
{
    bool rv = RETURN_FAILURE;
    if (argv[ARGS_MONITOR_STR_IND] == NULL) {
        goto exit;
    }

    printf("Monitor String: %s\n", argv[ARGS_MONITOR_STR_IND]);
    strcpy(save_here, argv[ARGS_MONITOR_STR_IND]);
    rv = RETURN_SUCCESS;

exit:
    return rv;
}

static void *monitor_string( void *arg )
{
    char *string = (char*) arg;
    printf("Monitoring %s...\n", string);

    return NULL;
}
