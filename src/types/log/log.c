/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:13:45 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/08 00:55:22 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

t_log	*log_create(void)
{
	t_log	*log;

	log = malloc(sizeof(t_log));
	if (!log)
		return (NULL);
	pthread_mutex_init(&log->lock, NULL);
	log->coder_died = 0;
	log->finished = 0;
	log->start = gettimems();
	return (log);
}

int	log_print(t_log *log, uint64_t time, int idx, char *arg, int death, int finished)
{
	pthread_mutex_lock(&log->lock);
	if (log->coder_died || death)
	{
		log->coder_died = 1;
		pthread_mutex_unlock(&log->lock);
		return (2);
	}
	if (time && arg)
	{
		ft_putstr_fd(ft_itoa(time - log->start), 1);
		write(1, " ", 1);
		ft_putstr_fd(ft_itoa(idx), 1);
		ft_putstr_fd(arg, 1);
	}
	if (log->finished || finished)
	{
		log->finished = 1;
		pthread_mutex_unlock(&log->lock);
		return (3);
	}
	pthread_mutex_unlock(&log->lock);
	return (0);
}

int	log_free(t_log *log)
{
	if (!log)
		return (1);
	pthread_mutex_destroy(&log->lock);
	free(log);
	return (0);
}
