/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_thread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:29:50 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/29 16:43:06 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w_thread.h"

t_w_threads	*w_thread_create(t_coder *coder, t_dongle **dongles, t_heap *heap,
		t_log *log)
{
	t_w_threads	*w_thread;

	if (!coder || !dongles || !dongles[0] || !dongles[1] || !heap || !log)
		return (NULL);
	w_thread = malloc(sizeof(t_w_threads));
	if (!w_thread)
		return (NULL);
	w_thread->coder = &coder;
	w_thread->dongles[0] = &dongles[0];
	w_thread->dongles[1] = &dongles[1];
	w_thread->heap = &heap;
	w_thread->log = &log;
	return (w_thread);
}

int	w_thread_free(t_w_threads *w_thread)
{
	if (!w_thread)
		return (0);
	free(w_thread);
	return (1);
}
