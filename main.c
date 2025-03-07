/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:47:49 by mumajeed          #+#    #+#             */
/*   Updated: 2025/02/25 21:33:30 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) ||
		(ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		fractal.julia_x = atodbl(av[2]);
		fractal.julia_y = atodbl(av[3]);
		// Inicia la aplicación correctamente
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}*/
/*int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) ||
		(ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];

		Inicializar julia_x y julia_y solo si es julia 
if (!ft_strncmp(av[1], "julia", 5))
{
    if (ac == 4)
    {
        fractal.julia_x = atodbl(av[2]);
        fractal.julia_y = atodbl(av[3]);
    }
    else
    {
        fractal.julia_x = -0.7; // Valores por defecto
        fractal.julia_y = 0.27015;
    }
}

	else
	{
		fractal.julia_x = 0.0;
		fractal.julia_y = 0.0;
	}

		fractal_init(&fractal);
		fractal_render(&fractal);
		if (fractal.mlx_connection && fractal.mlx_window)
			mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}*/
#include "fractol.h"
#include "minilibx-linux/mlx.h"

static int	check_args(char *arg)
{
	size_t	i;
	int	point_found;

	point_found = 0;
	i = 0;
	if (arg[0] != '-' && !ft_isdigit(arg[0]))
		return (0);
	i++;
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '.')
		       return (0);
		if (arg[i] == '.')
		{
			if (point_found == 0)
				point_found = 1;
			else
				return (0);
		}		
		i++;
	}
	return (1);
}

static void	init_julia(t_fractal *fractal, char **av)
{
    if (check_args(av[2]) == 1 && check_args(av[3]) == 1)
    {
        fractal->julia_x = atodbl(av[2]);
        fractal->julia_y = atodbl(av[3]);
	if (fractal->julia_x > 1 || fractal->julia_x < -1 || 
			fractal->julia_y > 1 || fractal->julia_y < -1)
	{
		putstr_fd("Argument out of range: please give numbers between 1 and -1\n", 2);
		exit(0);
	}
    }
    else
    {
        fractal->julia_x = -0.7;
        fractal->julia_y = 0.27015;
    }
}

int	main(int ac, char **av)
{
    t_fractal	fractal;

    fractal.color_shift = 100;
    if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) ||
        (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
    {
        fractal.name = av[1];
        if (!ft_strncmp(av[1], "julia", 5))
            init_julia(&fractal, av);
        fractal_init(&fractal);
        fractal_render(&fractal);
        if (fractal.mlx_connection && fractal.mlx_window)
            mlx_loop(fractal.mlx_connection);
    }
    else
    {
        putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
}
