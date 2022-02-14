/**
 * Author      : Adrian Morelos.
 * Version     : 1.0.0
 * Copyright   : © 2021 Adrian Morelos, All Rights Reserved.
 * Title       : choice_question.h
 * Description : Question helper functions.
 */
#ifndef CHOICE_QUESTION_H
#define CHOICE_QUESTION_H

/**
 * Traversable choice option struct.
 */
struct traversable_choice_option {

    /**
     * The choice identifier.
     *
     * @var *char id
     */
    char *id;

    /**
     * The choice label.
     *
     * @var *char label
     */
    char *label;

    /**
     * Pointer to the next choice item in the list.
     *
     * @var traversable_choice_option next
     */
    struct traversable_choice_option *next;

};

/**
 * Definition of the date type choice_option.
 *
 * @var traversable_task_item choice_option
 */
typedef struct traversable_choice_option *choice_option;

/**
 * Choice question item struct.
 */
struct choice_question_item {

    /**
     * The question to ask.
     *
     * @var *char[] label
     */
    char *label;

    /**
     * The default choice id.
     *
     * @var *char[] default_choice_id
     */
    char *default_choice_id;

    /**
      * Pointer to the next choice item.
      *
      * @var choice_option next
      */
    choice_option next;

    /**
     * Number of choices.
     *
     * @var int size
     */
    volatile int number_of_choices;

};

/**
 * Definition of the date type choice question.
 *
 * @var traversable_task_item choice_question
 */
typedef struct choice_question_item *choice_question;

/**
 * Create a new choice option instance.
 *
 * @param char* id
 *  The choice identifier.
 * @param char* label
 *  The choice label.
 *
 * @return choice_option
 * 	 The choice option instance.
 */
choice_option create_choice_option(char *id, char *label);

/**
 * Create a new choice question instance.
 *
 * @param char* label
 *  The question to ask.
 *
 * @return choice_question
 * 	 The question instance.
 */
choice_question create_choice_question(char *label);

/**
 * Add a choice to the list in a choice question.
 *
 * @param choice_question question
 *  The choice question.
 * @param char* id
 *  The choice identifier.
 * @param char* label
 *  The choice label.
 */
void add_choice_option(choice_question question, char *id, char *label);

/**
 * Ask choice question.
 *
 * @param choice_question question
 *  The choice question to ask.
 *
 * @return char const
 * 	 The selected choice identifier.
 */
char *ask_choice_question(choice_question question);

#endif
