/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:55:34 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/29 16:38:16 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

t_heap	*heap_create(int size)
{
	t_heap	*heap;

	heap = malloc(sizeof(t_heap));
	if (!heap)
		return(NULL);
	pthread_mutex_init(&heap->lock, NULL);
	heap->nodes = malloc(sizeof(t_node_heap *) * (size + 1));
	if (!heap->nodes)
		return(heap);
	heap->nodes[size] = NULL;
	while (size > 0)
	{
		heap->nodes[size - 1] = malloc(sizeof(t_node_heap));
		size--;
	}
	return(0);
}

int	heap_free(t_heap *heap)
{
	int i;

	i = 0;
	if(!heap)
		return(1);
	pthread_mutex_destroy(&heap->lock);
	while(heap->nodes && heap->nodes[i])
	{
		free(heap->nodes[i]);
		i++;
	}
	free(heap->nodes);
	free(heap);
	return(0);
}
