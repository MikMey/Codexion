/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 23:48:55 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/04 23:48:54 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_H
# define HEAP_H

# include <pthread.h>
# include <stdlib.h>
#include "../../tools.h"

typedef struct s_node_heap
{
	pthread_cond_t	wake;
	uint64_t			time;
	int				idx;
}					t_node_heap;

typedef struct s_heap
{
	t_node_heap		**nodes;
	pthread_mutex_t	lock;
}					t_heap;

t_heap				*heap_create(int size);
int					heap_free(t_heap *heap);
t_heap				*heap_insert(t_heap *heap, t_node_heap *node, size_t time);
void				heap_swap(t_heap *heap, int x, int y);
void				heap_pop_idx(t_heap *heap, int idx);
void				heap_sort(t_heap *heap, int i);
t_node_heap	*node_create(int idx, pthread_cond_t wake, size_t time);

#endif