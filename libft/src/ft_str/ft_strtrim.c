/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:51:30 by macuesta          #+#    #+#             */
/*   Updated: 2024/08/11 17:28:52 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	size_t		len;
	char		*dest;

	len = ft_strlen(s1) - 1;
	i = 0;
	j = 0;
	while (s1[i] && is_in_set(set, s1[i]))
		i++;
	if (i >= len + 1)
		return (ft_strdup(""));
	while (len && is_in_set(set, s1[len]))
		len--;
	dest = ft_calloc(len - i + 2, sizeof(char));
	if (!dest)
		return (NULL);
	while (i <= len)
		dest[j++] = s1[i++];
	dest[j] = '\0';
	return (dest);
}
/*
#include "stdio.h"
int	main(void)
{
	char const s1[] = "abba";
	char const set[] = "a";

	printf("%s\n", ft_strtrim(s1, set));
}*/
