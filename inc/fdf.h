/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:27:05 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/28 18:04:19 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

# define F_MIN -3000000000000.0
# define F_MAX 3000000000000.0

# define COLOR_ABOVE 0xFF0000
# define COLOR_FLOOR 0x545454
# define COLOR_UNDER 0xFFFFFF

# define ESC 65307
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define Z_KEY 122
# define X_KEY 120
# define B_KEY 98
# define M_KEY 109
# define PLUS_KEY 61
# define MINUS_KEY 45

# define TRANSL_STEP 10
# define ALTI_STEP 1
# define ZOOM_STEP 2

typedef struct s_env {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		**map;
	ssize_t	**color_map;
	int		nb_line;
	int		nb_col;
	float	alpha;
	float	translx;
	float	transly;
	float	rota;
	float	alti_step;
	int		x_relative;
	int		y_relative;
	int		zoom;
	int		scale;
	bool	is_hold;
	bool	projection;
}	t_env;

typedef struct s_pts {
	float	x;
	float	y;
	int		j_coor;
	int		i_coor;
}	t_pts;

typedef struct s_delta {
	float	dx;
	float	dy;
}	t_delta;

typedef struct s_inc {
	float	x_inc;
	float	y_inc;
}	t_inc;

typedef struct s_color {
	ssize_t	r;
	ssize_t	g;
	ssize_t	b;
	ssize_t	a;
}	t_color;

// colors.c
ssize_t	pt_gradient(t_env *env, t_pts start, t_pts cur, t_pts next);

// env.c
void	init_env(t_env *env, int **map, ssize_t **color_map);

// hooks
void	register_hooks(t_env *env);
int		close_window(t_env *env);
int		on_mouse_moov(int x, int y, t_env *env);

// parsing
int		**parse_map(char *file_path, int nb_line, int nb_col);
ssize_t	**parse_color_map(char *file_path, int nb_col, int nb_line);

// draw.c
void	draw_point(t_env *env);

// maths
float	angle_formula_x(t_env *env, int x, int y);
float	angle_formula_y(t_env *env, int x, int y, int z);
float	transl_calcul(t_env *env, char axe);

//minilib.c
void	my_pixel_put(t_env *env, int x, int y, ssize_t color);
void	recreate_image(t_env *env);

// free.c
void	free_parsing(char **parsed);
void	ft_free_map(t_env *env);
void	free_two_maps(t_env *env, int **map, ssize_t **color_map);
void	exit_all(t_env *env, int exit_type);

// utils.c
int		ft_len_splited(char **splited);
bool	check_map(t_env *env, char *file_path);

#endif // !FDF_H
