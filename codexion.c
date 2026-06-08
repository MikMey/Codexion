/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:03:24 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/08 01:36:15 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "codexion.h"

int	main(int argc, char **argv)
{
	size_t		*data;
	t_configs	*config;
	pthread_t	thread_monitor;
	size_t		i;

	i = 0;
	check_args(argc, argv);
	data = get_data(argc, argv);
	config = init(data);
	config->log->start = gettimems();
	while (i < data[CODERS])
	{
		pthread_create(&config->threads[i], NULL, coders, config->w_threads[i]);
		i++;
	}
	pthread_create(&thread_monitor, NULL, monitor, config->w_monitor);
	heap_manager(config->w_main);
}

// TODO fail coder = 1

// char name[16];
// snprintf(name, sizeof(name), "coder-%d", i);

// pthread_setname_np(config->threads[i], name);

// usleep(1000000);
// for (int i = 0; i < data[CODERS]; i++)
// 	printf("\n%d: %zu", i, config->coders[i]->times_compiled);
// printf("\nfinished and done\n");