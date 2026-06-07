/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 11:21:57 by mimeyer           #+#    #+#             */
/*   Updated: 2026/06/08 00:34:55 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "../utils/utils.h"
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdint.h>

# define DATA 8
# define MAX 999999
# define DELAY 10

# define CODERS 0
# define BURNOUT 1
# define COMPILE 2
# define DEBUG 3
# define REFRACTOR 4
# define REQUIRED 5
# define COOLDOWN 6
# define SCHEDULER 7

# define FIFO 0
# define EDF 1

# define M_TAKEN " has taken a dongle\n"
# define M_COMPILE " is compiling\n"
# define M_DEBUG " is debugging\n"
# define M_REFRACTOR " is refractoring\n"
# define M_BURNOUT " burned out\n"
# define M_START " has started\n"
# define M_END " is finished\n"
# define M_POP " is popped\n"
# define M_MONITOR " is being observed\n"

#endif