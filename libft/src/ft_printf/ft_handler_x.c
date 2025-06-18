/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:48:55 by macuesta          #+#    #+#             */
/*   Updated: 2024/11/15 13:38:28 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_handler_x(unsigned int n, char *base)
{
	char	*dest;
	int		len;

	dest = ft_uitoa_base(n, base);
	if (!dest)
		return (0);
	len = ft_strlen(dest);
	ft_putstr_fd(dest, 1);
	free(dest);
	return (len);
}
