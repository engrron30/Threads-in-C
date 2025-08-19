#include <stdio.h>
#include <time.h>
#include <stdbool.h>

bool get_time()
{
    bool rv = false;
    time_t current_time;
    struct tm *local;

    time(&current_time);
    local = localtime(&current_time);

    printf("Current date and time: %02d-%02d-%04d %02d:%02d:%02d\n",
           local->tm_mday, local->tm_mon + 1, local->tm_year + 1900,
           local->tm_hour, local->tm_min, local->tm_sec);
    rv = true;

exit:
    return rv;
}

int main()
{
    get_time();
}
