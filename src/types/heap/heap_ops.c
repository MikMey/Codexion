/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:10:14 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/31 21:24:47 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

t_heap	*heap_insert(t_heap *heap, size_t time, pthread_cond_t wake)
{
	int				i;
	int				temp_time;
	pthread_cond_t	temp_wake;

	// TODO i need idx of coder
	i = 0;
	if (!heap)
		return (heap);
	pthread_mutex_lock(&heap->lock);
	while (heap->nodes[i])
		i++;
	heap->nodes[i]->wake = wake;
	heap->nodes[i]->time = time;
	while (i > 0)
	{
		if (heap->nodes[(i - 1) / 2]->time > heap->nodes[i]->time)
		{
			temp_time = heap->nodes[i]->time;
			temp_wake = heap->nodes[i]->wake;
			heap->nodes[i]->time = heap->nodes[(i - 1) / 2]->time;
			heap->nodes[i]->wake = heap->nodes[(i - 1) / 2]->wake;
			heap->nodes[(i - 1) / 2]->time = temp_time;
			heap->nodes[(i - 1) / 2]->wake = temp_wake;
			i = (i - 1) / 2;
		}
		else
			break ;
	}
	pthread_mutex_unlock(&heap->lock);
	return (heap);
}
