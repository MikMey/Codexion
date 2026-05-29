/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:47:32 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/29 23:26:34 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"

t_dongle	*dongle_create(size_t idx)
{
	t_dongle	*dongle;

	dongle = malloc(sizeof(t_dongle));
	if (!dongle)
		return (dongle);
	pthread_mutex_init(&dongle->lock, NULL);
	dongle->idx = idx;
	dongle->eoc = 0;
	return (dongle);
}

int	dongle_free(t_dongle *dongle)
{
	if (!dongle)
		return (1);
	pthread_mutex_destroy(&dongle->lock);
	free(dongle);
	return (0);
}
