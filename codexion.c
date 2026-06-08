/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:03:24 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/08 22:47:08 by mimeyer          ###   ########.fr       */
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
	if(check_args(argc, argv))
		return (1);
	data = get_data(argc, argv);
	if (!data)
		return (1);
	config = init(data);
	if (!config)
		return (1);
	config->log->start = gettimems();
	while (i < data[CODERS])
	{
		pthread_create(&config->threads[i], NULL, coders, config->w_threads[i]);
		i++;
	}
	pthread_create(&thread_monitor, NULL, monitor, config->w_monitor);
	heap_manager(config->w_main);
	pthread_join(thread_monitor, NULL);
	finish(config);
	free(config);
}

int	finish(t_configs *config)
{
	size_t	i;

	i = 0;
	while (config->threads[i])
	{
		pthread_join(config->threads[i], NULL);
		i++;
	}
	free(config->threads);
	arr_free((void **)config->w_threads, w_thread_free);
	arr_free((void **)config->nodes, free);
	arr_free((void **)config->dongles, dongle_free);
	arr_free((void **)config->coders, coder_free);
	free(config->data);
	log_free(config->log);
	heap_free(config->heap);
	free(config->w_main);
	free(config->w_monitor);
	return (0);
}

int	arr_free(void **arr, void (*func)(void *))
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		func(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

// TODO fail coder = 1

// char name[16];
// snprintf(name, sizeof(name), "coder-%d", i);

// pthread_setname_np(config->threads[i], name);

// usleep(1000000);
// for (int i = 0; i < data[CODERS]; i++)
// 	printf("\n%d: %zu", i, config->coders[i]->times_compiled);
// printf("\nfinished and done\n");