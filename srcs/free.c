/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:11:31 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/30 15:30:50 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_parsing(char **parsed)
{
	int	i;

	i = 0;
	while (parsed && parsed[i])
		free(parsed[i++]);
	free(parsed);
}

void	free_two_maps(t_env *env, int **map, ssize_t **color_map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (i < env->nb_line && map[i])
			free(map[i++]);
		free(map);
	}
	i = 0;
	if (color_map)
	{
		while (i < env->nb_line && color_map[i])
			free(color_map[i++]);
		free(color_map);
	}
}

void	exit_all(t_env *env, int exit_type)
{
	free_two_maps(env, env->map, env->color_map);
	if (!env->mlx)
		exit(exit_type);
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	if (env->mlx_win)
		mlx_destroy_window(env->mlx, env->mlx_win);
	mlx_destroy_display(env->mlx);
	if (env->mlx)
		free(env->mlx);
	exit(exit_type);
}
