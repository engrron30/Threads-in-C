#include <stdio.h>
#include <stdarg.h>

#include "logger.h"
#include "timestamp.h"

/* Accepts multiple character array arguments.
 *
 * This function calls a timestamp function to get the current time
 * and stores it to time_stamp character array.
 *
 * Other character arrays in arguments will be printed as well with
 * the following format:
 * [TIMESTAMP] LOG DETAILS
 *
 * This function returns true if log is successful.
 * Otherwise, return false.
 */
bool logger(const char *format, ...)
{
    bool rv = false;

    FILE *file = fopen(LOG_FILE, "a+");
    if (file == NULL) {
        goto exit;
    }

    char timestamp[TIME_STR_MAX_LEN];
    if (!get_time(timestamp)) {
        goto exit;
    }

    va_list args;
    va_start(args, format);

    fprintf(file, "[%s] ", timestamp);
    vfprintf(file, format, args);
    fprintf(file, "\n");

    va_end(args);
    fclose(file);
    rv = true;

exit:
    return rv;
}
