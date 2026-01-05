#ifndef LOGGER_H
#define LOGGER_H

#include <stdbool.h>

#define LOG_DIR         "./"
#define LOG_FILE        LOG_DIR"logger_file.dat"

bool logger(const char *format, ...);

#endif
