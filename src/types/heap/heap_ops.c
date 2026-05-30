/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:10:14 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/29 15:13:40 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

t_heap	*heap_insert(t_heap *heap, int time, pthread_cond_t wake)
{
	int i;
	int temp_time;
	pthread_cond_t temp_wait;
// TODO i need idx of coder
	i = 0;
	if (!heap || !new_node)
		return(heap);
	pthread_mutex_lock(&heap->lock);
	while (heap->node[i])
		i++;
	heap->node[i]->wake = wake;
	heap->node[i]->time = time;
	while (i > 0)
	{
		if (heap->node[(i - 1) / 2]->time > heap->node[i]->time)
		{
			temp_time = heap->node[i]->time;
			temp_heap = heap->node[i]->wake;
			heap->node[i]->time = heap->node[(i - 1) / 2]->time;
			heap->node[i]->wake = heap->node[(i - 1) / 2]->wake;
			heap->node[(i - 1) / 2]->time = temp_time;
			heap->node[(i - 1) / 2]->wake = temp_heap;
			i = (i - 1) / 2;
		}
		else
			break;
	}
	pthread_mutex_unlock(&heap->lock);
	return(heap);
}
