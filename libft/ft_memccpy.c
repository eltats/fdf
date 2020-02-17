/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:22:45 by wkraig            #+#    #+#             */
/*   Updated: 2019/09/11 19:28:56 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	*s;
	unsigned char	ascii;

	dst = (unsigned char *)dest;
	s = (unsigned char *)src;
	ascii = (unsigned char)c;
	if (n + 1 < n)
		return (NULL);
	while (n--)
	{
		*dst = *s;
		dst++;
		if (*s == ascii)
			return (dst);
		s++;
	}
	return (NULL);
}
