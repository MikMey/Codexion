/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 00:01:22 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/04 23:50:03 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"

void	*coders(void *parse)
{
	size_t		times_compiled;
	uint64_t		time;
	t_w_threads	*w_threads;

	w_threads = (t_w_threads *)parse;
	times_compiled = 0;
	while (times_compiled != w_threads->data[REQUIRED])
	{
		if (w_threads->data[SCHEDULER] == FIFO)
			w_threads->heap = heap_insert(w_threads->heap, w_threads->node,
					gettimems());
		else
			w_threads->heap = heap_insert(w_threads->heap, w_threads->node,
					w_threads->coder->compile_start);
		pthread_mutex_lock(&w_threads->coder->lock);
		w_threads->coder->times_compiled = times_compiled;
		w_threads->coder->state = C_WAIT;
		pthread_cond_wait(&w_threads->coder->wake, &w_threads->coder->lock);
		pthread_mutex_lock(&w_threads->dongles[0]->lock);
		pthread_mutex_lock(&w_threads->dongles[1]->lock);
		pthread_mutex_unlock(&w_threads->coder->lock);
		while (1)
		{
			time = gettimems();
			if (time >= w_threads->dongles[0]->eoc
				&& time >= w_threads->dongles[1]->eoc)
				break ;
		}
		if (log_print(w_threads->log, time, w_threads->coder->idx, M_TAKEN, 0,
				0) == 2)
			break ;
		if (compile(w_threads->coder, w_threads->dongles, w_threads->log,
				w_threads->data) == 2)
			break ;
		pthread_mutex_unlock(&w_threads->dongles[0]->lock);
		pthread_mutex_unlock(&w_threads->dongles[1]->lock);
		if (wait_log(w_threads->log, w_threads->data[DEBUG],
				w_threads->coder->idx, M_DEBUG) == 2)
			break ;
		if (wait_log(w_threads->log, w_threads->data[REFRACTOR],
				w_threads->coder->idx, M_REFRACTOR) == 2)
			break ;
		times_compiled++;
	}
	return (NULL);
}
