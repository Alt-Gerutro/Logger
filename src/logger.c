#include "logger.h"

char *concat_strings(int va_count_cats, ...) {
    
    unsigned int size = 256;
    void *buf = malloc(size * sizeof(char));

    va_list factor;
    va_start(factor, va_count_cats);

    for (int i = 0; i < va_count_cats; i++) {

        char *str1, *str2;

        if (va_count_cats % 2 != 0 && i == va_count_cats - 1) {
            str1 = va_arg(factor, char*);
            str2 = " ";
        } else {
            str1 = va_arg(factor, char*);
            str2 = va_arg(factor, char*);
        }

        printf("str1 = %s\n", str1);
        printf("str2 = %s\n", str2);
        if (sizeof(str1) + sizeof(str2) + 2 < sizeof(*buf)) {
            printf("OLD SIZE = %d\n", size);
            size = size + sizeof(str1) + sizeof(str2) + 2;
            printf("NEW SIZE = %d\n", size);
            buf = realloc(buf, size);
        }

        if (!buf) {
            printf("Error: cannot allocate buffer.");
            return '\0';
        }

        strcat(buf, str1);
        strcat(buf, str2);
    }
    va_end(factor);
    return buf;
}

char *getTime() {
    // TODO: complete this
    char *result;

    return result;
}

/* Create log(Log_t) struct */
Log_t createLog(Logger_t logger, Level level, char *message) {
    Log_t result_log;

    result_log.logger = logger;
    result_log.level = level;
    result_log.message = message;

    return result_log;
}

void writeStringLogFile(char *filename, char *string) {
    FILE *fap = fopen(filename, "a");
    if (!fap) {
        perror("Error with reading file\n");
    }

    fputs(string, fap);
    fclose(fap);
}

void logMsg(Logger_t logger, Level level, char *message, char *path) {
    Log_t log = createLog(logger, level, message);
    char *level_S;

    switch(level) {
        case LOG_LVL_DEBUG:
            level_S = "DEBUG";
            break;

        case LOG_LVL_INFO:
            level_S = "INFO";
            break;
            
        case LOG_LVL_WARNING:
            level_S = "WARNING";
            break;

        case LOG_LVL_ERROR:
            level_S = "ERROR";
            break;

        case LOG_LVL_FATAL:
            level_S = "FATAL";
            break;

        default:
            level_S = "UNDEFINED";
            break;
    }
    char *log_string;
    // TODO: make a time displation
    if (logger.show_time) {
        log_string = concat_strings(8,
            logger.prefix, " ", " ", logger.postfix, " ",
            logger.prefix, " ", logger.name, " ", level_S, " ", logger.postfix, " ", log.message);
    } else {
        log_string = concat_strings(5,
            logger.prefix, " ", logger.name, " ", level_S, " ", logger.postfix, " ", log.message);
    }
    
    printf("%s\n", log_string);
}

// <Logger Prefix> <Logger Name> <Level> <Time> <Logger Postfix> <Message>