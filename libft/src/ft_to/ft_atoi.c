/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:36:21 by macuesta          #+#    #+#             */
/*   Updated: 2024/08/02 18:48:23 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

/*
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("atoi: %d\n", atoi(av[1]));
		printf("ft_atoi: %d\n", ft_atoi(av[1]));
	}
}*/
