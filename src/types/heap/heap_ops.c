/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:10:14 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/08 00:51:08 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

t_heap	*heap_insert(t_heap *heap, t_node_heap *node, uint64_t time)
{
	int	i;

	i = 0;
	if (!heap)
		return (heap);
	pthread_mutex_lock(&heap->lock);
	node->time = time;
	while (heap->nodes[i])
		i++;
	heap->nodes[i] = node;
	while (i > 0)
	{
		if (heap->nodes[(i - 1) / 2]->time > heap->nodes[i]->time)
		{
			heap_swap(heap, i, (i - 1) / 2);
			i = (i - 1) / 2;
		}
		else
			break ;
	}
	pthread_mutex_unlock(&heap->lock);
	return (heap);
}

void	heap_swap(t_heap *heap, int x, int y)
{
	t_node_heap	*temp_node;

	temp_node = heap->nodes[x];
	heap->nodes[x] = heap->nodes[y];
	heap->nodes[y] = temp_node;
}

void	heap_pop_coder(t_heap *heap, int coder)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	if (!heap->nodes[0])
		return ;
	while (heap->nodes[size])
	{
		if (heap->nodes[size]->idx == coder)
			i = size;
		size++;
	}
	heap_swap(heap, size - 1, i);
	heap->nodes[size - 1] = NULL;
	heap_sort(heap, i);
	return ;
}

void	heap_sort(t_heap *heap, int i)
{
	int	left_child;
	int	right_child;
	int	size;
	int	smallest;

	size = 0;
	left_child = 2 * i + 1;
	right_child = 2 * i + 2;
	while (heap->nodes[size])
		size++;
	smallest = i;
	if (left_child < size
		&& heap->nodes[left_child]->time < heap->nodes[i]->time)
		smallest = left_child;
	if (right_child < size
		&& heap->nodes[right_child]->time < heap->nodes[i]->time && heap->nodes[right_child]->time < heap->nodes[left_child]->time)
		smallest = right_child;
	if (smallest != i)
	{
		heap_swap(heap, smallest, i);
		heap_sort(heap, smallest);
	}
}
