/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 00:01:20 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/05 21:14:34 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"

void	heap_manager(t_w_main *w_main)
{
	int	idx;

	pthread_mutex_lock(&w_main->heap->lock);
	while (1)
	{
		pthread_mutex_unlock(&w_main->heap->lock);
		pthread_mutex_lock(&w_main->heap->lock);
		while(w_main->heap->nodes[0])
		{
			idx = w_main->heap->nodes[0]->idx;
			pthread_mutex_lock(&w_main->coders[idx]->lock);
			if (w_main->coders[idx]->state == C_BUSY)
			{
				pthread_mutex_unlock(&w_main->coders[idx]->lock);
				idx = w_main->heap->nodes[1]->idx;
				pthread_mutex_lock(&w_main->coders[idx]->lock);
				if (w_main->coders[idx]->state == C_BUSY)
				{
					pthread_mutex_unlock(&w_main->coders[idx]->lock);
					continue ;
				}
			}
			pthread_cond_broadcast(&w_main->coders[idx]->wake);
			pthread_mutex_unlock(&w_main->coders[idx]->lock);
			if (log_print(w_main->log, 0, 0, NULL, 0, 0) > 1)
				break ;
			heap_pop_idx(w_main->heap, idx);
		}
		if (log_print(w_main->log, 0, 0, NULL, 0, 0) > 1)
			break ;
	}
	pthread_mutex_unlock(&w_main->heap->lock);
}
