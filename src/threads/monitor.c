/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 00:01:18 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/08 01:33:07 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"

void	*monitor(void *parse)
{
	int			*finished;
	int			i;
	size_t		done;
	int			death;
	t_w_monitor	*w_monitor;

	w_monitor = (t_w_monitor *)parse;
	death = 0;
	done = 0;
	i = 0;
	finished = ft_calloc(sizeof(int), w_monitor->data[CODERS] + 1);
	while (!death)
	{
		i = (i + 1) % w_monitor->data[CODERS];
		if (finished[i])
		{
			i++;
			done++;
			if (done > w_monitor->data[CODERS])
			{
				log_print(w_monitor->log, 0, 0, NULL, 0, 1);
				break ;
			}
			continue ;
		}
		done = 0;
		pthread_mutex_lock(&w_monitor->coders[i]->lock);
		if (w_monitor->coders[i]->times_compiled >= w_monitor->data[REQUIRED])
			finished[i] = 1;
		else if ((w_monitor->coders[i]->compile_start
				+ (uint64_t)w_monitor->data[BURNOUT]) < gettimems())
			death = 1;
		pthread_mutex_unlock(&w_monitor->coders[i]->lock);
	}
	if (death)
		log_print(w_monitor->log, gettimems(), i, M_BURNOUT, 0, 0);
		log_print(w_monitor->log, 0, 0, NULL, death, 0);
	free(finished);
	return (NULL);
}
