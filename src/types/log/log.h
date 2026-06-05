/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 23:48:40 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/04 23:49:54 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include "../../tools.h"
# include <pthread.h>
# include <unistd.h>

typedef struct s_log
{
	pthread_mutex_t	lock;
	int				coder_died;
	int				finished;
	int				start;
}					t_log;

t_log				*log_create(void);
int					log_print(t_log *log, uint64_t time, int idx, char *arg,
						int death, int finished);
int					log_free(t_log *log);

#endif