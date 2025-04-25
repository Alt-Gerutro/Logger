#include <sl.h>

int main() {
    printf("SIMPLE TEST:\n");

    Logger_t logger_levels = {
        "Simple logger(levels)",
        "[",
        "]"
    };

    printf("LEVELS TEST:\n");
    logMsg(logger_levels, SL_LVL_FATAL, "fatal error text", NULL);
    logMsg(logger_levels, SL_LVL_ALERT, "alert error text", NULL);
    logMsg(logger_levels, SL_LVL_CRIT, "critical error text", NULL);
    logMsg(logger_levels, SL_LVL_ERR, "error error text", NULL);
    logMsg(logger_levels, SL_LVL_WARN, "warning error text", NULL);
    logMsg(logger_levels, SL_LVL_NOTICE, "notice error text", NULL);
    logMsg(logger_levels, SL_LVL_INFO, "info error text", NULL);
    logMsg(logger_levels, SL_LVL_DEBUG, "debug error text", NULL);
    logMsg(logger_levels, SL_LVL_UNDEFINED, "undefined error text", NULL);

    printf("LOGGER NAMES INFO:\n");

    Logger_t logger_logger_names1 = {
        "Simple logger(logger names 1)",
        "prefix",
        "postfix"
    };

    Logger_t logger_logger_names2 = {
        "Simple logger(logger names 2)",
        "{",
        "}"
    };

    Logger_t logger_logger_names3 = {
        "Simple logger(logger names 3)",
        "<",
        ">"
    };

    Logger_t logger_logger_names4 = {
        "Simple logger(logger names 4)",
        "?",
        "!"
    };

    logMsg(logger_logger_names1, SL_LVL_INFO, "logger name 1 and prefix = prefix, postfix = postfix", NULL);
    logMsg(logger_logger_names2, SL_LVL_INFO, "logger name 2 and prefix = {, postfix = }", NULL);
    logMsg(logger_logger_names3, SL_LVL_INFO, "logger name 3 and prefix = <, postfix = >", NULL);
    logMsg(logger_logger_names4, SL_LVL_INFO, "logger name 4 and prefix = ?, postfix = !", NULL);
    logMsg(logger_logger_names1, SL_LVL_INFO, "logger name 1 again", NULL);

    return 0;
}