#include <sl.h>

int main() {
    printf("FILE TEST\n");

    char *f = "testlog.log";

    Logger_t logger_levels = {
        "Simple logger(levels)",
        "[",
        "]"
    };

    logMsg(logger_levels, SL_LVL_FATAL, "fatal error text", f);
    logMsg(logger_levels, SL_LVL_ALERT, "alert error text", f);
    logMsg(logger_levels, SL_LVL_CRIT, "critical error text", f);
    logMsg(logger_levels, SL_LVL_ERR, "error text", f);
    logMsg(logger_levels, SL_LVL_WARN, "warning text", f);
    logMsg(logger_levels, SL_LVL_NOTICE, "notice text", f);
    logMsg(logger_levels, SL_LVL_INFO, "info text", f);
    logMsg(logger_levels, SL_LVL_DEBUG, "debug text", f);
    logMsg(logger_levels, SL_LVL_UNDEFINED, "undefined error text", f);

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

    logMsg(logger_logger_names1, SL_LVL_INFO, "logger name 1 and prefix = prefix, postfix = postfix", f);
    logMsg(logger_logger_names2, SL_LVL_INFO, "logger name 2 and prefix = {, postfix = }", f);
    logMsg(logger_logger_names3, SL_LVL_INFO, "logger name 3 and prefix = <, postfix = >", f);
    logMsg(logger_logger_names4, SL_LVL_INFO, "logger name 4 and prefix = ?, postfix = !", f);
    logMsg(logger_logger_names1, SL_LVL_INFO, "logger name 1 again", f);


    char *long_str1 = "Макрос va_arg() раскрывается в выражение, которое имеет тип и значение следующего аргумента в вызове. Аргумент ap — это va_list ap, инициализированный va_start(). Каждый вызов va_arg() изменяет ap так, что следующий вызов возвращает следующий аргумент. Аргумент type — это имя типа, указанное так, что тип указателя на объект, который имеет указанный тип, можно получить просто добавив * в type. Первый вызов макроса va_arg() после va_start() вернёт аргумент после last. Последующие вызовы вернут значения оставшихся аргументов. Если аргументы закончились, или если type не совместим с типом настоящего следующего аргумента (преобразование происходит согласно преобразованию аргументов по умолчанию), может произойти любая ошибка. Если ap передан в функцию, которая использует va_arg(ap,type), то значение ap не определено после возврата из функции. ";
    char *long_str2 = "Макрос va_copy() копирует (ранее инициализированный) список с переменным количеством аргументов src в dest. Его действие такое же, как если бы va_start() применили к dest с тем же аргументом last, после чего было бы совершено такое же количество вызовов va_arg(), которое имеется в текущем состоянии src. Очевидной реализацией было бы создать переменную с типом va_list, указывающую на стековый фрейм функции с переменным количеством аргументов. В этом случае (безусловно, наиболее распространенном) кажется, что достаточно присвоения va_list aq = ap; К сожалению, есть системы, в которых это массив указателей (длиной 1), и нужно делать va_list aq; *aq = *ap; Наконец, в системах, где аргументы передаются через регистры, в va_start() может потребоваться выделить память, сохранить там аргументы, а также индекс следующего элемента для того, чтобы va_arg() мог обойти список. Также va_end() может освобождать выделенную память. Чтобы всё это учесть в C99 добавлен макрос va_copy(), который позволяет показанное выше назначение заменить на";
    char *long_str3 = "Эти функции позволяют программам, созданным на Си, вызывать удалённые процедуры на других машинах в сети. Сначала, клиент вызывает процедуру путём отправки пакета с данными на сервер. После принятия пакета сервер вызывает функцию распределения (dispatch) для выполнения запрошенной службы и отсылает ответ обратно. Последним действием результат выполнения процедуры возвращается клиенту.";
    char *long_str4 = "Эта функция создаёт клиента RPC для удалённой программы prognum версии versnum; для передачи клиент использует протокол UDP/IP. Удалённая программа расположена по интернет-адресу *addr. Если addr->sin_port равно 0, тогда ему назначается реальный порт, который прослушивается удалённой программой (эта информация запрашивается у удалённой службы portmap). Параметр sockp — сокет; если его значение равно RPC_ANYSOCK, тогда эта функция открывает новый сокет и изменяет sockp. Протокол UDP повторяет отправку сообщения через интервал, указанный в параметре wait, пока не будет получен ответ или не истечёт время ожидания. Полное время ожидания вызова определяется clnt_call(). ";

    Logger_t logger = {
        "LST",
        "[",
        "]"
    };

    logMsg(logger, SL_LVL_INFO, long_str1, f);
    logMsg(logger, SL_LVL_INFO, long_str2, f);
    logMsg(logger, SL_LVL_INFO, long_str3, f);
    logMsg(logger, SL_LVL_INFO, long_str4, f);

    return 0;
}