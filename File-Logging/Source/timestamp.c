#include <stdio.h>
#include <time.h>

#include "timestamp.h"

bool get_time(char *time_str)
{
    bool rv = RETURN_TIME_FAILURE;
    time_t current_time;
    struct tm *local = NULL;

    time(&current_time);
    local = localtime(&current_time);
    if (local == NULL) {
        goto exit;
    }

    strftime(time_str, TIME_STR_MAX_LEN, "%Y-%m-%d %H:%M:%S", local);
    rv = RETURN_TIME_SUCCESS;

exit:
    return rv;
}
