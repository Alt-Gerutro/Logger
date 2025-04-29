#ifndef SIMPLE_LOGGER_H
#define SIMPLE_LOGGER_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


#ifndef SL_FILTER
#define SL_FILTER SL_LVL_UNDEFINED
#endif // SL_FILTER

#ifndef __SL_PRIORITY_NAMES
#define __SL_PRIORITY_NAMES 1
#endif // __SL_PRIORITY_NAMES


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

typedef struct {
    char *name;
    unsigned char value;
} charcode;

#if defined __SL_PRIORITY_NAMES && __SL_PRIORITY_NAMES

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

#else

charcode priority_names[] = {
    {(char *)SL_LVL_FATAL, SL_LVL_FATAL},
    {(char *)SL_LVL_ALERT, SL_LVL_ALERT},
    {(char *)SL_LVL_CRIT, SL_LVL_CRIT},
    {(char *)SL_LVL_ERR, SL_LVL_ERR},
    {(char *)SL_LVL_WARN, SL_LVL_WARN},
    {(char *)SL_LVL_NOTICE, SL_LVL_NOTICE},
    {(char *)SL_LVL_INFO, SL_LVL_INFO},
    {(char *)SL_LVL_DEBUG, SL_LVL_DEBUG},
    {(char *)SL_LVL_UNDEFINED, SL_LVL_UNDEFINED}
}

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