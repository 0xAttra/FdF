/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:19:14 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/27 15:21:28 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_color_map(ssize_t **color_map, int nb_line, int fd)
{
	int	j;

	j = 0;
	while (j < nb_line && color_map[j])
		free(color_map[j++]);
	free(color_map);
	get_next_line(-1);
	close(fd);
}

static ssize_t	*init_line_map(int nb_col, char **parsed)
{
	int		i;
	ssize_t	*line_map;
	char	**split;

	i = 0;
	line_map = (ssize_t *)ft_calloc(nb_col, sizeof(ssize_t));
	if (!line_map)
		return (NULL);
	while (i < nb_col)
	{
		split = ft_split(parsed[i], ',');
		if (!split)
			return (NULL);
		if (ft_len_splited(split) == 2)
			line_map[i] = ft_atossize_t_base(split[1]);
		else
			line_map[i] = -1;
		free_parsing(split);
		i++;
	}
	return (line_map);
}

static ssize_t	*parse_line_color(char *line, int nb_col)
{
	ssize_t	*line_map;
	char	**parsed;

	parsed = ft_split(line, ' ');
	if (!parsed)
		return (NULL);
	free(line);
	line_map = init_line_map(nb_col, parsed);
	free_parsing(parsed);
	if (!line_map)
		return (NULL);
	return (line_map);
}

ssize_t	**parse_color_map(char *file_path, int nb_line, int nb_col)
{
	int		fd;
	int		j;
	char	*line;
	ssize_t	**color_map;

	fd = open(file_path, O_RDONLY);
	color_map = (ssize_t **)ft_calloc(nb_line, sizeof(ssize_t *));
	if (!color_map || fd == -1)
		return (NULL);
	j = -1;
	line = get_next_line(fd);
	while (line && ++j < nb_line)
	{
		color_map[j] = parse_line_color(line, nb_col);
		if (!color_map[j])
		{
			free_color_map(color_map, nb_line, fd);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	close (fd);
	get_next_line(-1);
	return (color_map);
}
