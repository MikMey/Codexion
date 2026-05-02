/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 11:21:44 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/02 12:14:48 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../tools.h"

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	get_key_idx(t_dict *dict, void *key);
void	*get_value(t_dict *dict, void *key);
void	init_dict(t_dict **dict, void *keys[], void *values[]);

#endif