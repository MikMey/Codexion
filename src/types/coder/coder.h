/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 23:48:19 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/29 23:48:20 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODER_H
# define CODER_H

# include "../dongle/dongle.h"

# define C_WAIT 0
# define C_BUSY 1

typedef struct s_coder
{
	size_t			idx;
	size_t			compile_start;
	int				state;
	size_t			times_compiled;
	pthread_mutex_t	lock;
	pthread_cond_t	wake;
}					t_coder;

int					coder_free(t_coder *coder);
t_coder				*coder_create(size_t idx, t_dongle *dongles);

#endif