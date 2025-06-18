/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:59:36 by macuesta          #+#    #+#             */
/*   Updated: 2024/11/29 11:31:51 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	uli_get_power(unsigned long int n, char *base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= ft_strlen(base);
	}
	return (count);
}

char	*ft_ulitoa_base(unsigned long int n, char *base)
{
	char	*res;
	int		len_malloc;

	len_malloc = uli_get_power(n, base);
	res = (char *)ft_calloc(len_malloc + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (len_malloc)
	{
		len_malloc--;
		res[len_malloc] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
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
