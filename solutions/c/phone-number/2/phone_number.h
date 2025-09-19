#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H

#include <string.h>
#include <stdlib.h>

char *phone_number_clean(const char *input);

enum {
    MAX_PHONE_LEN = 10,
    AREA_CODE_OFFSET = 0,
    EXCHANGE_CODE_OFFSET = 3
};

#endif
