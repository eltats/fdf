/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:32:26 by wkraig            #+#    #+#             */
/*   Updated: 2019/09/11 22:20:17 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int n;

	i = 0;
	n = 0;
	if (to_find[n] == '\0')
	{
		return ((char *)str);
	}
	while (str[i] != '\0')
	{
		n = 0;
		while (str[i + n] == to_find[n] || to_find[n] == '\0')
		{
			if (to_find[n] == '\0')
			{
				return ((char *)str + i);
			}
			n++;
		}
		i++;
	}
	return (0);
}
