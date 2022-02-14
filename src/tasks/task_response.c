/**
 * Author      : Adrian Morelos.
 * Version     : 1.0.0
 * Copyright   : © 2021 Adrian Morelos, All Rights Reserved.
 * Title       : task_response.h
 * Description : Task response struct and helper functions implementation.
 */
#include <stdlib.h>
#include "task_response.h"

/**
 * {@inheritdoc}
 */
task_response task_response_create(int const succeeded) {
    size_t storage_amount = sizeof(struct task_response_item);
    task_response item = (task_response) malloc(storage_amount);
    if (item != NULL) {
        item->succeeded = succeeded;
    }
    return item;
}

