/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:47:42 by wkraig            #+#    #+#             */
/*   Updated: 2019/09/12 19:36:12 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tfnd, size_t len)
{
	size_t	i;
	int		n;

	i = 0;
	n = 0;
	if (len + 1 < len)
		return (NULL);
	if (tfnd[n] == '\0')
	{
		return ((char *)str);
	}
	while (str[i] != '\0' && i <= len)
	{
		n = 0;
		while ((str[i + n] == tfnd[n] && i + n < len) || tfnd[n] == '\0')
		{
			if (tfnd[n] == '\0')
			{
				return ((char *)str + i);
			}
			n++;
		}
		i++;
	}
	return (0);
}
