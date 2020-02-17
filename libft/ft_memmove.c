/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:48:58 by wkraig            #+#    #+#             */
/*   Updated: 2019/09/11 22:26:58 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*s;
	size_t			i;

	dst = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (dst > s)
	{
		while (n--)
		{
			dst[n] = s[n];
		}
		return (dst);
	}
	if (dst < s)
	{
		while (i < n)
		{
			dst[i] = s[i];
			i++;
		}
		return (dst);
	}
	return (dst);
}
