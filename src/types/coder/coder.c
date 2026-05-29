/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:12:47 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/29 16:32:58 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"

t_coder	*coder_create(size_t idx, t_dongle *dongles)
{
	t_coder	*coder;

	coder = (t_coder *)malloc(sizeof(t_coder));
	if (!coder)
		return (coder);
	pthread_mutex_init(&coder->lock, NULL);
	pthread_cond_init(&coder->wake, NULL);
	coder->idx = idx;
	coder->state = C_BUSY;
	coder->compile_start = 0;
	coder->times_compiled = 0;
	return (coder);
}

int	coder_free(t_coder *coder)
{
	if (!coder)
		return (1);
	pthread_mutex_destroy(&coder->lock);
	pthread_cond_destroy(&coder->wake);
	free(coder);
	return (0);
}
