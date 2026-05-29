/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:03:24 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/27 21:37:26 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int argc, char **argv)
{
	t_dict	*config;
	char	*keys[] = (char *[]){CODERS, BURNOUT, COMPILE, DEBUG, REFRACTOR,
			REQUIRED, COOLDOWN, SCHEDULER, NULL};

	if (!(init_manager(&config, argc, argv)))
	{
		printf("fu\n");
		return (0);
	}
	for (int i = 0; keys[i]; i++)
	{
		printf("%s\n", keys[i]);
	}
}
