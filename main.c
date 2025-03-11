/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:47:49 by mumajeed          #+#    #+#             */
/*   Updated: 2025/03/08 20:23:30 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

static int	check_args(char *arg)
{
	int	i;
	int	point_found;

	i = 0;
	point_found = 0;
	if (!arg || !arg[0])
		return (0);
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!ft_isdigit(arg[i]))
		return (0);
	while (arg[i])
	{
		if (arg[i] == '.')
		{
			if (point_found || !ft_isdigit(arg[i + 1]))
				return (0);
			point_found = 1;
		}
		else if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	init_julia(t_fractal *fractal, char **av)
{
	if (!check_args(av[2]) || !check_args(av[3]))
	{
		putstr_fd("Error: Julia values must be valid floats.\n", 2);
		exit(EXIT_FAILURE);
	}
	fractal->julia_x = atodbl(av[2]);
	fractal->julia_y = atodbl(av[3]);
	if (fractal->julia_x > 1 || fractal->julia_x < -1
		|| fractal->julia_y > 1 || fractal->julia_y < -1)
	{
		putstr_fd("Error: Julia values must be between -1 and 1.\n", 2);
		exit(EXIT_FAILURE);
	}
}

static int	check_fractal_name(char *name)
{
	if (!name)
		return (0);
	if (ft_strncmp(name, "mandelbrot", 11) == 0)
		return (1);
	if (ft_strncmp(name, "julia", 6) == 0)
		return (2);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;
	int			fractal_type;

	fractal.color_shift = 100;
	if (ac < 2 || ac > 4)
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	fractal_type = check_fractal_name(av[1]);
	if ((fractal_type == 1 && ac == 2) || (fractal_type == 2 && ac == 4))
	{
		fractal.name = av[1];
		if (fractal_type == 2)
			init_julia(&fractal, av);
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
}
