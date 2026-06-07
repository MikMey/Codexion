/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 00:01:20 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/08 01:32:56 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"
#include "../tools.h"

void	heap_manager(t_w_main *w_main)
{
	int	idx;
	uint64_t time;
	uint64_t	*eoc;

	eoc = ft_calloc(w_main->data[CODERS] ,sizeof(uint64_t));
	pthread_mutex_lock(&w_main->heap->lock);
	while (1)
	{
		if (log_print(w_main->log, 0, 0, NULL, 0, 0) > 1)
			break ;
		pthread_mutex_unlock(&w_main->heap->lock);
		pthread_mutex_lock(&w_main->heap->lock);
		if(w_main->heap->nodes[0])
		{
			heap_sort(w_main->heap, 0);
			idx = w_main->heap->nodes[0]->idx;
			pthread_mutex_lock(&w_main->coders[idx]->lock);
			if (w_main->coders[idx]->state == C_BUSY)
			{
				pthread_mutex_unlock(&w_main->coders[idx]->lock);
				continue ;
			}
			time = gettimems();
			if (time < eoc[idx]
				|| time < eoc[(idx + 1) % (w_main->data[CODERS] - 1)])
			{
				pthread_mutex_unlock(&w_main->coders[idx]->lock);
				continue;;
			}
			pthread_cond_broadcast(&w_main->coders[idx]->wake);
			pthread_mutex_unlock(&w_main->coders[idx]->lock);
			time = gettimems();
			eoc[idx] = time + w_main->data[COMPILE] + w_main->data[COOLDOWN];
			eoc[(idx + 1) % (w_main->data[CODERS] - 1)] = time + w_main->data[COMPILE] + w_main->data[COOLDOWN];
			heap_pop_coder(w_main->heap, idx);
		}
	}
	pthread_mutex_unlock(&w_main->heap->lock);
}
