/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atossize_t_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:26:24 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/17 16:26:24 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_base(char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	get_index_base(char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}

ssize_t	ft_atossize_t_base(char *s)
{
	int		i;
	ssize_t	res;
	char	*base;

	if (!s)
		return (-1);
	i = 0;
	res = 0;
	base = "0123456789ABCDEF";
	if (s && s[0] == '0' && s[1] == 'x')
		i += 2;
	while (s && s[i] && is_in_base(base, s[i]))
	{
		res *= ft_strlen(base);
		res += get_index_base(base, s[i]);
		i++;
	}
	return (res);
}
