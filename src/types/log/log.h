/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 23:48:40 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/08 22:07:14 by mimeyer          ###   ########.fr       */
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
	uint64_t		start;
}					t_log;

void				log_death(t_log *log, int death);
void				log_finished(t_log *log, int finished);
t_log				*log_create(void);
int					log_print(t_log *log, uint64_t time, int idx, char *arg);
int					log_free(t_log *log);
void				arg_write(t_log *log, uint64_t time, int idx, char *arg);

#endif