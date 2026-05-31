/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 23:48:55 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/31 21:24:37 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_H
# define HEAP_H

# include <pthread.h>
# include <stdlib.h>

typedef struct s_node_heap
{
	pthread_cond_t	wake;
	int				time;
	int				idx;
}					t_node_heap;

typedef struct s_heap
{
	t_node_heap		**nodes;
	pthread_mutex_t	lock;
}					t_heap;

t_heap				*heap_create(int size);
int					heap_free(t_heap *heap);
t_heap				*heap_insert(t_heap *heap, size_t time,
						pthread_cond_t wake);

#endif