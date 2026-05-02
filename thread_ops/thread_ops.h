/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_ops.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 11:21:35 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/02 11:21:39 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_OPS_H
# define THREAD_OPS_H

# include "../tools.h"

int	compile(pthread_cond_t **cond_dongles, pthread_mutex_t **lock_dongles,
		size_t burnout, size_t time);
int	debug(size_t time);
int	refractor(size_t time);

#endif