#ifndef TOOLS_H
#define TOOLS_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <stdbool.h>
#include "utils/utils.h"

#define CODERS "number_of_coders"
#define BURNOUT "time_to_burnout"
#define COMPILE "time_to_compile"
#define DEBUG "time_to_debug"
#define REFRACTOR "time_to_refactor"
#define REQUIRED "number_of_compiles_required"
#define COOLDOWN "dongle_cooldown"
#define SCHEDULER "scheduler"

typedef struct s_dict {
    void *key;
    void *value;
}   t_dict;

#endif