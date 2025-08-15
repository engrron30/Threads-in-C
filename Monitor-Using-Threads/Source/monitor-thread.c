#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static void *monitor_string( void *arg )
{
    char *string = (char*) arg;
    printf("Monitoring %s...\n", string);

    return NULL;
}
