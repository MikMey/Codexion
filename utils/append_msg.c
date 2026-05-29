/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:37:40 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/29 17:42:42 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * unsafe but fun
 */
char	**append_msg(char **msg, char *arg)
{
	int	i;

	i = 0;
	if (!msg)
		return (NULL);
	while (msg[i] && msg[i][0])
		i++;
	ft_strlcpy(msg[i], arg, ft_strlen(arg));
	return (msg);
}
