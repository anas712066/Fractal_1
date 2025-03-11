/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:56:21 by mumajeed          #+#    #+#             */
/*   Updated: 2025/03/11 21:56:22 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	update_julia(int button,
		double mouse_x, double mouse_y, t_fractal *fractal)
{
	if (button == Button1)
	{
		fractal->julia_x = mouse_x;
		fractal->julia_y = mouse_y;
		fractal_render(fractal);
	}
}

static void	update_zoom(int button,
		double mouse_x, double mouse_y, t_fractal *fractal)
{
	if (button == Button4)
	{
		fractal->shift_x -= (mouse_x - fractal->shift_x) * 0.05;
		fractal->shift_y -= (mouse_y - fractal->shift_y) * 0.05;
		fractal->zoom *= 1.1;
	}
	else if (button == Button5)
	{
		fractal->shift_x += (mouse_x - fractal->shift_x) * 0.05;
		fractal->shift_y += (mouse_y - fractal->shift_y) * 0.05;
		fractal->zoom /= 1.1;
	}
	fractal_render(fractal);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = (x / (double)WIDTH) * 4 - 2;
	mouse_y = (y / (double)HEIGHT) * 4 - 2;
	if (!ft_strncmp(fractal->name, "julia", 5))
		update_julia(button, mouse_x, mouse_y, fractal);
	update_zoom(button, mouse_x, mouse_y, fractal);
	return (0);
}
