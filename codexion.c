/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:03:24 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/31 21:30:10 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (i < config->data[CODERS])
	{
		pthread_create(&config->threads[i], NULL, coders,
			&config->w_threads[i]);
		i++;
	}
	pthread_create(&thread_monitor, NULL, monitor, &config->w_monitor);
	heap_manager(config->w_main);
}
