#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

#define LOG_DIR         "./"
#define LOG_FILE        LOG_DIR"ron_file.dat"

static bool ron_logger(const char *format, ...);

int main()
{
    printf("============= GENERATING DAT FILE ============\n\n");

    int test_num = 69;
    char *test_text = "HELOOOOOWOORRRRLLD"
    ron_logger("test_text=%s    test_num=%d", test_text, text_num);

    printf("=============      DONE PROGRAM   ============\n\n");
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
    vfprintf(file, format, args);
    fprintf(file, "\n");
    fclose(file);

    rv = true;
    va_end(args);

exit:
    return rv;
}
