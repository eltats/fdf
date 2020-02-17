/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:51:24 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/05 19:18:07 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_symbolcheck(char c)
{
	const char	str[17] = "0123456789abcdef";
	const char	str2[17] = "0123456789ABCDEF";
	int			i;
	
	i = 0;
	if (c != ' ' && !ft_isdigit(c) && c != '-')
		return (0);
	if (c != 'x')
		return (0);
	if (c )
	while (str[i])
	{
		if (c != str[i] || c != str2[i])
			return (0);
		i++;
	}
	return (1);
}

int ft_validation(char **map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_symbolcheck(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
