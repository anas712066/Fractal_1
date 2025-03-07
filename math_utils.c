/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:39:36 by mumajeed          #+#    #+#             */
/*   Updated: 2025/02/11 20:15:38 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*double	map(double n, t_range new_range, t_range old_range)
{
	double	scale;

	scale = (new_range.max - new_range.min) / (old_range.max - old_range.min);
	return (scale * (n - old_range.min) + new_range.min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}*/

#include "fractol.h"

double	map(double n, t_range new_range, t_range old_range)
{
	double	scale;

	scale = (new_range.max - new_range.min) /
		(old_range.max - old_range.min);
	return (scale * (n - old_range.min) + new_range.min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
