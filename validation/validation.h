#ifndef VALIDATION_H
#define VALIDATION_H

#include "../tools.h"

bool    init_manager(t_dict **config, int argc, char **argv);
bool    assign_args(t_dict **config, char **argv);
void    get_keys(char ***keys);

#endif