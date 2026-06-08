/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 00:01:22 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/08 02:06:46 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"

void	*coders(void *parse)
{
	size_t		times_compiled;
	uint64_t	time;
	t_w_threads	*w_threads;

	w_threads = (t_w_threads *)parse;
	time = gettimems() + ((w_threads->coder->idx % 2) * 1);
	times_compiled = 0;
	while (times_compiled != w_threads->data[REQUIRED])
	{
		w_threads->heap = heap_insert(w_threads->heap, w_threads->node, time);
		if (prep_compile(w_threads, times_compiled))
			break ;
		if (work(w_threads->log, w_threads->data, w_threads->coder->idx))
			break ;
		times_compiled++;
		if (w_threads->data[SCHEDULER] == FIFO)
			time = gettimems();
		else
			time = w_threads->coder->compile_start;
	}
	pthread_mutex_lock(&w_threads->coder->lock);
	w_threads->coder->times_compiled = times_compiled;
	pthread_mutex_unlock(&w_threads->coder->lock);
	return (NULL);
}

// log_print(w_threads->log, gettimems(), w_threads->coder->idx, M_END, 0, 0);
