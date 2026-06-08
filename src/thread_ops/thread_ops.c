/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 11:24:49 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/08 22:02:18 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tools.h"
#include "thread_ops.h"

int	compile(t_coder *coder, t_dongle **dongles, t_log *log, size_t *data)
{
	size_t	start;

	start = gettimems();
	if (log_print(log, start, coder->idx, M_COMPILE) == 2)
		return (1);
	pthread_mutex_lock(&coder->lock);
	coder->compile_start = start;
	pthread_mutex_unlock(&coder->lock);
	dongles[0]->eoc = start + data[COMPILE] + data[COOLDOWN];
	dongles[1]->eoc = start + data[COMPILE] + data[COOLDOWN];
	if (data[COMPILE] > MAX)
		return (1);
	while (1)
	{
		if (log_print(log, 0, 0, NULL) > 1)
			return (1);
		if (gettimems() >= (start + data[COMPILE]))
			return (0);
	}
}

int	prep_compile(t_w_threads *w_threads, size_t times_compiled)
{
	uint64_t	time;

	pthread_mutex_lock(&w_threads->coder->lock);
	w_threads->coder->times_compiled = times_compiled;
	w_threads->coder->state = C_WAIT;
	pthread_cond_wait(&w_threads->coder->wake, &w_threads->coder->lock);
	pthread_mutex_lock(&w_threads->dongles[0]->lock);
	pthread_mutex_lock(&w_threads->dongles[1]->lock);
	w_threads->coder->state = C_BUSY;
	pthread_mutex_unlock(&w_threads->coder->lock);
	time = gettimems();
	if (log_print(w_threads->log, time, w_threads->coder->idx, M_TAKEN) == 2)
	{
		unlock_dongles(w_threads->dongles);
		return (1);
	}
	if (compile(w_threads->coder, w_threads->dongles, w_threads->log,
			w_threads->data) == 2)
	{
		unlock_dongles(w_threads->dongles);
		return (1);
	}
	unlock_dongles(w_threads->dongles);
	return (0);
}

void	unlock_dongles(t_dongle **dongles)
{
	pthread_mutex_unlock(&dongles[0]->lock);
	pthread_mutex_unlock(&dongles[1]->lock);
}

int	wait_log(t_log *log, uint64_t time_to_pass, int idx, char *arg)
{
	uint64_t	start;

	start = gettimems();
	if (log_print(log, start, idx, arg) == 2)
		return (1);
	if (time_to_pass > 99999)
		return (1);
	while (1)
	{
		if (log_print(log, 0, 0, NULL) > 1)
			return (1);
		if (gettimems() >= (start + time_to_pass))
			return (0);
	}
}

int	work(t_log *log, size_t *data, int idx)
{
	if (wait_log(log, data[DEBUG], idx, M_DEBUG) == 2)
		return (1);
	if (wait_log(log, data[REFRACTOR], idx, M_REFRACTOR) == 2)
		return (1);
	return (0);
}

// usleep((time_to_pass * 1000) / 32);
