/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:48:46 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/27 15:05:55 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->mlx_win);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	get_next_line(-1);
	free_two_maps(env, env->map, env->color_map);
	exit(EXIT_SUCCESS);
}
