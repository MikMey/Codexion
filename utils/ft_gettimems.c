/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettimems.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 21:10:08 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/04 23:45:54 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

uint64_t	gettimems(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((uint64_t)tv.tv_sec * 1000 + (uint64_t)tv.tv_usec / 1000);
}
