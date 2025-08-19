#include <stdio.h>
#include <stdarg.h>

#include "logger.h"
#include "timestamp.h"

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
