/**
 * Author      : Adrian Morelos.
 * Version     : 1.0.0
 * Copyright   : © 2021 Adrian Morelos, All Rights Reserved.
 * Title       : bot.c
 * Description : Bot function definitions.
 */
#include "bot.h"
#include <stdlib.h>
#include <string.h>
#include "../tasks/task_manager.h"
#include "../question/choice_question.h"

/**
 * {@inheritdoc}
 */
char *ask_user_task_to_dispatch(task_manager const dispatcher) {
    choice_question question = create_choice_question("Please select option:");
    task_item index = dispatcher->next;
    while (index->next != NULL) {
        add_choice_option(question, index->task_id, index->task_description);
        index = index->next;
    }
    add_choice_option(question, index->task_id, index->task_description);
    return ask_choice_question(question);
}

/**
 * {@inheritdoc}
 */
int bot_init() {
    // The Task manger: It is the central object of the task dispatcher system.
    // In general, a single task manger is created, which maintains a registry
    // of tasks. When a task is dispatched via the dispatcher, it
    // notifies the callback registered with that task.
    task_manager dispatcher = get_task_manager();
    // Connecting Tasks: To take advantage of an existing event, you need
    // to connect a listener to the dispatcher so that it can be notified when
    // the event is dispatched. A call to the dispatcher’s addListener() method
    // associates any valid C callable to an event.
    add_task(dispatcher, "bot.say.hello", "Say Hello.", &do_say_hello);
    add_task(dispatcher, "bot.fetch.data", "Fetch Data.", &do_fetch_data);
    add_task(dispatcher, "bot.sample.data", "Sample Data.", &do_sample_data);
    add_task(dispatcher, "bot.show.messages", "Show Messages.", &do_show_messages);
    add_task(dispatcher, "bot.exit", "Bot Exit.", &do_exit);
    // Ask the user what to do until the user wants to halt the bot.
    char *task_id;
    task_response response;
    while (strcmp(task_id, "bot.exit") != 0) {
        // Let the user decide what to do.
        task_id = ask_user_task_to_dispatch(dispatcher);
        // Dispatch the task user requested.
        response = dispatch_task(dispatcher, task_id);
        // Show the task result.
        show_task_response(response);
    }
    // Clear memory.
    task_manager_destroy();
    // Stop bot execution.
    return EXIT_SUCCESS;
}
