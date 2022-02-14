/**
 * Author      : Adrian Morelos.
 * Version     : 1.0.0
 * Copyright   : © 2021 Adrian Morelos, All Rights Reserved.
 * Title       : task_manager.h
 * Description : Task manager helper functions and structs definitions.
 */
#ifndef BOT_TASK_MANAGER_H
#define BOT_TASK_MANAGER_H

#include "task_list.h"
#include "task_response.h"

/**
 *  Callable type-definition.
 *
 *  The callback function that will be executed when the specified task
 *  is dispatched. 'Callable' now can be used as type.
 */
typedef task_response (*Callable)();

/**
 * Traversable Task Item struct.
 */
struct traversable_task_item {

    /**
     * The unique identifier for this task.
     *
     * @var *char[] task_id
     */
    char *task_id;

    /**
     * The task description.
     *
     * @var *char[] task_description
     */
    char *task_description;

    /**
     * Pointer to the next task item in the list.
     *
     * @var callable callback
     *   The callback function that will be executed when the specified task is dispatched.
     */
    Callable callback;

    /**
     * Pointer to the next task item in the list.
     *
     * @var *traversable_task_item next
     *   The pointer to the next task item.
     */
    struct traversable_task_item *next;

};

/**
 * Definition of the date type task_item.
 *
 * @var traversable_task_item task_item
 * 	 The task-item data type.
 */
typedef struct traversable_task_item *task_item;

/**
 * Task Manager struct.
 */
struct traversable_task_manager {

    /**
     * Number of task registered in the manager.
     *
     * @var int number_of_tasks
     */
    volatile int number_of_tasks;

    /**
     * Pointer to the next task item.
     *
     * @var task_item next
     *   The pointer to the next task item.
     */
    task_item next;

};

/**
 * Definition of the date type task_manager.
 *
 * @var traversable_task_manager task_manager
 * 	 The task manager data type.
 */
typedef struct traversable_task_manager *task_manager;

/**
 * Get the global task manager service.
 *
 * @return task_manager
 * 	 The task manager service.
 */
task_manager get_task_manager();

/**
 * Clear memory associated with the task manager service.
 */
void task_manager_destroy();

/**
 * Create a new Task Item instance.
 *
 * @param char const *task_id
 *  The unique identifier for this task.
  * @param char const *task_description
 *  The task description.
 * @param Callable callable
 *  Callable function that will be executed when the specified event is dispatched.
 *
 * @return task_item
 * 	 The task item instance.
 */
task_item task_item_create(char const *task_id, char const *task_description, Callable callback);

/**
 * Add a task to the list of possible operations the bot can perform.
 *
 * @param task_manager dispatcher
 *  The task manager service.
 * @param char const *task_id
 *  The unique identifier for this task.
 * @param char const *task_description
 *  The task description.
 * @param Callable callable
 *  Callable function that will be executed when the specified event is dispatched.
 */
void add_task(task_manager dispatcher, char const *task_id, char const *task_description, Callable callback);

/**
 * Dispatches an task.
 *
 * @param task_manager dispatcher
 *  The task manager service.
 * @param char const *task_id
 *  The unique identifier of the event to dispatch.
 *
 * @return task_response
 *  The task response.
 */
task_response dispatch_task(task_manager const dispatcher, char const *task_id);

/**
 * Show task response.
 *
 * @param task_response const response
 *  The task response to show.
 */
void show_task_response(task_response const response);

#endif
