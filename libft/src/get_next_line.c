/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:23:22 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/30 12:55:43 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	free(s1);
	return (dest);
}

static char	*stash_filling(int fd, char *stash, char *buffer)
{
	ssize_t	nbytes;

	nbytes = 1;
	if (!stash)
		stash = ft_strdup("");
	while (nbytes > 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[nbytes] = 0;
		stash = ft_strjoin_gnl(stash, buffer);
		if ((ft_strchr(buffer, '\n')))
			break ;
	}
	free (buffer);
	return (stash);
}

static char	*extract_new_stash(char	*stash)
{
	int		len;
	int		i;
	char	*new_stash;

	len = 0;
	i = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[len] != '\n' && stash[len])
		len++;
	if (stash[len] == '\n')
		len++;
	new_stash = malloc((ft_strlen(stash) - len + 1) * sizeof(char));
	if (!new_stash)
		return (NULL);
	while (stash[len + i])
	{
		new_stash[i] = stash[len + i];
		i++;
	}
	free (stash);
	new_stash[i] = 0;
	return (new_stash);
}

static char	*extract_line(char *stash, char *line)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[len] != '\n' && stash[len])
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	line = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		free(buffer);
		stash = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	stash = stash_filling(fd, stash, buffer);
	if (*stash == 0)
	{
		free (stash);
		return (stash = 0);
	}
	line = extract_line(stash, line);
	stash = extract_new_stash(stash);
	return (line);
}
