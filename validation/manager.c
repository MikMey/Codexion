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
    return(true);
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
        i++;
    }
    ft_strlcpy((*config[i]).value, argv[i + 1], strlen(argv[i + 1]));
    if (!(strcmp(argv[i + 1], "fifo")) || !(strcmp(argv[i + 1], "edf")))
        return(false);
    return(true);
}

void    get_keys(char ***keys)
{
    int i;

    i = 0;
    (*keys) = ft_calloc(sizeof(char *), 9);
    while (i <= 8)
        (*keys)[i] = ft_calloc(sizeof(char), 30);

    ft_strlcpy((*keys)[0], CODERS, strlen(CODERS));
    ft_strlcpy((*keys)[1], BURNOUT, strlen(BURNOUT));
    ft_strlcpy((*keys)[2], COMPILE, strlen(COMPILE));
    ft_strlcpy((*keys)[3], DEBUG, strlen(DEBUG));
    ft_strlcpy((*keys)[4], REFRACTOR, strlen(REFRACTOR));
    ft_strlcpy((*keys)[5], REQUIRED, strlen(REQUIRED));
    ft_strlcpy((*keys)[6], COOLDOWN, strlen(COOLDOWN));
    ft_strlcpy((*keys)[7], SCHEDULER, strlen(SCHEDULER));
}
