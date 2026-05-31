/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 23:48:45 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/31 21:29:13 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DONGLE_H
# define DONGLE_H

# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_dongle
{
	size_t			idx;
	size_t			eoc;
	pthread_mutex_t	lock;
}					t_dongle;

t_dongle			*dongle_create(size_t idx);
int					dongle_free(t_dongle *dongle);

#endif