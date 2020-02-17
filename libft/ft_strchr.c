/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:29:00 by wkraig            #+#    #+#             */
/*   Updated: 2020/01/08 15:58:23 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char ascii;

	ascii = (char)c;
	while (*s != ascii)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
