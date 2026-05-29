/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:00:25 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/27 19:22:09 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*destt;
	unsigned char	*srcc;

	destt = (unsigned char *)dest;
	srcc = (unsigned char *)src;
	i = 0;
	while (n > i && (destt != 0 || srcc != 0))
	{
		destt[i] = srcc[i];
		i++;
	}
	return (dest);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 1)
// 		return(atoi(argv[1]));
// 	char *s = malloc(sizeof(char) * (strlen(argv[1]) + 1));
// 	char *d = malloc(sizeof(char) * (strlen(argv[1]) + 1));
// 	// char *test = 0;
// 	memcpy(s, argv[1], strlen(argv[1]) + 1);
// 	char *my = ft_memcpy(d, s, strlen(s) + 1);
// 	printf("\nmy dest: %s\nmy src: %s\n", d, s);
// 	char *og = memcpy(d, s, strlen(s) + 1);
// 	printf("og dest: %s\nmy src: %s\n", d, s);
// 	printf("\nmy: %s\nog: %s\n", my, og);
// 	if(!my || !*my)
// 	{
// 		free(d);
// 		free(s);
// 		return(0);
// 	}
// 	printf("compare: %i\n\n",memcmp(my, og, strlen(og) + 1));
// 	free(d);
// 	free(s);
// }
