/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_thread.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 23:48:36 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/29 23:48:37 by mimeyer          ###   ########.fr       */
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
	int			*data;
}				t_w_threads;

typedef struct s_w_monitor
{
	t_coder		**coders;
	t_log		*log;
	int			*data;
}	t_w_monitor

#endif