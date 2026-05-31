/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:48:41 by mimeyer           #+#    #+#             */
/*   Updated: 2026/05/30 13:48:44 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	invert(long nn, int i, char *str);
static int	check_size(long nn);

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nn;
	int		temp;

	nn = (long)n;
	i = 0;
	temp = 0;
	if (nn < 0)
	{
		temp = 1;
		nn *= -1;
	}
	i = check_size(nn);
	str = malloc(sizeof(char) * (i + 1 + temp));
	if (str == 0)
		return (NULL);
	if (temp == 1)
		str[0] = '-';
	invert(nn, i - 1, str + temp);
	str[i + temp] = '\0';
	return (str);
}

static void	invert(long nn, int i, char *str)
{
	if ((nn / 10) != 0)
		invert(nn / 10, i - 1, str);
	str[i] = (nn % 10) + '0';
}

static int	check_size(long nn)
{
	int	i;

	i = 0;
	if (nn == 0)
		i++;
	while (nn != 0)
	{
		nn /= 10;
		i++;
	}
	return (i);
}

// int	main(int argc, char **argv)
// {
// 	char	*str;

// 	if (argc < 1)
// 		return (atoi(argv[0]));
// 	str = ft_itoa(atoi(argv[1]));
// 	printf("\n%s\n\n", str);
// 	free(str);
// }
