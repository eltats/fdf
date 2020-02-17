/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:35:01 by wkraig            #+#    #+#             */
/*   Updated: 2019/09/11 19:30:41 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;

	tmpdst = dst;
	tmpsrc = (unsigned char *)src;
	i = 0;
	if (n + 1 < n)
		return (NULL);
	if (!(tmpdst) && !(tmpsrc))
		return (NULL);
	while (n--)
	{
		tmpdst[i] = tmpsrc[i];
		i++;
	}
	return (tmpdst);
}
