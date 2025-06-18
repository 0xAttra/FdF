/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:09:14 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/06 13:57:55 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}

size_t	count_words(char const *s, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		if (s && s[i] == c)
			i++;
		else
		{
			while (s && s[i] && s[i] != c)
				i++;
			count++;
		}
	}
	return (count);
}

void	free_all(char **res)
{
	int	j;

	j = 0;
	while (res[j])
		free(res[j++]);
	free(res);
}

char	*copy_word(char const *s, char c)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = ft_calloc(ft_len(s, c) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (s && s[i] && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**res;

	res = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	j = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			res[j] = copy_word(s, c);
			if (!res[j])
			{
				free_all(res);
				return (NULL);
			}
			s += ft_len(s, c);
			j++;
		}
	}
	res[j] = 0;
	return (res);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str;
	char	charset;
	char	**tab;
	size_t	i;
	
	i = 0;
	str = "bonjwecfur";
	charset = 'c';
	tab = ft_split(str, charset);
	while (i < count_words(str, charset))
	{
		printf("[%zu]-> %s\n", i, tab[i]);
		i++;
	}
}*/
