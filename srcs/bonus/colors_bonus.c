/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:07:33 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/28 10:52:29 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	get_position(t_pts start, t_pts end, t_pts cur)
{
	double	diag_full;
	double	diag_first_part;

	diag_full = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
	diag_first_part = sqrt(pow(cur.x - start.x, 2) + pow(cur.y - start.y, 2));
	if (diag_full)
		return (diag_first_part / diag_full);
	return (1);
}

static t_color	split_color(ssize_t rgba)
{
	t_color	color;

	color = (t_color){0, 0, 0, 0};
	if (rgba > 0xFFFFFF)
		color.a = 8;
	color.r = (rgba >> (16 + color.a)) & 0xFF;
	color.g = (rgba >> (8 + color.a)) & 0xFF;
	color.b = (rgba >> color.a) & 0xFF;
	if (color.a)
		color.a = rgba & 0xFF;
	return (color);
}

static ssize_t	gradient_color(ssize_t start, ssize_t end, double pos)
{
	t_color	color;
	t_color	start_color;
	t_color	end_color;

	start_color = split_color(start);
	end_color = split_color(end);
	color.r = round(start_color.r * (1 - pos) + end_color.r * pos);
	color.g = round(start_color.g * (1 - pos) + end_color.g * pos);
	color.b = round(start_color.b * (1 - pos) + end_color.b * pos);
	color.a = round(start_color.a * (1 - pos) + end_color.a * pos);
	return (color.a << 24 | color.r << 16 | color.g << 8 | color.b);
}

ssize_t	pt_gradient(t_env *env, t_pts start, t_pts cur, t_pts next)
{
	double	pos;
	ssize_t	a;
	ssize_t	b;

	a = COLOR_FLOOR;
	b = COLOR_FLOOR;
	if (env->color_map[start.j_coor][start.i_coor] != -1)
		a = env->color_map[start.j_coor][start.i_coor];
	if (env->color_map[next.j_coor][next.i_coor] != -1)
		b = env->color_map[next.j_coor][next.i_coor];
	if (a == COLOR_FLOOR && env->map[start.j_coor][start.i_coor] > 0)
		a = COLOR_ABOVE;
	if (b == COLOR_FLOOR && env->map[next.j_coor][next.i_coor] > 0)
		b = COLOR_ABOVE;
	if (a == COLOR_FLOOR && env->map[start.j_coor][start.i_coor] < 0)
		a = COLOR_UNDER;
	if (b == COLOR_FLOOR && env->map[next.j_coor][next.i_coor] < 0)
		b = COLOR_UNDER;
	pos = get_position(start, next, cur);
	return (gradient_color(a, b, pos));
}
