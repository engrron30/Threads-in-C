#include <stdio.h>
#include <stdarg.h>

static bool ron_logger(const char *format, ...)
{
    bool rv = false;
    va_list args;
    FILE *file = fopen(LOG_FILE, "a+");

    if (file == NULL) {
        goto exit;
    }

    va_start(args, format);
    vfprintf(file, format, args);
    fprintf(file, "\n");
    fclose(file);

    rv = true;
    va_end(args);

exit:
    return rv;
}
