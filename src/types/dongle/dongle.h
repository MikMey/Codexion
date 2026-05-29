#ifndef DONGLE_H
#define DONGLE_H

#include <pthread.h>
# include <stdbool.h>
#include <stdlib.h>

typedef struct s_dongle{
	size_t	idx;
	size_t	time_since_use;
	pthread_mutex_t lock;
}	t_dongle;

t_dongle	*dongle_create(size_t idx);
int			dongle_free(t_dongle *dongle);

#endif