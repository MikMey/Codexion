/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_thread.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 23:48:36 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/07 22:30:46 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_THREAD_H
# define W_THREAD_H

# include "../coder/coder.h"
# include "../dongle/dongle.h"
# include "../heap/heap.h"
# include "../log/log.h"

typedef struct s_w_threads
{
	t_coder		*coder;
	t_dongle	**dongles;
	t_heap		*heap;
	t_log		*log;
	size_t		*data;
	t_node_heap	*node;
}				t_w_threads;

typedef struct s_w_monitor
{
	t_coder		**coders;
	t_log		*log;
	size_t		*data;
}				t_w_monitor;

typedef struct s_w_main
{
	t_coder		**coders;
	t_dongle	**dongles;
	t_heap		*heap;
	t_log		*log;
	size_t		*data;
}				t_w_main;

typedef struct s_configs
{
	pthread_t	*threads;
	t_coder		**coders;
	t_dongle	**dongles;
	t_node_heap	**nodes;
	t_heap		*heap;
	t_log		*log;
	size_t		*data;
	t_w_main	*w_main;
	t_w_threads	**w_threads;
	t_w_monitor	*w_monitor;
}				t_configs;

void			w_thread_create(t_configs *configs, int i);
void			w_monitor_create(t_configs *config);
void			w_main_create(t_configs *config);

#endif