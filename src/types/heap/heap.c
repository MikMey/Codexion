/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:55:34 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/08 20:19:49 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

t_heap	*heap_create(int size)
{
	t_heap	*heap;

	heap = malloc(sizeof(t_heap));
	if (!heap)
		return (NULL);
	pthread_mutex_init(&heap->lock, NULL);
	heap->nodes = malloc(sizeof(t_node_heap *) * (size + 1));
	if (!heap->nodes)
		return (heap);
	heap->nodes[size] = NULL;
	while (size > 0)
	{
		heap->nodes[size - 1] = NULL;
		size--;
	}
	return (heap);
}

int	heap_free(t_heap *heap)
{
	int	i;

	i = 0;
	if (!heap)
		return (1);
	pthread_mutex_destroy(&heap->lock);
	free(heap->nodes);
	free(heap);
	return (0);
}

t_node_heap	*node_create(int idx, pthread_cond_t wake, uint64_t time)
{
	t_node_heap	*node;

	node = malloc(sizeof(t_node_heap));
	node->idx = idx;
	node->time = time;
	node->wake = wake;
	return (node);
}
