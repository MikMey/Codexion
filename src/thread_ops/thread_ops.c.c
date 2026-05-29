/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_ops.c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 11:24:49 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/30 00:04:55 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_ops.h"
#include <unistd.h>

int	compile(t_coder *coder, t_dongle **dongles, t_log *log, int *data)
{
	int	start;

	start = gettimeofday(NULL, NULL);
	if (log_print(log, start, coder->idx, M_COMPILE, 0) == 2)
		return (1);
	pthread_mutex_lock(&coder->lock);
	coder->compile_start = start;
	coder->state = C_BUSY;
	pthread_mutex_unlock(&coder->lock);
	dongles[0]->eoc = start + data[COMPILE] + data[COOLDOWN];
	dongles[1]->eoc = start + data[COMPILE] + data[COOLDOWN];
	if (data[COMPILE] < 0 || data[COMPILE] > 99999)
		return (1);
	while (1)
	{
		if (gettimeofday(NULL, NULL) >= (start + data[COMPILE]))
			return (0);
		usleep(data[COMPILE] / 32);
	}
}

int	wait_log(t_log *log, int time_to_pass, int idx, char *arg)
{
	int	start;

	start = gettimeofday(NULL, NULL);
	if (log_print(log, start, idx, arg, 0) == 2)
		return (1);
	if (time_to_pass < 0 || time_to_pass > 99999)
		return (1);
	while (1)
	{
		if (gettimeofday(NULL, NULL) >= (start + time_to_pass))
			return (0);
		usleep(time_to_pass / 32);
	}
}
