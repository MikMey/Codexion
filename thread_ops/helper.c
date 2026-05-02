/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 10:59:05 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/02 11:18:47 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_ops.h"

int	compile(pthread_cond_t **cond_dongles, pthread_mutex_t **lock_dongles,
		size_t burnout, size_t time)
{
	if (!pthread_cond_timedwait(cond_dongles[0], lock_dongles[0], burnout)
		&& !pthread_cond_timedwait(cond_dongles[1], lock_dongles[1], burnout)
		&& !usleep(time))
		return (0);
	else
		return (1);
}

int	debug(size_t time)
{
	return (usleep(time));
}

int	refractor(size_t time)
{
	return (usleep(time));
}
