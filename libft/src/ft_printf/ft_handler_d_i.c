/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:11:47 by macuesta          #+#    #+#             */
/*   Updated: 2024/11/15 11:38:31 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_handler_d_i(int n)
{
	int		len;
	char	*dest;

	dest = ft_itoa(n);
	if (!dest)
		return (0);
	len = ft_strlen(dest);
	ft_putstr_fd(dest, 1);
	free(dest);
	return (len);
}
