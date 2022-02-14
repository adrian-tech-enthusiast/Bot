/**
 * Author      : Adrian Morelos.
 * Version     : 1.0.0
 * Copyright   : © 2021 Adrian Morelos, All Rights Reserved.
 * Title       : task_manager.h
 * Description : Task manager helper functions implementation.
 */
#include <stdlib.h>
#include <string.h>
#include "task_manager.h"
#include "../messenger/messenger.h"

/**
 * {@inheritdoc}
 */
task_manager get_task_manager() {
    static task_manager instance;
    if (instance == NULL) {
        // Create the global instance.
        size_t storage_amount = sizeof(struct traversable_task_manager);
        instance = (task_manager) malloc(storage_amount);
        if (instance != NULL) {
            instance->next = NULL;
            instance->number_of_tasks = (int) 0U;
        }
    }
    return instance;
}

/**
 * {@inheritdoc}
 */
void task_manager_destroy() {
    task_manager dispatcher = get_task_manager();
    if (dispatcher == NULL) {
        // Uninitialized service.
        return;
    }
    // Releases the specified block of memory booked for the base dispatcher service.
    free(dispatcher);
}

/**
 * {@inheritdoc}
 */
task_item task_item_create(char const *task_id, char const *task_description, Callable callback) {
    size_t storage_amount = sizeof(struct traversable_task_item);
    task_item item = (task_item) malloc(storage_amount);
    if (item != NULL) {
        item->callback = callback;
        item->task_id = (char *) task_id;
        item->task_description = (char *) task_description;
        item->next = NULL;
    }
    return item;
}

/**
 * {@inheritdoc}
 */
void add_task(task_manager const dispatcher, char const *task_id, char const *task_description, Callable callback) {
    // Create the task item.
    task_item item = task_item_create(task_id, task_description, callback);
    // Add the task item to the task manager.
    if (dispatcher->number_of_tasks == 0) {
        // Task manager is empty.
        dispatcher->next = item;
    } else {
        // Task manager is not empty.
        task_item index = dispatcher->next;
        while (index->next != NULL) {
            index = index->next;
        }
        index->next = item;
    }
    // Increment the size ot the task manager.
    (dispatcher->number_of_tasks)++;
}

/**
 * {@inheritdoc}
 */
task_response dispatch_task(task_manager const dispatcher, char const *task_id) {
    int i;
    task_item task = dispatcher->next;
    for (i = 1; i <= dispatcher->number_of_tasks; ++i) {
        if (strcmp(task->task_id, task_id) == 0) {
            return task->callback();
        }
        // Move to the next task.
        task = task->next;
    }
    return task_response_create(0);
}

/**
 * {@inheritdoc}
 */
void show_task_response(task_response const response) {
    if (response->succeeded) {
        success("Task completed successfully.");
    } else {
        error("An error has occurred while executing task.");
    }
}
