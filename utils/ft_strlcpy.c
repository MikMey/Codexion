/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:12:52 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/15 17:39:45 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	if (dest == 0 || src == 0)
		return (ft_strlen(src));
	if (*src == '\0')
	{
		*dest = 0;
		return (ft_strlen(src));
	}
	if (n <= 0)
		return (ft_strlen(src));
	if (n > ft_strlen(src))
		n = ft_strlen(src) + 1;
	dest = ft_memcpy(dest, src, n);
	dest[n - 1] = '\0';
	return (ft_strlen(src));
}

// int main(int argc, char **argv)
// {
// 	if (argc < 1)
// 		return(atoi(argv[0]));

// 	char *d = malloc(sizeof(char *) * (11));
// 	char *dest = malloc(sizeof(char *) * (11));
// 	for(int i = 0; i < 10; i++)
// 	{
// 		d[i] = '1';
// 		dest[i] = '1';
// 	}
// 	d[10] = 0;
// 	dest[10] = 0;
// 	ft_strlcpy(d, argv[1], -1);
// 	strlcpy(dest, argv[1], -1);

// 	printf("\nmy: %s\nog: %s\n", d, dest);

// 	// if(!d || !(*d))
// 	// {
// 	// 	free(d);
// 	// 	free(dest);
// 	// 	return(0);
// 	// }
// 	printf("\ntotal: %i\n\n", memcmp(d, dest, strlen(dest) + 1));
// 	free(d);
// 	free(dest);
// }