/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:16:05 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/30 14:16:13 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_isdigit(int c)
{
	if (c < 58 && c > 47)
		return (c);
	return (0);
}

int	ft_isstr(char *arg, int (*check)(int))
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		if (check(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 1)
// 		return(atoi(argv[1]));
// 	// char *test = 0;
// 	int my = ft_isdigit(atoi(argv[1]));
// 	int og = isdigit(atoi(argv[1]));
// 	printf("\nmy: %i\nog: %i\ncompare: %i\n\n", my,
//	og, memcmp(&my, &og,sizeof(int)));
// }
