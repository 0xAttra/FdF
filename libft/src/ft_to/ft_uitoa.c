/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:58:08 by macuesta          #+#    #+#             */
/*   Updated: 2024/11/15 13:28:52 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	u_get_power(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_uitoa(unsigned int n)
{
	char	*res;
	int		len_malloc;
	int		i;

	len_malloc = u_get_power(n);
	res = (char *)ft_calloc(len_malloc + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (len_malloc > i)
	{
		len_malloc--;
		res[len_malloc] = n % 10 + '0';
		n /= 10;
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
