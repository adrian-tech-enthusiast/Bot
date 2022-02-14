/**
 * Author      : Adrian Morelos.
 * Version     : 1.0.0
 * Copyright   : © 2021 Adrian Morelos, All Rights Reserved.
 * Title       : do_say_hello.c
 * Description : Bot Task - Say Hello.
 */
#include "do_say_hello.h"
#include "../messenger/messenger.h"

/**
 * {@inheritdoc}
 */
task_response do_say_hello() {
    success("_> Hello There from Bot!");
    return task_response_create(1);
}
