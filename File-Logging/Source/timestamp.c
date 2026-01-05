#include <stdio.h>
#include <time.h>

#include "timestamp.h"

/* Accepts an argument of character array (char *time_str).
 * 
 * This function will get the current time using time() method and saves
 * it to time_str.
 *
 * If time is successfully saved to time_str, returb RETURN_TIME_SUCCESS.
 * Otherwise, return RETURN_TIME_FAILURE.
 * */
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
