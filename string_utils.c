/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:58:12 by mumajeed          #+#    #+#             */
/*   Updated: 2025/02/08 15:51:36 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

/*int	ft_strncmp(char *s1, char *s2, int n)
{
	if (!s1 || !s2 || n <= 0)
		return (0);
	while (*s1 && *s2 && n > 0 && *s1 != '\0')
	{
		s1++;
		s2++;
		--n;
	}
	return (*s1 - *s2);
}*/

int	ft_isdigit(char	c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int i;

	if (!s1 || !s2 || n <= 0)
		return (0);
	
	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}

	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	putstr_fd(char *s, int fd)
{
	int ret;
	
	if (!s || fd < 0)
		return ;
	ret = write(fd, s, ft_strlen(s));
	(void)ret;
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
