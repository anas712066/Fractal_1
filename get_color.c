/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:25:11 by mumajeed          #+#    #+#             */
/*   Updated: 2025/02/22 19:50:17 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int get_color(int iteration, int max_iteration, t_fractal *fractal)
{
    double  t;
    t_color	color;

    if (iteration >= max_iteration)
        return (BLACK);
    t = (double)iteration / (double)max_iteration;
    color.red = (int)(9 * (1 - t) * t * t * t * 255);
    color.green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    color.blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    // Apply color shift
    color.red = (color.red + fractal->color_shift) % 256;
    color.green = (color.green + fractal->color_shift) % 256;
    color.blue = (color.blue + fractal->color_shift) % 256;

    return ((color.red << 16) | (color.green << 8) | color.blue);
}