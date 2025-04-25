#ifndef SIMPLE_LOGGER_H
#define SIMPLE_LOGGER_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdarg.h>


typedef enum sl_level {
    SL_LVL_FATAL,    // Fatal error
    SL_LVL_ALERT,    // More critical than LOG_LEVEL_CRIT
    SL_LVL_CRIT,     // Critical error
    SL_LVL_ERR,      // Error, but can be ignored
    SL_LVL_WARN,     // Warning
    SL_LVL_NOTICE,   // Normal, but a litle not-so-normal
    SL_LVL_INFO,     // Info
    SL_LVL_DEBUG,    // Debug
    SL_LVL_UNDEFINED // Undefined
} Level;

#if defined __SL_PRIORITY_NAMES

typedef struct {
    char *name;
    unsigned char value;
} charcode;

charcode priority_names[] = {
    {"FATAL", SL_LVL_FATAL},
    {"ALERT", SL_LVL_ALERT},
    {"CRITICAL", SL_LVL_CRIT},
    {"ERROR", SL_LVL_ERR},
    {"WARNING", SL_LVL_WARN},
    {"NOTICE", SL_LVL_NOTICE},
    {"INFO", SL_LVL_INFO},
    {"DEBUG", SL_LVL_DEBUG},
    {"UNDEFINED", SL_LVL_UNDEFINED}
};

#endif

typedef struct logger {
    char *name;
    char *prefix;
    char *postfix;
} Logger_t;

typedef struct log_t {
    Logger_t logger;
    Level level;
    char *message;
} Log_t;

void logMsg(Logger_t logger, Level level, char *message, char *path);

#endif // SIMPLE_LOGGER_H