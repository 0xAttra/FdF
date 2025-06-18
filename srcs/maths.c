/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:38:11 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/28 18:10:00 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_x_max_point(t_env *env, float *highest, float *lowest)
{
	int		i;
	int		j;
	float	actual;

	j = 0;
	while (j < env->nb_line)
	{
		i = 0;
		while (i < env->nb_col)
		{
			actual = angle_formula_x(env, i, j) * env->zoom;
			if (actual > *highest)
				*highest = actual;
			if (actual < *lowest)
				*lowest = actual;
			i++;
		}
		j++;
	}
}

static void	get_y_max_point(t_env *env, float *highest, float *lowest)
{
	int		i;
	int		j;
	float	actual;

	j = 0;
	while (j < env->nb_line)
	{
		i = 0;
		while (i < env->nb_col)
		{
			actual = angle_formula_y(env, i, j, env->map[j][i]) * env->zoom;
			if (actual > *highest)
				*highest = actual;
			if (actual < *lowest)
				*lowest = actual;
			i++;
		}
		j++;
	}
}

float	transl_calcul(t_env *env, char axe)
{
	float	highest;
	float	lowest;

	highest = F_MIN;
	lowest = F_MAX;
	if (axe == 'x')
	{
		get_x_max_point(env, &highest, &lowest);
		return ((WINDOW_WIDTH - (highest - lowest)) / 2 - lowest);
	}
	if (axe == 'y')
	{
		get_y_max_point(env, &highest, &lowest);
		return ((WINDOW_HEIGHT - (highest - lowest)) / 2 - lowest);
	}
	return (0);
}

float	angle_formula_x(t_env *env, int x, int y)
{
	float	res;
	float	rota_x;
	float	rota_y;
	float	center_x;
	float	center_y;

	center_x = x - env->nb_col / 2.0;
	center_y = y - env->nb_line / 2.0;
	rota_x = center_x * cosf(env->rota) - center_y * sinf(env->rota);
	rota_y = center_x * sinf(env->rota) + center_y * cosf(env->rota);
	if (env->projection == false)
		res = (rota_x - rota_y) * cosf(env->alpha);
	else
		res = rota_x - rota_y;
	return (res);
}

float	angle_formula_y(t_env *env, int x, int y, int z)
{
	float	res;
	float	rota_x;
	float	rota_y;
	float	center_x;
	float	center_y;

	center_x = x - env->nb_col / 2.0;
	center_y = y - env->nb_line / 2.0;
	rota_x = center_x * cosf(env->rota) - center_y * sinf(env->rota);
	rota_y = center_x * sinf(env->rota) + center_y * cosf(env->rota);
	if (env->projection == false && z < 0)
		res = (rota_x + rota_y) * sinf(env->alpha) - z - env->alti_step;
	else if (env->projection == false && z > 0)
		res = (rota_x + rota_y) * sinf(env->alpha) - z + env->alti_step;
	else if (env->projection == false && z == 0)
		res = (rota_x + rota_y) * sinf(env->alpha) - z;
	else
		res = (rota_x + rota_y);
	return (res);
}
