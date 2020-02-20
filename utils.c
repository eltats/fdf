/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:44:28 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/20 03:42:00 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// добавить некоторые в либу
#include "fdf.h"

void	ft_swap(float *a, float *b)
{
	float tmp;

	tmp = *b;
	*a = *a + *b;
	*b = *a - *b;
	*a = tmp;
}

float	ft_abs(float a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

void	iso(float *x, float *y, int z)
{
	float x2;
	float	y2;

	x2 = *x;
	y2 = *y;
	*y = cos(1) * *y - sin(1) * z;
	// *x = sin(1) * *x - cos(1) * z;
	// *y = cos(1) * *y - sin(1) - z;
	// *x = sin(1) * *x - cos(1) - z;
	// *y = x * cos
}

static int		find_num(char c)
{
	int i;
	const char	str[17] = "0123456789abcdef";
	const char	str2[17] = "0123456789ABCDEF";

	i = 0;
	while (str[i])
	{
		if (c == str[i] || str2[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int		ft_atoi_base_16(char *str)
{
	int		nb;
	int		i;
	
	nb = 0;
	i = 0;
	while (str[i] == '0' || str[i] == 'x')
		i++;
	while (find_num(str[i]))
	{
		nb *= 16;
		nb += find_num(str[i]);
		i++;
	}
	return (nb);
}