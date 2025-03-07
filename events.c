/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:58:27 by mumajeed          #+#    #+#             */
/*   Updated: 2025/02/24 21:59:48 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection,
			fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection,
			fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}*/

int	close_handler(t_fractal *fractal)
{
    if (fractal->img.img_ptr)
        mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
    if (fractal->mlx_window)
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    if (fractal->mlx_connection)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
    }
    exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Escape)
        close_handler(fractal);
    else if (keysym == XK_Left)
        fractal->shift_x += (0.1 * fractal->zoom);
    else if (keysym == XK_Right)
        fractal->shift_x -= (0.1 * fractal->zoom);
    else if (keysym == XK_Up)
        fractal->shift_y += (0.1 * fractal->zoom);
    else if (keysym == XK_Down)
        fractal->shift_y -= (0.1 * fractal->zoom);
    else if (keysym == XK_j) // Activa/desactiva el cambio con el ratón
        fractal->allow_julia_change = !fractal->allow_julia_change;
    else if (keysym == XK_c) // Cambia el color
        fractal->color_shift = (fractal->color_shift + 64) % 256;
    else if (keysym == XK_minus) // Disminuye el color
        fractal->color_shift = (fractal->color_shift - 64 + 256) % 256;
    else if (keysym == XK_plus || keysym == XK_equal) // Aumenta el color
        fractal->color_shift = (fractal->color_shift + 64) % 256;
    
    fractal_render(fractal);
    return (0);
}


/*int	key_handler(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Escape)
        close_handler(fractal);
    else if (keysym == XK_Left)
        fractal->shift_x += (0.1 * fractal->zoom);
    else if (keysym == XK_Right)
        fractal->shift_x -= (0.1 * fractal->zoom);
    else if (keysym == XK_Up)
        fractal->shift_y -= (0.1 * fractal->zoom);
    else if (keysym == XK_Down)
        fractal->shift_y += (0.1 * fractal->zoom);
    else if (keysym == XK_j) // Activa/desactiva el cambio con el ratón
        fractal->allow_julia_change = !fractal->allow_julia_change;
    
    fractal_render(fractal);
    return (0);
}*/

/*int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (!fractal)
		return (1);

	(void)x;
	(void)y;
	if (button == Button1)
		fractal->allow_julia_change = !fractal->allow_julia_change;
	else if (button == Button5)
		fractal->zoom *= 0.95;
	else if (button == Button4)
		fractal->zoom *= 1.05;
	if (fractal->zoom < 0.01)
		fractal->zoom = 0.01;
	else if (fractal->zoom > 100)
		fractal->zoom = 100;
	fractal_render(fractal);
	return (0);
}*/

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    double	mouse_x;
    double	mouse_y;

    mouse_x = (x / (double)WIDTH) * 4 - 2;
    mouse_y = (y / (double)HEIGHT) * 4 - 2;

    if (!ft_strncmp(fractal->name, "julia", 5))
    {
        if (button == Button1)
        {
            fractal->julia_x = mouse_x;
            fractal->julia_y = mouse_y;
            fractal_render(fractal);
        }
    }

    if (button == Button4) // Zoom in
    {
        fractal->shift_x -= (mouse_x - fractal->shift_x) * 0.05;
        fractal->shift_y -= (mouse_y - fractal->shift_y) * 0.05;
        fractal->zoom *= 1.1;
        fractal_render(fractal);
    }
    else if (button == Button5) // Zoom out
    {
        fractal->shift_x += (mouse_x - fractal->shift_x) * 0.05;
        fractal->shift_y += (mouse_y - fractal->shift_y) * 0.05;
        fractal->zoom /= 1.1;
        fractal_render(fractal);
    }

    return (0);
}

int julia_track(int x, int y, t_fractal *fractal)
{
    double new_julia_x;
    double new_julia_y;

    if (!fractal->allow_julia_change) // Si no está activado, no cambia
        return (0);

    new_julia_x = (x / (double)WIDTH) * 4 - 2;
    new_julia_y = (y / (double)HEIGHT) * 4 - 2;

    if (new_julia_x != fractal->julia_x || new_julia_y != fractal->julia_y)
    {
        fractal->julia_x = new_julia_x;
        fractal->julia_y = new_julia_y;
        fractal_render(fractal);
    }

    return 0;
}
