/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 11:26:58 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/02 22:13:59 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	get_key_idx(t_dict *dict, void *key)
{
	size_t	i;

	i = 0;
	while (dict && dict[i].key)
	{
		if ((dict[i]).key == key)
			return (i);
		i++;
	}
	return (-1);
}

void	*get_value(t_dict *dict, void *key)
{
	size_t	i;

	i = get_key_idx(dict, key);
	return (dict[i].value);
}

void	init_dict(t_dict **dict, void *keys[], void *values[])
{
	size_t	i;

	i = 0;
	while (keys[i])
		i++;
	*dict = malloc(sizeof(dict) * (i + 1));
	if (!(*dict))
		return ;
	i = 0;
	while (keys[i])
    {
		(*dict[i]).key = ft_calloc(sizeof(void *), 30);
        memcpy((*dict[i]).key, (keys[i] + 0), 30);
        (*dict[i]).value = ft_calloc(sizeof(void *), 30);
		if (!values || !(values[i]))
			memcpy((*dict[i]).value, (NULL), 30);
		else
			memcpy((*dict[i]).value, (values[i] + 0), 30);
		i++;
    }
    (*dict[i]).key = ft_calloc(sizeof(void *), 30);
    (*dict[i]).value = ft_calloc(sizeof(void *), 30);
	(*dict[i]).key = NULL;
	(*dict[i]).value = NULL;
}
