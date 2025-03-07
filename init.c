/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:53:40 by mumajeed          #+#    #+#             */
/*   Updated: 2025/03/01 22:06:51 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}*/
/*
static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;/2 ^ 2 my hypotenus
fractal->iterations_definition = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->allow_julia_change = 0;

	if (!ft_strncmp(fractal->name, "julia", 5))
	{
    		if (fractal->julia_x == 0.0 && fractal->julia_y == 0.0)
    		{
        		fractal->julia_x = -0.7; // Valor por defecto
        		fractal->julia_y = 0.27015;
    		}
	}

}*/

/*static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window,
			KeyPress,
			KeyPressMask,
			key_handler,
			fractal);
	mlx_mouse_hook(fractal->mlx_window,
		mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_window,
		DestroyNotify,
		StructureNotifyMask,
		close_handler,
		fractal);
	mlx_hook(fractal->mlx_window,
		MotionNotify,
		PointerMotionMask,
		julia_track,
		fractal);

}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH,
			HEIGHT,
			fractal->name);
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH,
			HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, 
			&fractal->img.bpp,
			&fractal->img.line_len,
			&fractal->img.endian);
	if (!fractal->img.pixels_ptr)
	{
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	events_init(fractal);
	data_init(fractal);
}*/

#include "fractol.h"

static void	malloc_error(void)
{
    perror("Problems with malloc");
    exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
    fractal->escape_value = 4;
    fractal->iterations_definition = 42;
    fractal->shift_x = 0.0;
    fractal->shift_y = 0.0;
    fractal->zoom = 1.0;
    fractal->allow_julia_change = 0;
    if (!ft_strncmp(fractal->name, "julia", 5) &&
        fractal->julia_x == 0.0 && fractal->julia_y == 0.0)
    {
        fractal->julia_x = -0.7;
        fractal->julia_y = 0.27015;
    }
}

static void	events_init(t_fractal *fractal)
{
    mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
    mlx_mouse_hook(fractal->mlx_window, mouse_handler, fractal);
    mlx_hook(fractal->mlx_window, DestroyNotify,
        StructureNotifyMask, close_handler, fractal);
    mlx_hook(fractal->mlx_window, MotionNotify,
        PointerMotionMask, julia_track, fractal);
}

void	fractal_init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if (!fractal->mlx_connection)
        malloc_error();
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
            WIDTH, HEIGHT, fractal->name);
    if (!fractal->mlx_window)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
    if (!fractal->img.img_ptr)
        malloc_error();
    fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
            &fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
    if (!fractal->img.pixels_ptr)
        malloc_error();
    events_init(fractal);
    data_init(fractal);
}
