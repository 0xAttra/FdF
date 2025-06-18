/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:23:12 by macuesta          #+#    #+#             */
/*   Updated: 2024/11/13 16:09:03 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len > dstsize)
		dst_len = dstsize;
	if (dst_len == dstsize)
		return (src_len + dstsize);
	if (src_len < dstsize - dst_len)
		ft_memcpy((dst + dst_len), src, (src_len + 1));
	else
	{
		ft_memcpy((dst + dst_len), src, (dstsize - dst_len - 1));
		dst[dstsize - 1] = '\0';
	}
	return (dst_len + src_len);
}
