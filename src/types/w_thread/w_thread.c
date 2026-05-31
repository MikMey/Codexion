/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_thread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:29:50 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/31 20:38:19 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w_thread.h"

void	w_thread_create(t_configs *configs, int i)
{
	configs->w_threads[i] = malloc(sizeof(t_w_threads *));
	configs->w_threads[i]->coder = configs->coders[i];
	configs->w_threads[i]->dongles[0] = configs->dongles[configs->data[CODERS]
		% i];
	configs->w_threads[i]->dongles[1] = configs->dongles[configs->data[CODERS]
		% (i + 1)];
	configs->w_threads[i]->heap = configs->heap;
	configs->w_threads[i]->log = configs->log;
}

int	w_thread_free(t_w_threads *w_thread)
{
	if (!w_thread)
		return (0);
	free(w_thread);
	return (1);
}
