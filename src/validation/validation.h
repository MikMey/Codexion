/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 11:21:49 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/04 22:59:02 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "../tools.h"
# include "../types/types.h"

int			check_args(int argc, char **argv);
size_t		*get_data(int argc, char **argv);
t_configs	*init(size_t *data);

void		arr_coders_create(t_configs *config);
void		arr_dongles_create(t_configs *config);
void		arr_threads_create(t_configs *config);
void		arr_nodes_create(t_configs *config);

#endif