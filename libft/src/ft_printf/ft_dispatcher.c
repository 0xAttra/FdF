/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:32:50 by macuesta          #+#    #+#             */
/*   Updated: 2024/11/15 13:41:36 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_dispatcher(char c, va_list *args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_handler_c(va_arg(*args, int));
	else if (c == 's')
		len = ft_handler_s(va_arg(*args, char *));
	else if (c == 'p')
		len = ft_handler_p(va_arg(*args, unsigned long int));
	else if (c == 'd' || c == 'i')
		len = ft_handler_d_i(va_arg(*args, int));
	else if (c == 'u')
		len = ft_handler_u(va_arg(*args, unsigned int));
	else if (c == 'x')
		len = ft_handler_x(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len = ft_handler_x(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		len = ft_handler_c('%');
	return (len);
}
