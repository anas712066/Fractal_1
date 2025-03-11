/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:52:55 by mumajeed          #+#    #+#             */
/*   Updated: 2025/03/07 18:00:24 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\
./fractol julia <value_1> <value_2>\"\n"

# define WIDTH 800
# define HEIGHT 800

# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF

# define MAGENTA_BURST	0xFF00FF
# define LIME_SHOCK	0xCCFF00
# define NEON_ORANGE	0xFF6600
# define PSYCHEDELIC_PURPLE	0x660066
# define AQUA_DREAM	0x33CCCC
# define HOT_PINK	0xFF66B2
# define ELECTRIC_BLUE	0x0066FF
# define LAVA_RED	0xFF3300

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		allow_julia_change;
	int		color_shift;
}	t_fractal;

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}	t_color;

int			ft_strncmp(char *s1, char *s2, int n);
void		putstr_fd(char *s, int fd);

void		fractal_init(t_fractal *fractal);

typedef struct s_range
{
	double	min;
	double	max;
}	t_range;

typedef struct s_limits
{
	t_range	new_limits;
	t_range	old_limits;
	t_range	old_limits_windows;
}	t_limits;

typedef struct s_pixel_data
{
	t_complex	z;
	t_complex	c;
	t_limits	limits;
}	t_pixel_data;

typedef struct s_color_range
{
	t_range	color_range;
	t_range	iteration_range;
}	t_color_range;

double		map(double n, t_range new_range, t_range old_range);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

void		fractal_render(t_fractal *fractal);
int			get_color(int iteration, int max_iterations, t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
double		atodbl(char *s);
int			julia_track(int x, int y, t_fractal *fractal);
int			ft_isdigit(char c);
void		handle_pixel(int x, int y, t_fractal *fractal);
#endif
