/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 00:01:20 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/08 22:30:42 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tools.h"
#include "threads.h"

static void	wake_all_coders(t_w_main *w_main)
{
	size_t	i;

	i = 0;
	usleep(1000);
	while (w_main->coders[i])
	{
		pthread_mutex_lock(&w_main->coders[i]->lock);
		pthread_cond_broadcast(&w_main->coders[i]->wake);
		pthread_mutex_unlock(&w_main->coders[i]->lock);
		i++;
	}
}

void	heap_manager(t_w_main *w_main)
{
	uint64_t	*eoc;

	eoc = ft_calloc(w_main->data[CODERS], sizeof(uint64_t));
	pthread_mutex_lock(&w_main->heap->lock);
	while (1)
	{
		if (log_print(w_main->log, 0, 0, NULL) > 1)
			break ;
		pthread_mutex_unlock(&w_main->heap->lock);
		pthread_mutex_lock(&w_main->heap->lock);
		if (w_main->heap->nodes[0] && heap_check(w_main, eoc))
			continue ;
	}
	pthread_mutex_unlock(&w_main->heap->lock);
	wake_all_coders(w_main);
	free(eoc);
}

int	heap_check(t_w_main *w_main, uint64_t *eoc)
{
	uint64_t	time;
	int			idx;

	heap_sort(w_main->heap, 0);
	idx = w_main->heap->nodes[0]->idx;
	pthread_mutex_lock(&w_main->coders[idx]->lock);
	if (w_main->coders[idx]->state == C_BUSY)
	{
		pthread_mutex_unlock(&w_main->coders[idx]->lock);
		return (1);
	}
	time = gettimems();
	if (time < eoc[idx] || time < eoc[(idx + 1) % (w_main->data[CODERS] - 1)])
	{
		pthread_mutex_unlock(&w_main->coders[idx]->lock);
		return (1);
	}
	pthread_cond_broadcast(&w_main->coders[idx]->wake);
	pthread_mutex_unlock(&w_main->coders[idx]->lock);
	time = gettimems();
	eoc[idx] = time + w_main->data[COMPILE] + w_main->data[COOLDOWN];
	eoc[(idx + 1) % (w_main->data[CODERS] - 1)] = time + w_main->data[COMPILE]
		+ w_main->data[COOLDOWN];
	heap_pop_coder(w_main->heap, idx);
	return (0);
}
