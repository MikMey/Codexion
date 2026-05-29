#ifndef W_THREAD_H
#define W_THREAD_H

#include "../coder/coder.h"
#include "../dongle/dongle.h"
#include "../heap/heap.h"
#include "../log/log.h"

typedef struct s_w_threads{
	t_coder		*coder;
	t_dongle	**dongles;
	t_heap		*heap;
	t_log		*log;
}	t_w_threads;

#endif