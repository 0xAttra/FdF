/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:21:13 by macuesta          #+#    #+#             */
/*   Updated: 2024/08/02 19:24:41 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = (char *)malloc(count * size);
	if (!dst)
		return (NULL);
	while (i < count * size)
		dst[i++] = '\0';
	return (dst);
}
