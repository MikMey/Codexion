/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:12:47 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/08 20:22:50 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"

t_coder	*coder_create(size_t idx)
{
	t_coder	*coder;

	coder = (t_coder *)malloc(sizeof(t_coder));
	if (!coder)
		return (coder);
	pthread_mutex_init(&coder->lock, NULL);
	pthread_cond_init(&coder->wake, NULL);
	coder->idx = idx;
	coder->state = C_BUSY;
	coder->compile_start = gettimems();
	coder->times_compiled = 0;
	return (coder);
}

void	coder_free(void *parse)
{
	t_coder	*coder;

	coder = (t_coder *)parse;
	if (!coder)
		return ;
	pthread_mutex_destroy(&coder->lock);
	pthread_cond_destroy(&coder->wake);
	free(coder);
}
