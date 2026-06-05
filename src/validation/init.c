/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 14:09:57 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/04 23:07:16 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

t_configs	*init(size_t *data)
{
	t_configs	*config;

	config = malloc(sizeof(t_configs));
	config->threads = malloc(sizeof(pthread_t) * data[CODERS] + 1);
	config->coders = malloc(sizeof(t_coder *) * (data[CODERS] + 1));
	config->dongles = malloc(sizeof(t_dongle *) * (data[CODERS] + 1));
	config->nodes = malloc(sizeof(t_node_heap *) * (data[CODERS] + 1));
	config->data = data;
	config->heap = heap_create(data[CODERS]);
	config->log = log_create();
	arr_coders_create(config);
	arr_dongles_create(config);
	w_main_create(config);
	w_monitor_create(config);
	config->w_threads = malloc(sizeof(t_w_threads *) * (data[CODERS] + 1));
	arr_nodes_create(config);
	arr_threads_create(config);
	return (config);
}

void	arr_coders_create(t_configs *config)
{
	size_t	i;

	i = 0;
	while (i < config->data[CODERS])
	{
		config->coders[i] = coder_create(i);
		i++;
	}
	config->coders[i] = NULL;
}

void	arr_dongles_create(t_configs *config)
{
	size_t	i;

	i = 0;
	while (i < config->data[CODERS])
	{
		config->dongles[i] = dongle_create(i);
		i++;
	}
	config->dongles[i] = NULL;
}

void	arr_threads_create(t_configs *config)
{
	size_t	i;

	i = 0;
	while (i < config->data[CODERS])
	{
		w_thread_create(config, i);
		i++;
	}
	config->w_threads[i] = NULL;
}

void	arr_nodes_create(t_configs *config)
{
	size_t	i;

	i = 0;
	while (i < config->data[CODERS])
	{
		config->nodes[i] = node_create(i, config->coders[i]->wake, gettimems() + ((2 % (i + 1)) * DELAY));
		i++;
	}
	config->w_threads[i] = NULL;
}
