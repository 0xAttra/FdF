/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:43:01 by macuesta          #+#    #+#             */
/*   Updated: 2024/11/15 11:44:31 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_handler_u(unsigned int n)
{
	int		len;
	char	*dest;

	dest = ft_uitoa(n);
	if (!dest)
		return (0);
	len = ft_strlen(dest);
	ft_putstr_fd(dest, 1);
	free(dest);
	return (len);
}
