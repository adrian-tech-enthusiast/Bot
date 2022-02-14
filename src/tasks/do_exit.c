/**
 * Author      : Adrian Morelos.
 * Version     : 1.0.0
 * Copyright   : © 2021 Adrian Morelos, All Rights Reserved.
 * Title       : do_exit.c
 * Description : Bot Task - Do Exit.
 */
#include "do_show_messages.h"
#include "../messenger/messenger.h"

/**
 * {@inheritdoc}
 */
task_response do_exit() {
    success("_> Bye!");
    return task_response_create(1);
}
