/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:49:44 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/27 15:20:03 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_map(int **map, int nb_line, int fd)
{
	int	j;

	j = 0;
	while (j < nb_line && map[j])
		free(map[j++]);
	free(map);
	get_next_line(-1);
	close(fd);
}

static int	*init_line_map(int nb_col, char **parsed)
{
	int		i;
	int		*line_map;
	char	**split;

	i = 0;
	line_map = (int *)ft_calloc(nb_col, sizeof(int));
	if (!line_map)
		return (NULL);
	while (i < nb_col)
	{
		split = ft_split(parsed[i], ',');
		if (!split)
			return (NULL);
		if (split[0][0] != '\n')
			line_map[i] = ft_atoi(split[0]);
		free_parsing(split);
		i++;
	}
	return (line_map);
}

static int	*parse_line(char *line, int nb_col)
{
	int		*line_map;
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

int	**parse_map(char *file_path, int nb_line, int nb_col)
{
	int		fd;
	char	*line;
	int		**map;
	int		j;

	fd = open(file_path, O_RDONLY);
	map = (int **)ft_calloc(nb_line, sizeof(int *));
	if (!map || fd == -1)
		return (NULL);
	j = -1;
	line = get_next_line(fd);
	while (line && ++j < nb_line)
	{
		map[j] = parse_line(line, nb_col);
		if (!map[j])
		{
			free_map(map, nb_line, fd);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	close (fd);
	get_next_line(-1);
	return (map);
}
