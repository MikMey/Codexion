/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:15:21 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/01 14:57:35 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

bool    init_manager(t_dict **config, int argc, char **argv)
{
    if (argc < 9)
        return(false);
    *config = malloc(sizeof(t_dict *) * 9);
    if (!(*config))
    {
        free(*config);
        return(false);
    }
    if (!(assign_args(config, argv)))
        return(false);
}

bool    assign_args(t_dict **config, char **argv)
{
    int i;
    int buff;
    char **keys;

    get_keys(&keys);
    i = 0;
    while (i <= 7)
    {
        buff = atoi(argv[i + 1]);
        if (buff <= 0)
            return(false);
        (*config[i]).value = (unsigned int)malloc(sizeof(unsigned int));
        (*config[i]).value = buff
    }
}

void    get_keys(char ***keys)
{
    int i;

    i = 0;
    (*keys) = ft_calloc(sizeof(char *), 9);
    while (i <= 8)
        (*keys)[i] = ft_calloc(sizeof(char), 30);

    (*keys)[0] = CODERS;
    (*keys)[1] = BURNOUT;
    (*keys)[2] = COMPILE;
    (*keys)[3] = DEBUG;
    (*keys)[4] = REFRACTOR;
    (*keys)[5] = REQUIRED;
    (*keys)[6] = COOLDOWN;
    (*keys)[7] = SCHEDULER;
}
