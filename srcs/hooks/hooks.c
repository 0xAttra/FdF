/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:36:53 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/27 09:18:27 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_hook(int keycode, t_env *env)
{
	if (keycode == ESC)
		close_window(env);
	return (0);
}

void	register_hooks(t_env *env)
{
	mlx_key_hook(env->mlx_win, key_hook, env);
	mlx_hook(env->mlx_win, 17, 0, close_window, env);
}
