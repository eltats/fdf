/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:38:44 by wkraig            #+#    #+#             */
/*   Updated: 2019/09/11 19:32:16 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	j = 0;
	i = 0;
	if (size + 1 < size)
		return (0);
	if (!dest && !src)
		return (0);
	len = ft_strlen((char *)src);
	while (dest[i] && i < size)
		i++;
	if (size > 0)
	{
		while (src[j] && i < size - 1)
			dest[i++] = src[j++];
	}
	if (j > 0)
	{
		dest[i] = '\0';
		return (len + (i - j));
	}
	return (len + i);
}
