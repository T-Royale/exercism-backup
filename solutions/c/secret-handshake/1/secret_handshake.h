#ifndef SECRET_HANDSHAKE_H
#define SECRET_HANDSHAKE_H

#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMMAND_LEN strlen("close your eyes") + 1

const char **commands(size_t number);

#endif
