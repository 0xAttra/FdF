/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 08:21:30 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/30 15:33:18 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_env *env, int x, int y, ssize_t color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = env->addr + (y * env->line_length \
			+ x * (env->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	recreate_image(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!env->img)
		exit_all(env, EXIT_FAILURE);
	env->addr = mlx_get_data_addr(env->img, &env->bits_per_pixel, \
								&env->line_length, &env->endian);
	if (!env->addr)
		exit_all(env, EXIT_FAILURE);
	draw_point(env);
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img, 0, 0);
}
