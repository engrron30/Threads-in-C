#ifndef LOGGER_H
#define LOGGER_H

#include <stdbool.h>

#define LOG_DIR         "./"
#define LOG_FILE        LOG_DIR"ron_file.dat"

bool ron_logger(const char *format, ...);

#endif
