/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:18:24 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/01 14:27:13 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (NULL);
	while (i < (size * nmemb))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

// int	main(int argc, char **argv)
// {
// 	char	*s;
// 	char	*s1;

// 	if (argc < 2)
// 		return (atoi(argv[0]));
// 	s = ft_calloc(sizeof(char), strlen(argv[1]) + 1);
// 	// s = ft_calloc(0, 0);
// 	s1 = calloc(sizeof(char), strlen(argv[1]) + 1);
// 	// s1 = calloc(0, 0);
// 	printf("\n\nmy: %s\nog: %s", s, s1);
// 	printf("\n\nmy: %p\nog: %p", s, s1);
// 	memcpy(s, argv[1], strlen(argv[1]) + 1);
// 	memcpy(s1, argv[1], strlen(argv[1]) + 1);
// 	printf("\n\nmy: %s\nog: %s", s, s1);
// 	printf("\ntotal: %i\n", memcmp(s, s1, strlen(argv[1]) + 1));
// 	free(s);
// 	free(s1);
// }
