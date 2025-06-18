/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:43:25 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/31 09:20:36 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_width_and_height(char *file_path, int *nb_line, int *nb_col)
{
	int		fd;
	char	*line;
	char	**splited;

	*nb_line = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	splited = ft_split(line, ' ');
	if (!splited)
	{
		close(fd);
		return ;
	}
	*nb_col = ft_len_splited(splited);
	free_parsing(splited);
	while (line)
	{
		free(line);
		*nb_line += 1;
		line = get_next_line(fd);
	}
	get_next_line(-1);
	close(fd);
}

int	main(int ac, char **av, char **env)
{
	t_env	t_env;
	int		**map;
	ssize_t	**color_map;

	if (!env || !*env)
		return (ft_putstr_fd("An error as occured.\n", 2), 1);
	if (ac == 2)
	{
		get_width_and_height(av[1], &t_env.nb_line, &t_env.nb_col);
		if (t_env.nb_line == 0 || t_env.nb_col == 0 || check_map(&t_env, av[1]))
			return (ft_putstr_fd("Map invalid or an error as occured.\n", 2), 1);
		map = parse_map(av[1], t_env.nb_line, t_env.nb_col);
		color_map = parse_color_map(av[1], t_env.nb_line, t_env.nb_col);
		if (!map || !color_map)
		{
			free_two_maps(&t_env, map, color_map);
			return (ft_putstr_fd("An error as occured. Try again.\n", 2), 1);
		}
		init_env(&t_env, map, color_map);
		draw_point(&t_env);
		mlx_put_image_to_window(t_env.mlx, t_env.mlx_win, t_env.img, 0, 0);
		register_hooks(&t_env);
		mlx_loop(t_env.mlx);
	}
	return (ft_putstr_fd("Need two arguments. Usage: ./fdf [map]\n", 2), 1);
}
