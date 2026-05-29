#ifndef CODER_H
#define CODER_H

#include "../dongle/dongle.h"

#define C_WAIT 0
#define C_BUSY 1


typedef struct s_coder {
	size_t			idx;
	size_t			compile_start;
	int				state;
	size_t			times_compiled;
	pthread_mutex_t	lock;
	pthread_cond_t	wake;
}	t_coder;

int		coder_free(t_coder *coder);
t_coder	*coder_create(size_t idx, t_dongle *dongles);

#endif