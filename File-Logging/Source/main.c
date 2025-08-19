#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

#include "logger.h"



int main()
{
    printf("============= GENERATING DAT FILE ============\n\n");

    int test_num = 69;
    char *test_text = "HELOOOOOWOORRRRLLD";
    ron_logger("test_text=%s    test_num=%d", test_text, test_num);

    printf("=============      DONE PROGRAM   ============\n\n");
    return 0;
}
