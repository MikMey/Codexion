/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_ops.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 11:21:35 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/31 21:30:57 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_OPS_H
# define THREAD_OPS_H

# include "../tools.h"
# include "../types/types.h"

int	compile(t_coder *coder, t_dongle **dongles, t_log *log, size_t *data);
int	wait_log(t_log *log, size_t time_to_pass, int idx, char *arg);

#endif