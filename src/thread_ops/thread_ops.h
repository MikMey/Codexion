/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_ops.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 11:21:35 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/30 00:04:45 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_OPS_H
# define THREAD_OPS_H

# include "../tools.h"
# include "../types/types.h"

int	compile(t_coder *coder, t_dongle **dongles, t_log *log, int *data);
int	wait_log(t_log *log, int time_to_pass, int idx, char *arg);

#endif