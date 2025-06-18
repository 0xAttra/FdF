/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:58:08 by macuesta          #+#    #+#             */
/*   Updated: 2024/08/11 19:42:03 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_power(int n)
{
	unsigned int	nbr;
	int				count;

	count = 0;
	if (n <= 0)
	{
		count++;
		nbr = -n;
	}
	else
		nbr = n;
	while (nbr > 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*res;
	int				len_malloc;
	int				i;

	len_malloc = get_power(n);
	res = ft_calloc(len_malloc + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		res[0] = '-';
		i = 1;
		nbr = -n;
	}
	else
		nbr = n;
	while (len_malloc > i)
	{
		len_malloc--;
		res[len_malloc] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (res);
}
/*
#include <stdio.h>
#include <string.h>
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("number: %d\n", ft_atoi(av[1]));
		printf("array result: %s\n", ft_itoa(ft_atoi(av[1])));
		printf("cmp result: %d\n", strcmp("156", ft_itoa(ft_atoi(av[1]))));
	}
}*/
