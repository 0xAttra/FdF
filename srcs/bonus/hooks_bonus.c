/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:36:53 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/31 16:37:29 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	smooth_operator(t_env *env, char touch)
{
	int	i;

	i = 25;
	while (i--)
	{
		if (touch == 'z')
			env->rota -= 0.01;
		else if (touch == 'x')
			env->rota += 0.01;
		else if (touch == 'w')
			env->transly -= 0.5;
		else if (touch == 's')
			env->transly += 0.5;
		else if (touch == 'a')
			env->translx -= 0.5;
		else if (touch == 'd')
			env->translx += 0.5;
		else if (touch == '+')
			env->alti_step -= 0.05;
		else if (touch == '-')
			env->alti_step += 0.05;
		recreate_image(env);
	}
}

static int	key_hook(int keycode, t_env *env)
{
	if (keycode == ESC)
		close_window(env);
	if (keycode == M_KEY)
		env->projection = !env->projection;
	recreate_image(env);
	if (keycode == W_KEY)
		smooth_operator(env, 'w');
	if (keycode == S_KEY)
		smooth_operator(env, 's');
	if (keycode == A_KEY)
		smooth_operator(env, 'a');
	if (keycode == D_KEY)
		smooth_operator(env, 'd');
	if (keycode == Z_KEY)
		smooth_operator(env, 'z');
	if (keycode == X_KEY)
		smooth_operator(env, 'x');
	if (keycode == PLUS_KEY)
		smooth_operator(env, '+');
	if (keycode == MINUS_KEY)
		smooth_operator(env, '-');
	return (0);
}

static int	hold_mouse_hook(int button, int x, int y, t_env *env)
{
	if (button == 1 && !env->is_hold)
	{
		env->is_hold = true;
		env->x_relative = x;
		env->y_relative = y;
	}
	if (button == SCROLL_UP && env->zoom < 100)
		env->zoom *= ZOOM_STEP;
	else if (button == SCROLL_DOWN && env->zoom > 1)
		env->zoom /= ZOOM_STEP;
	recreate_image(env);
	return (0);
}

static int	end_hold_mouse_hook(int button, int x, int y, t_env *env)
{
	(void) x;
	(void) y;
	if (button == 1 && env->is_hold)
		env->is_hold = false;
	return (0);
}

void	register_hooks(t_env *env)
{
	mlx_key_hook(env->mlx_win, key_hook, env);
	mlx_hook(env->mlx_win, 17, 0, close_window, env);
	mlx_hook(env->mlx_win, 04, 1L << 2, hold_mouse_hook, env);
	mlx_hook(env->mlx_win, 06, 1L << 6, on_mouse_moov, env);
	mlx_hook(env->mlx_win, 05, 1L << 3, end_hold_mouse_hook, env);
}
