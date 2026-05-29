#ifndef HEAP_C
#define HEAP_C

#include <pthread.h>
#include <stdlib.h>

typedef struct s_heap{
	t_node_heap		**nodes;
	pthread_mutex_t lock;
}	t_heap;

typedef struct s_node_heap{
	pthread_cond_t	*wake;
	size_t			time;
}	t_node_heap;

t_heap	*heap_create(int size);
int		heap_free(t_heap *heap);

#endif