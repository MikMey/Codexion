/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:15:21 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/04 22:30:52 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	check_args(int argc, char **argv)
{
	size_t	i;

	i = 1;
	if (argc != 9)
		return (1);
	while (i <= 8)
	{
		if (!ft_isstr(argv[i], ft_isdigit))
			return (1);
		i++;
	}
	if (strcmp("fifo", argv[argc - 1]) != 0
		&& strcmp("edf", argv[argc - 1]) != 0)
		return (1);
	return (0);
}

size_t	*get_data(int argc, char **argv)
{
	size_t	i;
	size_t	*data;

	i = 0;
	data = ft_calloc(sizeof(size_t), DATA + 1);
	if (!data)
		return (NULL);
	while (i < 7)
	{
		data[i] = (size_t)atoi(argv[i + 1]);
		if (data[i] > MAX)
		{
			free(data);
			return (NULL);
		}
		i++;
	}
	if (!strcmp("fifo", argv[argc - 1]))
		data[SCHEDULER] = FIFO;
	else
		data[SCHEDULER] = EDF;
	return (data);
}
