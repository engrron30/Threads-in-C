#include <stdio.h>
#include <stdbool.h>

#define LOG_DIR         "./"
#define LOG_FILE        LOG_DIR"ron_file.dat"

static bool ron_logger();

int main()
{
    printf("============= Practicing fprintf() ============\n\n");
    ron_logger();

    return 0;
}

static bool ron_logger()
{
    bool rv = false;

    FILE *file = fopen(LOG_FILE, "a+");
    if (file == NULL) {
        goto exit;
    }

    fprintf(file, "Testing!!!\n");
    fclose(file);

    rv = true;

exit:
    return rv;
}
