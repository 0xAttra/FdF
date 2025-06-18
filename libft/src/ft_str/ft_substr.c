/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:30:17 by macuesta          #+#    #+#             */
/*   Updated: 2024/08/02 19:21:28 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	int				size;
	char			*dest;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= (unsigned int)size)
		return (ft_strdup(""));
	if ((size - start) < len)
		len = size - start;
	dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
/*
#include "stdio.h"
int	main(void)
{
	char *test = "tripouille";
	printf("result -> %s\n", ft_substr(test, 100, 1));
}*/
