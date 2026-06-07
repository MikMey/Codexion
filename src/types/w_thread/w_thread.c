/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_thread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:29:50 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/07 22:34:37 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w_thread.h"

void	w_thread_create(t_configs *configs, int i)
{
	configs->w_threads[i] = malloc(sizeof(t_w_threads));
	configs->w_threads[i]->coder = configs->coders[i];
	configs->w_threads[i]->dongles = malloc(sizeof(t_dongle) * 2);
	configs->w_threads[i]->dongles[0] = configs->dongles[i
		% configs->data[CODERS]];
	configs->w_threads[i]->dongles[1] = configs->dongles[(i + 1)
		% configs->data[CODERS]];
	configs->w_threads[i]->heap = configs->heap;
	configs->w_threads[i]->log = configs->log;
	configs->w_threads[i]->data = configs->data;
	configs->w_threads[i]->node = configs->nodes[i];
}

int	w_thread_free(t_w_threads *w_thread)
{
	if (!w_thread)
		return (0);
	free(w_thread);
	return (1);
}

void	w_monitor_create(t_configs *config)
{
	config->w_monitor = malloc(sizeof(t_w_monitor));
	config->w_monitor->coders = config->coders;
	config->w_monitor->data = config->data;
	config->w_monitor->log = config->log;
}

void	w_main_create(t_configs *config)
{
	config->w_main = malloc(sizeof(t_w_main));
	config->w_main->coders = config->coders;
	config->w_main->dongles = config->dongles;
	config->w_main->data = config->data;
	config->w_main->heap = config->heap;
	config->w_main->log = config->log;
}
