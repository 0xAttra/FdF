/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:17:52 by macuesta          #+#    #+#             */
/*   Updated: 2024/08/05 19:14:23 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst_cpy;
	const unsigned char	*src_cpy;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (const unsigned char *)src;
	if (dst == src)
		return (dst);
	if (dst_cpy > src_cpy)
	{
		while (len > 0)
		{
			len--;
			dst_cpy[len] = src_cpy[len];
		}
		return (dst);
	}
	i = 0;
	while (i < len)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	return (dst);
}
