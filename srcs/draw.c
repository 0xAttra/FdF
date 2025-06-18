/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:32:47 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/30 11:16:02 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	dda_algo(t_env *env, t_pts current, t_pts next)
{
	int		i;
	t_delta	delta;
	t_inc	inc;
	float	steps;

	delta.dx = next.x - current.x;
	delta.dy = next.y - current.y;
	if (fabsf(delta.dx) > fabsf(delta.dy))
		steps = fabsf(delta.dx);
	else
		steps = fabsf(delta.dy);
	inc.x_inc = delta.dx / steps;
	inc.y_inc = delta.dy / steps;
	i = 0;
	while (i < steps)
	{
		my_pixel_put(env, current.x + env->translx, current.y + env->transly, \
				0xFFFFFF);
		current.x += inc.x_inc;
		current.y += inc.y_inc;
		i++;
	}
}

static void	init_line_y(t_env *env, int i, int j, int nb_line)
{
	float	x;
	float	y;
	float	x_n;
	float	y_n;

	if (j + 1 < nb_line)
	{
		x = angle_formula_x(env, i, j) * env->zoom;
		y = angle_formula_y(env, i, j, env->map[j][i]) * env->zoom;
		x_n = angle_formula_x(env, i, j + 1) * env->zoom;
		y_n = angle_formula_y(env, i, j + 1, env->map[j + 1][i]) * env->zoom;
		if (env->map[j][i] == 0 && env->map[j + 1][i] > 0)
			dda_algo(env, (t_pts){x, y, j, i}, (t_pts){x_n, y_n, j + 1, i});
		else
			dda_algo(env, (t_pts){x_n, y_n, j + 1, i}, (t_pts){x, y, j, i});
	}
}

static void	init_line_x(t_env *env, int i, int j, int nb_col)
{
	float	x;
	float	y;
	float	x_n;
	float	y_n;

	if (i + 1 < nb_col)
	{
		x = angle_formula_x(env, i, j) * env->zoom;
		y = angle_formula_y(env, i, j, env->map[j][i]) * env->zoom;
		x_n = angle_formula_x(env, i + 1, j) * env->zoom;
		y_n = angle_formula_y(env, i + 1, j, env->map[j][i + 1]) * env->zoom;
		if (env->map[j][i] == 0 && env->map[j][i + 1] > 0)
			dda_algo(env, (t_pts){x, y, j, i}, (t_pts){x_n, y_n, j, i + 1});
		else
			dda_algo(env, (t_pts){x_n, y_n, j, i + 1}, (t_pts){x, y, j, i});
	}
}

void	draw_point(t_env *env)
{
	int	i;
	int	j;

	j = 0;
	while (j < env->nb_line)
	{
		i = 0;
		while (i < env->nb_col)
		{
			init_line_x(env, i, j, env->nb_col);
			init_line_y(env, i, j, env->nb_line);
			i++;
		}
		j++;
	}
}
