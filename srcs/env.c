/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:50:56 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/30 15:33:03 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	init_scale(int nb_line, int nb_col)
{
	int	biggest_value;
	int	scale;

	scale = 10;
	if (nb_line > nb_col)
		biggest_value = nb_line * 20;
	else
		biggest_value = nb_col * 20;
	biggest_value = abs(biggest_value);
	while (biggest_value > WINDOW_HEIGHT || biggest_value > WINDOW_WIDTH)
	{
		if (scale > 1)
			scale /= 2;
		biggest_value /= 2;
	}
	return (abs(scale));
}

void	init_mlx(t_env *env)
{
	env->mlx = mlx_init();
	if (!env->mlx)
		exit_all(env, EXIT_FAILURE);
	env->mlx_win = mlx_new_window(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	if (!env->mlx_win)
		exit_all(env, EXIT_FAILURE);
	env->img = mlx_new_image(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!env->img)
		exit_all(env, EXIT_FAILURE);
	env->addr = mlx_get_data_addr(env->img, &env->bits_per_pixel, \
								&env->line_length, &env->endian);
	if (!env->addr)
		exit_all(env, EXIT_FAILURE);
}

void	init_env(t_env *env, int **map, ssize_t **color_map)
{
	env->map = map;
	env->color_map = color_map;
	init_mlx(env);
	env->alpha = M_PI / 6;
	env->rota = 0;
	env->scale = init_scale(env->nb_line, env->nb_col);
	env->zoom = env->scale * ZOOM_STEP;
	env->x_relative = WINDOW_WIDTH / 2;
	env->y_relative = WINDOW_HEIGHT / 2;
	env->alti_step = 0;
	env->projection = false;
	env->is_hold = false;
	env->translx = transl_calcul(env, 'x');
	env->transly = transl_calcul(env, 'y');
}
