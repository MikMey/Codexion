/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:03:24 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/05 20:49:32 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "codexion.h"

int	main(int argc, char **argv)
{
	size_t		*data;
	t_configs	*config;
	pthread_t	thread_monitor;
	// size_t		i;

	// i = 0;
	check_args(argc, argv);
	data = get_data(argc, argv);
	config = init(data);
	// while (i < config->data[CODERS])
	// {
	// 	config->heap = heap_insert(config->heap, config->nodes[i], config->nodes[i]->time);
	// 	i++;
	// }
	// i = 0;
	for (int i = 0; i < (int)config->data[CODERS]; i++)
	{
		pthread_create(&config->threads[i], NULL, coders, config->w_threads[i]);

		char name[16];
		snprintf(name, sizeof(name), "coder-%d", i);

		pthread_setname_np(config->threads[i], name);
	}
	pthread_create(&thread_monitor, NULL, monitor, config->w_monitor);
	heap_manager(config->w_main);
}
