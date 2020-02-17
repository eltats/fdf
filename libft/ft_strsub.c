/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:37:04 by wkraig            #+#    #+#             */
/*   Updated: 2019/09/27 16:15:59 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*substr;

	if (len + 1 < len)
		return (NULL);
	if (s)
	{
		if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		i = 0;
		while (i < len)
		{
			substr[i] = s[i + start];
			i++;
		}
		substr[i] = '\0';
		return (substr);
	}
	return (NULL);
}
