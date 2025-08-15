#include <stdio.h>
#include <pthread.h>

static void *monitor_reboot( void *arg);

int main()
{
    pthread_t thread_monitor_reboot;
    pthread_create(&thread_monitor_reboot, NULL, monitor_reboot, NULL);
    pthread_join(thread_monitor_reboot, NULL);

    return 0;
}

static void *monitor_reboot( void *arg)
{
    printf("Monitoring reboot...\n");

    return NULL;
}
