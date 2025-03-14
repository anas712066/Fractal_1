/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:25:12 by mumajeed          #+#    #+#             */
/*   Updated: 2025/03/11 22:25:13 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_vs_julia(t_pixel_data *data, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		data->z.x = data->c.x;
		data->z.y = data->c.y;
		data->c.x = fractal->julia_x;
		data->c.y = fractal->julia_y;
	}
	else
	{
		data->z.x = 0.0;
		data->z.y = 0.0;
	}
}

static void	init_pixel_data(t_pixel_data *data,
		int x, int y, t_fractal *fractal)
{
	data->limits.new_limits.min = -2.0;
	data->limits.new_limits.max = 2.0;
	data->limits.old_limits.min = 0;
	data->limits.old_limits.max = WIDTH;
	data->limits.old_limits_windows.min = 0;
	data->limits.old_limits_windows.max = HEIGHT;
	data->c.x = map(x, data->limits.new_limits, data->limits.old_limits)
		* fractal->zoom + fractal->shift_x;
	data->c.y = map(y, data->limits.new_limits, data->limits.old_limits_windows)
		* fractal->zoom + fractal->shift_y;
	mandel_vs_julia(data, fractal);
}

static int	calculate_iterations(t_pixel_data *data, t_fractal *fractal)
{
	int	i;

	i = 0;
	while (i < fractal->iterations_definition)
	{
		data->z = sum_complex(square_complex(data->z), data->c);
		if ((data->z.x * data->z.x) + (data->z.y * data->z.y)
			> fractal->escape_value)
			return (get_color(i, fractal->iterations_definition, fractal));
		i++;
	}
	return (BLACK);
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_pixel_data	data;
	int				color;

	init_pixel_data(&data, x, y, fractal);
	color = calculate_iterations(&data, fractal);
	my_pixel_put(x, y, &fractal->img, color);
}
