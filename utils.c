/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:44:28 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/22 18:33:45 by hcloves          ###   ########.fr       */
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

void	iso(float *x, float *y, int z, t_win *win)
{
	float	x2;
	float	y2;

	x2 = *x;
	y2 = *y;
	*x = (x2 - y2) * cos(0.523599);
	*y = -z + (x2 + y2) * sin(0.523599);
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