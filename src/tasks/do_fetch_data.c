/**
 * Author      : Adrian Morelos.
 * Version     : 1.0.0
 * Copyright   : © 2021 Adrian Morelos, All Rights Reserved.
 * Title       : fetch_data.c
 * Description : Bot Task - fetch data.
 */
#include "do_fetch_data.h"
#include "../messenger/messenger.h"

/**
 * {@inheritdoc}
 */
task_response do_fetch_data() {
    success("_> Doing Fetch data...");
    return task_response_create(1);
}
