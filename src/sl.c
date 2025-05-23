#include "sl.h"

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

        if (sizeof(*buf) + sizeof(*str1) + sizeof(*str2) + 2 > sizeof(*buf)) {
            size = (sizeof(*buf) + sizeof(*str1) + sizeof(*str2) + size * 2);
            buf = realloc(buf, size);
        }

        if (!buf) {
            printf("SL Error: cannot allocate buffer.");
            return '\0';
        }

        strcat(buf, str1);
        strcat(buf, str2);
    }
    va_end(factor);
    return buf;
}

void writeStringLogFile(char *filename, char *string) {
    FILE *fap = fopen(filename, "a+");
    if (!fap) {
        perror("SL Error: cannot write file\n");
    }

    // TODO: MAKE FILE LOGGING.

    fclose(fap);
}

void logMsg(Logger_t logger, Level level, char *message, char *path) {
    char *log_string;
    
    log_string = concat_strings(5, logger.prefix, " ", logger.name, " ", priority_names[level].name, " ", logger.postfix, " ", message);
    strcat(log_string, "\n");
    
    if (path == NULL) {
        printf("%s", log_string);
    } else {
        writeStringLogFile(path, log_string);
    }
}