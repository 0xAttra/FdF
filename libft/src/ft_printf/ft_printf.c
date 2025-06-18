/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:15:54 by macuesta          #+#    #+#             */
/*   Updated: 2024/11/15 13:18:47 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fm, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!fm)
		return (-1);
	va_start(args, fm);
	while (fm && fm[i])
	{
		if (fm[i] && fm[i + 1] && fm[i] == '%' && is_a_formatter(fm[i + 1]))
		{
			len += ft_dispatcher(fm[i + 1], &args);
			i += 2;
		}
		else
			len += ft_print_until_format(fm + i, &i);
	}
	va_end(args);
	return (len);
}
