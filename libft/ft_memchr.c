/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:18:59 by wkraig            #+#    #+#             */
/*   Updated: 2019/09/11 19:53:27 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char *tmp;
	unsigned char ascii;

	tmp = (unsigned char*)arr;
	ascii = (unsigned char)c;
	if (n + 1 < n)
		return (NULL);
	while (n)
	{
		if (*tmp == ascii)
			return (tmp);
		tmp++;
		n--;
	}
	return (NULL);
}
