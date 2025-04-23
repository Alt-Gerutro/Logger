#include "logger.h"

char *concat_strings(const char *str1, const char *str2) {
    unsigned int size = 256;
    void *buf = malloc(size * sizeof(char));

    if (sizeof(str1) + sizeof(str2) + 2 < sizeof(*buf)) {
        size = size + sizeof(str1) + sizeof(str2) + 2;
        buf = realloc(buf, size);
    }

    if (!buf) {
        printf("Error");
        return '\0';
    }

    strcpy(buf, str1);
    strcat(buf, str2);

    return buf;
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

void log(Logger_t logger, Level level, char *message, char *path) {
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
    const time_t timer = time(NULL);
    if (logger.show_time) {
        char *str1 = concat_strings(logger.prefix, " ");
        char *str2 = concat_strings(str1, logger.name);
        char *str3 = concat_strings(str2, " ");
        char *str4 = concat_strings(str3, level_S);
        char *str5 = concat_strings(str4, " ");
        char *str6 = concat_strings(str5, logger.postfix);
        char *str7 = concat_strings(str6, " ");
        log_string = concat_strings(str7, message);
    }
    
    printf("%s\n", log_string);
}

// <Logger Prefix> <Logger Name> <Level> <Time> <Logger Postfix> <Message>