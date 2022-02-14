/**
 * Author      : Adrian Morelos.
 * Version     : 1.0.0
 * Copyright   : © 2021 Adrian Morelos, All Rights Reserved.
 * Title       : task_response.h
 * Description : Task response struct definition and helper functions.
 */
#ifndef BOT_TASK_RESPONSE_H
#define BOT_TASK_RESPONSE_H

/**
 * The task response that is received after processing a specific task.
 */
struct task_response_item {

    /**
     * The flag to check if the task succeeded in its execution.
     * 1 when the task execution was succeeded, otherwise 0.
     *
     * @var int
     */
    int succeeded;

};

/**
 * Definition of the date type task_response.
 *
 * @var task_response_item task_response
 * 	 The task response data type.
 */
typedef struct task_response_item *task_response;

/**
 * Create a new task response instance.
 *
 * @param int const succeeded
 *  The flag indicating whether the task was successful in its execution.
 *
 * @return task_response
 * 	 The task response.
 */
task_response task_response_create(int const succeeded);

#endif
