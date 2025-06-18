/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_formatter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:26:35 by macuesta          #+#    #+#             */
/*   Updated: 2024/11/15 09:27:24 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	is_a_formatter(char c)
{
	int		i;
	char	*formatter;

	i = 0;
	formatter = "cspdiuxX%";
	while (formatter[i])
	{
		if (formatter[i] == c)
			return (1);
		i++;
	}
	return (0);
}
