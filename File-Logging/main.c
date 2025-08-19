#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

#define LOG_DIR         "./"
#define LOG_FILE        LOG_DIR"ron_file.dat"

static bool ron_logger(const char *format, ...);

int main()
{
    printf("============= Practicing fprintf() ============\n\n");
    ron_logger("Test Text\n");

    return 0;
}

static bool ron_logger(const char *format, ...)
{
    bool rv = false;
    va_list args;
    FILE *file = fopen(LOG_FILE, "a+");

    if (file == NULL) {
        goto exit;
    }

    va_start(args, format);
    fprintf(file, "Testing!!!\n");
    fclose(file);

    rv = true;
    va_end(args);

exit:
    return rv;
}
