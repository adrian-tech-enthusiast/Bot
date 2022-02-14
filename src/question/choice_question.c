/**
 * Author      : Adrian Morelos.
 * Version     : 1.0.0
 * Copyright   : © 2021 Adrian Morelos, All Rights Reserved.
 * Title       : choice_question.c
 * Description : Question helper functions.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choice_question.h"
#include "../messenger/messenger.h"

/**
 * {@inheritdoc}
 */
choice_option create_choice_option(char *id, char *label) {
    size_t storage_amount = sizeof(struct traversable_choice_option);
    choice_option option = (choice_option) malloc(storage_amount);
    if (option != NULL) {
        option->id = id;
        option->label = label;
    }
    return option;
}

/**
 * {@inheritdoc}
 */
choice_question create_choice_question(char *label) {
    size_t storage_amount = sizeof(struct choice_question_item);
    choice_question q = (choice_question) malloc(storage_amount);
    if (q != NULL) {
        q->label = label;
        q->next = NULL;
    }
    return q;
}

/**
 * {@inheritdoc}
 */
void add_choice_option(choice_question question, char *id, char *label) {
    // Create the choice option.
    choice_option option = create_choice_option(id, label);
    // Add the choice option to the question.
    if (question->number_of_choices == 0) {
        // Choice question is empty.
        question->next = option;
    } else {
        // Choice question is not empty.
        choice_option index = question->next;
        while (index->next != NULL) {
            index = index->next;
        }
        index->next = option;
    }
    // Increment the size ot the task manager.
    (question->number_of_choices)++;
}

/**
 * {@inheritdoc}
 */
char *ask_choice_question(choice_question question) {
    // Display the question.
    info(question->label);
    // Display the choices.
    int i, message_length;
    int char_size = sizeof(char);
    char *message;
    choice_option index = question->next;
    for (i = 1; i <= question->number_of_choices; ++i) {
        // Format choice.
        message_length = strlen(index->label);
        message = malloc(message_length * char_size);
        sprintf(message, "[%i] %s", i, index->label);
        // Show choice.
        info(message);
        // Move to the next choice.
        index = index->next;
    }
    // Get the selected choice.
    int selected_choice_index;
    scanf("%d", &selected_choice_index);
    index = question->next;
    for (i = 1; i <= question->number_of_choices; ++i) {
        if (i == selected_choice_index) {
            return index->id;
        }
        // Move to the next choice.
        index = index->next;
    }
    index = question->next;
    return index->id;
}
