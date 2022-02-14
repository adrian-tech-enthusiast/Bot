/**
 * Author      : Adrian Morelos.
 * Version     : 1.0.0
 * Copyright   : © 2021 Adrian Morelos, All Rights Reserved.
 * Title       : messenger.h
 * Description : Messenger helper functions, sends formatted messages to stdout.
 */
#ifndef MESSENGER_H
#define MESSENGER_H

// Color variables.
#define GREEN             "\e[0;32m"
#define YELLOW            "\e[0;33m"
#define RED               "\e[0;31m"
// Bold high intensity text.
#define BACKGROUND_RED    "\e[30;48;5;1m"
#define BACKGROUND_GREEN  "\e[30;48;5;40m"
#define BACKGROUND_YELLOW "\e[30;48;5;11m"
// Reset the color.
#define RESET             "\e[0m"

/**
 * Adds a new info message.
 *
 * @param const char* message
 *   The given info message.
 */
void info(const char *message);

/**
 * Adds a new success message.
 *
 * @param const char* message
 *   The given success message.
 */
void success(const char *message);

/**
 * Adds a new error message.
 *
 * @param const char* message
 *   The given error message.
 */
void error(const char *message);

/**
 * Adds a new warning message.
 *
 * @param const char* message
 *   The given warning message.
 */
void warning(const char *message);

#endif
