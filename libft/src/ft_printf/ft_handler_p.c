/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:35:45 by macuesta          #+#    #+#             */
/*   Updated: 2024/11/15 13:27:01 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	get_malloc_size_handler_p(unsigned long int n, char *base)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n /= ft_strlen(base);
	}
	return (count);
}

char	*ft_ltoa_base_handler_p(unsigned long int n, char *base)
{
	char	*dest;
	int		len_malloc;

	len_malloc = get_malloc_size_handler_p(n, base) + 2;
	dest = (char *)ft_calloc(len_malloc + 1, sizeof(char));
	if (!dest)
		return (0);
	dest[0] = '0';
	dest[1] = 'x';
	dest[len_malloc] = '\0';
	while (n)
	{
		len_malloc--;
		dest[len_malloc] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	return (dest);
}

int	ft_handler_p(unsigned long int n)
{
	int		len;
	char	*dest;

	if (n == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	dest = ft_ltoa_base_handler_p(n, "0123456789abcdef");
	if (!dest)
		return (0);
	ft_putstr_fd(dest, 1);
	len = ft_strlen(dest);
	free(dest);
	return (len);
}
