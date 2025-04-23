#include "logger.h"

int main() {
    printf("Test logger: \n");
    Logger_t logger = {
        "Main",
        "[",
        "]",
        true
    };

    log(logger, LOG_LVL_INFO, "Hello", "stdout");
}