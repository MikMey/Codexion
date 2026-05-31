/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 00:03:07 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/31 20:33:51 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

# include "../thread_ops/thread_ops.h"

void	*coders(void *w_threads);
void	heap_manager(t_w_main *w_main);
void	*monitor(void *w_monitor);

#endif