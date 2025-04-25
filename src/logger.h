#ifndef LOGGER_H
#define LOGGER_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>

typedef enum level {
    LOG_LVL_DEBUG,
    LOG_LVL_INFO,
    LOG_LVL_WARNING,
    LOG_LVL_ERROR,
    LOG_LVL_FATAL
} Level;

typedef struct logger {
    char *name;
    char *prefix;
    char *postfix;
    bool show_time;
} Logger_t;

typedef struct log_t {
    Logger_t logger;
    Level level;
    char *message;
} Log_t;

void logMsg(Logger_t logger, Level level, char *message, char *path);

#endif // LOGGER_H