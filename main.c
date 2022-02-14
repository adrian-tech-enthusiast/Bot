#include "src/bot/bot.h"

/**
 * Main controller function.
 *
 * @param int argc
 *   The number of arguments passed by the user in the command line.
 * @param char* argv
 *   Array of char, the arguments names passed by the user.
 *
 * @return int
 *   The constant EXIT_SUCCESS on Successful exit status, otherwise EXIT_FAILURE.
 */
int main(int argc, char *argv[]) {
    return bot_init();;
}
