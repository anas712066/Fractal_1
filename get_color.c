/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:25:11 by mumajeed          #+#    #+#             */
/*   Updated: 2025/03/08 20:09:16 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iteration, int max_iteration, t_fractal *fractal)
{
	double	t;
	t_color	color;

	if (iteration >= max_iteration)
		return (0x101010);
	t = (double)iteration / (double)max_iteration;
	color.red = (int)(9 * (1 - t) * t * t * t * 255) + 50;
	color.green = (int)(15 * (1 - t) * (1 - t) * t * t * 255) + 50;
	color.blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255) + 50;
	if (color.red < 50)
		color.red = 50;
	if (color.green < 50)
		color.green = 50;
	if (color.blue < 50)
		color.blue = 50;
	color.red = (color.red + fractal->color_shift) % 256;
	color.green = (color.green + fractal->color_shift) % 256;
	color.blue = (color.blue + fractal->color_shift) % 256;
	return ((color.red << 16) | (color.green << 8) | color.blue);
}
