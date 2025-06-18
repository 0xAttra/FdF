/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:22:49 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/28 09:22:11 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_len_splited(char **splited)
{
	int	len;

	len = 0;
	while (splited && splited[len])
		len++;
	if (splited[len - 1][0] == '\n')
		len--;
	return (len);
}

static void	is_hexa(char *s, bool *bool_correct)
{
	int		i;
	char	*hexa;

	i = 0;
	hexa = "ABCDEF0123456789xabcdef";
	if (!s[0] || s[0] == '\n')
		*bool_correct = false;
	while (s && s[i])
	{
		if (s[i] != '\n' && !ft_strchr(hexa, s[i]))
			*bool_correct = false;
		i++;
	}
}

static bool	is_correct(char **splited)
{
	int		i;
	int		j;
	char	**s2;
	bool	bool_correct;

	i = 0;
	bool_correct = true;
	while (splited && splited[i])
	{
		s2 = ft_split(splited[i], ',');
		if (!s2)
			return (false);
		j = -1;
		while (s2[0][++j])
		{
			if (s2[0][j] != '\n' && !ft_isdigit(s2[0][j])
				&& s2[0][j] != '-' && s2[0][j] != '+')
				bool_correct = false;
		}
		if (ft_len_splited(s2) == 2)
			is_hexa(s2[1], &bool_correct);
		free_parsing(s2);
		i++;
	}
	return (bool_correct);
}

static bool	file_format(char *s)
{
	size_t	i;

	i = ft_strlen(s);
	if (s[i - 1] == 'f'
		&& s[i - 2] == 'd'
		&& s[i - 3] == 'f'
		&& s[i - 4] == '.')
		return (true);
	return (false);
}

bool	check_map(t_env *env, char *file_path)
{
	int		fd;
	char	*line;
	char	**splited;
	bool	error;

	error = false;
	fd = open(file_path, O_RDONLY);
	if (fd == -1 || !file_format(file_path))
		return (error = true);
	line = get_next_line(fd);
	while (line)
	{
		splited = ft_split(line, ' ');
		if (ft_len_splited(splited) != env->nb_col || !is_correct(splited))
			error = true;
		if (splited)
			free_parsing(splited);
		free(line);
		line = get_next_line(fd);
	}
	get_next_line(-1);
	close(fd);
	return (error);
}
