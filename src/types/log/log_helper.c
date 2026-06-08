/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 22:05:27 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/08 22:05:47 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

void	log_death(t_log *log, int death)
{
	pthread_mutex_lock(&log->lock);
	if (death)
		log->coder_died = 1;
	pthread_mutex_unlock(&log->lock);
}

void	log_finished(t_log *log, int finished)
{
	pthread_mutex_lock(&log->lock);
	if (finished)
		log->finished = 1;
	pthread_mutex_unlock(&log->lock);
}
