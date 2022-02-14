/**
 * Author      : Adrian Morelos.
 * Version     : 1.0.0
 * Copyright   : © 2021 Adrian Morelos, All Rights Reserved.
 * Title       : messenger.c
 * Description : Messenger helper functions, sends formatted messages to stdout.
 */
#include <stdio.h>
#include "messenger.h"

/**
 * {@inheritdoc}
 */
void info(const char *message) {
    printf(RESET "%s" "\n" RESET, message);
}

/**
 * {@inheritdoc}
 */
void success(const char *message) {
    printf(BACKGROUND_GREEN "[success]" RESET " " GREEN "%s" RESET "\n" RESET, message);
}

/**
 * {@inheritdoc}
 */
void warning(const char *message) {
    printf(BACKGROUND_YELLOW "[warning]" RESET " " YELLOW "%s" RESET "\n", message);
}

/**
 * {@inheritdoc}
 */
void error(const char *message) {
    printf(BACKGROUND_RED "[error]" RESET "   " RED "%s" RESET "\n", message);
}
