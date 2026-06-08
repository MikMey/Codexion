/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 00:01:18 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/08 02:27:30 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"

void	*monitor(void *parse)
{
	int			*finished;
	t_w_monitor	*w_monitor;

	w_monitor = (t_w_monitor *)parse;
	finished = ft_calloc(sizeof(int), w_monitor->data[CODERS] + 1);
	run_check(w_monitor, finished, 0);
	free(finished);
	return (NULL);
}

void	run_check(t_w_monitor *w_monitor, int *finished, size_t done)
{
	int	death;
	int	i;

	i = 0;
	death = 0;
	while (!death)
	{
		i = (i + 1) % w_monitor->data[CODERS];
		if (finished[i])
		{
			done++;
			if (done > w_monitor->data[CODERS])
			{
				log_finished(w_monitor->log, 1);
				break ;
			}
			continue ;
		}
		done = 0;
		death = check_death(w_monitor, finished, death, i);
	}
	if (death)
		log_print(w_monitor->log, gettimems(), i, M_BURNOUT);
	log_death(w_monitor->log, death);
}

int	check_death(t_w_monitor *w_monitor, int *finished, int death, int i)
{
	pthread_mutex_lock(&w_monitor->coders[i]->lock);
	if (w_monitor->coders[i]->times_compiled >= w_monitor->data[REQUIRED])
		finished[i] = 1;
	else if ((w_monitor->coders[i]->compile_start
			+ (uint64_t)w_monitor->data[BURNOUT]) < gettimems())
		death = 1;
	pthread_mutex_unlock(&w_monitor->coders[i]->lock);
	return (death);
}
