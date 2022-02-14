/**
 * Author      : Adrian Morelos.
 * Version     : 1.0.0
 * Copyright   : © 2021 Adrian Morelos, All Rights Reserved.
 * Title       : do_show_log_messages.c
 * Description : Bot Task - Show dummy messages.
 */
#include "do_show_messages.h"
#include "../messenger/messenger.h"

/**
 * {@inheritdoc}
 */
task_response do_show_messages() {
    info("---------------------------------");
    info("[info] _> This is a info message.");
    success("_> This is a success message.");
    warning("_> This is a warning message.");
    error("_> This is a error message.");
    info("---------------------------------");
    return task_response_create(1);
}
