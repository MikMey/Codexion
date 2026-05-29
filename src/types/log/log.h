#ifndef LOG_H
#define LOG_H

#include <pthread.h>
#include <unistd.h>
#include "../../tools.h"

typedef struct s_log{
	pthread_mutex_t	lock;
	int				coder_died;
}	t_log;

t_log	*log_create(void);
int		log_print(t_log* log, char **args, int death);
int		log_free(t_log *log);

#endif