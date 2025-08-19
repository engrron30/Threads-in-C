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

    char buffer[64];
    strftime(buffer, 64, "%Y-%m-%d %H:%M:%S", local);
    printf("%s\n", buffer);
    rv = true;

exit:
    return rv;
}

int main()
{
    get_time();
}
