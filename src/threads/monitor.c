/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 00:01:18 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/30 00:07:33 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"

void	monitor(t_w_monitor *w_monitor)
{
	int *finished;
	int i;
	int done;
	int death;

	death = 0;
	i = 0;
	finished = ft_calloc(sizeof(int), w_monitor->data[CODERS] + 1);
	while (!death)
	{
		if (finished[i])
		{
			i++;
			continue;
		}
		pthread_mutex_lock(&w_monitor->coders[i]->lock);
		if(w_monitor->coders[i]->times_compiled >= w_monitor->data[REQUIRED])
			finished[i] = 1;
		else if ((w_monitor->coders[i]->compile_start + w_monitor->data[BURNOUT]) > gettimeofday(NULL, NULL))
			death = 1;
		pthread_mutex_unlock(&w_monitor->coders[i]->lock);
		done = 0;
		while (finished[done])
			done++;
		if (done >= w_monitor->data[CODERS])
			break;
		i++;
	}
	if (death)
		log_print(w_monitor->log, gettimeofday(NULL, NULL), i - 1, M_BURNOUT, death);
	free(finished);
}
