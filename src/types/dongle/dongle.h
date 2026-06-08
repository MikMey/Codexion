/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 23:48:45 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/08 00:26:06 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DONGLE_H
# define DONGLE_H

# include "../../tools.h"
# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_dongle
{
	size_t			idx;
	uint64_t		eoc;
	pthread_mutex_t	lock;
}					t_dongle;

t_dongle			*dongle_create(size_t idx);
int					dongle_free(t_dongle *dongle);

#endif