/**
 * Author      : Adrian Morelos.
 * Version     : 1.0.0
 * Copyright   : © 2021 Adrian Morelos, All Rights Reserved.
 * Title       : sample_data.c
 * Description : Bot Task - sample data.
 */
#include "do_sample_data.h"
#include "../messenger/messenger.h"

/**
 * {@inheritdoc}
 */
task_response do_sample_data() {
    success("_> Doing Sample data...");
    return task_response_create(1);
}
