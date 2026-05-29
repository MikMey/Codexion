/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:13:45 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/29 23:30:20 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

t_log	*log_create(void)
{
	t_log	*log;

	log = malloc(sizeof(log));
	if (!log)
		return (NULL);
	pthread_mutex_init(&log->lock, NULL);
	log->coder_died = 0;
	log->start = gettimeofday(NULL, NULL);
	return (log);
}

int	log_print(t_log *log, int time, int idx, char *arg, int death)
{
	if (!arg)
		return (1);
	pthread_mutex_lock(&log->lock);
	ft_putstr_fd(arg, 1);
	if (log->coder_died || death)
	{
		log->coder_died = 1;
		pthread_mutex_unlock(&log->lock);
		return (2);
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
